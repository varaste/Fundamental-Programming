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