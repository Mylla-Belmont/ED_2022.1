#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void mostrar(vector<string> mat) {
    for (auto line : mat)
        cout << line << endl;
}

void furar(vector<string>& mat, int nl, int nc, int porcentagem) {
    for (int i { 0 }; i < nl; i++)
        for (int j { 0 }; j < nc; j++)
            if (rand() % 100 < porcentagem)
                mat[i][j] = '.';
}

int main(int argc, char * argv []){
    if (argc != 4){
        cout << "\nNumero de argumentos invelido!" << endl;
        cout << "./executavel nl nc %\n" << endl;
        exit(1);
    }

    int nl { 0 }, nc { 0 }, porcentagem { 0 };
    stringstream(argv[1]) >> nl; 
    stringstream(argv[2]) >> nc;
    stringstream(argv[3]) >> porcentagem;

    vector<string> mat(nl, string(nc, '#'));
    furar(mat, nl, nc, porcentagem);
    mostrar(mat);
}