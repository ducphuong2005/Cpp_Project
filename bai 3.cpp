#include<iostream>
#include<cmath>
using namespace std;
int main()
{
int a[5] = {40, 95, 50, 20,7};

for (int i=0; i<5; i++)

     for(int j=i+1;j<5;j++)

          if (a[i]<a[j]) swap(a[i],a[j]);

}
