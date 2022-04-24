#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void show(vector<string> mat){
    for (auto vet : mat)
        cout << vet << endl;
    getchar();
}

void tacar_fogo(vector<string> &mat, int lpos, int cpos){
    int nl = mat.size();
    int nc = mat[0].size();
    
    if (lpos < 0 || lpos >= nl || cpos < 0 || cpos >= nc)
        return;
    if (mat[lpos][cpos] != '#')
        return;
   
    mat[lpos][cpos] = 'o';
    show(mat);

    tacar_fogo(mat, lpos, cpos - 1);
    tacar_fogo(mat, lpos - 1, cpos);
    tacar_fogo(mat, lpos, cpos + 1);
    tacar_fogo(mat, lpos + 1, cpos);
}

int main() {
    vector<string> mat;
    ifstream arq("Input.txt");
    int nLine { }, nColumn { }, fLine { }, fColumn { };
    arq >> nLine >> nColumn >> fLine >> fColumn;

    for (int i {0}; i < nLine; i++) {
        string line;
        arq >> line;
        mat.push_back(line);
    }
    show(mat);
    tacar_fogo(mat, fLine, fColumn);
}