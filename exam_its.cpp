#include <iostream>
#include <math.h>
using namespace std;

int A1(int n)
{
    cout<<"Nhap n: "; cin>>n;
    while (n<=0)
    {
        cout<<"Nhap lai n: "; cin>>n;
    }
    int s=1;
    for (int i=1; i<=n; i++)
    {
       s*=i;
    }
    return s;
}
float A2(float &x, int n)
{

}