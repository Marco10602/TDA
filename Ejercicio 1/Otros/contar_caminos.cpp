#include <iostream>
#include <vector>

int contarCaminos(int n, int m) {
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

    // Primer fila y columna tienen solo un camino
    for (int i = 0; i < n; ++i) dp[i][0] = 1;
    for (int j = 0; j < m; ++j) dp[0][j] = 1;
    // dp[0]

    // Llenar el resto de la tabla
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n-1][m-1]; // Total de caminos al destino
}

//Va llenando una tabla que cada casilla dice cuanto caminos llegan

int main() {
    int n = 3, m = 4; // Tamaño de tu grilla
    std::cout << "Cantidad de caminos posibles: " << contarCaminos(n, m) << std::endl;
    return 0;
}
