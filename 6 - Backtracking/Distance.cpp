#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool inserir(string& line, int index, int lim, int value) {
    for(int i { index - lim }; i < index + lim + 1; i++ )
        if(line[i] == value)
            return false;
    return true;
}


bool preencher(string& line, int index, int lim) {
    if((int) line.size() == index)
        return true;
    if(line[index] != '.')
        return preencher(line, index + 1, lim);
    for(char value { '0' }; value <= lim + '0'; value++) {
        if(inserir(line, index, lim, value)) {
            line[index] = value;
            cout << line << endl;
            if(preencher(line, index + 1, lim))
                return true;
        }
    }
    line[index] = '.';
    cout << line << endl;
    return false;
}

int main() {
    string line;
    int lim { };
    ifstream arq("input.txt");

    arq >> line >> lim;
    preencher(line, 0, lim);
}