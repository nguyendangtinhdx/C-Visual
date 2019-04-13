#include "stdafx.h"
#include<conio.h>
#include<iostream>
#include<fstream>
#define max 100
using namespace std;

void nhap(float a[max][max], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "\n a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}

void nhap(float b[max], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n b[" << i << "] = ";
		cin >> b[i];
	}
}

void xuat(float a[max][max],int n)
{
	cout << "\n ";
	for (int i = 0; i < n; i++)
	{
		cout << "\n ";
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "\t";
		}
	}
}

void xuat(float b[max], int n)
{
	cout << "(";
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << ",";
		cout << b[n - 1] << ")";
	}
}

void xuatnghiem(float x[], int n, char *s)
{
	cout << "\n He phuong trinh co nghiem: ";
	for (int i = 0; i < n; i++)
	{
		cout << s << i + 1 << " = " << x[i];
	}
}

char HeTamGiacTren(float a[max][max], float x[max], float b[max], int n)
{
	for (int i = n-1; i >= 0 ; i--)
	{
		if (a[i][i] != 0)
		{
			if (i == n - 1)
				x[i] = b[i] / a[i][i];
			else
			{
				x[i] = b[i];
				for (int j = i+1; j < n; j++)
					x[i] = x[i] - a[i][j] * x[j];
					x[i] = x[i] / a[i][i];
			}
		}
		else
				return 0;
	}
	return 1;
}

char HeTamGiacDuoi(float a[max][max], float x[max], float b[max], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i][i] != 0)
		{
			if (i == 0)
				x[i] = b[i] / a[i][i];
			else
			{
				x[i] = b[i];
				for (int j = 0; j < i; j++)
					x[i] = x[i] - a[i][j] * x[j];
					x[i] = x[i] / a[i][i];
			}
		}
		else
			return 0;
	}
	return 1;
}

void PhanRaLU(float a[max][max], float l[max][max], float u[max][max], int n)
{
	for (int k= 0; k < n; k++)
	{
		u[k][k] = a[k][k];
		l[k][k] = 1;
		for (int i = k+1; i < n; i++)
		{
			l[i][k] = a[i][k] / u[k][k];
			u[k][i] = a[k][i];
			u[i][k] = 0;
			l[k][i] = 0;
		}
		for (int i = k+1; i < n; i++)
		{
			for (int j = k+1; j < n; j++)
			{
				a[i][j] = a[i][j] - l[i][k] * u[k][j];
			}
		}
	}
}

void giai(float a[max][max], float x[max], float b[max], int n)
{
	float l[max][max], u[max][max], y[max];
	cout << "\n Phan ra A = LU ";
	PhanRaLU(a, l, u, n);
	cout << "\n Ma tran L: ";
	xuat(l, n);
	cout << "\n Ma tran U: ";
	xuat(u, n);
	cout << "\n Giai Ly = B ";
	if (HeTamGiacDuoi(l, y, b, n))
	{
		xuatnghiem(y, n, "\ny");
		cout << "\n Giai Ux = y ";
		if (HeTamGiacTren(u, x, y, n))
			xuatnghiem(x, n, "\nx");
		else
			cout << "\n He phuong trinh khong co nghiem ";
	} 
	else
		cout << "\n He phuong trinh khong co nghiem ";
}

int main()
{
	int n;
	ofstream open("j.txt");
	float a[max][max], b[max], x[max];
	cout << "\n Phuong trinh bac n = ";
	cin >> n;
	cout << "\n He so ma tran A: ";
	nhap(a, n);
	cout << "\n He so ma tran B: ";
	nhap(b, n);
	giai(a, x, b, n);
	open.close();
	_getch();
}