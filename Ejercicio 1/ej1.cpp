#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

int sumatoria(vector<int> camino) {
    int sum = 0;

    for (size_t i = 0; i < camino.size(); i++) {
        sum = sum + camino[i];
    };
    return sum;
}

void buscarCamino(int i, int j, int n, int m, int sumActual, vector<int>& caminoActual, const vector<vector<int>>& aulas, bool& terminado) {
    
    if (terminado) return;

    // int caminoCorto = n + m - 1;
    int pasosRestantes = (n - 1 - i) + (m - 1 - j);

    // Sumar el valor actual
    sumActual += aulas[i][j];
    caminoActual.push_back(aulas[i][j]);

    //Poda: por falta de pasos para resolver --> no me resuelve mucho
    if (abs(sumActual) > pasosRestantes) {
        caminoActual.pop_back();
        return;
    }

    // Caso base: llegamos al final
    if (i == n - 1 && j == m - 1) {
        if (sumActual == 0) {
            terminado = true;
        }
    } else {
        // Mover hacia abajo
        if (i + 1 < n)
            buscarCamino(i + 1, j, n, m, sumActual, caminoActual, aulas, terminado);

        // Mover hacia la derecha
        if (j + 1 < m)
            buscarCamino(i, j + 1, n, m, sumActual, caminoActual, aulas, terminado);
    }

    // Retroceso
    caminoActual.pop_back();
}


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

    /* 1)Busco caminos: n=aulas.size() and m=aulas[0].size() */
    vector<int> caminoActual;               //Importante
    bool control = false;
    int sumaInicial = 0;
    buscarCamino(0,0,n,m, sumaInicial, caminoActual, aulas, control); 

    /* 2)Tengo que ver que haya una suma que de 0 */

    if (control){
        return "Yes";
    } else {
        return "No";
    }
    
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