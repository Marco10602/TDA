#include <iostream>
#include <vector>
using namespace std;

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

        // Aquí puedes procesar la grilla como necesites para tu problema
        // Por ejemplo, imprimirla:
        cout << "Grilla leida:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
