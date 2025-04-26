#include "bst.h"
#include <iostream>

BST::BST() : root(nullptr) {}
BST::~BST() { destroy(root); }

void BST::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

Node* BST::insert(Node* node, const std::string& key, int value) {
    if (!node) return new Node(key, value);
    if (key < node->key)
        node->left = insert(node->left, key, value);
    else if (key > node->key)
        node->right = insert(node->right, key, value);
    else
        node->data = value;
    return node;
}

void BST::set(const std::string& key, int value) {
    root = insert(root, key, value);
}

Node* BST::find(Node* node, const std::string& key) const {
    if (!node) return nullptr;
    if (key == node->key) return node;
    return (key < node->key) ? find(node->left, key) : find(node->right, key);
}

int BST::find(const std::string& key) const {
    Node* result = find(root, key);
    return result ? result->data : 0;
}

void BST::print_in_order(Node* node) const {
    if (!node) return;
    print_in_order(node->left);
    std::cout << node->key << ": " << node->data << "\n";
    print_in_order(node->right);
}

void BST::print() const {
    print_in_order(root);
}

Node* BST::find_min(Node* node) const {
    return node && node->left ? find_min(node->left) : node;
}

Node* BST::find_max(Node* node) const {
    return node && node->right ? find_max(node->right) : node;
}

void BST::min() const {
    Node* min_node = find_min(root);
    if (min_node) std::cout << "Min: " << min_node->key << " = " << min_node->data << "\n";
}

void BST::max() const {
    Node* max_node = find_max(root);
    if (max_node) std::cout << "Max: " << max_node->key << " = " << max_node->data << "\n";
}

Node* BST::remove(Node* node, const std::string& key) {
    if (!node) return nullptr;
    if (key < node->key)
        node->left = remove(node->left, key);
    else if (key > node->key)
        node->right = remove(node->right, key);
    else {
        if (!node->left) {
            Node* right = node->right;
            delete node;
            return right;
        } else if (!node->right) {
            Node* left = node->left;
            delete node;
            return left;
        }
        Node* min_node = find_min(node->right);
        node->key = min_node->key;
        node->data = min_node->data;
        node->right = remove(node->right, min_node->key);
    }
    return node;
}

void BST::delete_key(const std::string& key) {
    root = remove(root, key);
}

void BST::save_in_order(Node* node, std::ofstream& out) const {
    if (!node) return;
    save_in_order(node->left, out);
    out << node->key << " " << node->data << "\n";
    save_in_order(node->right, out);
}

void BST::save_file(const std::string& filename) const {
    std::ofstream out(filename);
    if (out.is_open())
        save_in_order(root, out);
}

int& BST::operator[](const std::string& key) {
    Node* found = find(root, key);
    if (!found) {
        set(key, 0);
        found = find(root, key);
    }
    return found->data;
}
