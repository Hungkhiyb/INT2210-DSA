#include <iostream>

using namespace std;

void quick_sort(int a[], int low, int high){
    if(low == high)
        return;
    int pivot = high;
    high--;
    while(low < high){
        if(a[low] > a[pivot] && a[high] < a[pivot])
            swap(a[low], a[high]);
        if(a[low] < a[pivot])
            low++;
        else if(a[high] > a[pivot])
            high--;
    }

    if(low == high && a[pivot] < a[low]){
        swap(a[low], a[pivot]);
        quick_sort(a, 0, low - 1);
        quick_sort(a + low + 1, 0, pivot - low - 1);
    }
    else
        quick_sort(a, 0, low);

    return;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    quick_sort(a, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';

    return 0;
}
