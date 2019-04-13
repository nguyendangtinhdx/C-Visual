#pragma once
#include<iostream>
using namespace std;
class function
{
public:
	function();
	~function();
public:
	typedef int item;

	typedef struct Node 
	{
		item Data; 
		Node *Prev; 
		Node *Next; 
	};

	typedef struct DList 
	{
		Node *Head; 
		Node *Tail; 
	};

	void Init(DList &L);
	int Empty(DList L); //kiem tra DS rong
	int Lengh(DList L); // Do dai danh sach
	Node *Make_Node(Node *P, item x); //tao 1 Node P chua thong tin la x 
	void Insert_first(DList &L, item x);  //Chen x vao vi tri dau tien trong danh sach
	void Insert_last(DList &L, item x);  //Chen x vao vi tri cuoi cung trong danh sach
	void Insert_k(DList &L, item x, int k); //chen x vao vi tri k trong danh sach
	void Del_first(DList &L, item &x); //Xoa phan tu dau tien
	void Del_k(DList &L, item &x, int k); //Xoa Node k trong danh sach
	int Search(DList L, item x); //tim x trong danh sach
	void Del_x(DList &L, item x); //xoa phan tu x trong danh sach
	void Input(DList &L); //nhap danh sach
	void Output(DList L); //xuat danh sach


	void Init(DList &L)
	{
		L.Head = NULL; 
		L.Tail = NULL; 
	}

	int Empty(DList L) //kiem tra DS rong
	{
		return (L.Head == NULL);
	}

	int Lengh(DList L) // Do dai danh sach
	{
		Node *PH = L.Head, *PT = L.Tail; 
		int i = 0; 
		if (PH != NULL) i = 1;
		while (PH != NULL) 
		{
			if (PH == PT) break;
			PH = PH->Next; 
			i++;
			if (PH == PT) break;
			PT = PT->Prev; 
			i++;
		}
		return i; 
	}

	Node *Make_Node(item x) //tao 1 Node P chua thong tin la x 
	{
		Node *P = (Node *)malloc(sizeof (Node)); 
		P->Data = x; 
		P->Prev = NULL;
		P->Next = NULL;
		return P;
	}

	void Insert_first(DList &L, item x)  //Chen x vao vi tri dau tien trong danh sach
	{
		Node *P;
		P = Make_Node(x); 
		if (Isempty(L)) 
		{
			L.Head = P;
			L.Tail = P;
		}
		else
		{
			P->Next = L.Head;
			L.Head->Prev= P;
			L.Head = P;
		}
	}

	void Insert_last(DList &L, item x)  //Chen x vao vi tri cuoi cung trong danh sach
	{
		Node *P;
		P = Make_Node(x); 
		if (Isempty(L)) 
		{
			L.Head = P;
			L.Tail = P;
		}
		else
		{
			L.Tail->Next = P; 
			P->Prev = L.Tail; 
			L.Tail = P; 
		}
	}

	void Insert_k(DList &L, item x, int k) //chen x vao vi tri k trong danh sach
	{
		Node *PH = L.Head, *PT, *R;
		int i = 1, l = Len(L);
		if (k<1 || k> l + 1) 
			cout<<"Vi tri chen khong hop le !" ; 
		else
		{
			R = Make_Node(x); 
			if (k == 1) Insert_first(L, x); 
			else
			if (k == l + 1) Insert_last(L, x); 
			else //chen vao vi tri 1<k<l+1
			{
				while (PH != NULL && i != k - 1) //duyet den vi tri k-1
				{
					i++;
					PH = PH->Right;
				}
				PT = PH->Next; //xac dinh vi tri k
				R->Right = PT;   //(1)
				R->Left = PH;    //(2)
				PH->Right = R;   //(3)
				PT->Left = R;    //(4)
			}
		}
	}

	void Del_first(DList &L, item &x) //Xoa phan tu dau tien
	{
		if (!Isempty(L))
		{
			x = L.Head->Data; //lay gia tri ra neu can dung
			L.Head = L.Head->Next; 
		}
	}

	void Del_last(DList &L, item &x) //Xoa phan tu dau tien
	{
		if (!Empty(L))
		{
			x = L.Tail->Data;
			L.Tail = L.Tail->Prev;
			L.Tail->Next = NULL;
		}
	}

	void Del_k(DList &L, item &x, int k) //Xoa Node k trong danh sach
	{
		Node *PH = L.Head, *PT;
		int i = 1, l = Len(L);
		if (k<1 || k> l) 
			cout<<"Vi tri xoa khong hop le !"; 
		else
		{
			if (k == 1) Del_first(L, x); //xoa vi tri dau tien
			else
			if (k == l) Del_last(L, x); //xoa vi tri cuoi
			else 
			{
				while (PH != NULL && i != k - 1) 
				{
					i++;
					PH = PH->Right;
				}
				x = PH->Next->Data;
				PT = PH->Next->Next; 
				PH->Next = PT;
				PT->Prev = PH;
			}
		}
	}

	int Search(DList L, item x) //tim x trong danh sach
	{
		Node *P = L.Head;
		int i = 1;
		while (P != NULL && P->Data != x) 
		{
			P = P->Next;
			i++;
		}
		if (P != NULL) return i; 
		else return 0; 
	}

	void Del_x(DList &L, item x) //xoa phan tu x trong danh sach
	{
		int l = Search(L, x);
		while (l)
		{
			Del_k(L, x, l); 
			l = Search(L, x);
		}
	}


	void Input(DList &L) //nhap danh sach
	{
		int i = 0;
		item x;
		do
		{
			i++;
			cout<<"Nhap phan tu thu: "<< i;
			cin >> x;
			if (x != 0) Insert_k(L, x, Len(L) + 1);
		} while (x != 0); 
	}

	void Output(DList L) //xuat danh sach
	{
		Node *P = L.Head;
		while (P != L.Tail->Right)
		{
			cout<<P->Data
			P = P->Prev;
		}
		cout<<"\n";	
	}

	int main()
	{
		DList L;
		Init(L);
		Input(L);
		Output(L);

		int lua_chon;
		cout<<"Moi ban chon phep toan voi DS LKD:";
		cout<<"\n1: Kiem tra DS rong";
		cout<<"\n2: Do dai DS";
		cout<<"\n3: Chen phan tu x vao vi tri k trong DS";
		cout<<"\n4: Tim mot phan tu trong DS";
		cout<<"\n5: Xoa phan tu tai vi tri k";
		cout<<"\n6: XOa phan tu x trong DS";
		cout<<"\n7: Thoat";
		do
		{
			cout<<"\nBan chon: ";
			cin>>lua_chon;
			switch (lua_chon)
			{
			case 1:
			{
					  if (Empty(L)) cout<<"DS rong !";
					  else cout<<"DS khong rong !";
					  break;
			}
			case 2: cout<<"Do dai DS la: "<< Lengh(L)); break;
			case 3:
			{
					  item x;
					  int k;
					  cout<<"Nhap phan tu can chen vao DS: ";
					  cin >> x;
					  cout<<"Nhap vi tri can chen: ";
					  cin >> k;
					  Insert_k(L, x, k);
					  cout<<"DS sau khi chen:\n";
					  Output(L);
					  break;
			}
			case 4:
			{
					  item x;
					  cout<<"Moi ban nhap vao phan tu can tim: ";
					  cin >> x;
					  int k = Search(L, x);
					  if (k) cout<<"Tim thay"<<x<<" trong DS tai vi tri thu:"<< k;
					  else cout<<"Khong tim thay "<< x <<" trong danh sach";
					  break;
			}
			case 5:
			{
					  int k;
					  item x;
					  cout<<"Nhap vi tri can xoa: ";
					  cin >> k;
					  Del_k(L, x, k);
					  cout<<"DS sau khi xoa:\n";
					  Output(L);
					  break;
			}
			case 6:
			{
					  item x;
					  cout<<"Nhap phan tu can xoa: ";
					  cin >> x;
					  Del_x(L, x);
					  cout<<"DS sau khi xoa:\n";
					  Output(L);
					  break;
			}
			case 7: break;
			}
		} while (lua_chon != 7);
		return 0;
	}
};

