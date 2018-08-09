#include<iostream>
#include<time.h>
#include<ctime>
#include <windows.h>
#include<cstdlib>
#include<string>
using namespace std;

HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE); //Color for text
HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE); //Color for text

bool guidence(long int a[][9]) {

	int check1[10] = { 1,1,2,3,4,5,6,7,8,9 };//check 1 baraye check kardane moraba ha

	int checks[10] = { 1,1,2,3,4,5,6,7,8,9 };//checks araye check kardane soton

	int checkr[10] = { 1,1,2,3,4,5,6,7,8,9 };//checkr baraye check kardane radif

	int p = 0;
	int r = 0;
	int s = 0;

	bool v = false;

	for (int i = 0; i<9; i++) {
		for (int j = 0; j<9; j++) {
			for (int o = 0; o<10; o++) {
				if (o == 0) {
					check1[o] = 10;
					checks[o] = 10;
					checkr[o] = 10;
				}
				else {
					check1[o] = o;
					checks[o] = o;
					checkr[o] = o;
				}
			}



			if (j<3 && i<3)									// morabae 1 ra barresi mikonad
				for (int x = 0; x<3; x++)
					for (int y = 0; y<3; y++)
						if (a[x][y] != 0)
							check1[a[x][y]] = 10;

			if (j<3 && i>2 && i<6)							// morabae 2 ra barresi mikonad
				for (int x = 3; x<6; x++)
					for (int y = 0; y<3; y++)
						if (a[x][y] != 0)
							check1[a[x][y]] = 10;

			if (j<3 && i>5)									// morabae 3 ra barresi mikonad
				for (int x = 6; x<9; x++)
					for (int y = 0; y<3; y++)
						if (a[x][y] != 0)
							check1[a[x][y]] = 10;

			if (j>2 && j<6 && i<3)							// morabae 4 ra barresi mikonad	
				for (int x = 3; x<6; x++)
					for (int y = 3; y<6; y++)
						if (a[x][y] != 0)
							check1[a[x][y]] = 10;

			if (j>2 && j<6 && i>2 && i<6)					// morabae 5 ra barresi mikonad
				for (int x = 3; x<6; x++)
					for (int y = 3; y<6; y++)
						if (a[x][y] != 0)
							check1[a[x][y]] = 10;


			if (j>2 && j<6 && i>5)							// morabae 6 ra barresi mikonad
				for (int x = 6; x<9; x++)
					for (int y = 3; y<6; y++)
						if (a[x][y] != 0)
							check1[a[x][y]] = 10;

			if (j>5 && i<3)									// morabae 7 ra barresi mikonad
				for (int x = 0; x<3; x++)
					for (int y = 6; y<9; y++)
						if (a[x][y] != 0)
							check1[a[x][y]] = 10;

			if (j>5 && i>2 && i<6)							// morabae 8 ra barresi mikonad
				for (int x = 3; x<6; x++)
					for (int y = 6; y<9; y++)
						if (a[x][y] != 0)
							check1[a[x][y]] = 10;

			if (j>5 && i>5)									// morabae 9 ra barresi mikonad
				for (int x = 6; x<9; x++)
					for (int y = 6; y<9; y++)
						if (a[x][y] != 0)
							check1[a[x][y]] = 10;

			for (int x = 0; x<9; x++)						//sotoon ha ra baresi mikonad
				if (a[i][x] != 0)
					checks[a[i][x]] = 10;

			for (int x = 0; x<9; x++)						//radif ha ra baresi mikonad
				if (a[x][j] != 0)
					checkr[a[x][j]] = 10;


			for (int m = 0; m<10; m++) {
				if (check1[m] != 10)
					p++;
				if (checkr[m] != 10)
					r++;
				if (checks[m] != 10)
					s++;
			}


			if (p == 1 && s == 1 && r == 1 && a[i][j] == 0) {
				SetConsoleTextAttribute(hstdout, 0x0c); //Color for text
				cout << "\nguidence:you can add number at the position" << i << " and " << j << endl;
				v = true;
			}
			s = 0;
			r = 0;
			p = 0;
		}
	}

	if (v == false)
		SetConsoleTextAttribute(hstdout, 0x0a); //Color for text
	cout << "no guidence is possible";
	return 1;
}

//checkkol baraye in ast ke begim jadval betore dorost va kamel por shode ya na
bool checkkol(long int a[][9]) {
	int check1[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			for (int y = 0; y < 9; y++) {
				check1[a[y][j]] = 0;
			}

			for (int k = 0; k < 10; k++)
				if (check1[k] != 0)
					return false;
			for (int k = 0; k < 10; k++)
				check1[k] = k;

			for (int x = 0; x < 9; x++) {
				check1[a[i][x]] = 0;
			}
			for (int k = 0; k < 10; k++)
				if (check1[k] != 0)
					return false;

			for (int k = 0; k < 10; k++)
				check1[k] = k;

		}

	}
	//ta inja check kardane soton va radif ha tamam shod hala mirim vase moraba ha
	//dar fore payin baz neshani mikonim
	for (int k = 0; k < 10; k++)
		check1[k] = k;

	for (int i = 0; i <= 6; i = i + 3) {
		for (int j = 0; j <= 6; j = j + 3) {
			for (int x = i; x<i + 3; x++) {
				for (int y = j; y<j + 3; y++) {
					check1[a[x][y]] = 0;
				}
			}
			for (int k = 0; k < 10; k++)
				if (check1[k] != 0)
					return false;

			for (int k = 0; k < 10; k++)
				check1[k] = k;
		}
	}

	return true;
}

int main()
{
	string answer;
	int rr, rs, n, x, y, adad;//rr=remove radif rs=remove soton
	long int a[9][9] = { 5,3,4,6,7,8,9,1,2,
		6, 7, 2, 1, 9, 5, 3, 4, 8 ,
		1, 9, 8, 3, 4, 2, 5, 6, 7 ,
		8, 5, 9, 7, 6, 1, 4, 2, 3 ,
		4, 2, 6, 8, 5, 3, 7, 9, 1 ,
		7, 1, 3, 9, 2, 4, 8, 5, 6 ,
		9, 6, 1, 5, 3, 7, 2, 8, 4 ,
		2, 8, 7, 4, 1, 9, 6, 3, 5 ,
		3, 4, 5, 2, 8, 6, 1, 7, 9 }, k[9][9];
	bool c, komaki = false;
	//hala mikhahim pak konim
	unsigned seed = time(NULL);
	srand(seed);
	SetConsoleTextAttribute(hstdout, 0x0a); //Color for text
	cout << "chand adad mikhahid hazf konid?\n";
	cin >> n;
	for (int i = 0; i<n; i++) {
		rr = rand() % 9;
		rs = rand() % 9;
		if (a[rr][rs] != 0)
			a[rr][rs] = 0;
		else i--;

	}
	for (int i = 0; i<9; i++)
		for (int j = 0; j<9; j++)
			k[i][j] = a[i][j];

	//hala while asli ra minevisim
	while (checkkol(a) == false) {

		system("cls");
		SetConsoleTextAttribute(hstdout, 0x0e); //Color for text
		cout << "    " << "--1--2--3--4--5--6--7--8--9" << endl;
		for (int i = 0; i<9; i++) {
			if (i == 0)
				cout << 'a' << "    ";
			if (i == 1)
				cout << 'b' << "    ";
			if (i == 2)
				cout << 'c' << "    ";
			if (i == 3)
				cout << 'd' << "    ";
			if (i == 4)
				cout << 'e' << "    ";
			if (i == 5)
				cout << 'f' << "    ";
			if (i == 6)
				cout << 'g' << "    ";
			if (i == 7)
				cout << 'h' << "    ";
			if (i == 8)
				cout << 'i' << "    ";
			for (int j = 0; j<9; j++) {


				if (a[i][j] != 0)
					cout << a[i][j] << "| ";
				else cout << " | ";
			}
			cout << endl;
		}


		SetConsoleTextAttribute(hstdout, 0x09); //Color for text
		cout << "\ndo you want guidence?\n";
		cin >> answer;
		SetConsoleTextAttribute(hstdout, 0x0a); //Color for text
		if (answer == "yes")
			c = guidence(a);

		while (komaki == false) {
			SetConsoleTextAttribute(hstdout, 0x0b); //Color for text
			cout << "\nenter the position you want to add number\n";
			cin >> x >> y;

			if (k[x][y] == 0) {
				SetConsoleTextAttribute(hstdout, 0x0d); //Color for text
				cout << "\nwhat number do you want to add?\n";
				cin >> adad;
				a[x][y] = adad;
				komaki = true;

			}

			else cout << "inja nemitavanid adad vared konid";
		}
		komaki = false;
		SetConsoleTextAttribute(hstdout, 0x0b); //Color for text
		cout << "\ndo you want to erase a number?\n";
		cin >> answer;
		SetConsoleTextAttribute(hstdout, 0x0a); //Color for text
		if (answer == "yes")
			while (komaki == false) {
				SetConsoleTextAttribute(hstdout, 0x0f); //Color for text
				cout << "enter the position you want to erase\n";
				cin >> x >> y;
				if (k[x][y] == 0) {
					a[x][y] = 0;
					komaki = true;
				}

				else
					SetConsoleTextAttribute(hstdout, 0x0c); //Color for text

				cout << "shoma ejaze nadarid in adad ra pak konid chon male jadvale asli ast\n";
			}
		komaki = false;

	}
	SetConsoleTextAttribute(hstdout, 0x0c); //Color for text
	cout << "you won\n";
	system("pause");

	return 0;
}
