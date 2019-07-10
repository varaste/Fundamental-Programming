#include<iostream>
#include<cmath>
#include<vector>

bool is_prime(size_t num);
int search(const std::vector<size_t>& v, size_t num, size_t start, size_t end);
bool do_permute(size_t a, size_t b, size_t c);
void seperate_digits(int* d, size_t num);
void sort(int* d, size_t num);



int main()
{
	std::vector<unsigned int> primes;
	primes.reserve(2000);

	for (size_t i{ 1001 }; i < 10000; i += 2)
		if (is_prime(i))
			primes.push_back(i);
	std::cout << primes.size() << std::endl;

	std::vector<std::vector<size_t>> primes_diff;
	size_t index_max{ primes.size() - 1 };
	for (size_t index1{}; index1 < index_max - 1; index1++)
	{
		for (size_t index2{ index1 + 1 }; index2 < index_max; index2++)
		{
			size_t val{ 2 * primes[index2] - primes[index1] };
			int index3{ search(primes, val, index2 + 1, index_max) };
			if (index3 != -1)
				primes_diff.push_back(std::vector<size_t>{index1, index2,
					static_cast<size_t>(index3)});
		}
	}
	std::cout << primes_diff.size() << std::endl;

	for (auto v : primes_diff)
		if (do_permute(primes[v[0]], primes[v[1]], primes[v[2]]))
			std::cout << primes[v[0]] << ' ' << primes[v[1]] << ' ' << primes[v[2]] <<
			std::endl;

	return 0;
}


bool is_prime(size_t num)
{
	size_t root{ static_cast<size_t>(std::sqrt(num)) + 1 };
	for (size_t i{ 3 }; i <= root; i += 2)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

int search(const std::vector<size_t>& v, size_t num, size_t start, size_t end)
{
	size_t mid{ (start + end) / 2 };
	if (v[mid] == num)
		return mid;
	if (start >= end)
		return -1;
	else if (num < v[mid])
		return search(v, num, start, mid - 1);
	else
		return search(v, num, mid + 1, end);
}

bool do_permute(size_t a, size_t b, size_t c)
{
	int d1[4]{};
	int d2[4]{};
	int d3[4]{};
	seperate_digits(d1, a);
	seperate_digits(d2, b);
	seperate_digits(d3, c);
	sort(d1, 4);
	sort(d2, 4);
	sort(d3, 4);
	for (size_t i{}; i < 4; i++)
	{
		if (d1[i] != d2[i] || d2[i] != d3[i])
			return false;
	}
	return true;
}

void seperate_digits(int* d, size_t num)
{
	size_t i{};
	while (num > 0)
	{
		d[i++] = num % 10;
		num /= 10;
	}
}

void sort(int* d, size_t num)
{
	bool swapped{ false };
	for (size_t x{}; x < num - 1; x++)
	{
		swapped = false;
		for (size_t i{ 1 }; i < num; i++)
		{
			if (d[i - 1] > d[i])
			{
				int t{ d[i - 1] };
				d[i - 1] = d[i];
				d[i] = t;
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}