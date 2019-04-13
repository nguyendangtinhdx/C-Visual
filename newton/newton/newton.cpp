#include"stdafx.h"
#include <conio.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;
float f(float x)
{
	return (x*x-2);
}
float df(float x)
{
	return (2*x);
}
int main()
{
	float p, e, y[99], s;
	int i = 1, n;
	ofstream openfile("a.txt");
	cout << "\n Giai phuong trinh bang phuong phap Newton: ";
	cout << "\n Nhap diem xuat phat Po = ";
	cin >> p;
	cout << "\n Nhap gia tri Epsilon  = ";
	cin >> e;
	cout << "\n Nhap so buoc lap cuc dai = ";
	cin >> n;
	cout << "\n\t n\t Pn\t\t Sai so tuong doi" << endl;
	cout << "\n\t " << i - 1 << "\t " << p << "\t " << "\t\t _";
	openfile << "\n\t n\t Pn\t\t\t\t Sai so tuong doi" << endl;
	openfile << "\n\t " << i - 1 << "\t " << p << "\t " << "\t\t\t\t _";
	y[0] = f(p) - 1;
	while (i <= n && fabs(y[i] - y[i - 1])>e)
	{
		s = (p / (p - f(p) / df(p))) - 1;
		p = p - f(p) / df(p);
		i++;
		y[i] = f(p);
		cout << "\n\t " << i - 1 << "\t " << setprecision(10) << p << "\t " << setprecision(10) << s;
		openfile << "\n\t " << i - 1 << "\t " << setprecision(10) << p << "\t " << setprecision(10) << s;
	}
	openfile.close();
	_getch();
}
