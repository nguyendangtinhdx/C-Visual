// VectTo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<conio.h>
#include<iostream>
using namespace std;
class vecto
{
	int *a, n, i;
public:
	void nhap()
	{
		a = new int[100];
		cout << "\n So phan tu: ";
		cin >> n;
		for (i = 0; i < n; i++)
		{
			cout << "\n a[" << i << "] = ";
			cin >> a[i];
		}
	}
	void in()
	{
		for (i = 0; i < n; i++)
		{
			cout << "  " << a[i];
		}
	}
	vecto operator --(int)
	{
		for (i = 0; i < n; i++)
			a[i]--;
		return *this;
	}
	int operator ==(vecto v2)
	{
		if (n != v2.n)
		{
			cout << "\n So phan tu # nhau";
		}
		else
			for (i = 0; i < n; i++)
				if (a[i] == v2.a[i])
					return 1;
				return 0;
	}
};
void main()
{
	vecto v1, v2;
	v1.nhap();
	v1.in();
	/*	v1--;
	cout << "\n Sau khi giam: ";
	v1.in();*/
	v2.nhap();
	v2.in();
	if (v1 == v2)
		cout << "\n 2 doi tuong = nhau";
	else
		cout << "\n 2 doi tuong # nhau ";
	_getch();
}