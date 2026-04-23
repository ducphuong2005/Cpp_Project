#include <iostream>
#include <iomanip>
using namespace std;

struct TaiSan
{
    string ten;
    string tinhTrang;
    long long giaTri;
};

// ===== A1: Đệ quy hiển thị =====
void A1(TaiSan *ds, int n, int i)
{
    if (i == n) return;

    cout << left << setw(20) << ds[i].ten
         << setw(15) << ds[i].tinhTrang
         << setw(15) << ds[i].giaTri << endl;

    A1(ds, n, i + 1);
}

// ===== Chia để trị tìm max =====
TaiSan timMax(TaiSan *ds, int l, int r)
{
    if (l == r) return ds[l];

    int m = (l + r) / 2;

    TaiSan a = timMax(ds, l, m);
    TaiSan b = timMax(ds, m + 1, r);

    return (a.giaTri > b.giaTri) ? a : b;
}

// ===== Hiển thị phương án =====
void show(TaiSan *ds, int *x, int n, int &dem)
{
    dem++;
    cout << "Phuong an " << dem << ":\n";

    for (int i = 0; i < n; i++)
    {
        cout << ds[i].ten
             << " -> Phong " << x[i] + 1 << endl;
    }
    cout << "----------------------\n";
}

// ===== Quay lui =====
void backtrack(int k, TaiSan *ds, int *used, int *x, int n, int &dem)
{
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            x[k] = i;
            used[i] = 1;

            if (k == n - 1)
                show(ds, x, n, dem);
            else
                backtrack(k + 1, ds, used, x, n, dem);

            used[i] = 0;
        }
    }
}

int main()
{
    int n = 6; // 6 ≤ n ≤ 20

    TaiSan *d = new TaiSan[n]{
        {"Laptop", "Moi", 15000000},
        {"Ban", "Cu", 2000000},
        {"Tu", "Moi", 5000000},
        {"DienThoai", "Moi", 10000000},
        {"Quat", "Hong", 500000},
        {"MayIn", "Cu", 3000000}
    };

    // ===== Danh sách ban đầu =====
    cout << "Danh sach ban dau:\n";
    cout << left << setw(20) << "Ten"
         << setw(15) << "Tinh trang"
         << setw(15) << "Gia tri" << endl;

    A1(d, n, 0);

    // ===== Sắp xếp =====
    sort(d, d + n, [](TaiSan a, TaiSan b)
    {
        return a.ten < b.ten;
    });

    cout << "\nDanh sach sau sap xep:\n";
    cout << left << setw(20) << "Ten"
         << setw(15) << "Tinh trang"
         << setw(15) << "Gia tri" << endl;

    A1(d, n, 0);

    // ===== Tìm max =====
    TaiSan maxTS = timMax(d, 0, n - 1);

    cout << "\nTai san co gia tri lon nhat:\n";
    cout << maxTS.ten << " - " << maxTS.giaTri << endl;

    // ===== Quay lui =====
    int *used = new int[n]{};
    int *x = new int[n]{};
    int dem = 0;

    cout << "\nCac phuong an xep vao phong:\n";
    backtrack(0, d, used, x, n, dem);

    cout << "\nTong so phuong an: " << dem << endl;

    return 0;
}
