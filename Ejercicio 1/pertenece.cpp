#include <iostream>
#include <vector>
using namespace std;

bool pertenece(vector<int> lista, int n) {

    for (size_t i = 0; i < lista.size(); i++) {
        if (lista[i] == n) {
           return true;
        }
    }
    return false;
}

int main() {
    vector<int> numeros = {3, 7, 2, 9};

    int buscado = 6;

    cout << pertenece(numeros, buscado) << endl;
    return 0;
}
