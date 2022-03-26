#include <iostream>]
#include <vector>

using namespace std;

void imprimir_vetor(vector<bool> circulo, int inicio) {

}

int procurar_vivos(vector<bool> circulo, int inicio) {
    
}

void marcacao(vector<bool> circulo, int inicio, int size) {
    for (int i {0}; i < size; i++) {
        imprimir_vetor(circulo, inicio);
        int morre {procurar_vivos(circulo, inicio)};
        circulo[morre] = false;
        inicio = procurar_vivos(circulo, morre);
    }
}

int main() {
    int  inicio {0}, size {0};
    cout << "Digite o tamanho e o inicio:" << endl;
    cin >> size  >> inicio;
    vector<bool>  circulo(size, true);

    marcacao(circulo, (inicio-1), size);
}