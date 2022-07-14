#pragma once
#include <functional>
#include <iostream>
#include <sstream>

using namespace std;

struct Node{
    int value;
    Node * next;
    Node(int value = 0, Node * next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

struct LinkedList{
    Node * head {nullptr};

    void push_back(int value) {
        function <Node* (Node*, int)> fn;
        fn = [&fn](Node * node, int value) {
            if(node == nullptr)
                return new Node(value);
            node->next = fn(node->next, value);
            return node;
        };
        this->head = fn(this->head, value);
    }

    void push_front(int value) {
        if(this->head == nullptr)
            this->head = new Node(value);
        else
            this->head = new Node(value, this->head);
    }

    void pop_back() {
        std::function <Node* (Node*)> fn;
            fn = [&](Node * node) -> Node *{
                if(node == nullptr)
                    return nullptr;
                if(node->next == nullptr) {
                    delete node;
                    return nullptr;
                }
                node->next = fn(node->next);
                return node;
            };
        this->head = (this->head);
    }

    void pop_front() {
        if(head == nullptr)
            return;
        Node * node = head;
        head = head->next;
        delete node;
    }
    
    int  size();

    LinkedList();
    ~LinkedList();
    friend ostream& operator<<(ostream& os, LinkedList& lista);
};
