#include <bits/stdc++.h>


using namespace std;

#define MAX 100
 struct SinhVien
 {
     char hoTen[30];
     double diemTK;
     char maSV[10];
 };

 struct List
 {
     int Count;
     SinhVien e[MAX];
 };


 void nhap_sv(SinhVien&x)
 {

     cout<<"Ho ten: ";
     fflush(stdin);
     gets(x.hoTen);
     cout<<"Nhap diem tong ket: ";
     fflush(stdin);
     cin>>x.diemTK;
     cout<<"Nhap ma sinh vien: ";
     fflush(stdin);
     gets(x.maSV);
}

void nhap_ds (List&L)
{
    cout<<"Nhap so sinh vien trong danh sach: ";
    cin>>L.Count;
    for(int i=0; i<L.Count; i++)
    {
        cout<<"Nhap thong tin sinh vien "<<i+1<<":"<<endl;
        nhap_sv(L.e[i]);
    }
}

void xuat_ds (List L)
{
    cout<<setw(10)<<"Stt "<<setw(10)<<"Ma SV "<<setw(10)<<"Ten SV "<<setw(10)<<"Diem TK "<<setw(10)<<endl;
    for (int i=0; i<L.Count; i++)
    {
        cout<<setw(10)<<i+1<<setw(10)<<L.e[i].maSV<<setw(10)<<L.e[i].hoTen<<setw(10)<<L.e[i].diemTK<<endl;
    }
}

void them(List &L,int k)
{
    SinhVien x;
    cout<<"Nhap thong tin sinh vien can them: "<<endl;
    nhap_sv(x);
    for(int i=L.Count; i>=k; i--)
    {
        L.e[i]=L.e[i-1];
    }
            L.Count = L.Count + 1;
            L.e[k-1]=x;
}
void xoa(List &L,int k)
{
    for(int i=k-1; i<L.Count-1; i++)
    {
        L.e[i]=L.e[i+1];
    }
     L.Count = L.Count - 1;
}
void sapxep(List &L)
{
    for(int i=0; i<L.Count-1; i++)
    {
        for(int j=i+1; j<L.Count; j++)
        {
            if(L.e[i].diemTK>L.e[j].diemTK)
            {
                SinhVien temp=L.e[i];
                L.e[i]=L.e[j];
                L.e[j]=temp;
            }
        }
    }
}
//tim kiem sinh vien co ten la Ha
void timkiem(List L)
{
    char ten[30];
    cout<<"Nhap ten sinh vien can tim: ";
    fflush(stdin);
    gets(ten);
    cout<<setw(10)<<"Stt "<<setw(10)<<"Ma SV "<<setw(10)<<"Ten SV "<<setw(10)<<"Diem TK "<<setw(10)<<endl;
    bool temp=false;
    for(int i=0; i<L.Count; i++)
    {
        if(strcmp(L.e[i].hoTen,ten)==0)
        {
            cout<<setw(10)<<i+1<<setw(10)<<L.e[i].maSV<<setw(10)<<L.e[i].hoTen<<setw(10)<<L.e[i].diemTK;
            temp = true;
        }
    }
   if(!temp)
    {
        cout<<endl<<"Khong tim thay sinh vien co ten "<<ten<<endl;
    }
    else
    {
        cout<<endl<<"Da tim thay sinh vien co ten "<<ten<<endl;
    }
}

int main()
{
    List L;
    int k;
    cout<<"DANH SACH SINH VIEN"<<endl;
    nhap_ds(L);
    cout<<"Danh sach sinh vien: "<<endl;
    xuat_ds(L);
    cout<<"*********************************************************"<<endl<<"Nhap vi tri can them: ";
    cin>>k;
    them(L,k);
    cout<<"Danh sach sinh vien sau khi them: "<<endl;
    xuat_ds(L);
    cout<<"**********************************************************"<<endl<<"Nhap vi tri can xoa: ";
    cin>>k;
    while(k<=0 || k>L.Count)
        {
            cout<<"Nhap lai vi tri can xoa ";
            cin>>k;
        }
    xoa(L,k);
    cout<<"Danh sach sinh vien sau khi xoa: "<<endl;
    xuat_ds(L);
    sapxep(L);
    cout<<"***********************************************************"<<endl<<"Danh sach sinh vien sau khi sap xep: "<<endl;
    xuat_ds(L);
    timkiem(L);
    return 0;
}


