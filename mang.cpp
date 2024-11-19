#include<iostream>
#include<fstream>
#include<math.h>
1

using namespace std;

void nhap (int &n, float *a)
{
    cout << "nhap n: "; cin >>n;
    while(n<=0 || n>=30)
        cin>>n;
    for (int i=0; i<n; i++)
    {
    cout << "a["<<i<<"]= ";
    cin >> a[i];
    }
}

void luufile (int n, float *a)
{
    ofstream f("BT2.txt", ios::out);
    for(int i=0; i<n; i++)
        f << a[i] << " ";
    f.close();
}

void sapxep (int n, float *a)
{
    ofstream f("BT2.txt",ios::app);
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
            if(a[i]<a[j])
                swap(a[i],a[j]);
    }
    
    f<<"mang giam dan";
    for (int i=0; i<n; i++)
        
        f<<a[i]<<" ";
        f.close();
}
void MAX2 (int n, float *a)
{
    sapxep(n,a);
    for (int i=n-2; i>=0; i--)
        if(a[i]<a[n-1])
     cout<<"Gia tri lon thu hai la: "<<a[i]<<endl;

}
void xuat (int n, float *a)
{
    for (int i=0; i<n; i++)
        cout << a[i] << " ";
}

int main()
{
    int n; float *a;
    a = new float [n];
    nhap(n,a);
    luufile(n,a);
    sapxep(n,a);
    xuat (n,a);
    MAX2(n,a);

}