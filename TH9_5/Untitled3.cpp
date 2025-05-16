#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct SinhVien{
	char ten[20];
	char maSV[10];
	double diemTK;
};

struct Node{
	SinhVien infor;
	Node *next;
};

typedef Node*TRO;
TRO L;
void create  (TRO &L)
{
	L=NULL;
}
//nhap thong tin sinh vien
void nhapTT(SinhVien &sv)
{
	cout<<"Nhap ten: ";
	cin.getline(sv.ten, 20);
	cout<<"Nhap ma sinh vien: ";
	cin.getline(sv.maSV, 10);
	cout<<"Nhap diem TK: ";
	cin>>sv.diemTK;
	cin.ignore();
}
//nhap danh sach sinh vien
void nhapDS(TRO &L)
{
	SinhVien sv;
	TRO P,Q;
	int i;
	cout<<"Nhap so sinh vien: ";
	cin>>i;
	cin.ignore();
	L=NULL;
	for(int j=0; j<i; j++)
	{
		cout<<"Nhap thong tin sinh vien thu: "<<j+1<<endl;
		nhapTT(sv);
		P=new Node;
		P-> infor=sv;
		P->next=NULL;
		if(L==NULL)
		{
			L=P;
		}
		else Q->next=P;
		Q=P;
	}
}

//xuat danh sach sinh vien
void xuatDS(TRO &L)
{
	TRO Q=L;
	cout<<left<<setw(8)<<"STT";
	cout<<left<<setw(20)<<"Ten";
	cout<<left<<setw(20)<<"Ma sinh vien";
	cout<<left<<setw(20)<<"Diem tong ket"<<endl;
	int d=0;
	while(Q!=NULL)
	{
		SinhVien sv=Q->infor;
			cout<<left<<setw(8)<<d+1;
			cout<<left<<setw(20)<<sv.ten;
			cout<<left<<setw(20)<<sv.maSV;
			cout<<left<<setw(20)<<sv.diemTK<<endl;
			Q=Q->next;
			d++;
	}
}
//tinh tbc diem tong ket cac sinh vien
double tBC(TRO &L)
{
	TRO Q=L;
	double d=0;
	int count=0;
	while (Q!=NULL){
		d=d+Q->infor.diemTK;
		Q=Q->next;
		count++;
	}
	return d/count;
}
//chen sau
void chenSau(TRO &L, TRO Q)
{
	SinhVien sv;
	cout<<"Nhap thong tin sinh vien can chen: "<<endl;
	nhapTT(sv);
	TRO P=new Node;
	P->infor=sv;
	P->next=Q->next;
	Q->next=P;
}
//xoa sau
void xoaSau(TRO &L, TRO Q){
	TRO M=Q->next;
	Q->next=M->next;
	delete(M);
}
int main()
{
	TRO L;
	create(L);
	nhapDS(L);
	cout<<"Danh sach sinh vien "<<endl;
	xuatDS(L);
	tBC(L);
	cout<<"Diem trung binh: "<<tBC(L)<<endl;
	TRO R=L;
	while (R!=NULL)
	{
		if(R->infor.diemTK==tBC(L))
		{
			TRO Q=L;
			Q=Q->next;
			chenSau(L,Q);
			break;
		}
		R=R->next;
	}
	cout<<"Danh sach sinh vien sau khi chen: "<<endl;
	xuatDS(L);
	
	TRO K=L;
	while (K!=NULL)
	{
		if(K->infor.diemTK==tBC(L))
		{
			TRO M=L;
			M=M->next;
			xoaSau(L,M);
			break;
		}
		K=K->next;
	}
	cout<<"Danh sach sinh vien sau khi xoa: "<<endl;
	xuatDS(L);
}






