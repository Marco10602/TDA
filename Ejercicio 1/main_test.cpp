#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>

//Llamada
int main() {
    vector< vector<int>> matriz {
        {1,-1,-1,-1},
        {-1,1,1,-1},
        {1,1,1,-1},
    };
 
    memo.assign(3, vector<int>(4, -1));
    
    cout << cambiandose_de_aula(matriz) << endl;
    return 0;
}

int main() {
    vector< vector<int>> matriz {
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,-1},
        {1,1,1,-1},
        {1,1,1,-1},
        {1,1,1,-1},
        {1,1,1,-1},
        {1,1,1,-1},
    };
 
    memo.assign(9, vector<int>(4, -1));
    
    cout << cambiandose_de_aula(matriz) << endl;
    return 0;
}