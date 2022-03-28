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

int mais_ocorrencia(const vector<int>& fila) {
    int cont {0}, size {(int) fila.size()}; 
    for (int i {0}; i < size; i++) {
        int aux {1};
        for (int j {i+1}; j < size; j++) 
            if (abs(fila[i]) == abs(fila[j]))
                aux = aux + 1;
        if (aux > cont)
            cont = aux;
    }
    return cont;
}         

// vector<int> mais_recorrente(const vector<int>& fila) {
//     int size {(int) fila.size()}, cont {mais_ocorrencia(fila)}; 
//     vector<int> recorrentes {};
//     for (int i {0}; i < size; i++) {
//         int aux {1};
//         for (int j {i+1}; j < size; j++) 
//             if (abs(fila[i]) == abs(fila[j]))
//                 aux = aux + 1;
//         if (aux == cont)
//             recorrentes.push_back(abs(fila[i]));
//     }
//     return recorrentes;
// }

int briga(const vector<int>& fila) {
    int size {(int) fila.size()}, cont {0};
    for (int i {1}; i < size-1; i++)
        if (abs(fila[i]) > 50 && abs(fila[i-1]) > 30 && abs(fila[i+1]) > 30)
            cont = cont + 1;
    return cont;
}

vector<int> apaziguador(const vector<int>& fila) {
    int size {(int) fila.size()};
    vector<int> calmos {};
    for (int i {0}; i < size; i++)
        if (abs(fila[i]) > 80 && (abs(fila[i-1]) < 10 || abs(fila[i+1]) < 10))
            calmos.push_back(i);
    return calmos;
}

int main() {
    /*  MAP - MANIPULAÇÕES  */
    //imprimir(sozinhos({1, 3, 4, 3, -1, -3, -3}));
    cout << mais_ocorrencia({1, 3, 4, 5, -1, -5, -5}) << endl;
    //imprimir(mais_recorrente({1, 3, 4, 3, -1, -3, -3}));
    /*  APROXIMIDADE  */
    cout << briga({50, 98, 31, -51, 31, -99}) << endl;
    imprimir(apaziguador({83, -4, 65, 8, -99, 12}));
}