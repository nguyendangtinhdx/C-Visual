// library.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "function.h"
#include<iostream>
using namespace std;

void main()
{
	function f;
	typedef int item;

	typedef struct Node //cau truc 1 Node
	{
		item Data; //du lieu cua Node
		Node *Left; //Con tro trai
		Node *Right; //con tro phai
	};

	typedef struct DList //cau truc Cua List
	{
		Node *Head; //con tro dau
		Node *Tail; //con tro cuoi
	};

	void Init(DList &L);
	int Isempty(DList L); //kiem tra DS rong
	int Len(DList L); // Do dai danh sach
	Node *Make_Node(Node *P, item x); //tao 1 Node P chua thong tin la x 
	void Insert_first(DList &L, item x);  //Chen x vao vi tri dau tien trong danh sach
	void Insert_last(DList &L, item x);  //Chen x vao vi tri dau tien trong danh sach
	void Insert_k(DList &L, item x, int k); //chen x vao vi tri k trong danh sach
	void Del_first(DList &L, item &x); //Xoa phan tu dau tien
	void Del_k(DList &L, item &x, int k); //Xoa Node k trong danh sach
	int Search(DList L, item x); //tim x trong danh sach
	void Del_x(DList &L, item x); //xoa phan tu x trong danh sach
	void Input(DList &L); //nhap danh sach
	void Output(DList L); //xuat danh sach

	system("pause");
}
