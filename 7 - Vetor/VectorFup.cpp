#include <iostream>
#include <sstream>

using namespace std;

struct Vector{
    int capacity;
    int size;
    int * data;
};

Vector * vector_create(int capacity){
    Vector * vetor = new Vector();
    vetor -> size = 0;
    vetor -> capacity = capacity;
    vetor -> data = new int[capacity];
    return vetor;
}

void vector_destroy(Vector * vector){
    delete [] vector -> data;
    delete vector;
}

void vector_add(Vector * vector, int value){
    if(vector->size < vector->capacity) {
        vector->data[vector->size] = value;
        vector->size += 1;
    }
}

void vector_show(Vector * vector){
    cout << "[";
    for(int i = 0; i < vector->size; i++)
        cout << vector->data << " ";
    cout << " " << endl;
}

int main(){
    string line, cmd;
    int value;
    Vector * v = vector_create(0);
    while(true){
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        } else if(cmd == "init"){
            ss >> value;
            if(v != nullptr)
                vector_destroy(v);
            v = vector_create(value);
        } else if(cmd == "status"){
            cout << "size:" << v->size << " capacity:" << v->capacity << "\n";
        } else if(cmd == "add"){
            while(ss >> value)
                vector_add(v, value);
        } else if(cmd == "show"){
            vector_show(v);
        } else {
            cout << "fail: comando invalido\n";
        }
    }
    vector_destroy(v);
}