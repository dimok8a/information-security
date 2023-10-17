#include "Crypto.h"


// ������� ������
array<std::array<int, 16>, 8> CHANGE_TABLE = {
		{
			{0x4, 0xA, 0x9, 0x2, 0xD, 0x8, 0x0, 0xE, 0x6, 0xB, 0x1, 0xC, 0x7, 0xF, 0x5, 0x3},
			{0xE, 0xB, 0x4, 0xC, 0x6, 0xD, 0xF, 0xA, 0x2, 0x3, 0x8, 0x1, 0x0, 0x7, 0x5, 0x9},
			{0x5, 0x8, 0x1, 0xD, 0xA, 0x3, 0x4, 0x2, 0xE, 0xF, 0xC, 0x7, 0x6, 0x0, 0x9, 0xB},
			{0x7, 0xD, 0xA, 0x1, 0x0, 0x8, 0x9, 0xF, 0xE, 0x4, 0x6, 0xC, 0xB, 0x2, 0x5, 0x3},
			{0x6, 0xC, 0x7, 0x1, 0x5, 0xF, 0xD, 0x8, 0x4, 0xA, 0x9, 0xE, 0x0, 0x3, 0xB, 0x2},
			{0x4, 0xB, 0xA, 0x0, 0x7, 0x2, 0x1, 0xD, 0x3, 0x6, 0x8, 0x5, 0x9, 0xC, 0xF, 0xE},
			{0xD, 0xB, 0x4, 0x1, 0x3, 0xF, 0x5, 0x9, 0x0, 0xA, 0xE, 0x7, 0x6, 0x8, 0x2, 0xC},
			{0x1, 0xF, 0xD, 0x0, 0x5, 0x7, 0xA, 0x4, 0x9, 0x2, 0x3, 0xE, 0x6, 0xB, 0x8, 0xC}
		}
};
/*
array<array<int, 16>, 8> CHANGE_TABLE = {
		{
			{0x9, 0x6, 0x3, 0x2, 0x8, 0xB, 0x1, 0x7, 0xA, 0x4, 0xE, 0xF, 0xC, 0x0, 0xD, 0x5},
			{0x3, 0x7, 0xE, 0x9, 0x8, 0xA, 0xF, 0x0, 0x5, 0x2, 0x6, 0xC, 0xB, 0x4, 0xD, 0x1},
			{0xE, 0x4, 0x6, 0x2, 0xB, 0x3, 0xD, 0x8, 0xC, 0xF, 0x5, 0xA, 0x0, 0x7, 0x1, 0x9},
			{0xE, 0x7, 0xA, 0xC, 0xD, 0x1, 0x3, 0x9, 0x0, 0x2, 0xB, 0x4, 0xF, 0x8, 0x5, 0x6},
			{0xB, 0x5, 0x1, 0x9, 0x8, 0xD, 0xF, 0x0, 0xE, 0x4, 0x2, 0x3, 0xC, 0x7, 0xA, 0x6},
			{0x3, 0xA, 0xD, 0xC, 0x1, 0x2, 0x0, 0xB, 0x7, 0x5, 0x9, 0x4, 0x8, 0xF, 0xE, 0x6},
			{0x1, 0xD, 0x2, 0x9, 0x7, 0xA, 0x6, 0x0, 0x8, 0xC, 0x4, 0x5, 0xF, 0x3, 0xB, 0xE},
			{0xB, 0xA, 0xF, 0x5, 0x0, 0xC, 0xE, 0x8, 0x6, 0x2, 0x3, 0x9, 0x1, 0x7, 0xD, 0x4}
		}
};
*/



// ���������� ����� �� ������ ��� ��������� ������
uint32_t Crypto::getNumberFromBinary(vector<uint32_t> binaryCode)
{
	uint32_t answer = 0;
	int base = 1;
	for (int i = binaryCode.size() - 1; i >= 0; i--) {
		answer += base * binaryCode.at(i);
		base *= 2;
	}
	return answer;
}


// �������� �������� ��� ����� � ��������� ������ ���
vector<uint32_t> Crypto::getBinary(uint32_t number, int size)
{
	int bitsCounter = 0;
	vector<uint32_t> binaryCode;
	while (number) {
		if (number & 1)
			binaryCode.push_back(1);
		else
			binaryCode.push_back(0);
		number >>= 1;
		bitsCounter++;
	}
	while (bitsCounter < size)
	{
		binaryCode.push_back(0);
		bitsCounter++;
	}
	reverse(binaryCode.begin(), binaryCode.end());
	return binaryCode;
}

// ���������� �����-������ (UTF-16) �� 8 ���������
array<uint32_t, (size_t)8> Crypto::divideKey(System::String^ key)
{
	array<uint32_t, size_t(8)> result;
	vector<uint32_t> currentBlock;
	int i = 0;
	int j = 7;
	while (i < key->Length)
	{
		// ������� 32-������ ���� �� ���� 16-�� ������ ��������
		currentBlock.push_back(key[i++]);
		currentBlock.push_back(key[i++]);
		// �� �������� ���� ���� � �������� ������� K = {K8, K7, K6, K5, K4, K3, K2, K1}, ������� ��� � ������
		result[j--] = getNumberFromBlocks(currentBlock, 16);
		currentBlock.clear();
	}
	return result;
}

// ������� ��������� ������� �� ���������� � �������� chunkCount
vector <vector <uint32_t>> Crypto::separateVector(vector <uint32_t> originalVector, int chunkCount)
{
	vector <vector <uint32_t>> result;
	size_t chunkSize = originalVector.size() / chunkCount;
	for (int i = 0; i < chunkCount; i++)
	{
		if (i != chunkCount - 1)
		{
			vector <uint32_t> newVector(originalVector.begin() + i * chunkSize, originalVector.begin() + (i + 1) * chunkSize);
			result.push_back(newVector);
		}
		else
		{
			vector <uint32_t> newVector(originalVector.begin() + i * chunkSize, originalVector.end());
			result.push_back(newVector);
		}
	}
	return result;

}

// ������� �������� ����� �� ������ � ������ �����
uint32_t Crypto::getNumberFromBlocks(vector <uint32_t> blocks, int blockSize)
{
	// �������� ����� �� ������ � ������
	// ������� ����������� � �������� �������
	vector<uint32_t> binaryCode;
	for (int i = 0; i < blocks.size(); i++) {
		vector <uint32_t> binaryNumber = getBinary(blocks[i], blockSize);
		binaryCode.insert(binaryCode.end(), binaryNumber.begin(), binaryNumber.end());
	}
	// �� �������� ����������� � ����������
	return getNumberFromBinary(binaryCode);
}


// ������� ���������� ����� (UTF-16) � ������ �� ��� �� 32 ��� (����� ����� + ������ �����)
vector<array<uint32_t, 2>> Crypto::divideTextToPairs(System::String^ text)
{
	if (text->Length == 0)
	{
		vector<uint32_t> leftPart{ 0, 0 };
		vector<uint32_t> rightPart{ 0, 0 };
		vector<array<uint32_t, 2>> result{ {getNumberFromBlocks(leftPart, 16), getNumberFromBlocks(rightPart, 16)} };
		return result;
	}
	else
	{
		vector<uint32_t> leftPart, rightPart;
		vector<array<uint32_t, 2>> result;
		for (int i = 0; i < text->Length; i++)
		{
			if (leftPart.size() < 2)
				leftPart.push_back(text[i]);
			else if (rightPart.size() < 2)
				rightPart.push_back(text[i]);
			if (rightPart.size() == 2)
			{
				result.push_back({ getNumberFromBlocks(leftPart, 16), getNumberFromBlocks(rightPart, 16) });
				leftPart.clear();
				rightPart.clear();
			}
		}
		// ���� ���������� �������� �� ����� 4 (������ != 64), �� ���������� ������ ������� 
		if (text->Length % 4 != 0)
		{
			while (leftPart.size() < 2)
				leftPart.push_back(0);
			while (rightPart.size() < 2)
				rightPart.push_back(0);
			result.push_back({ getNumberFromBlocks(leftPart, 16), getNumberFromBlocks(rightPart, 16) });
		}
		return result;
	}
}



// ���������� ������ �� blocksCount ������ �� bitsCount ��� ����� number
// ������ ����� ������� �� ��������� 2^bitsCount - 1
vector<uint32_t> Crypto::separateNumberByNBits(uint32_t number, int bitsCount, int blocksCount)
{
	vector <uint32_t> result;
	int counter = 0;
	uint32_t newNumber = 0;
	// �������� �������� ���
	vector <uint32_t> binaryCode = getBinary(number, bitsCount * blocksCount);
	// ����� ��� �� blocksCount �����
	vector<vector<uint32_t>> binaryVectors = separateVector(binaryCode, blocksCount);
	// ������ ��� ������� ���������� � �����
	for (int i = 0; i < binaryVectors.size(); i++)
		result.push_back(getNumberFromBinary(binaryVectors[i]));
	return result;
}


// ��������� 32 ������ ����� �� �������
uint32_t Crypto::changeByTable(uint32_t r)
{
	// ������ �����/������ ����� ������ �� 8 ������ �� 4 ���
	vector <uint32_t> blocks = separateNumberByNBits(r, 4, 8);
	// �������������, ��� ��� ������ ���� � �����
	reverse(blocks.begin(), blocks.end());
	for (int i = 0; i < blocks.size(); i++)
		blocks[i] = CHANGE_TABLE[i][blocks[i]];
	// ���������� ����������� �������
	reverse(blocks.begin(), blocks.end());
	// �������� ����� � ������ �����
	return getNumberFromBlocks(blocks, 4);
}

// ����������
System::String^ Crypto::encrypt(System::String^ keyString, System::String^ textString)
{
	// ����� ����� �� ������ �� ��� (����� � ������ �����)
	vector<array<uint32_t, 2>> text = divideTextToPairs(textString);
	// ����� ���� �� 8 ���������
	array<uint32_t, size_t(8)> key = divideKey(keyString);
	
	System::String^ resultString = "";
	for (int k = 0; k < text.size(); k++)
	{
		array<uint32_t, 2> currentText = text.at(k);
		vector<array<uint32_t, 2>> result;
		int i = 1;
		uint32_t l = currentText[0];
		uint32_t r = currentText[1];
		uint32_t v;
		while (i <= 32)
		{
			v = r;
			int j = i < 25 ? (i - 1) % 8 : (32 - i) % 8;
			r = (r + key[j]) % UINT32_MAX;
			r = changeByTable(r);
			r = (r << 11) | (r >> (32 - 11));
			r = r ^ l;
			l = v;
			i++;
		}
		array<uint32_t, 2> newBlock{ r, l };
		resultString += convertToUTF16(newBlock);
	}
	return resultString;
}

// ������� ������������ ����� � ������ ����� (�������������� � 32 ������ ������) 
// � ������ �� 4 �������� (UTF-16)
System::String^ Crypto::convertToUTF16(array<uint32_t, 2> encryptedText)
{
	// ������ ������ ����� �� 2 ������� �� 16 ���
	vector<uint32_t> leftPartBits = separateNumberByNBits(encryptedText[0], 16, 2);
	vector<uint32_t> rightPartBits = separateNumberByNBits(encryptedText[1], 16, 2);
	System::String^ leftPart = gcnew System::String("");
	System::String^ rightPart = gcnew System::String("");
	for (int i = 0; i < leftPartBits.size(); i++)
	{
		leftPart += (char16_t)leftPartBits[i];
		rightPart += (char16_t)rightPartBits[i];
	}
	return leftPart + rightPart;
}


// ������������
System::String^ Crypto::decrypt(System::String^ keyString, System::String^ textString)
{
	vector<array<uint32_t, 2>> text = divideTextToPairs(textString);
	array<uint32_t, size_t(8)> key = divideKey(keyString);
	System::String^ resultString = "";
	for (int k = 0; k < text.size(); k++)
	{
		array<uint32_t, 2> currentText = text.at(k);
		array<uint32_t, 2> result;
		int i = 1;
		uint32_t l = currentText[0];
		uint32_t r = currentText[1];
		uint32_t v;
		while (i <= 32)
		{
			v = r;
			int j = i <= 8 ? (i - 1) % 8 : (32 - i) % 8;
			r = (r + key[j]) % UINT32_MAX;
			r = changeByTable(r);
			r = (r << 11) | (r >> (32 - 11));
			r = r ^ l;
			l = v;
			i++;
		}
		array<uint32_t, 2> newBlock{ r, l };
		resultString += convertToUTF16(newBlock);
	}
	return resultString;
}