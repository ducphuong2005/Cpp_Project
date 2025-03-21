#include<iostream>

using namespace std;

int SelectionSort(int a[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(a[i], a[min]);
        }
    }
}
int main()
{
    int a[] = { 34, 14, 24, 54, 84, 64, 94, 74, 4 };
    int n = 9;
    SelectionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}