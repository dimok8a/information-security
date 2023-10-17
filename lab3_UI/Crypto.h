#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <windows.h>
#include <locale.h>

using namespace std;
#pragma once
class Crypto
{
private:
	static uint32_t getNumberFromBinary(vector<uint32_t> binaryCode);
	static vector<uint32_t> getBinary(uint32_t number, int blockSize);
	static vector <vector <uint32_t>> separateVector(vector <uint32_t> originalVector, int chunkCount);
	static uint32_t getNumberFromBlocks(vector <uint32_t> blocks, int blockSize);
	static vector<array<uint32_t, 2>> divideTextToPairs(System::String^ text);
	static std::array<uint32_t, (size_t)8> divideKey(System::String^ key);
	static vector<uint32_t> separateNumberByNBits(uint32_t number, int n, int k);
	static uint32_t changeByTable(uint32_t r);
	static System::String^ convertToUTF16(array<uint32_t, 2> encryptedText);
public:
	
	static System::String^ encrypt(System::String^ key, System::String^ text);
	static System::String^ decrypt(System::String^ key, System::String^ text);

};

