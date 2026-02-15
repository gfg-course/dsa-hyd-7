#include<bits/stdc++.h>
using namespace std;

int main() {

    int arr[5] = {5, 4, 1, 2, 3};

    cout << *arr << endl;

    for (int i = 0; i < 5; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}
