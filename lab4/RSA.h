#pragma once
#include "BigInt.h"
class RSA : public BigInt
{
public:
	// Поиск Наибольшего Общего Делителя
	static BigInt getNOD(BigInt a, BigInt b);
	// Проверка простое ли число
	static bool isSimple(BigInt a);

	// Функция возведения числа а в степень b
	static BigInt pow(BigInt a, BigInt b);
	// Функция генерации 20-ти чисел e на основе переданного fi
	static std::vector<BigInt> generateENumbers(BigInt fi);
	// Функция генерации 100 чисел d на основе переданного e и fi
	static std::vector<BigInt> generateDNumbers(BigInt e, BigInt fi);
	// Функция поиска чисел ax + by = НОД(a, b)
	static void gcdExtended(BigInt a, BigInt b, BigInt* x, BigInt* y, bool* isNegativeX, bool* isNegativeY);
	// Возвращает значение (a ^ b) % n
	static BigInt getRemainder(BigInt a, BigInt b, BigInt n);
};

