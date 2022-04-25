#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void imprimir(vector<int> vetor) {
    for(int vet : vetor)
        cout << vet << " ";
    cout << endl;
}

void triangulo(vector<int> vet, int size) {
    size = (int) vet.size();
    vector<int> aux { };
    if (size != 1) {
        for (int i = 0; i < size-1; i++)
            aux.push_back(vet[i] + vet[i+1]);
        triangulo(aux, size); 
        imprimir(aux);
    } return;
}

int main() {
    cout << "Insira os elementos:" << endl;

    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> vet;

    int value;
    while(ss >> value)
        vet.push_back(value);
    
    triangulo(vet, (int) vet.size());
    imprimir(vet);
}