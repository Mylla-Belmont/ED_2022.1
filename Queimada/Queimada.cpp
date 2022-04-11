#include <iostream>
#include <vector>

using namespace std;

void show(vector<string> mat){
    for(int l = 0; l < (int) mat.size(); l++)
        cout << mat[l] << "\n";
}

void tocar_fogo(vector<string> &mat, int l, int c){
    int nl = mat.size();
    int nc = mat[0].size();
    //TODO faca seu codigo aqui
}

int main() {
    int nLine {}, nColumn {}, fLine {}, fColumn {};
    cin >> nLine >> nColumn >> fLine >> fColumn;
    vector<string> mat;

    for (int i {0}; i < nLine; i++) {
        string line;
        cin >> line;
        mat.push_back(line);
    }
    tocar_fogo(mat, fLine, fColumn);
    show(mat);
}