#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void nhap (int &n, float *&a)
{
    cout << "nhap n: ";
    cin >> n;
    a = new float [n];
    for (int i=0; i<n; i++)
    {
        cout << "a["<<i<<"]= ";
        cin >> a[i];
    }
}

void xuat_file(int n, float *a)
{
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
	ofstream f("ABC2110.TXT", ios :: out);
	for (int i=0; i<n; i++)
		f << a[i] << " ";
	f.close();
}

void sap (int n, float *a)
{
	for(int i=0; i<n-1; i++)
	for(int j=i+1; j<n; j++)
		if(a[i]<a[j])
		{
			float tg =a[i];
			a[i]=a[j];
			a[j]=tg;
		}
}

void bosung (int n, float *a)
{
	sap(n,a);
	ofstream f("ABC2110.TXT", ios :: app);
	for (int i=0; i<n; i++)
		f << a[i] << " ";
        f.close();
}

int ktra (int n, float *a)
{
	float M=a[0];
	for (int i=0; i<n; i++)
		if(a[i]<M)
			M=a[i];
	cout << "\nSo nho nhat trong mang la: " << M << endl;
	int dem =0; 
	for (int i=0; i<n; i++)
		if (a[i]==M)
			dem ++;
	return dem;
}

void chen (int &n, float *a, float &x)
{
	cout << "nhap x: "; cin >> x;
	sap(n,a);
	if(a[0]<=x)
		cout << "day so khong co phan tu nao lon hon x.";
	else
	{
		int vt;
        for(int i = n - 1; i >= 0; i--)
            if(a[i] > x)
            {
                vt = i;
                break;
            }
        	for (int i=n-1; i>=vt; i--)
				a[i+1]=a[i];
			a[vt]=x;
			n++;
			cout << "mang sau khi chen: ";
   			for(int i=0; i<n; i++)
      			cout<<a[i]<<" ";
	} 
}

int main()
{
    int n;
    float *a, x;
    nhap(n,a);
    xuat_file(n,a);
    bosung(n,a);
    cout << "so phan tu bang min la: " << ktra(n,a) << endl;
    chen(n,a,x);
    return 0;
}
