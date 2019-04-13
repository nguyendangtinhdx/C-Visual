// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
void main()
{
	int n,i,s=0;
	cout << "\n Nhap: ";
	cin >> n;
	for (i = 1; i <= n; i++)
	{

		s += i;
		
	}
	cout << "\n Tong = " << s;
	_getch();
}

