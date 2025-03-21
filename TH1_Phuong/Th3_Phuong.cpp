#include<iostream>

using namespace std;

int sumDivideConquer(int a[], int l, int r) {
    if (l == r) return a[l];
    int m = (l + r) / 2;
    int sum1 = sumDivideConquer(a, l, m);
    int sum2 = sumDivideConquer(a, m + 1, r);
    return sum1 + sum2;
}
int main()
{
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin>>n;
    int a[n];
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Tong cac phan tu cua mang la: " << sumDivideConquer(a, 0, n - 1);
    return 0;
}