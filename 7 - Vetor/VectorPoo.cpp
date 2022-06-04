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
        this->size = other.size;
        this->capacity = other.capacity;
        if(this->data != nullptr)
            delete [] this->data;
        this->data = new int[other.capacity];
        for(int i = 0; i < other.size; i++)
            this->data[i] = other.data[i];
    }

    Vector(Vector& other){
        *this = other;
    }

    ~Vector(){
        //devolta this->data
    }
}