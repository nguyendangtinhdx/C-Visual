#include"stdafx.h"
#include<conio.h>
#include<iostream>
#include<stdio.h>
using namespace std;
class stack
{
	int s[100], top;
public:
	stack()
	{
		top = -1;
	}
	void push(int ch);
	int pop();
	int gettop()
	{
		return top;
	}
};
void stack::push(int ch)
{
	if (top == 99)
	{
		cout << "\n Stack day ";
		return;
	}
	s[++top] = ch;
}
int stack::pop()
{
	if (top == -1)
	{
		cout << "\n Stack rong ";
		return 0;
	}
	return s[top--];
}
class chuyendoi : public stack
{
	int n, i, m;
public:
	/*	void nhap2()
	{
	cout<<"\n Nhap so n = "; cin>>n;
	while(n!=0)
	{
	i=n%2;
	push(i);
	n/=2;
	}
	}
	void in2()
	{
	cout<<"\n Chuyen sang he so 2 =  ";
	while(gettop()!=-1)
	cout<<pop();
	}*/
	void nhap()
	{
		cout << "\n Nhap he so 10: "; cin >> n;
		cout << "\n Nhap co so: "; cin >> m;
		while (n != 0)
		{
			i = n%m;
			push(i);
			n /= m;
		}
	}
	int getcoso()
	{
		return m;
	}
	void in()
	{
		cout << "\n Chuyen qua he so " << getcoso() << " = ";
		while (gettop() != -1)
		if (getcoso() == 16)
			cout << hex << pop();
		else
			cout << pop();
	}

};
void main()
{
	chuyendoi c;
	c.nhap();
	c.in();
	_getch();
}
