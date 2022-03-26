#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

void imprimir(vector<int> nome_vetor){
    cout << "[";
    for (auto vetor : nome_vetor)
        cout << vetor << " ";
    cout << "]" << endl;
}

vector<int> abandonados(const vector<int>& fila){
    int size {(int) fila.size()};
    vector<int> novo_vetor {};
    
    return novo_vetor;
}

vector<int> diferentes(const vector<int>& fila){
    vector<int> novo_vetor {};
    for (auto vet : fila) 
        if (vet > 0) 
            novo_vetor.push_back(vet);
    return novo_vetor;
}

vector<int> exclusivos(const vector<int>& fila){
    vector<int> novo_vetor {fila};
    auto last = unique(novo_vetor.begin(), novo_vetor.end());  
    novo_vetor.erase(last, novo_vetor.end());  
    return novo_vetor;
}

void swap(int *a, int *b) {
    int aux = *a; 
    *a = *b; 
    *b = aux; 
}

void ordenar(vector<int>& fila) {
    int size {(int) fila.size()};
    for (int i {0}; i < (size-1); i++) {
        int min {i};
        for (int j {i+1}; j < size; j++) {
            if (fila[j] < fila[min])
                min = j;
        }
        swap(fila[i], fila[min]);
    }
}

void embaralhar(vector<int>& fila) {
    random_shuffle(fila.begin(), fila.end());
}

int sortear(const vector<int>& fila) {
    srand((unsigned) time(0));
    int size {(int) fila.size()}, randomNumber {0};
    randomNumber = (rand() % size);
    return fila[randomNumber];
}

void inverter_inplace(vector<int>& fila) {
    int size {(int) fila.size()};
    for (int i = 0, j = (size-1); i < (size/2); i++, j--) {
        int aux{fila[i]};
        fila[i] = fila[j];
        fila[j] = aux;
    }
}

vector<int> inverter_com_copia(const vector<int>& fila) {
    vector<int> novo_vector {};
    int size {(int) fila.size()};
    for (int i = size-1; i >=0; i--)
        novo_vector.push_back(fila[i]);
    return novo_vector;
}

vector<int> pegar_mulheres_calmas(const vector<int>& fila) {
    vector<int> novo_vector {};
    for (auto vet : fila)
        if (vet < 0 && abs (vet) < 10)
            novo_vector.push_back(vet);
    return novo_vector;
}

vector<int> pegar_calmos(const vector<int>& fila) {
    vector<int> novo_vector {};
    for (auto vet : fila)
        if (abs (vet) < 10)
            novo_vector.push_back(vet);
    return novo_vector;
}

vector<int> pegar_homens(const vector<int>& fila) {
    vector<int> novo_vector {};
    for (auto vet : fila)
        if (vet > 0)
            novo_vector.push_back(vet);
    return novo_vector;
}

vector<int> clonar(const vector<int>& fila) {
    vector<int> novo_vector {};
    for (auto vet : fila)
        novo_vector.push_back(vet);
    return novo_vector;
}

int main() {
    vector<int> vetor {-51, 99, 1, -50, -1, -99, 1, -50, -1};
    /*  FILTER  */
    imprimir(clonar(vetor));
    imprimir(pegar_homens(vetor));
    imprimir(pegar_calmos(vetor));
    imprimir(pegar_mulheres_calmas(vetor));                            
    /*  ACESSO  */
    imprimir(inverter_com_copia(vetor));
    inverter_inplace(vetor);
    imprimir(vetor);
    cout << sortear(vetor) << endl;
    embaralhar(vetor);
    imprimir(vetor);     
    ordenar(vetor);
    imprimir(vetor);   
    /* FUNÇÕES */
    imprimir(exclusivos(vetor));              
    imprimir(diferentes(vetor));              
    imprimir(abandonados(vetor));              
}