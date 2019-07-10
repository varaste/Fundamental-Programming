#include<iostream>
#include<sstream>

std::string reverse(const std::string& str);
unsigned int to_integer(const std::string& str);
std::string to_string(unsigned int x);

int main()
{
	unsigned int hamkhan{};
	for (size_t i{ 999 }; i > 99; i--)
		for (size_t j{ 999 }; j > i; j--)
		{
			if (i * j < hamkhan)
				break;
			unsigned int x = i * j;
			std::string str_x{ to_string(x) };
			if (reverse(str_x) == str_x)
			{				
				hamkhan = to_integer(str_x);
			}

		}
	std::cout << hamkhan << std::endl;
	return 0;
}

std::string reverse(const std::string& str)
{
	std::string out{str};
	size_t len{ str.size() - 1};
	size_t cnt{};
	while (cnt <= len)
	{
		out[cnt] = str[len - cnt];
		cnt += 1;
	}
	return out;
}

unsigned int to_integer(const std::string& str)
{
	unsigned int x{};
	std::istringstream is{str};
	is >> x;
	return x;
}

std::string to_string(unsigned int x)
{
	std::ostringstream os{};
	os << x;
	return os.str();
}

