#include <iostream>
using namespace std;

void main()
{
	const int arraySize = 10;
	int total = 0, i;
	int a[arraySize];
	for (i = 0; i < arraySize; i++)
	{
		cout << "Enter number " << i << " : ";
		cin >> a[i];
	}
	for (i = 0; i < arraySize; i++)
		total += a[i];
	cout << "Total of array element values is " << total << endl;
	system("pause");


}