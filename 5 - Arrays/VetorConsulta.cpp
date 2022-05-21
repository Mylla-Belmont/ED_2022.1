#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using vet = vector<string>;
using vet_int = vector<int>;

void show(vet_int vetor) {
    for(auto value : vetor)
        cout << value << " ";
    cout << endl;
}

void matchingStrings(vet vet1, vet vet2, vet_int& vetResult) {
    for(int i { 0 }; i < (int) vet2.size(); i++)
        for(int j { 0 }; j < (int) vet1.size(); j++)
            if(vet1[j] == vet2[i])
                vetResult[i] = vetResult[i] + 1;
}

int main() {
    int size1 { 0 }, size2 { 0 };
    vet vet1(size1);
    vet vet2(size2);
    vet_int vetResult(size2, 0);
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

    matchingStrings(vet1, vet2, vetResult);
    show(vetResult);
}