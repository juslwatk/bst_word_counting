#ifndef BST_H
#define BST_H

#include "node.h"
#include <string>
#include <fstream>

class BST {
private:
    Node* root;

    void destroy(Node* node);
    Node* insert(Node* node, const std::string& key, int value);
    Node* remove(Node* node, const std::string& key);
    Node* find(Node* node, const std::string& key) const;
    void print_in_order(Node* node) const;
    void save_in_order(Node* node, std::ofstream& out) const;
    Node* find_min(Node* node) const;
    Node* find_max(Node* node) const;

public:
    BST();
    ~BST();

    void set(const std::string& key, int value);
    int find(const std::string& key) const;
    void print() const;
    void min() const;
    void max() const;
    void save_file(const std::string& filename) const;
    void delete_key(const std::string& key);

    int& operator[](const std::string& key); // Bonus
};

#endif
