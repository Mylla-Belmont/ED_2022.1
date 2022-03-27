#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void imprimir(vector<int> nome_vetor){
    cout << "[";
    for (auto vetor : nome_vetor)
        cout << vetor << " ";
    cout << "]" << endl;
}

// vector<int> sozinhos(const vector<int>& fila) {
//     int size {(int) fila.size()};
//     vector<int> novo_vetor {};
//     return novo_vetor;  
// }

int main() {
    /*  MAP - MANIPULAÇÕES  */
    //imprimir(sozinhos({1, 3, 4, 3, -1, -3, -3}));
}