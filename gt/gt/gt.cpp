#include"stdafx.h"
#include<conio.h>
#include<iostream>
using namespace std;
int main()
{
	float i,n, gt = 1;
	float s=1;
	cout << "\n nhap n = ";
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		gt *= i;
		s += 1 / gt;
	}
	cout << "\n Tong = " << s;
	_getch();
}