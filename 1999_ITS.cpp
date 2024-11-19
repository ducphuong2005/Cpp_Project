#include <iostream>
#include <fstream>

using namespace std;
void nhap(int &n, int *&a)
{
    cout << "Nhap so phan tu cua day so A: ";
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
    }
}
void xuat(int n, int *a)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    ofstream ghi_tep("ABC2017.TXT", ios::out);
    for (int i = 0; i < n; i++)
    {
        ghi_tep << a[i] << " ";
    }
    ghi_tep << endl;
    ghi_tep.close();
}
void xuat_bosung(int n, int *a)
{
    int tg;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
        }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    ofstream ghi_tep("ABC2017.TXT", ios ::app);
    for (int i = 0; i < n; i++)
        ghi_tep << a[i] << " ";
    ghi_tep.close();
}
void so_min(int n, int *a)
{
    int m = a[0], d = 0;
    for (int i = 0; i < n; i++)
        if (m > a[i])
            m = a[i];
    cout << m;
    for (int i = 0; i < n; i++)
        if (a[i] == m)
            d++;
    cout << "\nSo cac phan tu nho nhat trong day la: " << d;
}
void chen(int n, int *b)
{
    int x, l;
    cout << "\nNhap so x: ";
    cin >> x;
    for (int i = 0; i < n; i++)
       { if (b[i] > x)
            {
                l = i;
                break;
            }
       }
       cout<<"Vi tri phan tu dau tien lon hon x la: "<<l<<endl;
    for(int i=0; i<l; i++)
    b[i]=b[i+1];
    b[l]=x;
    cout<<"Day so A sau khi chen la: ";
    for(int i=0; i<n; i++)
    cout<<b[i]<<" ";
}

int main()
{
    int n, *a;
    nhap(n, a);
     int *b = new int[n];
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    xuat(n, a);
    xuat_bosung(n, a);
    so_min(n, a);
    chen (n,b);
}