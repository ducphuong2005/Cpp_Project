#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cout<<"Nhap n\n";
    cin>>n;
        for(int m=1; m<=n; m++)
        {int d=0;
            if(m==1)
        cout<<"1"<<" ";
        if(m>1)
        {
            for(int n=2; n<= sqrt(m); n++)
            { 
                if(m%n==0)
                d++;
            }
            if(d==0)
                cout << m <<" ";
        }
    
    }
    return 0;

}
