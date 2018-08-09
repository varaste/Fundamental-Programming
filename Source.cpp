#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void main()
{
	int a[10][10], i, j;
	for (i = 0; i<10; i++)
		for (j = 0; j<10; j++)

			a[i][j] = (i + 1)*(j + 1);
	for (i = 0; i<10; i++) {
		for (j = 0; j<10; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}
	system("pause");

}