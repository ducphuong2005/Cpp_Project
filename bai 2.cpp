#include <iostream>
#include<cmath>
using namespace std;
int nhap(int &n)
{
    cout<<"nhap gia tri cua n: ";
    cin>>n;
    while (n<=0)
    {
        cout<<"nhap lai gia tri n: ";
        cin>>n;
    }
}


int main()
{int m;
nhap(m);

}



