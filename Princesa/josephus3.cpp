#include <iostream>
#include <list>

using namespace std;

void imprimir_vetor(list<int>& lista, list<int>::iterator& inicio) {
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        cout << " " << *it;
        if(it == inicio)
            cout << ">";
    } cout << endl;
}   


void lista_princesa(list<int> lista, int inicio) {
    auto it = lista.begin();
    advance(it, inicio - 1);

    auto fix_loop = [&lista](auto it) {
        return it == lista.end() ? lista.begin() : it;
    };

    while(lista.size() > 1){
        imprimir_vetor(lista, it);
        it = fix_loop(next(it, 1));
        it = fix_loop(lista.erase(it));
    }imprimir_vetor(lista, it);
}

int main() {
    int  inicio {}, size {};
    cout << "Digite o tamanho e o inicio:" << endl;
    cin >> size  >> inicio;
    list<int> lista;

    for (int i {0}; i < size; i++)
        lista.push_back(i+1);

    lista_princesa(lista, inicio);
}