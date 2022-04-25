#include <iostream>
#include <vector>

using namespace std;

void imprimir_vetor(vector<int> circulo, int inicio) {
    for (int i {0}; i < (int) circulo.size(); i++) {
            if (circulo[i] != 0)
                cout << " " << i+1;
            if (i == inicio)
                cout << ">";
    } cout << endl;
}   

int procurar_vivos(vector<int>& circulo, int inicio) {
    int next = (inicio + 1) % (int) circulo.size();
    while(circulo[next] == 0)
        next = (next + 1) % (int) circulo.size();
    return next;
}

void marcacao(vector<int> circulo, int inicio, int size) {
    for (int i {0}; i < size; i++) {
        imprimir_vetor(circulo, inicio);
        int next {procurar_vivos(circulo, inicio)};
        circulo[next] = 0;
        inicio = procurar_vivos(circulo, next);
    }
}

int main() {
    int  inicio {0}, size {0};
    cout << "Digite o tamanho e o inicio:" << endl;
    cin >> size  >> inicio;
    vector<int> circulo(size, true);

    marcacao(circulo, (inicio-1), size);
}