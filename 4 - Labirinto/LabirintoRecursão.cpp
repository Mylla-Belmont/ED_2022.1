#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
using matrix = vector<string>;

struct Pos {
    int l, c;
    Pos (int l, int c) : l(l), c(c){}
};

vector<Pos> vizinhos(Pos p) {
    auto [l, c] = p;
    return {{l, c-1}, {l-1, c}, {l, c+1}, {l+1, c}};
}

void mostrar(matrix& mat) {
    for (auto line : mat)
        cout << line << endl;
    getchar();
}

bool limite(matrix& mat, Pos p) {
    auto [l, c] = p;
    int nl = mat.size();
    int nc = mat[0].size();
    if (l < 0 || l >= nl || c < 0 || c >= nc)
        return true;
    return false;
}

vector<Pos> shuflle(vector<Pos> vet) {
    random_shuffle(begin(vet), end(vet));
    return vet;
}

bool pode_furar(matrix& mat, Pos p) {
    int cont { 0 };
    for(auto viz : vizinhos(p)) {
        if(limite(mat, viz))
            continue;
        if(mat[viz.l][viz.c] == '#')
            cont += 1; 
    } return (cont >= 3);
}

void furar(matrix& mat, Pos p) {
    auto[l, c] = p;
    if(limite(mat, p))
        return;
    if(mat[l][c] != '#')
        return;
    if(!pode_furar(mat, p))
        return;
    mat[l][c] = '.';
    mostrar(mat);
    for(auto viz : shuflle(vizinhos(p)))
        furar(mat, viz);
}

int main(int argc, char * argv[]) {
     if (argc != 3){
        cout << "\nNumero de argumentos invelido!" << endl;
        cout << "./executavel nl nc %\n" << endl;
        exit(1);
    }

    int nl { 0 }, nc { 0 };
    stringstream(argv[1]) >> nl; 
    stringstream(argv[2]) >> nc;

    vector<string> mat(nl, string(nc, '#'));
    furar(mat, Pos(1, 1));
    mostrar(mat);
}