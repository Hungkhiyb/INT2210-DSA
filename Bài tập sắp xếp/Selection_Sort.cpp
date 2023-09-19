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
    for(int i = 0; i < n - 1; i++){
        int _min = a[i];
        int index = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < _min){
                _min = a[j];
                index = j;
            }
        }
        swap(a[i], a[index]);
    }
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    return 0;
}
