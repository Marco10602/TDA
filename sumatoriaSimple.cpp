#include <iostream>
#include <vector>

using namespace std;

int sumatoria(vector<int>& camino) {
    int sum = 0;

    for (size_t i = 0; i < camino.size(); i++) {
        sum = sum + camino[i];
    };
    return sum;
}

int main() {
    vector<int> unos = {1, -1, -1, -1};

    int resultado = sumatoria(unos);

    cout << resultado << endl;
    return 0;
}