#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct SinhVien
{
    char ten[30];
    char gioiTinh[4];
    double diemTK;
};
struct Node
{
    SinhVien infor;
    Node * next;
};
typedef Node*TRO;
TRO L;

void create (TRO & L)
{
    L=NULL;
}

void nhapTT(SinhVien &sv)
{
    cout<<"Nhap ten: ";
    cin.getline(sv.ten, 30);
    cout<<"Nhap gioi tinh: ";
    cin.getline(sv.gioiTinh,4);
    cout<<"Nhap diem tong ket: ";
    cin>>sv.diemTK;
    cin.ignore();
}

void nhapDS(TRO &L)
{
    SinhVien sv;
    TRO P,Q;
    int i;
    cout<<"Nhap so luong sinh vien: ";
    cin>>i;
    cin.ignore();
    while (i<3)
    {
        cout<<"Nhap lai so luong sinh vien >=3";
        cin>>i;
    }
    for(int j=0; j<i; j++)
    {
        cout<<"Nhap sinh vien thu: "<<j+1<<endl;
        nhapTT(sv);
        P=new Node;
        P->infor=sv;
        P->next=NULL;
        if(L==NULL)
        {
            L=P;
        }
        else Q->next=P;
        Q=P;
    }
}

void xuatDS(TRO &L)
{
    if(L==NULL)
    {
        cout<<"Danh sach rong"<<endl;
        return;
    }
    TRO Q=L;
    cout<<left<<setw(8)<<"STT";
    cout<<left<<setw(10)<<"Ten";
    cout<<left<<setw(10)<<"Gioi tinh";
    cout<<left<<setw(10)<<"Diem tong ket"<<endl;
    int d=0;
    while (Q!=NULL)
    {
        SinhVien sv = Q->infor;
    cout<<left<<setw(8)<<d+1;
    cout<<left<<setw(10)<<sv.ten;
    cout<<left<<setw(10)<<sv.gioiTinh;
    cout<<left<<setw(10)<<sv.diemTK<<endl;
    Q=Q->next;
    d++;
    }
}
//tim kiem 
void timKiem(TRO &L)
{
    char timTen[30];
    cout<<"Nhap ten de kiem tra: ";
    cin.getline(timTen,30);
    TRO Q=L;
    TRO P=NULL;
    int d=0;
    while (Q!=NULL)
    {
        if(strcmp(Q->infor.ten,timTen)==0)
        {
    cout<<left<<setw(8)<<"STT";
    cout<<left<<setw(10)<<"Ten";
    cout<<left<<setw(10)<<"Gioi tinh";
    cout<<left<<setw(10)<<"Diem tong ket"<<endl;   

    cout<<left<<setw(8)<<d+1;
    cout<<left<<setw(10)<<Q->infor.ten;
    cout<<left<<setw(10)<<Q->infor.gioiTinh;
    cout<<left<<setw(10)<<Q->infor.diemTK<<endl;

    if(Q==L)
    {
        L=Q->next;
        delete Q;
        Q=L;
    }
    else 
    {
        P->next=Q->next;
        delete Q;
        Q=P->next;
    }
            d++;
        }
        else 
        {
        P=Q;
        Q=Q->next;
        }
    }

    if(d==0) cout<<"Khong tim thay sinh vien "<<endl;
    else cout<<"Da tim thay va xoa "<<endl;
}

void chenSV(TRO &L, SinhVien sv)
{
    TRO P= new Node;
    P->infor =sv;
    P->next=NULL;

    if(L==NULL || L->next ==NULL)
    {
        P->next=L;
        L=P;
        return;
    }
    TRO Q=L;
    int count =0;
    while (Q!=NULL && count <1)
    {
        Q=Q->next;
        count ++;
    }
    if(Q!=NULL)
    {
        P->next= Q->next;
        Q->next=P;
    }
} 

int main()
{
    TRO L;
    SinhVien sv;
    create (L);
    nhapDS(L);
    cout<<"Danh sach sinh vien"<<endl;
    xuatDS(L);
    timKiem(L);
    cout<<"Danh sach sau khi xoa "<<endl;
    xuatDS(L);
    cout<<"Nhap sinh vien can chen: ";
    nhapTT(sv);
    chenSV(L,sv);
    cout<<"Danh sach sau khi chen: "<<endl;
    xuatDS(L);
}
