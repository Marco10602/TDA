#include <iostream>
#include <vector>

using namespace std;

void buscarCaminos(int i, int j, int n, int m,
                   vector<pair<int, int>>& caminoActual,
                   vector<vector<pair<int, int>>>& todosLosCaminos) {
    // Agregar la celda actual al camino
    caminoActual.push_back({i, j});

    // Si llegamos al final, guardar el camino
    if (i == n - 1 && j == m - 1) {
        todosLosCaminos.push_back(caminoActual);
    } else {
        // Mover hacia abajo
        if (i + 1 < n)
            buscarCaminos(i + 1, j, n, m, caminoActual, todosLosCaminos);

        // Mover hacia la derecha
        if (j + 1 < m)
            buscarCaminos(i, j + 1, n, m, caminoActual, todosLosCaminos);
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

    vector<pair<int, int>> caminoActual;
    vector<vector<pair<int, int>>> todosLosCaminos;

    buscarCaminos(0, 0, n, m, caminoActual, todosLosCaminos);

    // Mostrar los caminos
    cout << "Cantidad de caminos: " << todosLosCaminos.size() << endl;
    for (const auto& camino : todosLosCaminos) {
        for (const auto& pos : camino) {
            cout << "(" << pos.first << "," << pos.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
