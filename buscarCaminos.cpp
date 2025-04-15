#include <iostream>
#include <vector>

using namespace std;

void buscarCaminos(int i, int j, int n, int m, 
                    vector<int>& caminoActual, 
                    vector<vector<int>>& todosLosCaminos,
                    const vector<vector<int>>& aulas) {
    
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
}


int main() {
    int n = 3, m = 4;

    vector<vector<int>> grilla = {
        {1, -1, -1, -1},
        {-1, 1, 1, -1},
        {1, 1, 1, -1}
    };

    vector<int> caminoActual;               //Importante
    vector<vector<int>> todosLosCaminos;    //Importante

    buscarCaminos(0, 0, n, m, caminoActual, todosLosCaminos, grilla);


    // Mostrar los caminos
    cout << "Cantidad de caminos: " << todosLosCaminos.size() << endl;
    for (const auto& fila : todosLosCaminos) {
        for (int valor : fila) {
            std::cout << valor << " ";
        }
        std::cout << std::endl; // Salto de línea por fila
    }
    return 0;
}
