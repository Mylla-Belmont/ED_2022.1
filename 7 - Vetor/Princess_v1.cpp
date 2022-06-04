#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using vet = vector<int>;

void marcacao(vet circulo, int E, int F) {
    
}

int main(){
    int N { 0 }, E { 0 }, F { 0 };
    ifstream arq("input.txt");

    arq >> N >> E >> F;
    vet circulo(N, true);
    marcacao(circulo, E, F);
}