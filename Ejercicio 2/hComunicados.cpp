#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

//Combinatorio
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
//Fin combinatorio

double hiloComu(string e, string r) {
    int mas = 0;
    int menos = 0;
    int inc = 0;

    //Recorro s1 (Solo puede haber '+' o '-')
    for (int i = 0; i < e.length(); i++) {
        if (e[i] == '+') {
            mas++;
        } else if (e[i] == '-'){
            menos++;
        }
    }
    
    //Recorro s2 (Solo puede haber '+' o '-' o '?')
    for (int i = 0; i < e.length(); i++) { //baso todo en el largo de s1
        if (r[i] == '+') {
            mas--;
        } else if (r[i] == '-') {
            menos--;
        } else if (r[i] == '?'){ //cubro caso que no sea '?'
            inc++;
        }
    }

    //Hasta aca, se tiene cual es la diferencia entre s1 - s2

    //Casos
    if (mas == 0 and menos == 0) {                  //Caso igual - misma cant de signos
        return 1;
    }

    if (mas < 0 or menos < 0) {                     //No puede pasar que haya mas signos de un tipo abajo que arriba
        return 0;
    }

    if (inc != mas + menos ) {                      //Si la suma de los signos faltantes supera los comodines
        return 0;
    }

    if (inc == mas + menos) {                       //Cuando '+' y '-' son distinto de cero
        float cf = combinatorio(inc, mas);  //Casos correctos
        float ct = pow(2,inc);              //Casos totales
        
        return (cf/ct);
    }
    
}

int main() {
    string s1;
    string s2;
    
    cin >> s1;
    cin >> s2;
    
    cout << fixed << setprecision(10) << hiloComu(s1,s2) << endl;
    return 0;
}