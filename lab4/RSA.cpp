#include "RSA.h"

BigInt RSA::pow(BigInt a, BigInt b)
{
	BigInt temp(a);
	temp ^= b;
	return temp;
}

BigInt RSA::getNOD(BigInt a, BigInt b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

bool RSA::isSimple(BigInt a)
{
	for (BigInt i = 2; i <= sqrt(a) + 1; i++)
	{
		if (a % i == BigInt("0"))
			return false;
	}
	return true;
}


std::vector<BigInt> RSA::generateENumbers(BigInt fi)
{
	std::vector <BigInt> eNumbers;
	BigInt currentNumber = fi - 1;
	while (currentNumber != BigInt(1) && eNumbers.size() < 20)
	{
		if (RSA::isSimple(currentNumber) && RSA::getNOD(currentNumber, fi) == BigInt(1))
			eNumbers.push_back(currentNumber);
		currentNumber -= BigInt(1);
	}
	return eNumbers;
}

std::vector<BigInt> RSA::generateDNumbers(BigInt e, BigInt fi)
{
	std::vector<BigInt> dNumbers;
	BigInt x, y;
	bool isNegativeX, isNegativeY;
	RSA::gcdExtended(e, fi, &x, &y, &isNegativeX, &isNegativeY);
	if (isNegativeX)
		x = fi - x;
	BigInt currentNumber = x;
	for (int i = 0; i < 100; i++)
	{
		dNumbers.push_back(currentNumber);
		currentNumber += fi;
	}
	return dNumbers;
}

void RSA::gcdExtended(BigInt a, BigInt b, BigInt* x, BigInt* y, bool* isNegativeX, bool* isNegativeY)
{
	// Base Case 
	if (a == BigInt("0"))
	{
		*x = BigInt("0");
		*y = BigInt("1");
		*isNegativeX = false;
		*isNegativeY = false;
		return;
	}

	BigInt x1, y1; // To store results of recursive call 
	bool isNegativeX1, isNegativeY1;
	RSA::gcdExtended(b % a, a, &x1, &y1, &isNegativeX1, &isNegativeY1);

	// Поскольку класс не работает с отрицательными числами, то запоминаем их состояние и работаем исходя из него
	if (isNegativeX1)
	{
		if (isNegativeY1)
		{
			try
			{
				*x = (b / a) * x1 - y1;
				*isNegativeX = false;
			}
			catch (const std::exception&)
			{
				*x = y1 - (b / a) * x1;
				*isNegativeX = true;
			}
		}
		else
		{
			*x = (b / a) * x1 + y1;
			*isNegativeX = false;
		}
	}
	else
	{
		if (isNegativeY1)
		{
			*x = (b / a) * x1 + y1;
			*isNegativeX = true;
		}
		else
		{
			try
			{
				*x = y1 - (b / a) * x1;
				*isNegativeX = false;
			}
			catch (const std::exception&)
			{
				*x = (b / a) * x1 - y1;
				*isNegativeX = true;
			}
		}
	}
	*y = x1;
	if (isNegativeX1)
		*isNegativeY = true;
	else
		*isNegativeY = false;
	return;
}

BigInt RSA::getRemainder(BigInt a, BigInt b, BigInt n)
{
	BigInt result = 1;
	a %= n;

	while (b > BigInt("0")) {
		if (b % 2 == 1) {
			result = (result * a) % n;
		}
		a = (a * a) % n;
		b /= 2;
	}
	return result;
	/* 
	BigInt remainder = a % n;
	for (int i = 1; i < b; i++)
	{
		remainder = (remainder * a) % n;
	}
	return remainder;
	*/
}
