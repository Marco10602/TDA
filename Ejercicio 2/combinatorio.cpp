#include <iostream>
#include <vector>

using namespace std;

int factorial(int n) {
    vector<long long> dp(n + 1);
    dp[0] = 1; // Caso base

    for (int i = 1; i <= n; ++i) {
        dp[i] = i * dp[i - 1]; // Transición
    }

    return dp[n];
}

int combinatorio(int m, int k) {
    return factorial(m) / (factorial(k) * factorial(m - k));
}

int main() {
    while (true) {

        int m;
        int k;
        cin >> m;
        cin >> k;
        std::cout << combinatorio(m, k) << std::endl;
        return 0;
    }
}