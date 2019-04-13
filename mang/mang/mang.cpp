// mang.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include<conio.h>
#include<iostream>
using namespace std;
void nhap(int a[], int n)
{
	int i;
	for (i = 0; i<n; i++)
	{
		cout << "\n a[" << i << "] = ";
		cin >> a[i];
	}
}
void in(int a[], int n)
{
	int i;
	for (i = 0; i<n; i++)
		cout << "\t" << a[i];
}
void sapxep(int a[], int n)
{
	int i, j, x;
	for (i = 0; i<n - 1; i++)
	for (j = i + 1; j<n; j++)
	if (a[i]>a[j])
	{
		x = a[i];
		a[i] = a[j];
		a[j] = x;
	}
}
void xoa(int a[], int n, int x)
{
	int i, j;
	for (i = 0; i<n; i++)
	if (x == a[i])
	{
		for (j = i; j<n - 1; j++)
			a[j] = a[j + 1];
		//	n--;
	}
}
void chen(int a[], int n, int vt, int gt)
{
	int i, j;
	for (i = n; i>vt; i--)
	{
		a[i] = a[i - 1];
	}
	//  n++;
	a[vt] = gt;
}
int main()
{
	int a[100];
	int n, i;
	cout << "\n Nhap so phan tu: ";
	cin >> n;
	nhap(a, n);
	cout << "\n Mang la: ";
	in(a, n);
	int x;
	cout << "\n Nhap so muon xoa x = ";
	cin >> x;
	cout << "\n Sau khi xoa: ";
	xoa(a, n, x);
	n--;
	in(a, n);
	int vt, gt;
	cout << "\n Vi tri muon chen: ";
	cin >> vt;
	cout << "\n Gia tri muon chen: ";
	cin >> gt;
	cout << "\n Say khi chen: ";
	chen(a, n, vt, gt);
	n++;
	in(a, n);
	cout << "\n Mang sau khi sap xep: ";
	sapxep(a, n);
	in(a, n);
	_getch();
}
