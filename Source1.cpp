#include <iostream>

using namespace std;

int maximum(int, int, int);		//function prototype

int main() {
	int a;
	int b;
	int c;

	cout << "enter 3 integers";
	cin >> a >> b >> c;
	 
	cout << "maximum is" << maximum(a, b, c) << \n;

	return 0;

}

int maximum(int x, int y, int z) {

	int max = x;

	if (y > max)
		max = y

		if (z > max)
			max = z;

	return max;
}