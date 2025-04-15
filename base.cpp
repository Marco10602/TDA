#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

void buscarCaminos(int i, int j, int n, int m, vector<int>& caminoActual, vector<vector<int>>& todosLosCaminos, const vector<vector<int>>& aulas) {

    // Agregar la celda actual al camino
    caminoActual.push_back(aulas[i][j]);

    // Si llegamos al final, guardar el camino
    if (i == n - 1 && j == m - 1) {
        todosLosCaminos.push_back(caminoActual);
    } else {
        // Mover hacia abajo
        if (i + 1 < n)
            buscarCaminos(i + 1, j, n, m, caminoActual, todosLosCaminos, aulas);

        // Mover hacia la derecha
        if (j + 1 < m)
            buscarCaminos(i, j + 1, n, m, caminoActual, todosLosCaminos, aulas);
    }

    // Volver atrás
    caminoActual.pop_back();
};

vector<int> sumaDeCaminos(vector<vector<int>>& todosLosCaminos) {
    
    vector<int> res;
    for (size_t i = 0; i < todosLosCaminos.size(); i++) {
        
        int sum = 0;

        for (size_t k = 0; k < todosLosCaminos[i].size(); k++) {
            sum = sum + todosLosCaminos[i][k];
        }

        res.push_back(sum);

    }

    return res;

};
bool pertenece(vector<int> lista, int n) {

    for (size_t i = 0; i < lista.size(); i++) {
        if (lista[i] == n) {
           return true;
        }
    }
    return false;
};
//Funciones que necesito

string cambiandose_de_aula (const vector<vector<int>>& aulas) { //const -> solo me permite leer la matriz
    
    //Poda: Longitud par de soluciones
    if ((aulas.size()+aulas[0].size()-1)%2!=0) {
        return "No";
    }

    /* 1)Busco caminos: n=aulas.size() and m=aulas[0].size() */
    vector<int> caminoActual;               //Importante
    vector<vector<int>> todosLosCaminos;    //Importante
    buscarCaminos(0,0,aulas.size(),aulas[0].size(), caminoActual,todosLosCaminos,aulas); //todosLosCaminos

    /* 2)Sumo los caminos */
    vector<int> res = sumaDeCaminos(todosLosCaminos);

    /* 3)Tengo que ver que haya una suma que de 0 */

    if (pertenece(res,0)) {
        return "Yes";
    } else {
        return "No";
    }
    
}

//Llamada

int main() {
    int cp; // número de casos de prueba
    cin >> cp;

    while (cp--) {
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