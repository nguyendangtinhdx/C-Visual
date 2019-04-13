// bang cuu chuong.cpp : Defines the entry point for the console application.
//
#include"stdafx.h"
#include<conio.h>
#include<iostream>
using namespace std;
int main()
{
	int i, j;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j <= 10; j++)
		{
			cout << "\t " << i << " X " << j << " = " << i*j;	
		}
		cout << "\n";
	}
	_getch();
}