#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    std::string key;
    int data;
    Node* left;
    Node* right;

    Node(const std::string& k, int val = 1) 
        : key(k), data(val), left(nullptr), right(nullptr) {}
};

#endif
