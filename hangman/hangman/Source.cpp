#include<iostream>
#include<conio.h>

using namespace std;
int main()
{
	char word[128];
	int i = 0;

	cout << "please entere your word\n";
	word[0] = _getch();
	

	while (((int)word[i] < 97 || (int)word[i]>122) && (int)word[i] != 13)
	{
		cout << "invalid character has been entered\nplease entere an other charactere from a-z\n";
		word[i] = _getch();
	}

	cout << word[0];


	while (i<128 && (int)word[i]!=13)      //input
	{
		i++;
		word[i] = _getch();
		cout << word[i];


		while (((int)word[i] < 97 || (int)word[i]>122) && (int)word[i]!=13)
		{
			cout << "invalid character has been entered\nplease entere an other charactere from a-z\n";
			word[i] = _getch();
			
		}
										

	}

												//getting input end
	


	system("pause");

	return 0;
}