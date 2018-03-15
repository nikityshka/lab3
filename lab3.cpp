
#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int lim = 40;
void getline(char *str, int lim)
{
	int c, i;
	c = 1;
	for (i = 0; (i<lim - 1) && (c != (int)'\n'); i++)
	{
		c = getchar();
		str[i] = c;
	}
	str[i] = '\0';
}

struct book
{
	int UDKnumber;
	char autor[lim];
	char bookname[lim];
	long int year;
	int kolvo;
	book* next;
};
book* firstbook = new book;
book* lastbook = firstbook;
bool isFirst = true;


int main()
{
	int n, i, c, j, k;
	int zapros;
	printf("Kol-vo knig\n");
	cin >> n;
	for (i = 0; i <= n - 1; i++)
	{
		if (isFirst) isFirst = false;
		else
		{
			lastbook->next = new book;
			lastbook = lastbook->next;
		}
		printf("Kniga %d\n", i + 1);
		cout << "\n" << "UDK:" << "\n" << "Avtor knigi: " << "\n" << "Nazvanie knigi: " << "\n" << "God izdaniya: " << "\n" << "Kol-vo knig: " << "\n";
		cin >> lastbook->UDKnumber;
		cin.ignore();
		getline(&lastbook->autor[0], lim);
		getline(&lastbook->bookname[0], lim);
		cin >> lastbook->year;
		cin >> lastbook->kolvo;
		lastbook->next = NULL;

	}
	for (k = 0; k >= 0; k++)
	{
		cout << " 1-Vidat' Knigu \n 2-Sdat' Knigu \n 3-Proverka nalichiya knigi \n 4-Vse knigi\n";	
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "Vvedite udk: ";
			cin >> zapros;
			j = 0;
			for (book* t = firstbook; t != NULL; t = t->next)
			{
				if (zapros == t->UDKnumber)
				{
					if (t->kolvo != 0)
					{
						t->kolvo = t->kolvo - 1;
						break;
					}
					else
					{
						cout << "Net knigi\n";
						break;
					}
				}
				if (j == n - 1)cout << "Net knigi\n";
				j++;
			}
			break;
		case 2:
			cout << "Vvedite udk: ";
			cin >> zapros;
			j = 0;
			for (book* t = firstbook; t != NULL; t = t->next)
			{
				if (zapros == t->UDKnumber)
				{
					if (t->kolvo != 0)
					{
						t->kolvo = t->kolvo + 1;
						break;
					}
				}
				if (j == n - 1) cout << "Net knigi\n";
				j++;
			}
			break;
		case 3:
			cout << "Vvedite udk: ";
			cin >> zapros;
			j = 0;
			for (book* t = firstbook; t != NULL; t = t->next)
			{

				if (zapros == t->UDKnumber)
				{
					printf("%d      ", t->UDKnumber);
					for (i = 0; t->autor[i] != 10; i++)
						cout << t->autor[i];
					cout << "    ";
					for (i = 0; t->bookname[i] != 10; i++)
						cout << t->bookname[i];
					cout << "    ";
					printf("%d  ", t->year);
					printf("%d\n", t->kolvo);
					break;
				}
			}


			break;
		case 4:
			for (book* t = firstbook; t != NULL; t = t->next)
			{
				printf("%d      ", t->UDKnumber);
				for (i = 0; t->autor[i] != 10; i++)
					cout << t->autor[i];
				cout << "    ";
				for (i = 0; t->bookname[i] != 10; i++)
					cout << t->bookname[i];
				cout << "    ";
				printf("%d  ", t->year);
				printf("%d\n", t->kolvo);
			}
			break;
		}
	}
}

