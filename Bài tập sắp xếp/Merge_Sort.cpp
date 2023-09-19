#include <iostream>

using namespace std;

int* merge(int a[], int b[], int size_a, int size_b){
    int c[size_a + size_b];
    int tmp1 = 0;
    int tmp2 = 0;
    while(tmp1 < size_a && tmp2 <size_b){
        if(a[tmp1] < b[tmp2]){
            c[tmp1 + tmp2] = a[tmp1];
            tmp1++;
        }
        else{
            c[tmp1 + tmp2] = b[tmp2];
            tmp2++;
        }
    }
    while(tmp1 < size_a){
        c[tmp1 + tmp2] = a[tmp1];
        tmp1++;
    }
    while(tmp2 <size_b){
        c[tmp1 + tmp2] = b[tmp2];
        tmp2++;
    }

    for(int i = 0; i < size_a + size_b; i++){
        a[i] = c[i];
    }
    return a;
}


int* merge_sort(int a[], int size){
    if(size == 1)
        return a;
    int* array_one = a;
    int* array_two = a + size / 2;

    array_one = merge_sort(array_one, size / 2);
    array_two = merge_sort(array_two, size - size / 2);

    return merge(array_one, array_two, size / 2, size - size / 2);

}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    merge_sort(a, n);

    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    return 0;
}
