#include <iostream>
#include <iomanip>
using namespace std;

struct CauThu
{
    string hoTen;
    int namSinh;
    float luongThang;
    int namBatDau;
};

void A1 (CauThu *ds, int n, int i)
{
    if (i == n) return;
    cout << left << setw(15) << ds[i].hoTen
        << setw(10) << ds[i].namSinh
        << setw(15) << ds[i].luongThang
        << setw(10) << ds[i].namSinh << endl;
    A1(ds, n, i+1);
}

int A2(CauThu *ds, int l, int r)
{
    if (l == r)
        return (ds[l].namBatDau == 0);

    int m = (l + r) / 2;
    return A2(ds, l, m) + A2(ds, m + 1, r);
}

void show(CauThu *ds, int *x, int n, int &dem)
{
    dem++;
    cout << "Phuong an: " << dem <<":\n";
    for(int i =0; i < n; i++)
    {
        cout << ds[i].hoTen << " => vi tri " << x[i] + 1 << endl;
    }
    cout << "------------------------\n";
}

// A3 Quay lui
void A3(int k, CauThu *ds, int *used, int *x, int n, int &dem)
{
    for (int i = 0; i < n; i++)
    {
        if(!used[i])
        {
            x[k] = i;
            used[i] = 1;
            if ( k == n - 1)
                show(ds, x, n, dem);
            else
                A3(k+1, ds, used, x, n, dem);
            used[i] = 0;
        }
    }
}

int main()
{
    int n = 7;
    CauThu *d = new CauThu[n]{
        {"Quang Hai", 1990, 300, 2000},
        {"Quang Huy", 1995, 40000, 0},
        {"Tuan Hai", 1999, 30000, 2008},
        {"Viet Anh", 1985, 60000, 1999},
        {"Xuan Son", 1990, 5000, 2005},
        {"Ronaldo", 1980, 99000, 1995},
        {"Messi", 1985, 33300, 2000}
    };
    cout << "DANH SACH CAU THU\n";
    cout << left << setw(15) << "Ho ten"
        << setw(10) << "Nam sinh"
        << setw(15) << "Luong"
        << setw(10) << "Nam BD" << endl;
    A1(d, n, 0);

    int kq = A2(d, 0, n - 1);
    cout << "\nSo cau thu thi dau chuyen nghiep: " << kq << endl;

    int *used = new int[n]{};
    int *x = new int[n]{};
    int dem = 0;
    cout << "\nCAC PHUONG AN SAP XEP";
    A3(0, d, used, x, n, dem);
    cout << "\nTong so phuong an: " << dem << endl;
    return 0;
}

