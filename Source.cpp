#include <iostream>
using namespace std;
void main()
{
	const int arraySize = 10;
	int s[arraySize];
	for (int i = 0; i < arraySize; i++)
		s[i] = 2 + 2 * i;
	cout << "Element Value" << endl;
	for (int j = 0; j < arraySize; j++)
		cout << j << "\t " << s[j] << endl;
	system("pause");

}