#include<iostream>
#include<conio.h> 
#include<math.h>
using namespace std;

#define MR 40
#define MC 80

void init1(char w[][MC], char a, char d)
{

	for (int ri = 0; ri < MR; ri++)
	{
		for (int ci = 0; ci < MC; ci++)
		{
			if (ri == 0 || ri == 79 || ci == 0 || ci == 79)
			{
				w[ri][ci] = a;
			}
			else
				w[ri][ci] = d;
		}
	}
}
void init2(char w[][MC], char a, char d)
{

	for (int ri = 0; ri < MR; ri++)
	{
		for (int ci = 0; ci < MC; ci++)
		{
			if (ri == 0 || ri == MR - 1 || ci == 0 || ci == MC - 1 || ci == MC / 2)
			{
				w[ri][ci] = a;
			}
			else
				w[ri][ci] = d;
		}
	}
}
void init10(char w[][MC], char a, char d)
{

	for (int ri = 0; ri < MR; ri++)
	{
		for (int ci = 0; ci < MC; ci++)
		{
			if (ri == 0 || ri == MR - 1 || ci == 0 || ci == MC - 1 || ci == MC / 4 || ci == MC * 3 / 4 || ri == ci || ri + ci == MC || ri + ci == MR || ri - ci == MC - MR - 2 * ci || ri + ci == MC - 7 || ri == ci - 7 || ri + ci == MC - MR + 2 * ri || ri + ci == MC - MR + 2 * ri - 7)
			{
				w[ri][ci] = a;
			}
			else
				w[ri][ci] = d;
		}
	}
}
void init3(char w[][MC], char a, char d)
{

	for (int ri = 0; ri < MR; ri++)
	{
		for (int ci = 0; ci < MC; ci++)
		{
			if (ci == MC / 2 || ri == MR / 2)
			{
				w[ri][ci] = a;
			}
			else
				w[ri][ci] = d;
		}
	}
}
void init4(char w[][MC], char a, char d)
{

	for (int ri = 0; ri < MR; ri++)
	{
		for (int ci = 0; ci < MC; ci++)
		{
			if (ci == MC / 2 || ri == MR - 1 || ri == 0 || ri == MR / 2)
			{
				w[ri][ci] = a;
			}
			else
				w[ri][ci] = d;

		}
	}
}
void init5(char w[][MC], char a, char d)
{

	for (int ri = 0; ri < MR; ri++)
	{
		for (int ci = 0; ci < MC; ci++)
		{
			if (ci % 4 == 0)
			{
				w[ri][ci] = a;
			}
			else
				w[ri][ci] = d;

		}
	}
}
void init6(char w[][MC], char a, char d)
{

	for (int ri = 0; ri < MR; ri++)
	{
		for (int ci = 0; ci < MC; ci++)
		{
			if (ci % 4 == 0 || ri % 4 == 0)
			{
				w[ri][ci] = a;
			}
			else
				w[ri][ci] = d;

		}
	}
}
void init7(char w[][MC], char a, char d)
{
	system(" Color 0D");
	for (int ri = 0; ri < MR; ri++)
	{
		for (int ci = 0; ci < MC; ci++)
		{
			if (ci % 10 == 0 || ri % 10 == 0)
			{
				w[ri][ci] = a;
			}
			else
				w[ri][ci] = d;

		}
	}
}
void init8(char w[][MC], char a, char d)
{
	system(" Color 0F");

	for (int ri = 0; ri < MR; ri++)
	{
		for (int ci = 0; ci < MC; ci++)
		{
			if (ci % 10 == 0 || ri % 8 == 0)
			{


				w[ri][ci] = a;
			}
			else
				w[ri][ci] = d;

		}
	}
}
void init9(char w[][MC], char a, char d)
{
	system(" Color 0B");
	for (int ri = 0; ri < MR; ri++)
	{
		for (int ci = 0; ci < MC; ci++)
		{
			if (ci % 4 == 0 || ri % 10 == 0)
			{
				w[ri][ci] = a;
			}
			else if (ci == MC / 2 || ci == MC / 4 || ci == MC * 3 / 4)
			{
				w[ri][ci] = a;
			}
			else
				w[ri][ci] = d;

		}
	}
}

void menu()
{
	cout << "PATTERN 1" << endl
		<< "PATTERN 2" << endl
		<< "PATTERN 3" << endl
		<< "PATTERN 4" << endl
		<< "PATTERN 5" << endl;
}
void display(char w[][MC])
{
	system("cls");
	for (int ri = 0; ri < MR; ri++)
	{
		for (int ci = 0; ci < MC; ci++)
		{
			cout << w[ri][ci];
		}
		cout << endl;

	}
}
int surroundinga(char w[][MC], char a, int r, int c)
{
	int count = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int ci = -1; ci <= 1; ci++)
		{


			if (w[r + i][c + ci] == a)
			{
				if (i == 0 && ci == 0)
				{
					continue;
				}

				count++;
			}
		}
	}
	return count;
}
int surrounding(char w[][MC], char a, int r, int c)
{
	int count = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int ci = -1; ci <= 1; ci++)
		{
			if (r + i >= MR || r + i < 0 || c + ci >= MC || c + ci < 0)
			{
				continue;
			}

			else if (w[r + i][c + ci] == a)
			{
				if (i == 0 && ci == 0)
				{
					continue;
				}

				count++;
			}
		}
	}
	return count;
}
void modWa(char w[][MC], char a, char d)
{
	char mw[MR][MC];
	for (int ri = 0; ri < MR; ri++)
	{
		for (int ci = 0; ci < MC; ci++)
		{
			int count = surroundinga(w, a, ri, ci);
			if (count == 3)
			{
				mw[ri][ci] = a;
			}
			else if (count < 2)
			{
				mw[ri][ci] = d;
			}
			else if (count > 3)
			{
				mw[ri][ci] = d;
			}
			else
			{
				mw[ri][ci] = w[ri][ci];
			}
		}
	}


	for (int ri = 0; ri < MR; ri++)
	{
		for (int ci = 0; ci < MC; ci++)
		{
			w[ri][ci] = mw[ri][ci];
		}
	}
}
void modW(char w[][MC], char a, char d)
{
	char mw[MR][MC];
	for (int ri = 0; ri < MR; ri++)
	{
		for (int ci = 0; ci < MC; ci++)
		{
			int count = surrounding(w, a, ri, ci);
			if (count == 3)
			{
				mw[ri][ci] = a;
			}
			else if (count < 2)
			{
				mw[ri][ci] = d;
			}
			else if (count > 3)
			{
				mw[ri][ci] = d;
			}
			else
			{
				mw[ri][ci] = w[ri][ci];
			}
		}
	}


	for (int ri = 0; ri < MR; ri++)
	{
		for (int ci = 0; ci < MC; ci++)
		{
			w[ri][ci] = mw[ri][ci];
		}
	}
}
int maina()
{
	char w[MR][MC], mw[MR][MC], ac = -37, dc = ' ';
	while (true)
	{
		cout << "**********************************************" << endl;
		menu();
		cout << "**********************************************" << endl;
		int choice;
		cout << " enter choice ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init1(w, ac, dc);
			break;
		case 2:
			init2(w, ac, dc);
			break;

		case 3:
			init3(w, ac, dc);
			break;

		case 4:
			init4(w, ac, dc);
			break;

		case 5:
			init5(w, ac, dc);
			break;

		case 6:
			init6(w, ac, dc);
			break;
		case 7:
			init7(w, ac, dc);
			break;
		case 8:
			init8(w, ac, dc);
			break;
		case 9:
			init9(w, ac, dc);
			break;
		case 10:
			init10(w, ac, dc);
			break;
		default:
			break;

		}


		_getch();
		while (true)
		{
			modW(w, ac, dc);
			display(w);
		}
	}
	return 0;
}
int mainb()
{
	srand(time(0));
	char w[MR][MC], mw[MR][MC], ac = -37, dc = ' '; int n = rand() % 20;

	while (true)
	{
		if (n < 10)
		{
			init2(w, ac, dc);
		}
		while (n < 10)
		{
			modW(w, ac, dc);
			display(w);
			n++;
			cout << "face 1" << endl;

		}
		if (n < 20)
		{
			init10(w, ac, dc);
		}
		while (n < 20)
		{
			modW(w, ac, dc);
			display(w);
			n++;

		}
		if (n < 30)
		{
			init4(w, ac, dc);
		}
		while (n < 30)
		{
			modW(w, ac, dc);
			display(w);
			n++;
			cout << "face 2" << endl;

		}
		if (n < 40)
		{
			init1(w, ac, dc);
		}
		while (n < 40)
		{
			modW(w, ac, dc);
			display(w);
			n++;
			cout << "face 3" << endl;

		}
		if (n < 50)
		{
			init3(w, ac, dc);
		}
		while (n < 50)
		{
			modW(w, ac, dc);
			display(w);
			n++;
			cout << "face 4" << endl;

		}
		if (n < 60)
		{
			init5(w, ac, dc);
		}
		while (n < 60)
		{

			modW(w, ac, dc);
			display(w);
			n++;
			cout << "face 5" << endl;

		}
		if (n < 70)
		{
			init5(w, ac, dc);
		}
		while (n < 70)
		{

			modW(w, ac, dc);
			display(w);
			n++;
			cout << "face 6" << endl;
		}





		if (n == 70)
			n = 0;
	}
	return 0;
}
void menua()
{
	cout << "1.10 pattern " << endl
		<< "2.Cubic world " << endl
		<< "3.Circular world " << endl;
}
int mainc()
{
	char w[MR][MC], mw[MR][MC], ac = -37, dc = ' ';

	init10(w, ac, dc);
	_getch();
	while (true)
	{
		modWa(w, ac, dc);
		display(w);
	}
	return 0;
}
int main()
{
	while (true)
	{
		cout << "____________________________________________________________________" << endl;
		menua();
		cout << "____________________________________________________________________" << endl;
		int choice;
		cout << " Enter choice " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			maina();
			break;
		case 2:
			mainb();
			break;
		case 3:
			mainc();
			break;
		default:
			break;
		}



	}
}
