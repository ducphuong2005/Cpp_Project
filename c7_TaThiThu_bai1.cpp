#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n, k, s=0, min, max; 
    float tb;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
    cin >> a[i];
    max=a[0];
    min=a[0];
    cin >> k;
    int b[n+1];
    for(int i=0; i<=n; i++){
        if(i==0){
            b[0]=k;
        }
        else{
            b[i]=a[i-1];
        }
            cout << b[i] << " ";
    }
    cout << endl;
    for(int i=0; i<n; i++){
        if(min>a[i]){
            min=a[i];
            cout << "Min la: " << min << endl;
        }
        if(a[i]>max){
            max=a[i];
            cout << "Max la: " << max << endl;
        }
    }
    for(int i=0; i<n; i++){
        s+=a[i];
    }
    tb=(float)s/n;
    cout << "Medium score la: " << tb;
    return 0;
}