#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct NhanVien
{
    char hoDem[20];
    char ten[10];
    char gioiTinh[4];
    int maNV;
    double heSoLuong;
};

struct Node
{
    NhanVien infor;
    Node *next;
};

typedef Node *TRO;
TRO L;

void create(TRO &L)
{
    L = NULL;
}

// nhap thong tin nhan vien
void nhapNV(NhanVien &nv)
{
    cout << "Nhap ho dem: ";
    cin.getline(nv.hoDem, 20);
    cout << "Nhap ten: ";
    cin.getline(nv.ten, 10);
    cout << "Nhap gioi tinh: ";
    cin.getline(nv.gioiTinh, 4);
    cout << "Nhap ma nhan vien: ";
    cin >> nv.maNV;
    cin.ignore();
    cout << "Nhap he so luong: ";
    cin >> nv.heSoLuong;
    cin.ignore();
}

// nhap danh sach
void nhapDS(TRO &L)
{
    NhanVien nv;
    TRO P, Q;
    int i;
    cout << "Nhap so luong nhan vien: ";
    cin >> i;
    cin.ignore();
    while (i < 3)
    {
        cout << "Nhap lai so luong >=3 ";
        cin >> i;
    }
    for (int j = 0; j < i; j++)
    {
        cout << "Nhap nhan vien thu: " << j + 1 << endl;
        nhapNV(nv);
        P = new Node;
        P->infor = nv;
        P->next = NULL;
        if (L == NULL)
        {
            L = P;
        }
        else
        {
            Q->next = P;
        }
        Q = P;
    }
}

// xuat danh sach
void xuatDS(TRO &L)
{
    if (L == NULL)
    {
        cout << "Danh sach rong ";
        return;
    }
    TRO Q = L;
    cout << left << setw(8) << "STT" << setw(20) << "Ho Dem" << setw(20) << "Ten" << setw(20) << "Gioi tinh" << setw(20)
         << "Ma nhan vien" << setw(20) << "He so luong" << endl;

    int d = 0;
    while (Q != NULL)
    {
        NhanVien nv = Q->infor;
        cout << left << setw(8) << d + 1;
        cout << left << setw(20) << nv.hoDem;
        cout << left << setw(20) << nv.ten;
        cout << left << setw(20) << nv.gioiTinh;
        cout << left << setw(20) << nv.maNV;
        cout << left << setw(20) << nv.heSoLuong << endl;
        Q = Q->next;
        d++;
    }
}
// tim kiem
void timKiem(TRO &L)
{
    TRO Q = L;
    int k;
    cout << "Nhap ma nhan vien de kiem tra: ";
    cin >> k;
    cin.ignore();
    int n = 0;
    while (Q != NULL)
    {
        if (Q->infor.maNV == k)
        {
            cout << left << setw(8) << "STT";
            cout << left << setw(20) << "Ho Dem";
            cout << left << setw(20) << "Ten";
            cout << left << setw(20) << "Gioi tinh";
            cout << left << setw(20) << "Ma nhan vien";
            cout << left << setw(20) << "He so luong" << endl;

            cout << left << setw(8) << n + 1;
            cout << left << setw(20) << Q->infor.hoDem;
            cout << left << setw(20) << Q->infor.ten;
            cout << left << setw(20) << Q->infor.gioiTinh;
            cout << left << setw(20) << Q->infor.maNV;
            cout << left << setw(20) << Q->infor.heSoLuong << endl;
            if (Q->next != NULL)
            {
                TRO temp = Q->next;
                Q->next = temp->next;
                delete temp;
                cout << "Da xoa";
            }
            else
            {
                cout << "Khong co nhan vien nao de xoa";
            }
        }
        Q = Q->next;
        n++;
    }
    if (n == 0)
        cout << "Khong tim thay nhan vien nao";
    else
        cout << "Da tim thay va xoa nhan vien dung sau ";
}
// chen vao dau danh sach
void chenDauNV(NhanVien nv, TRO &L)
{
    TRO P = new Node;
    P->infor = nv;
    P->next = L;
    L = P;
    cout << "Da chen nhan vien vao dau danh sach." << endl;
}
//hien thi danh sach theo chieu tang dan he so luong
void xapSep( TRO &L)
{
    if (L == NULL)
    {
        cout << "Danh sach rong. Khong the sap xep." << endl;
        return;
    }
    for (TRO i = L; i != NULL; i = i->next)
    {
        for (TRO j = i->next; j != NULL; j = j->next)
        {
            if (i->infor.heSoLuong > j->infor.heSoLuong)
            {
                NhanVien temp = i->infor;
                i->infor = j->infor;
                j->infor = temp;
            }
        }
    }
    cout << "Da sap xep danh sach theo he so luong tang dan." << endl;
}


int main()
{
    TRO L;
    create(L);
    nhapDS(L);
    cout << "Danh sach sinh vien" << endl;
    xuatDS(L);
    timKiem(L);
    cout << "Danh sach nhan vien sau khi xoa" << endl;
    xuatDS(L);
    cout << "Nhap thong tin nhan vien can chen" << endl;
    NhanVien nv;
    nhapNV(nv);
    chenDauNV(nv, L);
    cout << "Danh sach nhan vien sau khi chen" << endl;
    xuatDS(L);
    xapSep(L);
    cout << "Danh sach nhan vien sau khi sap xep" << endl;
    xuatDS(L);
    return 0;
}