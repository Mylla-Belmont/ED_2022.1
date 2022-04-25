#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void show (vector<string> vet) {
    cout << "[ ";
    for(auto value : vet)
        cout << value << " ";
    cout << "]" << endl;
}

void right_rotation (vector<string>& vet, int nrot) {
    int fim { vet.size()-1 };
    for (int i { 0 }; i < nrot; i++){
        string aux = vet[fim];
            for(int j { fim }; j > 0; j--)
                vet[j] = vet[j-1];
        vet[0] = aux;
    }
}

int main(){
    vector<string> vet;
    int size { 0 }, nrot { 0 };
    ifstream arq("Input.txt");
    arq >> size >> nrot;
   
    for (int i { 0 }; i < size; i++) {
        string line;
        arq >> line;
        vet.push_back(line);
    }
    right_rotation(vet, nrot);
    show(vet);
}