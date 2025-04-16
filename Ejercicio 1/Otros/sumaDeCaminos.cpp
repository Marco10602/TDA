#include <iostream>
#include <vector>

using namespace std;

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

}


int main() {
    vector<vector<int>> grilla = {
        {1, -1, -1, -1},
        {-1, 1, 1, -1},
        {1, 1, 1, -1}
    };

    vector<int> resultados = sumaDeCaminos(grilla);

    for (int valor : resultados) {
        std::cout << valor << " ";
    }

    cout << endl;
    return 0;
}

