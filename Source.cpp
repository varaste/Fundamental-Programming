#include <iostream>
#include <string>
#include<cstring>

using namespace std;

int main(){

	const int n = 7;

	int beg = 0;
	int end = n - 0;
	int mid;
	int x[n];
	int i;
	int item;

	cout<<" enter 7 element:\n";

	for (i = 0; i < n; i++) {
		cin >> x[i];
	}
	cout << "enter item to serch";
	cin >> item;

	mid = (beg + end) / 2;

	while (item != x[mid] && beg <= end) {

		if (item > x[mid]) {

			beg = mid + 1;
		}
		else {

			end = beg - 1;
		}

		mid = (beg + end) / 2;

		}
	if (beg > end) {

		cout << "vojod nadarad\n";
	}
	else {

		cout << mid;
	}

	system("pause");
	return 0;
}