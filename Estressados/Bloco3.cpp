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

/*int size {(int) fila.size()};
    vector<int> novo_vetor {}, aux {fila};
    for (int i {0}; i < size; i++)
        for (int j {i}; j < size; j++){
            novo_vetor.push_back((abs(fila[i]) == abs(aux[j])) ? 0 : fila[i]);
            aux[j] = 0;
        }
    vector<int> vetor = exclusivos(novo_vetor);    */

vector<int> sozinhos(const vector<int>& fila) {
    return;  
}

int main() {
    /*  MAP - MANIPULAÇÕES  */
    imprimir(sozinhos({1, 3, 4, 3, -1, -3, -3}));
}