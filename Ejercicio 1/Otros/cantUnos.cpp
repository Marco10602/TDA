#include <iostream>
#include <vector>

bool cantUnos(int n, int m, const vector<vector<int>>& aulas) {
    int uno = 0;
    int mUno = 0;
    int caminoMin = n + m - 1;
    bool unoM = false;
    bool mUnoM = false;

    for (int i = 0; i < aulas.size(); i++) {

        for (int k = 0; k < count; k++) {
            if (aulas[i][k] == 1) {
                uno++;
                
            } else {
                mUno++;
            }
        }
    }

    if ( uno >= caminoMin/2 and mUno >= caminoMin/2 ) {
        return true;
    }
    return false;
}
