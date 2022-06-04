#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using vet = vector<string>;
using vet_int = vector<int>;

void show(vet_int vetor) {
    for(int i = 0; i < (int) vetor.size(); i++){
        if(i != 0)
            cout << " ";
        cout << vetor[i];
    }
}

vet_int matchingStrings(vet vet1, vet vet2) {
    vet_int vetResult(vet2.size(), 0);
    for(int i { 0 }; i < (int) vet2.size(); i++)
        for(int j { 0 }; j < (int) vet1.size(); j++)
            if(vet1[j] == vet2[i])
                vetResult[i] = vetResult[i] + 1;
    return vetResult;
}

int main() {
    int size1 { 0 }, size2 { 0 };
    vet vet1(size1);
    vet vet2(size2);
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

    vet_int vetResult = matchingStrings(vet1, vet2);
    show(vetResult);
}