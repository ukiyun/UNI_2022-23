#include <iostream>
#include <climits>

using namespace std;

int max(const int a[], int n){
    int maximum = INT_MIN;
    for (int i =0; i<n; i++){
        if(a[i]>maximum){
            maximum = a[i];
        }
    }

    return maximum;
}