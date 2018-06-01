#include "BigNum.h"
#include <intrin.h>
#define min(a,b) (((a)<(b)) ? (a) : (b))
#define max(a,b) (((a)>(b)) ? (a) : (b))

int BigInteger::addition(const unsigned int * a, unsigned int a_size, const unsigned int * b, unsigned int b_size, unsigned int * c, unsigned int c_size)
{
	if (max(a_size, b_size) > c_size)
	{
		return -1;
	}
	unsigned long long carry = 0;
	for (int i = 0; i < min(a_size, b_size); i++)
	{
		unsigned long long sum = (unsigned long long)a[i] + (unsigned long long)b[i] + carry;
		carry = 0;
		if (sum >(unsigned int)-1)
		{
			carry = 1;
		}

		c[i] = (unsigned int)sum;
	}

	for (int i = min(a_size, b_size); i < max(a_size, b_size); i++)
	{
		unsigned long long sum = (unsigned long long)((a_size > b_size) ? a[i] : b[i]) + carry;
		carry = 0;
		if (sum >(unsigned int)-1)
		{
			carry = 1;
		}

		c[i] = (unsigned int)sum;
	}

	if (c_size > max(a_size, b_size))
	{
		c[max(a_size, b_size)] = carry;
	}

	for (int i = max(a_size, b_size) + 1; i < c_size; i++)
	{
		c[i] = 0;
	}

	return 0;
}

int BigInteger::subtraction(const unsigned int * a, unsigned int a_size, const unsigned int * b, unsigned int b_size, unsigned int * c, unsigned int c_size)
{
	if (max(a_size, b_size) > c_size)
	{
		return -1;
	}
	unsigned long long carry = 0;
	for (int i = 0; i < min(a_size, b_size); i++)
	{
		unsigned long long dif = ((unsigned long long)a[i] - (unsigned long long)b[i]) - carry;
		carry = 0;
		if (dif >(unsigned int)-1)
		{
			carry = 1;
		}

		c[i] = (unsigned int)dif;
	}

	for (int i = min(a_size, b_size); i < max(a_size, b_size); i++)
	{
		unsigned long long dif = (unsigned long long)((a_size > b_size) ? a[i] : b[i]) - carry;
		carry = 0;
		if (dif >(unsigned int)-1)
		{
			carry = 1;
		}

		c[i] = (unsigned int)dif;
	}

	if (c_size > max(a_size, b_size))
	{
		c[max(a_size, b_size)] = -(int)carry;
	}

	for (int i = max(a_size, b_size) + 1; i < c_size; i++)
	{
		c[i] = -(int)carry;
	}

	return 0;
}

bool BigInteger::compare_less_than(const unsigned int * a, unsigned int a_size, const unsigned int * b, unsigned int b_size)
{
	for (int i = max(a_size, b_size) - 1; i >= min(a_size, b_size); i--)
	{
		if (a_size > b_size && a[i] != 0)
		{
			return false;
		}
		if (b_size > a_size && b[i] != 0)
		{
			return true;
		}

	}

	for (int i = min(a_size, b_size) - 1; i >= 0; i--)
	{
		if (a[i] > b[i])
		{
			return false;
		}
		if (a[i] < b[i])
		{
			return true;
		}
	}
	return false;
}

bool BigInteger::compare_greater_than(const unsigned int * a, unsigned int a_size, const unsigned int * b, unsigned int b_size)
{
	return compare_less_than(b, b_size, a, a_size);
}

bool BigInteger::compare_equal_to(const unsigned int * a, unsigned int a_size, const unsigned int * b, unsigned int b_size)
{
	for (int i = max(a_size, b_size) - 1; i >= min(a_size, b_size); i--)
	{
		if ((a_size > b_size) ? a[i] : b[i])
		{
			return false;
		}
	}

	for (int i = min(a_size, b_size) - 1; i >= 0; i--)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}

int BigInteger::multiplication(const unsigned int * a, unsigned int a_size, const unsigned int * b, unsigned int b_size, unsigned int * c, unsigned int c_size)
{
	for (int i = 0; i < c_size; i++)
	{
		c[i] = 0;
	}

	for (int i = 0; i < a_size; i++)
	{
		for (int o = 0; o < b_size; o++)
		{
			unsigned long long number_64 = (unsigned long long)a[i] * (unsigned long long)b[o];
			int destination_index = i + o;
			unsigned int store[2] = { (unsigned int)(number_64 & 0xffffffff), (unsigned int)(number_64 >> 32) };
			addition(c + destination_index, c_size - destination_index, store, 2, 
					 c + destination_index, c_size - destination_index);
		}
	}
	return 0;
}

int BigInteger::division(const unsigned int * a, unsigned int a_size, const unsigned int * b, 
						 unsigned int b_size, unsigned int * c, unsigned int c_size)
{
	unsigned long long max_guess_log_2;
	
	return 0;
}

unsigned long long BigInteger::log_base_2(unsigned int * a, unsigned int a_size)
{
	for (int i = a_size - 1; i >= 0; i--)
	{
		if (a[i])
		{
			unsigned long nonzero, MSB;
			nonzero = _BitScanReverse(&MSB, a[i]);
			return 32 * i + MSB;
		}
	}
	return -1;
}

unsigned long long div_32_ceil(unsigned long long ax_variable)
{
	if (ax_variable & 0b11111)
	{
		return (ax_variable >> 5) + 1;
	}
	else
	{
		return ax_variable >> 5;
	}
}

int BigInteger::left_shift(unsigned int * z, unsigned int z_size, unsigned long long ammount,
	unsigned int* output, unsigned int output_size)
{
	if (z_size + div_32_ceil(ammount) > output_size)
	{
		return -1;
	}

	for (int i = 0; i < output_size; i++)
	{
		output[i] = 0;
	}
	
	for (int i = 0; i < z_size; i++)
	{
		unsigned long long broken_weird_name_value;

	}
	return 0;
}
