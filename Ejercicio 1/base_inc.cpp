#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

string cambiandose_de_aula_dp(const vector<vector<int>>& aulas) {
    int n = aulas.size();
    int m = aulas[0].size();

    // Poda: si la cantidad de pasos (n + m - 1) es impar, no puede haber suma 0
    if ((n + m - 1) % 2 != 0){
        return "No";
    } 

    // Inicializar DP
    int maxSuma = n + m - 1;
    vector<vector<unordered_set<int>>> dp(n, vector<unordered_set<int>>(m));
    dp[0][0].insert(aulas[0][0]);


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            for (int sum : dp[i][j]) {
                if (i + 1 < n) {
                    int nextSum = sum + aulas[i + 1][j];
                    if (abs(nextSum) <= maxSuma) {
                        dp[i + 1][j].insert(nextSum);
                    }
                }

                if (j + 1 < m) {
                    int nextSum = sum + aulas[i][j + 1];
                    if (abs(nextSum) <= maxSuma) {
                        dp[i][j + 1].insert(nextSum);
                    }
                }
            }
        }
    }

    // Verificar si hay un camino con suma 0 en la esquina inferior derecha
    return dp[n - 1][m - 1].count(0) ? "Yes" : "No";
}

int main() {
    int cp; // cantidad de casos de prueba
    cin >> cp;

    while (cp--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> aulas(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> aulas[i][j];

        cout << cambiandose_de_aula_dp(aulas) << endl;
    }

    return 0;
}