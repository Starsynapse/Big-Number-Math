
#ifndef JORDAN
#define JORDAN

#include <iostream>
#include <vector>
using namespace std;

class BigInteger
{
public:
	vector<unsigned int> number_array;
	/// <summary>
	/// jordan is cool at adding
	/// </summary>
	/// <param name="a">first variable used in addition</param>
	/// <param name="a_size">32b size of a</param>
	/// <param name="b">second variable used in addition</param>
	/// <param name="b_size">32b size of b</param>
	/// <param name="c">output</param>
	/// <param name="c_size">32b size of output</param>
	/// <returns>zero for sucess, non zero for error</returns>
	static int addition(const unsigned int* a, unsigned int a_size, const unsigned int* b,
		unsigned int b_size, unsigned int* c, unsigned int c_size);

	/// <summary>
	/// jordan is cool at subtracting
	/// </summary>
	/// <param name="a">first variable used in subtraction</param>
	/// <param name="a_size">32b size of a</param>
	/// <param name="b">second variable used in subtraction</param>
	/// <param name="b_size">32b size of b</param>
	/// <param name="c">output</param>
	/// <param name="c_size">32b size of output</param>
	/// <returns>zero for sucess, non zero for error</returns>
	static int subtraction(const unsigned int* a, unsigned int a_size, const unsigned int* b,
		unsigned int b_size, unsigned int* c, unsigned int c_size);

	/// <summary>
	/// Compares if a is less than b
	/// </summary>
	/// <param name="a"></param>
	/// <param name="a_size"></param>
	/// <param name="b"></param>
	/// <param name="b_size"></param>
	/// <returns></returns>
	static bool compare_less_than(const unsigned int* a, unsigned int a_size, const unsigned int* b,
		unsigned int b_size);

	/// <summary>
	/// Compares if a is greater than b
	/// </summary>
	/// <param name="a"></param>
	/// <param name="a_size"></param>
	/// <param name="b"></param>
	/// <param name="b_size"></param>
	/// <returns></returns>
	static bool compare_greater_than(const unsigned int* a, unsigned int a_size, const unsigned int* b,
		unsigned int b_size);

	/// <summary>
	/// Compares a and b if equal
	/// </summary>
	/// <param name="a"></param>
	/// <param name="a_size"></param>
	/// <param name="b"></param>
	/// <param name="b_size"></param>
	/// <returns></returns>
	static bool compare_equal_to(const unsigned int* a, unsigned int a_size, const unsigned int* b,
		unsigned int b_size);

	/// <summary>
	/// Multiplies a by b
	/// </summary>
	/// <param name="a"></param>
	/// <param name="a_size"></param>
	/// <param name="b"></param>
	/// <param name="b_size"></param>
	/// <param name="c"></param>
	/// <param name="c_size"></param>
	/// <returns></returns>
	static int multiplication(const unsigned int* a, unsigned int a_size, const unsigned int* b,
		unsigned int b_size, unsigned int* c, unsigned int c_size);

	/// <summary>
	/// Divide a by b
	/// </summary>
	/// <param name="a"></param>
	/// <param name="a_size"></param>
	/// <param name="b"></param>
	/// <param name="b_size"></param>
	/// <param name="c"></param>
	/// <param name="c_size"></param>
	/// <returns></returns>
	static int division(const unsigned int* a, unsigned int a_size, const unsigned int* b,
		unsigned int b_size, unsigned int* c, unsigned int c_size);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="a"></param>
	/// <param name="a_size"></param>
	/// <returns></returns>
	static unsigned long long log_base_2(unsigned int* a, unsigned int a_size);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="z"></param>
	/// <param name="z_size"></param>
	/// <param name="ammount"></param>
	/// <returns></returns>
	static int left_shift(unsigned int* z, unsigned int z_size, unsigned long long ammount, 
					unsigned int* output, unsigned int output_size);
};

#endif //JORDAN