#include <iostream>

using namespace std;

void nhap(int &m, int *&b)
{
    cout << "nhap m: "; cin >> m;
    while(m<3)
    {
        cout << "nhap lai m>3, m: ";
        cin >> m;
    }
    b = new int [m];
    for (int i=0; i<m; i++)
    {
        cout << "b["<<i<<"]= ";
        cin >> b[i];
    }
    for (int i=0; i<m; i++)
        cout << b[i] << " ";
}

float tong (int m, int *b, int &x)
{
    cout << "\nnhap x: "; cin >> x;
    cout<<"Tong cac so >=x la: ";
    float T=0;
    for (int i=0; i<m; i++)
    {
        if(b[i]>=x)
            T+=b[i];
    }
    return T;
}

int MIN (int m, int *b)
{   int min=b[0];
    for (int i=0; i<m; i++)
    if(min>b[i])
        min=b[i];

    int dem=0;
    for(int i=0; i<m; i++)
    {
        if (b[i]==min)
            dem++;
    }
    return dem;
}
void check(int  *b, int n)
{
    int k=0;
    for(int i=1; i<n; i++)
    {
        if(b[i]<b[k])
        {
            if(i!=k+1)
            cout<<"\nMang khong hop le";
            k=i;
        }

    }
    cout<<"\nMang. hop le";

}
int main()
{
    int m, *b, x;
    nhap(m,b);
    cout <<tong(m,b,x)<< endl;
    cout << "So phan tu nho nhat trong mang: "<<MIN(m,b);
    return 0;
}
