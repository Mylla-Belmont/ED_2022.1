#include <iostream>
#include <sstream>

using namespace std;

struct Vector {
    int size {0};
    int capacity {0};
    int * data {nullptr}; 

    Vector(int capacity){
        this->size = 0;
        this->capacity = capacity;
        this->data = new int[capacity];
    }
    void operator = (const Vector& other){
        //inicialize this->capacity com other.capacity
        //inicialize this->size com other.size
        //se this->data não for nulo, devolva a memória com delete
        //crie nova memória para this->data do tamanho de other.capacity
        //copie os dados de other.data para this->data
    }
}