#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* left;
    Node* right;
};

class Tree {
    Node* root;
public:
    Tree() { root = nullptr; }
    void add(int elem);
    bool isExist(int elem);
    void show(Node* elem = nullptr);
    int min(Node* start);
    int max(Node* start);
    Node* getRoot() { return root; }
};
void Tree::show(Node* elem) {
    if (elem != nullptr) {
        show(elem->left);
        cout << elem->data << ' ';
        show(elem->right);
    }
}
bool Tree::isExist(int elem) {
    Node* tmp = root;
    while (tmp != nullptr) {
        if (tmp->data == elem)
            return true;
        if (elem < tmp->data)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    return false;
}
int Tree::min(Node* start)
{
    if (start != nullptr)
        while (start->left != nullptr)
            start = start->left;
    return start->data;
}
int Tree::max(Node* start)
{
    if (start != nullptr)
        while (start->right != nullptr)
            start = start->right;
    return start->data;
}
void Tree::add(int elem) {
    Node* n = new Node;
    n->data = elem;
    n->left = nullptr;
    n->right = nullptr;

    //указатель для обхода дерева
    Node* tmp = root;
    //указатель для будущего родителя n
    Node* prnt = nullptr;
    //ищем родителя
    while (tmp != nullptr) {
        prnt = tmp;
        if (elem < tmp->data)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    //заполяем prev найденым родителем
    n->prev = prnt;
    //если родителя нет
    if (prnt == nullptr)
        root = n;                //значит элемент первый и становится root
    //если новый элемент меньше родителя
    else if (elem < prnt->data)
        prnt->left = n;            //запишем его адрес в левую ветку
    else
        prnt->right = n;        //иначе в правую

}

int main() {
    Tree t;
    for (int i = 0; i < 10; i++) {
        int tmp = rand() % 100;
        cout << tmp << ' ';
        t.add(tmp);
    }
    cout << endl;
    t.show(t.getRoot());
    cout << endl;
    cout << t.min(t.getRoot()) << endl;
    cout << t.isExist(620) << endl;
    cout << t.max(t.getRoot()) << endl;
}