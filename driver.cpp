#include "bst.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

std::string clean_word(const std::string& word) {
    std::string clean;
    for (char c : word) {
        if (std::isalnum(c) || c == '\'') clean += std::tolower(c);
    }
    return clean;
}

void count_words(BST& tree, const std::string& filename) {
    std::ifstream file(filename);
    std::string word;
    while (file >> word) {
        std::string cleaned = clean_word(word);
        if (!cleaned.empty()) tree[cleaned]++;
    }
    std::cout << "Word count complete.\n";
}

void menu() {
    BST tree;
    int choice;
    std::string key, filename;
    int value;

    do {
        std::cout << "\n1. Set key-value\n2. Get value\n3. Delete key\n4. Print Tree\n"
                  << "5. Min key\n6. Max key\n7. Save to file\n8. Word Count from file\n9. Exit\n"
                  << "Choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout << "Enter key and value: ";
                std::cin >> key >> value;
                tree.set(key, value);
                break;
            case 2:
                std::cout << "Enter key: ";
                std::cin >> key;
                std::cout << "Value: " << tree.find(key) << "\n";
                break;
            case 3:
                std::cout << "Enter key to delete: ";
                std::cin >> key;
                tree.delete_key(key);
                break;
            case 4:
                tree.print();
                break;
            case 5:
                tree.min();
                break;
            case 6:
                tree.max();
                break;
            case 7:
                std::cout << "Enter filename: ";
                std::cin >> filename;
                tree.save_file(filename);
                break;
            case 8:
                std::cout << "Enter text file name: ";
                std::cin >> filename;
                count_words(tree, filename);
                break;
        }
    } while (choice != 9);
}
int main() {
    menu();
    return 0;
}
