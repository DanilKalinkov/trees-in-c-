#include <iostream>
#include <string>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

// Создание нового узла
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Вставка значения в дерево
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Обратный обход дерева
void reverseInOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    reverseInOrderTraversal(root->right);
    std::cout << root->value << " ";
    reverseInOrderTraversal(root->left);
}

// Прямой обход дерева
void preOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->value << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Возрастающий порядок
void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);
    std::cout << root->value << " ";
    inOrderTraversal(root->right);
}

// Поиск значения в дереве
bool search(Node* root, int value) {
    if (root == nullptr || root->value == value) {
        return (root != nullptr);
    }

    if (value < root->value) {
        return search(root->left, value);
    }
    else {
        return search(root->right, value);
    }
}

// Удаление значения из дерева
Node* remove(Node* root, int value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->value) {
        root->left = remove(root->left, value);
    }
    else if (value > root->value) {
        root->right = remove(root->right, value);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* successor = root->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }

        root->value = successor->value;
        root->right = remove(root->right, successor->value);
    }

    return root;
}

// Подсчет количества символов во всех строках в узлах дерева
int countCharacters(Node* root, int& sum) {
    if (root == nullptr) {
        return 0;
    }
    int i;
    int count = 0;
    i = root->value;                                                                          // Здесь можно добавить логику для подсчета символов в строке,
    // предполагая, что в каждом узле есть строковое поле.
// Например, если поле называется "stringField":
    std::string s;                                                                    // count += root->stringField.length();
    std::string strNumber = std::to_string(i);
    const char* charNumber = strNumber.c_str();
    int is = strlen(charNumber);
    sum = sum + is;
    count += countCharacters(root->left, sum);
    count += countCharacters(root->right, sum);
    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Node* root = nullptr;

    // Добавление значений в дерево

    for (int i = -50; i < 50; i++) {
        root = insert(root, i);
    }
    // Прямой обход дерева
    std::cout << "Прямой обход дерева: ";
    preOrderTraversal(root);
    std::cout << std::endl;

    // Обратный обход дерева
    std::cout << "Обратный обход дерева: ";
    reverseInOrderTraversal(root);
    std::cout << std::endl;

    // Возрастающий порядок
    std::cout << "Возрастающий порядок: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    // Поиск значения
    int value = 5;
    if (search(root, value)) {
        std::cout << value << " найдено в дереве." << std::endl;
    }
    else {
        std::cout << value << " не найдено в дереве." << std::endl;
    }

    // Удаление значения
    value = 20;
    root = remove(root, value);

    // Прямой обход дерева после удаления
    std::cout << "Прямой обход дерева после удаления: ";
    preOrderTraversal(root);
    std::cout << std::endl;

    // Подсчет количества символов в строках
    int sum;
    sum = 0;
    int characterCount = countCharacters(root, sum);

    std::cout << "Количество символов во всех строках:sum " << sum << std::endl;
    return 0;
}