#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using vet = vector<int>;

void imprimir_vetor(vet circulo, int inicio) {
    for (int i {0}; i < (int) circulo.size(); i++)
        cout << circulo[i] << (i == inicio ? "> " : " ");
    cout << endl;
}   

void matar(vet circulo, int E, int F) {
    for (int i {0}; i < (int) circulo.size(); i++) {
        imprimir_vetor(circulo, E);
        if(F > 0)

    }
}

int main(){
    int N { 0 }, E { 0 }, F { 0 };
    ifstream arq("input.txt");

    arq >> N >> E >> F;
    vet circulo(N);

    for (int i {0}; i < N; i++) {
        if (F < 0)
            circulo[i] = (i % 2 == 0 ? -1*(i+1) :  i+1);
        if (F > 0)
            circulo[i] = (i % 2 != 0 ? -1*(i+1) :  i+1);
    }

    matar(circulo, E, F);
}