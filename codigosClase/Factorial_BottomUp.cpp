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

int main() {
    int n = 10;
    cout << n << "! es: " << factorial(n) << endl;

    for (int i = 0; i <= 10; ++i) {
        cout << i << "! = " << factorial(i) << endl;
    }
    return 0;
}
