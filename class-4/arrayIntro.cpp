#include<bits/stdc++.h>
using namespace std;

int main() {

    int arr[5] = {4, 2, 1, 3, 5};

    cout << *arr << endl;

    for (int i = 0; i < 5; i++) {
        cout << *(arr + i) << endl;
    }
}