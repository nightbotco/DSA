/*
Neeti Kurulkar
SE  Div: A  Batch: S2
Roll No. : 21038
DSAL Practical Assignment 4

A Dictionary stores keywords and its meanings. Provide facility for adding new
keywords, deleting keywords, updating values of any entry. Provide facility to display
whole data sorted in ascending/ descending order. Also find how many maximum
comparisons may require for finding any keyword. Use Binary Search Tree for
implementation.
*/


#include<iostream>
#include<string>
using namespace std;

class Node {
public:
    string key, meaning;
    Node *left, *right;
    Node(string k, string m) {
        key = k;
        meaning = m;
        left = right = NULL;
    }
};

class Dictionary {
public:
    Node *root;
    Dictionary() {
        root = NULL;
    }

    Node* insert(Node* node, string key, string meaning) {
        if (node == NULL) return new Node(key, meaning);
        if (key < node->key) node->left  = insert(node->left, key, meaning);
        else if (key > node->key) node->right = insert(node->right, key, meaning);   
        return node;
    }

    void inorder(Node *root) {
        if (root != NULL) {
            inorder(root->left);
            cout<<root->key<<" --> "<<root->meaning<<endl;
            inorder(root->right);
        }
    }

    Node* search(Node* root, string key) {
        if (root == NULL || root->key == key) return root;
        if (root->key < key) return search(root->right, key);
        return search(root->left, key);
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, string key) {
        if (root == NULL) return root;
        if (key < root->key) root->left = deleteNode(root->left, key);
        else if(key > root->key) root->right = deleteNode(root->right, key);
        else {
            if (root->left == NULL) {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }

    void update(Node* root, string key, string new_meaning) {
        Node* node = search(root, key);
        if(node != NULL) node->meaning = new_meaning;
        else cout<<"Key not found."<<endl;
    }
};

int main() {
    Dictionary dict;
    dict.root = dict.insert(dict.root, "apple", "a fruit");
    dict.root = dict.insert(dict.root, "banana", "an edible fruit");
    dict.inorder(dict.root);
    dict.update(dict.root, "apple", "a tasty fruit");
    dict.inorder(dict.root);
    dict.root = dict.deleteNode(dict.root, "banana");
    dict.inorder(dict.root);
    return 0;
}
