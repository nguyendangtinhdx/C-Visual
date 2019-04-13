// ThuVien.cpp : Defines the entry point for the console application.
#include"stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<string.h>
using namespace std;
class thuvien
{
private:
	char ma[50], ten[50];
	int sdt;
public:
	thuvien *next;
	thuvien();
	thuvien(char *m, char *t, int s, thuvien *n);
	void nhap();
	void in();
	char *getma();
	char *getten();
	int getsdt();
};
thuvien::thuvien(){}
thuvien::thuvien(char *m, char *t, int s, thuvien *n)
{
	strcpy_s(ma, m);
	strcpy_s(ten, t);
	sdt = s;
	next = n;
}
/*void thuvien::nhap()
{
cout << "\n Ma thu vien: ";
fflush(stdin);
gets(ma);
cout << "\n Tem thu vien: ";
gets(ten);
cout << "\n So dien thoai: ";
cin >> sdt;
}*/
void thuvien::in()
{
	cout << "\n\t " << ma << "\t " << ten << "\t " << sdt;
}
char *thuvien::getma()
{
	return ma;
}
char *thuvien::getten()
{
	return ten;
}
int thuvien::getsdt()
{
	return sdt;
}
class qldg
{
	thuvien *first;
public:
	qldg();
	void bosung(thuvien *q);
	void inds();
	thuvien *tim(char *ma);
	void xoa(char *ma);
};
qldg::qldg()
{
	first = NULL;
}
void qldg::bosung(thuvien *q)
{
	q->next = first;
	first = q;
}
void qldg::inds()
{
	thuvien *p = first;
	cout << "\n\t MaTV\t TenTV\t SDT ";
	while (p != NULL)
	{
		p->in();
		p = p->next;
	}
}
thuvien *qldg::tim(char *ma)
{
	thuvien *p = first;
	while (p != NULL)
	{
		if (strcmp(p->getma(), ma) == 0)
			return p;
		p = p->next;
	}
	return NULL;
}
/*void qldg::xoa(char *ma)
{
	thuvien *p = tim(ma);
	thuvien *t;
	if (p != NULL)
	{
		if (p == first)
		{
			first = first->next;
			delete p;
		}
		else
		{
			thuvien *q = first;
			while (q != NULL&&q != tim(ma))
			{
				t = q;
				q = q->next;
			}
			t->next = p->next;
			delete p;
		}
	}
}*/
void qldg::xoa(char *ma)
{
	while (first != NULL&&strcmp(first->getma(), ma) == 0)
	{
		thuvien *x = first;
		first = first->next;
		delete(x);
	}
	if (first != NULL)
	{
		thuvien *p = first;
		if (p->next != NULL)
		{
			if (strcmp(p->next->getma(), ma) == 0)
			{
				thuvien *x = p->next;
				p->next = p->next->next;
				delete(x);
			}
			else
				p = p->next;
		}
	}
}
void main()
{
	qldg q;
	char ma[50], ten[50];
	int sdt;
	do
	{
		cout << "\n Ma thu vien: ";
		fflush(stdin);
		gets_s(ma);
		if (strcmp(ma, "") != 0)
		{
			if (q.tim(ma) == NULL)
			{
				cout << "\n Ten thu vien: ";
				gets_s(ten);
				cout << "\n So dien thoai: ";
				cin >> sdt;
				thuvien *p = new thuvien(ma, ten, sdt, NULL);
				q.bosung(p);
			}
		}
	} while (strcmp(ma, "") != 0);
	q.inds();
	cout << "\n Nhap ma can xoa: ";
	gets_s(ma);
	q.xoa(ma);
	q.inds();

	cout << "\n Nhap ma can tim: ";
	gets_s(ma);
	thuvien *r = q.tim(ma);
	if (r != NULL)
		cout << "\n Da tim thay ";
	else
		cout << "\n Khong tim thay ";

	char m[50], t[50];
	int s;
	cout << "\n Bo sung 1 thu vien: ";
	cout << "\n Ma thu vien: ";
	gets_s(m);
	cout << "\n Ten thu vien: ";
	gets_s(t);
	cout << "\n So dien thoai: ";
	cin >> s;
	thuvien *y = new thuvien(m, t, s, NULL);
	q.bosung(y);
	cout << "\n Sau khi bo sung: ";
	q.inds();


	_getch();


}