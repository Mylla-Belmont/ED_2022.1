#include <iostream>

using namespace std;

void imprimir_vetor(int circulo[], int size, int inicio) {
    cout << "[";
    for (int i {0}; i < size; i++) {
        if (circulo[i] != 0)
            cout << " " << circulo[i];
        if (i == inicio)
            cout << ">";
    }
    cout << " ]" << endl;
}

int tirar_mortos(int circulo[], int inicio, int next) {

}

int procurar_vivo (int circulo[], int inicio, int size) {
    int next = (inicio + 1) % size;
    while(circulo[next] == 0)
        next = (next + 1) % size;
    return next;
}

void remocao(int circulo[], int inicio, int size) {
    for (int i {0}; i < size; i++) {
        imprimir_vetor(circulo, size, inicio);
        int next {procurar_vivo(circulo, inicio, size)};
        tirar_mortos(circulo, inicio, next);
        inicio = procurar_vivo(circulo, next, size);
    }
}

int main() {
    int  inicio {0}, size {0};
    cout << "Digite o tamanho e o inicio:" << endl;
    cin >> size  >> inicio;
    int  circulo[size] {};

    for (int i {0}; i < size; i++)
        circulo[i] = i+1;
    
    remocao(circulo, (inicio-1), size);
}