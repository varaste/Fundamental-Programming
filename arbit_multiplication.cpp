#include<iostream>
#include<string>
#include<sstream>

std::string add(const std::string& x, const std::string& y);
std::string _mul(const std::string& x, const char& ch);
std::string mul(const std::string& x, const std::string& y);
std::string fact(int n);

int main()
{
	std::string a{ "789456123" };
	std::string b{ "789456123" };
	std::cout << mul("2", "1") << std::endl;
	std::cout << fact(500) << std::endl;
	return 0;
}

std::string add(const std::string& x, const std::string& y)
{
	size_t l_x{ x.length() };
	size_t l_y{ y.length() };
	size_t l_min{ l_x < l_y ? l_x : l_y };
	size_t l_max{ l_x > l_y ? l_x : l_y };
	std::string sum;
	sum.resize(l_max + 1);

	int carry{};
	for (size_t s{}, i_x{ l_x }, i_y{ l_y }, i_z{l_max}; i_z > l_max-l_min; i_z--)
	{
		s = x[--i_x] - '0' + y[--i_y] - '0' + carry;
		sum[i_z] = (s % 10) + '0';
		carry = s / 10;
	}
			
	const std::string& z = l_x > l_y ? x : y;
	for (size_t i_sum{ l_max - l_min }, s{}, i_z{l_max-l_min}; i_sum > 0; i_sum--)
	{
		s = z[--i_z] - '0' + carry;
		sum[i_sum] = (s % 10) + '0';
		carry = s / 10;
	}
	if (carry != 0)
		sum.front() = carry + '0';
	else
		sum.erase(0, 1);
	return sum;
}

std::string _mul(const std::string& x, const char& ch)
{
	size_t l_x{ x.length() };
	std::string product;
	product.resize(l_x + 1);
	int carry{};
	int mul{ ch - '0' };
	for (size_t i{ l_x }, s{}; i > 0; i--)
	{
		s = mul * (x[i-1] - '0') + carry;
		product[i] = s % 10 + '0';
		carry = s / 10;
	}
	if (carry != 0)
		product.front() = carry + '0';
	else
		product.erase(0, 1);
	return product;
}

std::string mul(const std::string& a, const std::string& b)
{
	size_t l_a{ a.length() };
	size_t l_b{ b.length() };
	size_t l_min{ l_a < l_b ? l_a : l_b };
	size_t l_max{ l_a > l_b ? l_a : l_b };
	const std::string& y = l_a >= l_b ? a : b; // longer string
	const std::string& z = l_a < l_b ? a : b; // shorter string
	std::string product;
	product.reserve(l_a + l_b);
	std::string temp;
	temp.reserve(l_a + l_b);
	// loop on shorter string which is z
	for (int i_z{ static_cast<int>(l_min) - 1 }, order{}; i_z >= 0; i_z--)
	{
		temp = _mul(y, z[i_z]);
		temp += std::string(order++, '0');
		product = add(product, temp);
	}
	return product;
}

std::string fact(int n)
{
	std::ostringstream str_n;
	str_n << n;
	std::string s{ str_n.str() };
	if (n > 1)
		return mul(s, fact(n - 1));
	else
		return "1";
}