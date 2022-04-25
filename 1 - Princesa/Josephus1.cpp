#include <iostream>
#include <vector>

using namespace std;

void imprimir_vetor(vector<int> circulo, int inicio) {
    for (int i {0}; i < (int) circulo.size(); i++)
        cout << circulo[i] << (i == inicio ? "> " : " ");
    cout << endl;
}

void remocao(vector<int> circulo, int inicio, int size) {
    for (int i {0}; i < size; i++) {
        imprimir_vetor(circulo, inicio);
        inicio = (inicio + 1) % (int) circulo.size();
        circulo.erase(circulo.begin() + inicio);
        inicio = inicio % (int) circulo.size();
    }
}

int main() {
    int  inicio {0}, size {0};
    cout << "Digite o tamanho e o inicio:" << endl;
    cin >> size  >> inicio;
    vector<int> circulo (size);

    for (int i {0}; i < size; i++)
        circulo[i] = i+1;

    remocao(circulo, (inicio-1), size);
}