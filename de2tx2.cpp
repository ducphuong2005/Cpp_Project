#include <iostream>
#include <fstream>
using namespace std;

void nhap(int &m, int *&b)
{
    cout << "nhap m: ";
    cin >> m;
    while (m < 3)
    {
        cout << "nhap lai m>3, m: ";
        cin >> m;
    }
    b = new int[m];
    for (int i = 0; i < m; i++)
    {
        cout << "b[" << i << "]= ";
        cin >> b[i];
    }
    for (int i = 0; i < m; i++)
        cout << b[i] << " ";
}

float tong(int m, int *b, int &x)
{
    cout << "\nnhap x: ";
    cin >> x;
    cout << "Tong cac so >=x la: ";
    float T = 0;
    for (int i = 0; i < m; i++)
    {
        if (b[i] >= x)
            T += b[i];
    }
    return T;
}

int MIN(int m, int *b)
{
    int min = b[0];
    for (int i = 0; i < m; i++)
        if (min > b[i])
            min = b[i];

    int dem = 0;
    for (int i = 0; i < m; i++)
    {
        if (b[i] == min)
            dem++;
    }
    return dem;
}
void check(int *b, int n)
{
    int k = 1;
    int min = b[0];
    for (int i = 0; i < n; i++)
        if (min > b[i])
            min = b[i];

    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == min)
        {
            f = i;
            break;
        }
    }
    for (int i = f; i < n; i++)
    {
        if (b[i] == min && b[i + 1] == min)
            k++;

        else

            break;
    }
    
    if (k == MIN(n, b))
        cout << "\nMang hop le";
    else
        cout << "\nMang khong hop le";
}
void chen(int m, int *b, int &k, int &x)
{
    cout << "nhap 0<=k<=m, k: "; cin >> k;
    cout << "nhap x: "; cin >> x;
    for (int i=m; i>k; i--)
    {
        b[i]=b[i-1];
    }
    b[k]=x;
    m++;
    ofstream f("chen.txt", ios::out);
    for(int i=0; i<m; i++)
    {
        f<< b[i] << " ";
    }
    f.close();
}
int main()
{
    int m, *b, x,k;
    nhap(m, b);
    cout << tong(m, b, x) << endl;
    cout << "So phan tu nho nhat trong mang: " << MIN(m, b);
    check(b, m);
    chen(m,b,k,x);
}
