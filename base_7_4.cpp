#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <unordered_set>

using namespace std;

string cambiandose_de_aula (const vector<vector<int>>& aulas) { //const -> solo me permite leer la matriz
    
    int n = aulas.size();
    int m = aulas[0].size();

    //Poda: Unica fila
    if (n == 1) {
        if (sumatoria(aulas[0])==0) {
            return "Yes";
        } else {
            return "No";
        }
    }
    
    //Poda: Longitud par de soluciones
    if ((n+m-1)%2 != 0) {
        return "No";
    }

    vector<vector<int>> dp;
    


}


//Llamada
int main() {
    int cp; // número de casos de prueba
    cin >> cp;

    for (int k = 0; k < cp; k++) {
        int n, m;
        cin >> n >> m; //n = filas, m = columnas

        vector< vector<int>> matriz(n,vector<int>(m));

        // Leer la matriz
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matriz[i][j];
            }
        }

        cout << cambiandose_de_aula(matriz) << endl;
    }

    return 0;
}