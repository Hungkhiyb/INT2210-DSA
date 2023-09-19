#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Size: ";
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++){
        int j = i - 1;
        while(a[j + 1] < a[j]){
            swap(a[j + 1], a[j]);
            j--;
        }
    }
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    return 0;
}
