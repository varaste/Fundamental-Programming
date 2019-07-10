#include<iostream>
#include<sstream>
#include<cmath>



int main()
{
	size_t p{ 1001 };
	size_t i_max{ p / 2 };

	size_t p_max{};
	size_t cnt_max{};

	size_t cnt{};

	while (--p <= 1000)
	{
		cnt = 0;
		for (size_t a{ 1 }; a < i_max; a++)
			for (size_t b{ a }; b < i_max; b++)
			{
				int c{ static_cast<int>(std::sqrtf(static_cast<float>(a*a + b*b))) };
				if (a*a + b*b == c*c) // right triangle
					if (a + b + c == p)
						cnt += 1;

			}
		if (cnt > cnt_max)
		{
			cnt_max = cnt;
			p_max = p;
		}
	}
	std::cout << p_max << std::endl;
	return 0;
}
