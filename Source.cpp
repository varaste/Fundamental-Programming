#include <iostream>
#include <string>
# include <cmath>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <time.h>

using namespace std;

bool win(int a[][10]) {
	bool p=true;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (a[i][j] == 1)
				p = false;
	return p;
}



int main() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);  //Color for text
	int a[10][10] = { 0 }, i, j, t = 1, direction, f = 1, m = 1, n = 1, rfs, x, y; //rs=random for start
	string name;
	bool check = false, wina = false, winpc = false, check1 = false;
	cout << "whats your name?";
	cin >> name;
	// for baraye 4444444444444444444444444444444444444444444444444444444444444444444444444444444
	for (; t <= 1; ) {
		cout << "whats your 4s position?";
		cin >> i >> j;

		if (i < 10 && i >= 0 && j < 10 && j >= 0 && a[i][j] == 0) {
			cout << "whats the navis direction?";
			cout << "for up : 1\nfor right : 2\nfor down : 3\nfor left : 4\n";
			cin >> direction;
			switch (direction) {
			case 1: if (i - 3 >= 0 && a[i - 1][j] == 0 && a[i - 2][j] == 0 && a[i - 3][j] == 0) {
				//gozashtane 1	4
				a[i - 1][j] = a[i - 2][j] = a[i - 3][j] = a[i][j] = 1;

				//gozashtane 2  4
				for (int k = i; k >= i - 3; k--) {
					if (j + 1 <= 9)
						a[k][j + 1] = 2;
					if (j - 1 >= 0)
						a[k][j - 1] = 2;
				} //for gozashtane 2  4

				  //4 ta if gooshe case 1  4
				if (i - 4 >= 0 && j - 1 >= 0)
					a[i - 4][j - 1] = 2;
				if (i - 4 >= 0 && j + 1 <= 9)
					a[i - 4][j + 1] = 2;
				if (i + 1 <= 9 && j - 1 >= 0)
					a[i + 1][j - 1] = 2;
				if (i + 1 <= 9 && j + 1 <= 9)
					a[i + 1][j + 1] = 2;

				if (i - 4 >= 0)
					a[i - 4][j] = 2;
				if (i + 1 <= 9)
					a[i + 1][j] = 2;


				t++;
				break;
			}//if dakhele case 1  4
					else {
						cout << "diraction ghalate dobare vared konid\n" << endl;
						break;

					}//end else   case 1   4


			case 2:if (j + 2 >= 0 && a[i][j + 1] == 0 && a[i][j + 2] == 0 && a[i][j + 3] == 0) {
				//gozashtane 1 case 2  4
				a[i][j + 1] = a[i][j + 2] = a[i][j + 3] = a[i][j] = 1;

				//gozashtane 2  case 2  4
				for (int k = j; k <= j + 3; k++) {
					if (i + 1 <= 9)
						a[i + 1][k] = 2;
					if (i - 1 >= 0)
						a[i - 1][k] = 2;

				} //for gozashtane 2   case 2  4

				if (j - 1 >= 0)
					a[i][j - 1] = 2;
				if (j + 4 <= 9)
					a[i][j + 4] = 2;
				//4 ta if gooshe  case 2  4
				if (i - 1 >= 0 && j - 1 >= 0)
					a[i - 1][j - 1] = 2;
				if (i - 1 >= 0 && j + 3 <= 9)
					a[i - 1][j + 4] = 2;
				if (i + 1 <= 9 && j - 1 >= 0)
					a[i + 1][j - 1] = 2;
				if (i + 1 <= 9 && j + 3 <= 9)
					a[i + 1][j + 4] = 2;
				t++;
				break;
			}//if dakhele case 2-4
				   else {
					   cout << "diraction ghalate dobare vared konid\n" << endl;
					   break;

				   }// end else case 2  4

			 //end case 2  4

			case 3:if (i + 3 >= 0 && a[i + 1][j] == 0 && a[i + 2][j] == 0 && a[i + 3][j] == 0) {
				//gozashtane 1
				a[i + 1][j] = a[i + 2][j] = a[i + 3][j] = a[i][j] = 1;

				//gozashtane 2
				for (int k = i; k <= i + 3; k++) {
					if (j + 1 <= 9)
						a[k][j + 1] = 2;
					if (j - 1 >= 0)
						a[k][j - 1] = 2;

				} //for
				if (i + 4 <= 9)
					a[i + 4][j] = 2;
				if (i - 1 >= 0)
					a[i - 1][j] = 2;
				//4 ta if gooshe
				if (i - 1 >= 0 && j - 1 >= 0)
					a[i - 1][j - 1] = 2;
				if (i - 1 >= 0 && j + 1 <= 9)
					a[i - 1][j + 1] = 2;
				if (i + 4 <= 9 && j - 1 >= 0)
					a[i + 4][j - 1] = 2;
				if (i + 4 <= 9 && j + 1 <= 9)
					a[i + 4][j + 1] = 2;
				t++;
				break;
			}//if dakhele case
				   else {
					   cout << "diraction ghalate dobare vared konid\n" << endl;
					   break;

				   }
			case 4:if (j - 3 >= 0 && a[i][j - 1] == 0 && a[i][j - 2] == 0 && a[i][j - 1] == 0) {
				/*gozashtane 1*/	a[i][j - 3] = a[i][j - 2] = a[i][j - 1] = a[i][j] = 1;

				//gozashtane 2
				for (int k = j; k >= j - 3; k--) {
					if (i + 1 <= 9)
						a[i + 1][k] = 2;
					if (i - 1 >= 0)
						a[i - 1][k] = 2;

				} //for
				if (j - 4 >= 0)
					a[i][j - 4] = 2;
				if (j + 1 <= 9)
					a[i][j + 1] = 2;
				//4 ta if gooshe
				if (i - 1 >= 0 && j - 4 >= 0)
					a[i - 1][j - 4] = 2;
				if (i - 1 >= 0 && j + 1 <= 9)
					a[i - 1][j + 1] = 2;
				if (i + 1 <= 9 && j - 4 >= 0)
					a[i + 1][j - 4] = 2;
				if (i + 1 <= 9 && j + 1 <= 9)
					a[i + 1][j + 1] = 2;
				t++;
				break;
			}//if dakhele case
				   else {
					   cout << "diraction ghalate dobare vared konid\n" << endl;
					   break;

				   }
			}// switch


		}
		else {
			cout << "ghalat dadi";
		}
		for (int k = 0; k < 10; k++) {
			for (int o = 0; o < 10; o++)
				cout << a[k][o];
			cout << endl;
		}
	}//// for baraye 4



	// for baraye 3 3333333333333333333333333333333333333333333333333333333333333333333333
	for (; f <= 2; ) {
		cout << "whats your 3s position?\n";
		cin >> i >> j;

		if (i < 10 && i >= 0 && j < 10 && j >= 0 && a[i][j] == 0) {
			cout << "whats the navis direction?\n";
			cout << "for up : 1\nfor right : 2\nfor down : 3\nfor left : 4\n";
			cin >> direction;
			switch (direction) {
			case 1: if (i - 2 >= 0 && a[i - 1][j] == 0 && a[i - 2][j] == 0) {
				//gozashtane 1
				a[i - 1][j] = a[i - 2][j] = a[i][j] = 1;

				//gozashtane 2
				for (int k = i; k >= i - 2; k--) {
					if (j + 1 <= 9)
						a[k][j + 1] = 2;
					if (j - 1 >= 0)
						a[k][j - 1] = 2;

				} //for gozashtane 2
				if (i - 3 >= 0)
					a[i - 3][j] = 2;
				if (i + 1 <= 9)
					a[i + 1][j] = 2;
				//4 ta if gooshe
				if (i - 3 >= 0 && j - 1 >= 0)
					a[i - 3][j - 1] = 2;
				if (i - 3 >= 0 && j + 1 <= 9)
					a[i - 3][j + 1] = 2;
				if (i + 1 <= 9 && j - 1 >= 0)
					a[i + 1][j - 1] = 2;
				if (i + 1 <= 9 && j + 1 <= 9)
					a[i + 1][j + 1] = 2;
				f++;
				break;
			}//if dakhele case
					else {
						cout << "diraction ghalate dobare vared konid\n" << endl;
						break;

					}//end else case 1

			case 2:if (j + 2 >= 0 && a[i][j + 1] == 0 && a[i][j + 2] == 0) {
				/*gozashtane 1*/
				a[i][j + 1] = a[i][j + 2] = a[i][j] = 1;

				//gozashtane 2
				for (int k = j; k <= j + 2; k++) {
					if (i + 1 <= 9)
						a[i + 1][k] = 2;
					if (i - 1 >= 0)
						a[i - 1][k] = 2;

				} //for

				if (j - 1 >= 0)
					a[i][j - 1] = 2;
				if (j + 3 <= 9)
					a[i][j + 3] = 2;
				//4 ta if gooshe
				if (i - 1 >= 0 && j - 1 >= 0)
					a[i - 1][j - 1] = 2;
				if (i - 1 >= 0 && j + 3 <= 9)
					a[i - 1][j + 3] = 2;
				if (i + 1 <= 9 && j - 1 >= 0)
					a[i + 1][j - 1] = 2;
				if (i + 1 <= 9 && j + 3 <= 9)
					a[i + 1][j + 3] = 2;
				f++;
				break;
			}//if dakhele case
				   else {
					   cout << "diraction ghalate dobare vared konid\n" << endl;
					   break;

				   }
			case 3:if (i + 2 >= 0 && a[i + 1][j] == 0 && a[i + 2][j] == 0) {
				/*gozashtane 1*/	a[i + 1][j] = a[i + 2][j] = a[i][j] = 1;

				//gozashtane 2
				for (int k = i; k <= i + 2; k++) {
					if (j + 1 <= 9)
						a[k][j + 1] = 2;
					if (j - 1 >= 0)
						a[k][j - 1] = 2;

				} //for
				if (i + 3 <= 9)
					a[i + 3][j] = 2;
				if (i - 1 >= 0)
					a[i - 1][j] = 2;
				//4 ta if gooshe
				if (i - 1 >= 0 && j - 1 >= 0)
					a[i - 1][j - 1] = 2;
				if (i - 1 >= 0 && j + 1 <= 9)
					a[i - 1][j + 1] = 2;
				if (i + 3 <= 9 && j - 1 >= 0)
					a[i + 3][j - 1] = 2;
				if (i + 3 <= 9 && j + 1 <= 9)
					a[i + 3][j + 1] = 2;
				f++;
				break;
			}//if dakhele case
				   else {
					   cout << "diraction ghalate dobare vared konid\n" << endl;
					   break;

				   }
			case 4:if (j - 2 >= 0 && a[i][j - 2] == 0 && a[i][j - 1] == 0) {
				/*gozashtane 1*/	a[i][j - 2] = a[i][j - 1] = a[i][j] = 1;

				//gozashtane 2
				for (int k = j; k >= j - 2; k--) {
					if (i + 1 <= 9)
						a[i + 1][k] = 2;
					if (i - 1 >= 0)
						a[i - 1][k] = 2;

				} //for
				if (j - 3 >= 0)
					a[i][j - 3] = 2;
				if (j + 1 <= 9)
					a[i][j + 1] = 2;
				//4 ta if gooshe
				if (i - 1 >= 0 && j - 3 >= 0)
					a[i - 1][j - 3] = 2;
				if (i - 1 >= 0 && j + 1 <= 9)
					a[i - 1][j + 1] = 2;
				if (i + 1 <= 9 && j - 3 >= 0)
					a[i + 1][j - 3] = 2;
				if (i + 1 <= 9 && j + 1 <= 9)
					a[i + 1][j + 1] = 2;
				f++;
				break;
			}//if dakhele case
				   else {
					   cout << "diraction ghalate dobare vared konid\n" << endl;
					   break;

				   }
			}// switch
		}//if1
		else {
			cout << "mahal ghalat dadi\n";

		}//elce if 1
		for (int k = 0; k < 10; k++) {
			for (int o = 0; o < 10; o++)
				cout << a[k][o];
			cout << endl;
		}
	}//for 3

	//for bara 2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
	for (; m <= 3; ) {
		cout << "whats your 2s position?\n";
		cin >> i >> j;

		if (i < 10 && i >= 0 && j < 10 && j >= 0 && a[i][j] == 0) {
			cout << "whats the navis direction?\n";
			cout << "for up : 1\nfor right : 2\nfor down : 3\nfor left : 4\n";
			cin >> direction;

			switch (direction) {
			case 1: if (i - 2 >= 0 && a[i - 2][j] == 0) {
				//gozashtane 1
				a[i - 2][j] = a[i][j] = a[i - 1][j] = 1;

				//gozashtane 2
				for (int k = i; k >= i - 1; k--) {
					if (j + 1 <= 9)
						a[k][j + 1] = 2;
					if (j - 1 >= 0)
						a[k][j - 1] = 2;

				} //for gozashtane 2
				if (i - 2 >= 0)
					a[i - 2][j] = 2;
				if (i + 1 <= 9)
					a[i + 1][j] = 2;
				//4 ta if gooshe
				if (i - 2 >= 0 && j - 1 >= 0)
					a[i - 2][j - 1] = 2;
				if (i - 2 >= 0 && j + 1 <= 9)
					a[i - 2][j + 1] = 2;
				if (i + 1 <= 9 && j - 1 >= 0)
					a[i + 1][j - 1] = 2;
				if (i + 1 <= 9 && j + 1 <= 9)
					a[i + 1][j + 1] = 2;
				m++;
				break;
			}//if dakhele case
					else {
						cout << "diraction 2 ro ghalate dobare vared konid\n" << endl;
						break;

					}//end else case 1

			case 2:if (j + 2 >= 0 && a[i][j + 2] == 0 && a[i][j + 1] == 0) {
				//gozashtane 1
				a[i][j + 1] = a[i][j] = a[i][j + 2] = 1;

				//gozashtane 2
				for (int k = j; k <= j + 1; k++) {
					if (i + 1 <= 9)
						a[i + 1][k] = 2;
					if (i - 1 >= 0)
						a[i - 1][k] = 2;

				} //for

				if (j - 1 >= 0)
					a[i][j - 1] = 2;
				if (j + 2 <= 9)
					a[i][j + 2] = 2;
				//4 ta if gooshe
				if (i - 1 >= 0 && j - 1 >= 0)
					a[i - 1][j - 1] = 2;
				if (i - 1 >= 0 && j + 2 <= 9)
					a[i - 1][j + 2] = 2;
				if (i + 1 <= 9 && j - 1 >= 0)
					a[i + 1][j - 1] = 2;
				if (i + 1 <= 9 && j + 2 <= 9)
					a[i + 1][j + 2] = 2;
				m++;
				break;
			}//if dakhele case
				   else {
					   cout << "diraction 2 ro ghalate dobare vared konid\n" << endl;
					   break;

				   }

			case 3:if (i + 2 >= 0 && a[i + 1][j] == 0 && a[i + 2][j] == 0) {
				//gozashtane 1
				a[i + 1][j] = a[i][j] = a[i + 2][j] = 1;

				//gozashtane 2
				for (int k = i; k <= i + 1; k++) {
					if (j + 1 <= 9)
						a[k][j + 1] = 2;
					if (j - 1 >= 0)
						a[k][j - 1] = 2;

				} //for
				if (i + 2 <= 9)
					a[i + 2][j] = 2;
				if (i - 1 >= 0)
					a[i - 1][j] = 2;
				//4 ta if gooshe
				if (i - 1 >= 0 && j - 1 >= 0)
					a[i - 1][j - 1] = 2;
				if (i - 1 >= 0 && j + 1 <= 9)
					a[i - 1][j + 1] = 2;
				if (i + 2 <= 9 && j - 1 >= 0)
					a[i + 2][j - 1] = 2;
				if (i + 2 <= 9 && j + 1 <= 9)
					a[i + 2][j + 1] = 2;
				m++;
				break;
			}//if dakhele case
				   else {
					   cout << "diraction 2 ro ghalate dobare vared konid\n" << endl;
					   break;

				   }
			case 4:if (j - 2 >= 0 && a[i][j - 1] == 0 && a[i][j - 2] == 0) {
				//gozashtane 1
				a[i][j - 1] = a[i][j] = a[i][j - 2] = 1;

				//gozashtane 2
				for (int k = j; k >= j - 1; k--) {
					if (i + 1 <= 9)
						a[i + 1][k] = 2;
					if (i - 1 >= 0)
						a[i - 1][k] = 2;

				} //for
				if (j - 2 >= 0)
					a[i][j - 2] = 2;
				if (j + 1 <= 9)
					a[i][j + 1] = 2;
				//4 ta if gooshe
				if (i - 1 >= 0 && j - 2 >= 0)
					a[i - 1][j - 2] = 2;
				if (i - 1 >= 0 && j + 1 <= 9)
					a[i - 1][j + 1] = 2;
				if (i + 1 <= 9 && j - 2 >= 0)
					a[i + 1][j - 2] = 2;
				if (i + 1 <= 9 && j + 1 <= 9)
					a[i + 1][j + 1] = 2;
				m++;
				break;
			}//if dakhele case
				   else {
					   cout << "diraction 2ro ghalate dobare vared konid\n" << endl;
					   break;

				   }
			}// switch
		}//if1
		else {
			cout << "mahal ghalat dadi\n";

		}//elce if 1
		for (int k = 0; k < 10; k++) {
			for (int o = 0; o < 10; o++)
				cout << a[k][o];
			cout << endl;
		}

	}//for 2
	//??? ????? ???? ??
	//???? ??? ????????
	//gereftane karbar tamam shod
	unsigned seed = time(NULL);
	srand(seed);
	rfs = rand() % 2 + 1;
	//random


	int pc[10][10] = { 0 };
	pc[0][2] = pc[0][4] = pc[0][5] = pc[0][7] = pc[3][1] = pc[3][2] = pc[3][3] = pc[3][4] = pc[2][9] = pc[3][9] =
		pc[5][7] = pc[6][7] = pc[7][0] = pc[7][2] = pc[8][2] = pc[9][2] = pc[9][5] = pc[9][6] = pc[9][7] = pc[8][9] = 1;




	if (rfs == 1) {
		while (wina == 0 && winpc == 0) {
			cout << "its" << name << "`s turn so please fire and give me a position\n";

			//while payin baraye shelike karbar
			while (check1 == false) {
				cin >> x >> y;

				if (a[x][y] == 8 || a[x][y] == 9 || a[x][y] == 7) {
					cout << "inja nemitavanid shelik konid va mokhtasate jadid baraye shelik vared konid";
					continue;
				}

				else {
					if (pc[x][y] == 1) {
						pc[x][y] = 9;
						if (x + 1 <= 9 && y + 1 <= 9)
							pc[x + 1][y + 1] = 8;
						if (x + 1 <= 9 && y - 1 >= 0)
							pc[x + 1][y - 1] = 8;
						if (x - 1 >= 0 && y + 1 <= 9)
							pc[x - 1][y + 1] = 8;
						if (x - 1 >= 0 && y - 1 >= 0)
							pc[x - 1][y - 1] = 8;
						continue;
					}

					if (pc[x][y] == 0 || pc[x][y] == 2) {
						pc[x][y] = 7;
						check1 = true;
						continue;


					}


				}// else
			}//while voroudi karbar

			wina = win(a);
			if (wina == true)
				continue;

			check1 = false;

			//hala pc
			while (check1 == false) {
				x = rand() % 10 + 1;
				y = rand() % 10 + 1;

				if (a[x][y] == 8 || a[x][y] == 9 || a[x][y] == 7) {
					cout << "inja nemitavanid shelik konid va mokhtasate jadid baraye shelik vared konid";
					continue;
				}

				else {
					if (pc[x][y] == 1) {
						pc[x][y] = 9;
						if (x + 1 <= 9 && y + 1 <= 9)
							pc[x + 1][y + 1] = 8;
						if (x + 1 <= 9 && y - 1 >= 0)
							pc[x + 1][y - 1] = 8;
						if (x - 1 >= 0 && y + 1 <= 9)
							pc[x - 1][y + 1] = 8;
						if (x - 1 >= 0 && y - 1 >= 0)
							pc[x - 1][y - 1] = 8;
						continue;
					}

					if (pc[x][y] == 0 || pc[x][y] == 2) {
						pc[x][y] = 7;
						check1 = true;
						continue;


					}


				}// else
			}//while pc
			check1 = false;
			winpc = win(pc);
			if (winpc == true)
				continue;
			

			
		}//while avvali
	}//if rfs==1


	if (rfs == 2){
		while (wina == 0 && winpc == 0) {
			//hala pc
			while (check1 == false) {
				x = rand() % 10 + 1;
				y = rand() % 10 + 1;

				if (a[x][y] == 8 || a[x][y] == 9 || a[x][y] == 7) {
					cout << "inja nemitavanid shelik konid va mokhtasate jadid baraye shelik vared konid";
					continue;
				}

				else {
					if (pc[x][y] == 1) {
						pc[x][y] = 9;
						if (x + 1 <= 9 && y + 1 <= 9)
							pc[x + 1][y + 1] = 8;
						if (x + 1 <= 9 && y - 1 >= 0)
							pc[x + 1][y - 1] = 8;
						if (x - 1 >= 0 && y + 1 <= 9)
							pc[x - 1][y + 1] = 8;
						if (x - 1 >= 0 && y - 1 >= 0)
							pc[x - 1][y - 1] = 8;
						continue;
					}

					if (pc[x][y] == 0 || pc[x][y] == 2) {
						pc[x][y] = 7;
						check1 = true;
						continue;


					}


				}// else
			}//while pc



			cout << "its" << name << "`s turn so please fire and give me a position\n";
			//while payin baraye shelike karbar
			while (check1 == false) {
				cin >> x >> y;

				if (a[x][y] == 8 || a[x][y] == 9 || a[x][y] == 7) {
					cout << "inja nemitavanid shelik konid va mokhtasate jadid baraye shelik vared konid";
					continue;
				}

				else {
					if (pc[x][y] == 1) {
						pc[x][y] = 9;
						if (x + 1 <= 9 && y + 1 <= 9)
							pc[x + 1][y + 1] = 8;
						if (x + 1 <= 9 && y - 1 >= 0)
							pc[x + 1][y - 1] = 8;
						if (x - 1 >= 0 && y + 1 <= 9)
							pc[x - 1][y + 1] = 8;
						if (x - 1 >= 0 && y - 1 >= 0)
							pc[x - 1][y - 1] = 8;
						continue;
					}

					if (pc[x][y] == 0 || pc[x][y] == 2) {
						pc[x][y] = 7;
						check1 = true;
						continue;


					}


				}// else
			}//while voroudi karbar
		}// while avvali
}//if rfs==2

		system("pause");
		return 0;
	}//main

