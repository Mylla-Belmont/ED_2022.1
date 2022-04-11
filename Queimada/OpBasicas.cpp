#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void printOut (vector<int> vet, int size) {
    if(size == 1)
        cout << vet[size-1] << " "; 
    else {
        printOut (vet, size-1);
        cout << vet[size-1] << " ";
    }
}

// void rvet_function(vector<int> vet, int first, int size) {
//     if(first == size)
//         cout << vet[size-1] << " "; 
//     else {
//         rvet_function (vet, first+1, size-1);
//         cout << vet[size-1] << " ";
//     }
// }

int sum_function (vector<int> vet, int size) {
    if(size == 0)
        return 0;
    return vet[size - 1] + sum_function(vet, size - 1);
}

int mult_function (vector<int> vet, int size) {
    if(size == 0)
        return 1;
    return vet[size - 1] * mult_function(vet, size - 1);
}

int min_function (vector<int> vet, int size, int index) {
    if(size == 0)
        return vet[index];
    if(vet[size-1] < vet[index])
        return min_function(vet, size-1, size-1);
    return min_function(vet, size-1, index);
}

void invt(vector<int>& vet,  int first, int last) {
    int aux { };
    aux = vet[first];
    vet[first] = vet[last];
    vet[last] = aux;
}

void inv_function (vector<int>& vet, int first, int last) {
    if(first >= last)
        printOut(vet, (int) vet.size());
    else{
        invt(vet, first, last);
        inv_function(vet, first + 1, last - 1);
    }
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

    int size {(int) vet.size()};
    cout << "vet : [ "; printOut(vet, size); cout << "]" << endl;
    //cout << "rvet: [ "; rvet_function(vet, 0, size); cout << "]" << endl;
    cout << "sum : " << sum_function(vet, size) <<  endl;
    cout << "mult: " << mult_function(vet, size) <<  endl;
    cout << "min : " << min_function(vet, size, 0)  << endl;
    cout << "inv : [ "; inv_function(vet, 0, size - 1); cout << "]" << endl;
}