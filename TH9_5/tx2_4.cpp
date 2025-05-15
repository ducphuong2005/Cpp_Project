#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

struct MatHang
{
    char maHang[20];
    char tenHang[50];
    int soLuong;
};
struct Node
{
    MatHang infor;
    Node *next;
};

typedef Node *TRO;
TRO L;
// khoi tao ds rong
void create(TRO &L)
{
    L = NULL;
}
//nhap thong tin mat hang
void nhapTT(MatHang &mh)
{
    cout << "Nhap ma hang: ";
    cin.getline(mh.maHang, 20);
    cout << "Nhap ten hang: ";
    cin.getline(mh.tenHang, 50);
    cout << "Nhap so luong: ";
    cin >> mh.soLuong;
    cin.ignore();
}
//nhap danh sach mat hang
void nhapDS(TRO &L)
{
    MatHang mh;
    TRO P,Q;
    int i;
    cout<<"Nhap so mat hang can them: ";
    cin>>i;
    cin.ignore();
    while (i<=3)
    {
        cout<<"Nhap lai so mat hang >3 ";
        cin>>i;
    }
    for(int j=0; j<i; j++)
    {
        cout<<"Nhap mat hang thu: "<<j+1<<endl;
        nhapTT(mh);
        P=new Node;
        P->infor=mh;
        P->next=NULL;
        if(L==NULL){
            L=P;
        }
        else Q->next=P;
        Q=P;
    }
}
//xuat ds
void xuatDS(TRO &L)
{
    if(L==NULL) {
        cout<<"Danh sach rong"<<endl;
        return;
    }
    TRO Q=L;
    cout<<left<<setw(8)<<"STT";
    cout<<left<<setw(20)<<"Ma hang";
    cout<<left<<setw(20)<<"Ten hang";
    cout<<left<<setw(20)<<"So luong"<<endl;
    int d=0;
    while (Q!=NULL)
    {
        MatHang mh=Q->infor;
        cout<<left<<setw(8)<<d+1;
        cout<<left<<setw(20)<<mh.maHang;
        cout<<left<<setw(20)<<mh.tenHang;
        cout<<left<<setw(20)<<mh.soLuong<<endl;
        Q=Q->next;
        d++;
    }
}
//tim mat hang so luong lon nhat
void search(TRO &L)
{
    if(L==NULL) {
        cout<<"Danh sach rong"<<endl;
        return;
    }
    TRO Q=L;
    int max=Q->infor.soLuong;
    while (Q!=NULL)
    {
        if(Q->infor.soLuong>max)
            max=Q->infor.soLuong;
        Q=Q->next;
    }
    cout<<"Mat hang co so luong lon nhat la: "<<max<<endl;
    cout<<left<<setw(8)<<"STT";
    cout<<left<<setw(20)<<"Ma hang";
    cout<<left<<setw(20)<<"Ten hang";
    cout<<left<<setw(20)<<"So luong"<<endl;
    Q=L;
    int d=0;
    // in ra danh sach mat hang co so luong lon nhat
    while (Q!=NULL)
    {
        if(Q->infor.soLuong==max){
            cout<<left<<setw(8)<<d+1;
            cout<<left<<setw(20)<<Q->infor.maHang;
            cout<<left<<setw(20)<<Q->infor.tenHang;
            cout<<left<<setw(20)<<Q->infor.soLuong<<endl;
        }
        Q=Q->next;
        d++;
    }
    //xoa mat hang co so luong lon nhat
    Q=L;
    int n=0;
    TRO P=NULL;
    while (Q!=NULL)
    {
        if(Q->infor.soLuong==max)
        {
            if(P==NULL)
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
            n++;
        }
        else
        {
            P=Q;
            Q=Q->next;
        }
    }
    if(n==0)
        cout<<"Khong tim thay mat hang co so luong lon nhat"<<endl;

}
//chen 1 mat hang moi vao sau mat hang thu nhat
void chenMH(MatHang mh, TRO &L)
{
    TRO P = new Node;
    P->infor = mh;
    P->next = NULL;

    if (L == NULL) {
        cout << "Danh sach rong. Khong the chen sau mat hang thu nhat." << endl;
        delete P;
        return;
    }
    // Lúc này L != NULL => chèn sau phần tử đầu tiên
    TRO Q = L;
    P->next = Q->next;
    Q->next = P;

    cout << "Da chen mat hang vao sau mat hang thu nhat." << endl;
}
//chen mat hang moi vao dau danh sach
void chenDauMH(MatHang mh, TRO &L)
{
    TRO P = new Node;
    P->infor = mh;
    P->next = L;
    L = P;
    cout << "Da chen mat hang vao dau danh sach." << endl;
}
//sap xep danh sach theo tang dan so luong
void sapXepTangDan(TRO &L)
{
    if (L == NULL) {
        cout << "Danh sach rong. Khong the sap xep." << endl;
        return;
    }
    for( TRO i = L; i != NULL; i = i->next) {
        for (TRO j = i->next; j != NULL; j = j->next) {
            if (i->infor.soLuong > j->infor.soLuong) {
                MatHang temp = i->infor;
                i->infor = j->infor;
                j->infor = temp;
            }
        }
    }
    cout << "Da sap xep danh sach theo so luong tang dan." << endl;
}    
int main()
{
    create(L);
    nhapDS(L);
    cout<<"Danh sach mat hang"<<endl;
    xuatDS(L);
    search(L);
    cout<<"Danh sach mat hang sau khi xoa"<<endl;
    xuatDS(L);
    MatHang mh;
    cout<<"Nhap thong tin mat hang can chen"<<endl;
    nhapTT(mh);
    chenMH(mh,L);
    cout<<"Danh sach mat hang sau khi chen"<<endl;
    xuatDS(L);
    sapXepTangDan(L);
    cout<<"Danh sach mat hang sau khi sap xep"<<endl;
    xuatDS(L);
    cout<<"Nhap thong tin mat hang can chen vao dau"<<endl;
    nhapTT(mh);
    chenDauMH(mh,L);
    cout<<"Danh sach mat hang sau khi chen vao dau"<<endl;
    xuatDS(L);
    return 0;
}