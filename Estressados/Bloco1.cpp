#include <iostream>
#include <vector>

using namespace std;

string homens_sao_mais_estressados_que_mulheres(vector<int> fila) {
    int soma_homens {}, soma_mulheres {}, homens {}, mulheres {};
    for (int vet : fila) {
        if (vet > 0) {
            soma_homens += abs (vet);
            homens =+ 1;
        } else {
            soma_mulheres += abs (vet);
            mulheres =+ 1;
        }
    }
    return ((soma_homens/homens) > (soma_mulheres/mulheres)) ? "Sim" : "Nao";
}

string qual_metade_eh_mais_estressada(vector<int> fila) {
    int soma1 {}, soma2 {}, size {(int) fila.size()};
    for (int i = 0; i < (size/2); i++)
        soma1 += abs (fila[i]);
    for (int i = (size/2); i < size; i++)
        soma2 += abs (fila[i]);
    if (soma1 == soma2)
        return "Empate";
    return (soma1 > soma2) ? "Primeira" : "Segunda";
}

string mais_homens_ou_mulheres(vector<int> fila) {
    int cont_mulheres {}, cont_homens {};
    for (int vet : fila)
        if (vet > 0)
            cont_homens += 1;
        else
            cont_mulheres += 1;
    if (cont_homens == cont_mulheres)
        return "Empate";
    return (cont_homens > cont_mulheres) ? "Homens" : "Mulheres";
}

int calcular_stress_medio(vector<int> fila) {
    int soma {};
    for (int vet : fila){
        soma += abs (vet);
    }
    return (soma / fila.size());
}

int posicao(vector<int> fila, int inicio, int comparador) {
    int pos {}, size {(int)fila.size()};
    for (int i = inicio; i < size; i++)
        if (fila[i] <= comparador){
            comparador = fila[i];
            pos = i;
        }
    return pos;
}

int procurar_pos_menor_apartir(vector<int> fila, int inicio) {
    int comparador {fila[inicio]}, pos {};
    pos = posicao(fila, inicio, comparador);
    return pos;
}

int procurar_pos_menor(vector<int> fila) {
    int comparador {fila[0]}, pos {};
    pos = posicao(fila, 0, comparador);
    return pos;
}

int procurar_menor(vector<int> fila){
    int comparador {fila[0]};
    for (int vet : fila)
        if (vet < comparador)
            comparador = vet;
    return comparador;
}

int procurar_apartir(vector<int> fila, int x, int inicio) {
    int size {(int)fila.size()};
    for (int i = inicio; i < size; i++)
        if (fila[i] == x)
            return i;
    return -1;
}

int procurar(vector<int> fila, int x) {
    int size {(int)fila.size()};
    for (int i = 0; i < size; i++)
        if (fila[i] == x)
            return i;
    return -1;
}

int contar(vector<int> fila, int x) {
    int cont {};
    for (int vet : fila)
        cont += (vet == x) ? 1 : 0;
    return cont;
}

bool exite(vector<int> fila, int x) {
    for (int vet : fila)
        return (vet == x) ? true : false;
    return false;
}

int main() {
    /* BUSCA */
    cout << exite({-1, -50, -99}, -1) << endl;   
    cout << contar({-1, -50, -1, -99}, -1) << endl;    
    cout << procurar({-1, -50, -1, -99}, -50) << endl;    
    cout << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 4) << endl;   
    /* MELHOR CASO */
    cout << procurar_menor({5, 3, -1, -50, -1, -99}) << endl;
    cout << procurar_pos_menor({5, 3, -1, -50, -1, -99}) << endl;   
    cout << procurar_pos_menor_apartir({5, 3, -1, -50, -1, 10}, 1) << endl;  
    /* CONTAGEM */
    cout << calcular_stress_medio({5, 3, -1, -50, -1, -99}) << endl; 
    cout << mais_homens_ou_mulheres({5, 3, -1, -50, -1, -99}) << endl;
    cout << qual_metade_eh_mais_estressada({5, 3, -1, -50, -1, -99}) << endl;
    cout << homens_sao_mais_estressados_que_mulheres({5, 3, -1, -50, -1, -99}) << endl;
}