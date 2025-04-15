#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

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
    
    //Recorro s2
    for (int i = 0; i < e.length(); i++) { //baso todo en el largo de s1
        if (r[i] == '+') {
            mas--;
        } else if (r[i] == '-') {
            menos--;
        } else if (r[i] == '?'){ //cubro caso que no sea '?'
            inc++;
        }
    }

    double res = 1/(pow(2,inc));

    if (mas == 0 and menos == 0 and inc == 0) {
        return 1;
    } else if (mas != 0 and menos != 0 ) {
        if (inc == 0) {
             return 0;
        } else if (abs(mas)+abs(menos) == inc) {
            return res;
        } else {
            return 0;
        }
    } else if (inc != 0 and menos != 0) {
        return res;
    } else {
        return res;
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

