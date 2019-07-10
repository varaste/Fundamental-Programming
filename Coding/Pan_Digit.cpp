#include<iostream>
#include<sstream>


bool is_prime(long long num);
int pandigit(long long x);


int main()
{
	std::cout << "Started..." << std::endl;
	long long num{ 9876543201 };
	int index{};
	while (num > 0)
	{
		index = pandigit(num);
		if (index == -1)
		{
			std::cout << num << std::endl;
			if (is_prime(num))
			{
				std::cout << num << std::endl;
				break;
			}
			else
				num -= 2;
		}
		else
			num = index > 0 ? num - num % (index * 10) : num;
		if (num % 2 == 0)
			num -= 1;
		else
			num -= 2;
		

	}
	
	return 0;
}

bool is_prime(long long num)
{
	long long root{ static_cast<long long>(std::sqrt(num)) + 1 };
	for (long long i{ 3 }; i <= root; i += 2)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

int pandigit(long long x)
{
	std::ostringstream os{};
	os << x;
	std::string x_s{ os.str() };

	int i_max{ static_cast<int>(x_s.size()) - 1 };
	int index{ -1 };

	for (int i{}; i < i_max; i++)
		for (int j{ i + 1 }; j <= i_max; j++)
			if (x_s[j] == x_s[i])
				if (i_max - j > index)
					index = i_max - j;
	return index;
}