// mofile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<conio.h>
#include<iostream>
#include<fstream>
using namespace std;

void main()
{
	int n, s = 0, i,a,b;
	ofstream open("a.txt");
	for (a = 1; a < 2016; a++)
	{
		for (b = 2; b <= 2016; b++)
		{
			s = 3 * b - 2 * a;
		}
	}		
	cout << "\n Tong = " << s;
	open << s;
	open.close();
	_getch();
}

