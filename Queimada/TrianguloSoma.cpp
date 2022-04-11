#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void imprimir(vector<int> vetor) {
    for(int vet : vetor)
        cout << " "<< vet;
    cout << endl;
}

void triangulo(vector<int> vet, int size) {
    vector<int> aux;
    if (size != 0) {
        for (int i = 0; i < size; i++)
            aux.push_back(vet[i] + vet[i+1]);
        triangulo(vet, size-1);
        imprimir(vet);
    }
    return;    
}

int main() {
    cout << "Insira o elemento:" << endl;

    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> vet;

    int value;
    while(ss >> value)
        vet.push_back(value);
    
    triangulo(vet, (int)vet.size()-1);
    imprimir(vet);
}