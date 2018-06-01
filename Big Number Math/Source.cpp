

#include "BigNum.h"

int main()
{
	unsigned int a[3], b[3], c[4], d[4], e[6];
	BigInteger jordan;

	a[0] = 5;
	a[1] = 34;
	a[2] = 0;

	b[0] = 5;
	b[1] = 34;
	b[2] = 34;

	jordan.addition(a, 3, b, 3, c, 4);
	jordan.subtraction(a, 3, b, 3, d, 4);
	bool answer = jordan.compare_less_than(a, 3, b, 3);
	jordan.multiplication(a, 3, b, 3, e, 6);
	answer = jordan.compare_equal_to(a, 3, b, 2);

	int g = 0;
}