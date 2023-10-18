#include <iostream>

using namespace std;


unsigned long bell(unsigned long n){
    unsigned long bell[n+1][n+1];
    bell[0][0] = 1;
    for (unsigned long i=1; i<=n; i++){
        bell[i][0] = bell[i-1][i-1];

        for (unsigned long j=1; j<=i; j++){
            bell[i][j] = bell[i-1][j-1] + bell[i][j-1];
        }
    }
    return bell[n][0];
}