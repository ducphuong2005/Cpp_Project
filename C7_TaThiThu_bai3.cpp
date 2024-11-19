#include<iostream>
using namespace std;
int main(){
    int n, m; 
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
    cin >> a[i];
    for(int i=0; i<n; i++){
        if(a[i]<0)
        a[i]=a[i]*(-1)+3;
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j]){
                m = a[i];
                a[i] = a[j];
                a[j] = m;        
            }
        }
    }
    for(int i=0; i<n; i++)
    cout << a[i] << " ";
    return 0;
}
