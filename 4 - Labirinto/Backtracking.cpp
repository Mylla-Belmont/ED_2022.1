#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool inserir(string& line, int index, int value, int prox) {
    for(int i { index + 1 }; i < index + 1 + prox; i++ )
        if(i < (int) line.size() && line[i] == value + '0')
            return false;
    for(int i { index - prox }; i < index; i++ )
        if(i >= 0 && line[i] == value + '0')
            return false;
    return true;
}

bool preencher(string& line, int index, int lim, int prox) {
    if((int) line.size() == index)
        return false;
    if(line[index] != '.')
        return preencher(line, index + 1, lim, prox);
    for(int value { 0 }; value <= lim; value++) {
        if(inserir(line, index, value, prox)) {
            line[index] = value + '0';
            cout << line << endl;
            if(preencher(line, index + 1, lim, prox))
                return true;
        }
    }
    line[index] = '.';
    cout << line << endl;
    return false;
}

int main() {
    string line;
    int lim { 1 };
    int prox { 0 };
    ifstream arq("input.txt");

    arq >> line >> prox;
    preencher(line, 0, lim, prox);
}