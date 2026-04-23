#include <iostream>
#include <iomanip>
using namespace std;

struct HocSinh
{
    string hoTen;
    float diemTK;
    string daoDuc;
    int tienThuong;
};

// ===== A4 =====
int A4(HocSinh *ds, int n, int i)
{
    if (i == n) return 0;

    cout << left << setw(20) << ds[i].hoTen
         << setw(10) << ds[i].diemTK
         << setw(15) << ds[i].daoDuc
         << setw(15) << ds[i].tienThuong << endl;

    return ds[i].tienThuong + A4(ds, n, i + 1);
}

// ===== A5 =====
int A5(HocSinh *ds, int l, int r)
{
    if (l == r)
        return (ds[l].diemTK >= 7.0);

    int m = (l + r) / 2;
    return A5(ds, l, m) + A5(ds, m + 1, r);
}

// ===== show =====
void show(HocSinh *ds, int *x, int &dem)
{
    dem++;
    cout << "Phuong an " << dem << ":\n";

    for (int i = 0; i < 6; i++)
    {
        cout << ds[x[i]].hoTen
             << " - Dao duc: " << ds[x[i]].daoDuc << endl;
    }
    cout << "----------------------\n";
}
// ===== A6 =====
void A6(int k, HocSinh *ds, int *x, int n, int &dem, int start)
{
    for (int i = start; i < n; i++)
    {
        x[k] = i;

        if (k == 5) // chọn đủ 6
        {
            show(ds, x, dem);
        }
        else
        {
            A6(k + 1, ds, x, n, dem, i + 1);
        }
    }
}

int main()
{
    int n = 7;

    HocSinh *d = new HocSinh[n]{
        {"Nguyen Van A", 8.5, "Tot", 1000000},
        {"Tran Thi B", 6.5, "Kha", 500000},
        {"Le Van C", 7.2, "Tot", 800000},
        {"Pham Thi D", 9.0, "Tot", 1200000},
        {"Hoang Van E", 5.5, "Trung binh", 300000},
        {"Do Thi F", 7.8, "Kha", 700000},
        {"Vu Van G", 8.0, "Tot", 900000}
    };

    // ===== In danh sách =====
    cout << "===== DANH SACH HOC SINH =====\n";
    cout << left << setw(20) << "Ho ten"
         << setw(10) << "Diem"
         << setw(15) << "Dao duc"
         << setw(15) << "Tien thuong" << endl;

    int tong = A4(d, n, 0);
    cout << "\nTong tien thuong: " << tong << endl;

    int demHS = A5(d, 0, n - 1);
    cout << "So hoc sinh diem >= 7.0: " << demHS << endl;

    int *x = new int[6];
    int dem = 0;

    cout << "\nCac phuong an chon 6 hoc sinh:\n";
    A6(0, d, x, n, dem, 0);

    cout << "\nTong so phuong an: " << dem << endl;

    return 0;
}
