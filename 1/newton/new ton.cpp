// newton.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<conio.h>
#include<math.h>
#include<iostream>
#include <iomanip>
using namespace std;

float f(float x)
{
	return (exp(x) - x - 2);
}
float df(float x)
{
	return (exp(x) - 1);
}
int main()
{
	int i = 1, n,j;
	float e, p, p0;
	cout << "\n Nhap diem xuat phat: "; cin >> p0;
	cout << "\n Sai so: "; cin >> e;
	cout << "\n So buoc lap cuc dai: "; cin >> n;
	p = p0 + 1;
	while (i <= n)
	{
		p = p0 - f(p0) / df(p0);
		if (p - p0 < e)
		{
			cout << "\n p = " << p;
			break;
		}
		else
		{
			i++;
			p0 = p;
			cout << "\n " << setprecision(10) << p;
		}
		
	}
	_getch();
}
	