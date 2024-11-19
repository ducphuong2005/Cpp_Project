#include <iostream>
using namespace std;

int main()
{
    int n,j,T;
    cout << "n=";cin>>n;
    j = 0; T = 0;
    for(int i =2;i<=n;i++)
    {
        int dem = 0;
        for ( int j=2;j<i;j++)
            if(i%j==0) 
                dem++;
        if (dem==0)
            T=T+i;

    }
    cout<<"T = " <<T;
}