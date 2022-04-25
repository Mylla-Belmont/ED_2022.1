#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void show(vector<string> vet) {
    for(auto value : vet)
        cout << value << " ";
}

void filaIngressos(vector<string> &vet1, vector<string> &vet2, vector<string> &vetResult){
    for(int i { 0 }; i < (int) vet1.size(); i++)
        for(int j { 0 }; j < (int) vet2.size(); j++)
            if(vet1[i] == vet2[j])
                vet1[i] = "0";

    for(int i { 0 }; i < (int) vet1.size(); i++)
        if(vet1[i] != "0")
            vetResult.push_back(vet1[i]);
}

int main() {
    int size1 { 0 }, size2 { 0 };
    vector<string> vet1;
    vector<string> vet2;
    vector<string> vetResult;
    ifstream arq("Input.txt");

    arq >> size1;
    for (int i { 0 }; i < size1; i++) {
        string line;
        arq >> line;
        vet1.push_back(line);
    }

    arq >> size2;
    for (int i { 0 }; i < size2; i++) {
        string line;
        arq >> line;
        vet2.push_back(line);
    }
    
    filaIngressos(vet1, vet2, vetResult);
    show(vetResult);
}