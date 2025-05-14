#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct SinhVien{
    char hoDem[30];
    char ten[30];
    char gioiTinh[10];
    float diemTK;
};
struct Node{
    SinhVien infor;
    Node* next;
};
typedef Node * TRO;
TRO L;
//khoi tao ds rong
void create(TRO&L)
{
    L=NULL;
}

//nhap thong tin sinh vien
void nhapTT(SinhVien &sv){
    cout<<"Nhap ho dem: ";
    cin.getline(sv.hoDem,30);
    cout<<"Nhap ten: ";
    cin.getline(sv.ten,30);
    cout<<"Nhap gioi tinh: ";
    cin.getline(sv.gioiTinh,10);
    cout<<"Nhap diem TK: ";
    cin>>sv.diemTK;
    cin.ignore();
    while (sv.diemTK<0 || sv.diemTK>10){
        cout<<"Nhap lai diem TK: ";
        cin>>sv.diemTK;
    }
}
//nhap danh sach sinh vien
void nhapDS(TRO &L)
{
    SinhVien sv;
    TRO P,Q;
    int i;
    cout<<"Nhap so sinh vien can dien: ";
    cin>>i;
    cin.ignore();
    L=NULL;
    while (i<=3)
    {
        cout<<"Nhap lai so sinh vien >3 ";
        cin>>i;
    }
    for(int j=0;j<i;j++){
        cout<<"Nhap sinh vien thu "<<j+1<<endl;
        nhapTT(sv);
        P=new Node;
        P->infor=sv;
        P->next=NULL;
        if(L==NULL){
            L=P;
        }
        else{
            Q->next=P;
        }
        Q=P;
    }
}
//xuat danh sach sinh vien
void xuatDS(TRO &L){
    if(L==NULL){
        cout<<"Danh sach rong "<<endl;
        return;
    }
    TRO Q=L;
    cout<<left<<setw(8)<<"STT";
    cout<<left<<setw(20)<<"Ho";
    cout<<left<<setw(20)<<"Ten";
    cout<<left<<setw(20)<<"Gioi tinh";
    cout<<left<<setw(10)<<"Diem TK"<<endl;
    int d=0;
    while(Q!=NULL){
        SinhVien sv=Q->infor;
        cout<<left<<setw(8)<<d+1;
        cout<<left<<setw(20)<<sv.hoDem;
        cout<<left<<setw(20)<<sv.ten;
        cout<<left<<setw(20)<<sv.gioiTinh;
        cout<<left<<setw(10)<<sv.diemTK<<endl;
        Q=Q->next;
        d++;
    }   
}
//tim kiem sinh vien 
void tim(TRO &L)
{
    char name[30];
    cout<<"Nhap ten sinh vien de tim kiem va xoa: ";
    cin.getline(name,30);
    
    TRO Q = L;
    TRO P = NULL;
    int d = 0;

    while (Q != NULL) {
        if (strcmp(Q->infor.ten, name) == 0) 
        {
            cout<<left<<setw(8)<<"STT";
            cout<<left<<setw(20)<<"Ho";
            cout<<left<<setw(20)<<"Ten";
            cout<<left<<setw(20)<<"Gioi tinh";
            cout<<left<<setw(10)<<"Diem TK"<<endl;

            cout<<left<<setw(8)<<d+1;
            cout<<left<<setw(20)<<Q->infor.hoDem;
            cout<<left<<setw(20)<<Q->infor.ten;
            cout<<left<<setw(20)<<Q->infor.gioiTinh;
            cout<<left<<setw(10)<<Q->infor.diemTK<<endl;

            // xóa nút hiện tại
            if (Q == L) {
                L = Q->next;
                delete Q;
                Q = L;
            } else {
                P->next = Q->next;
                delete Q;
                Q = P->next;
            }

            d++;
        }
        else 
        {
            P = Q;2
            Q = Q->next;
        }
    }

    if (d == 0) {
        cout << "Khong tim thay sinh vien ten \"" << name << "\"\n";
    } else {
        cout << "Da tim va xoa " << d << " sinh vien co ten \"" << name << "\"\n";
    }
}
//chen them 1 sinh vien truoc sinh vien thu 3 trong danh sach
void chenSV(TRO &L, SinhVien sv)
{
    TRO P = new Node;
    P->infor = sv;
    P->next = NULL;

    // Trường hợp đặc biệt: chèn đầu danh sách
    if (L == NULL || L->next == NULL) {
        P->next = L;
        L = P;
        return;
    }

    // Nếu muốn chèn trước sinh viên thứ 3 (vị trí thứ 2), cần đến phần tử thứ 1
    TRO Q = L;
    int count = 0;

    // Tìm phần tử đứng trước sinh viên thứ 3 (tức là phần tử thứ 1, nếu đếm từ 0)
    while (Q != NULL && count < 1) {
        Q = Q->next;
        count++;
    }

    // Nếu Q hợp lệ (không phải NULL), thì chèn vào sau Q
    if (Q != NULL) {
        P->next = Q->next;
        Q->next = P;
    }

    cout << "Da chen sinh vien vao truoc sinh vien thu 3.\n";
}

//ham main
int main()
{
    TRO L;
    create(L);
    nhapDS(L);
    cout<<"Danh sach sinh vien: "<<endl;
    xuatDS(L);
    tim(L);
    cout<<"Danh sach sinh vien sau khi xoa: "<<endl;
    xuatDS(L);
    SinhVien sv;
    cout<<"Nhap thong tin sinh vien can chen: ";
    nhapTT(sv);
    chenSV(L, sv);
    cout<<"Danh sach sinh vien sau khi chen: "<<endl;
    xuatDS(L);
    return 0;
}