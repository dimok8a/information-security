#pragma once
#include "BigInt.h"
class RSA : public BigInt
{
public:
	// ����� ����������� ������ ��������
	static BigInt getNOD(BigInt a, BigInt b);
	// �������� ������� �� �����
	static bool isSimple(BigInt a);

	// ������� ���������� ����� � � ������� b
	static BigInt pow(BigInt a, BigInt b);
	// ������� ��������� 20-�� ����� e �� ������ ����������� fi
	static std::vector<BigInt> generateENumbers(BigInt fi);
	// ������� ��������� 100 ����� d �� ������ ����������� e � fi
	static std::vector<BigInt> generateDNumbers(BigInt e, BigInt fi);
	// ������� ������ ����� ax + by = ���(a, b)
	static void gcdExtended(BigInt a, BigInt b, BigInt* x, BigInt* y, bool* isNegativeX, bool* isNegativeY);
	// ���������� �������� (a ^ b) % n
	static BigInt getRemainder(BigInt a, BigInt b, BigInt n);
};

