#include <iostream>
#include <math.h> // for asserting height
#include <queue>
using namespace std;
#define RED 0
#define BLACK 1

//https://www.cs.usfca.edu/~galles/visualization/BST.html
//https://www.cs.usfca.edu/~galles/visualization/AVLtree.html
//https://www.cs.usfca.edu/~galles/visualization/RedBlack.html

template<class T>
class RBT;
template <class T>
class RBTNode;

template <class T>
class RBT {
    RBTNode<T>* root;
    void singleLR(RBTNode<T>*& point);
    void singleRR(RBTNode<T>*& point);
    void doubleRLR(RBTNode<T>*& point);
    void doubleLRR(RBTNode<T>*& point);
public:
    RBT() : root(nullptr) {}
    void insert(const T&, RBTNode<T>*& point, RBTNode<T>* parent);
    void insert(const T&);
    int height() const { return root->height(); }
    void prettyPrint() const { root->prettyPrint(0); }
};

template<class T>
class RBTNode {
    T data;
    RBTNode<T>* parent;
    RBTNode<T>* left;
    RBTNode<T>* right;
    int color;
public:
    RBTNode(T data) : data(data), parent(nullptr), left(nullptr), right(nullptr), color(RED) {}
    int height() const;
    void prettyPrint(int indent) const;
    template<class T1>
    friend void swapColor(RBTNode<T1>*);
    template<class T1>
    friend int getColor(RBTNode<T1>*);
    friend class RBT<T>;
};

//recursive:  hight() = MAX{(*left).hight(),(*right).hight()}
template <class T>
int RBTNode<T>::height() const {
    int left_h, right_h;
    left_h = 0;
    if (left == nullptr) {}
    else {
        left_h = left->height();
    }
    right_h = 0;
    if (right == nullptr) {}
    else {
        right_h = right->height();
    }
    return 1 + max(left_h, right_h);
}

//recursive:   
template <class T>
void RBTNode<T>::prettyPrint(int indent) const {
    //
    if (right == nullptr) {}
    else {
        right->prettyPrint(indent + 1);
    }
    //tab
    int margin = indent * 2;
    for (int i = 0; i < margin; i++) {
        cout << '\t';
    }
    cout << "DATA: " << data << endl;
    for (int i = 0; i < margin; i++) {
        cout << '\t';
    }
    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;
    //
    if (left == nullptr) {}
    else {
        left->prettyPrint(indent + 1);
    }
}

//swapColor(RBTNode<T> *node): change the variable "color";
int swapColor(int c) {
    return (c == 0) ? 1 : 0;
}
template <class T>
void swapColor(RBTNode<T>* node) {
    if (node != nullptr) {
        node->color = swapColor(node->color);
    }
}

//getColor(RBTNode<T> *node): return BLACK/RED(node);return BLACK (root);
template <class T>
int getColor(RBTNode<T>* node) {
    if (node != nullptr) {
        return node->color;
    }
    else {
        return BLACK;
    }
}


//|F       |F       |F       |F
//|     GB |     GB |   *R   |   *B
//| PR     |   *B   | PB  GR | PR  GR
//|   *R   | PB     |        |
template <class T>
void RBT<T>::doubleRLR(RBTNode<T>*& point) {
    singleRR(point->left);
    singleLR(point);
    point->parent->color = BLACK;
    point->parent->left->color = RED;
}

//|F        |F        |F       |      F
//| GB      | GB      |  *R    |  *B
//|     PR  |   *B    |GR  PB  |GR  PR
//|   *R    |     PB  |        |
template <class T>
void RBT<T>::doubleLRR(RBTNode<T>*& point) {
    singleLR(point->right);
    singleRR(point);
    point->parent->color = BLACK;
    point->parent->right->color = RED;
}
//|F         |F
//|       GB |   PB
//|   PR     | *R    GR
//| *R  BB   |     BB
template <class T>
void RBT<T>::singleLR(RBTNode<T>*& point) {
    RBTNode<T>* forefather = point->parent;
    RBTNode<T>* grandparent = point;
    RBTNode<T>* parent = point->left;
    RBTNode<T>* brother = point->left->right;
    if (forefather == nullptr) {
        grandparent->parent = parent;
        grandparent->left = brother;
        parent->parent = nullptr;
        parent->right = grandparent;
        if (brother != nullptr) 
            brother->parent = grandparent;
        root = parent;
    }
    else {
        if (forefather->left == grandparent)
            forefather->left = parent;
        else 
            forefather->right = parent;      
        grandparent->parent = parent;
        grandparent->left = brother;
        parent->parent = forefather;
        parent->right = grandparent;
        if (brother != nullptr) 
            brother->parent = grandparent;
    }
    parent->color=BLACK;
    grandparent->color=RED;
}

//|F         |F
//|GB        |    PB
//|    PR    |GR    *R
//|  BB  *R  |  BB
template <class T>
void RBT<T>::singleRR(RBTNode<T>*& point) {
    RBTNode<T>* forefather = point->parent;
    RBTNode<T>* grandparent = point;
    RBTNode<T>* parent = point->right;
    RBTNode<T>* brother = point->right->left;
    if (forefather == nullptr) {
        grandparent->parent = parent;
        grandparent->right = brother;
        parent->parent = nullptr;
        parent->left = grandparent;
        if (brother != nullptr) 
            brother->parent = grandparent;
        root = parent;
    }
    else {
        if (forefather->left == grandparent) 
            forefather->left = parent;
        else 
            forefather->right = parent;
        grandparent->parent = parent;
        grandparent->right = brother;
        parent->parent = forefather;
        parent->left = grandparent;
        if (brother != nullptr) 
            brother->parent = grandparent;
    }
    parent->color = BLACK;
    grandparent->color = RED;
}

template <class T>
void RBT<T>::insert(const T& toInsert, RBTNode<T>*& point, RBTNode<T>* parent) {
    if (point == nullptr) {
        point = new RBTNode<T>(toInsert);
        point->parent = parent;
        if ( point->parent == nullptr) {
            point->color=BLACK;
            root = point;
            return;
        }
        else {
            if (toInsert < parent->data) {
                parent->left = point;
            }
            else {
                parent->right = point;
            }
        }
        //check rotation:
        RBTNode<T>* curr_grandparent;
        RBTNode<T>* curr_parent;
        RBTNode<T>* curr_uncle;
        for (RBTNode<T>* curr_node = point;    ; curr_node = curr_node->parent) {
            curr_parent = curr_node->parent;
            if (curr_parent->color == BLACK) {
                return;
            }
            else {//(curr_parent->color == RED)
                curr_grandparent = curr_parent->parent;
                if (curr_grandparent->left == curr_parent) {
                        curr_uncle = curr_grandparent->right;
                }
                else {
                        curr_uncle = curr_grandparent->left;
                }
                if (curr_uncle == nullptr) {
                    if (curr_grandparent->left == curr_parent && curr_parent->left == curr_node) {
                        singleLR(curr_grandparent);
                    }
                    if (curr_grandparent->left == curr_parent && curr_parent->right == curr_node) {
                        doubleRLR(curr_grandparent);
                    }
                    if (curr_grandparent->right == curr_parent && curr_parent->left == curr_node) {
                        doubleLRR(curr_grandparent);
                    }
                    if (curr_grandparent->right == curr_parent && curr_parent->right == curr_node) {
                        singleRR(curr_grandparent);
                    }
                    if (curr_node->parent->color == BLACK) {
                        return;
                    }
                }
                else if (curr_uncle->color == BLACK) {
                    if (curr_grandparent->left == curr_parent && curr_parent->left == curr_node) {
                        singleLR(curr_grandparent);
                    }
                    if (curr_grandparent->left == curr_parent && curr_parent->right == curr_node) {
                        doubleRLR(curr_grandparent);
                    }
                    if (curr_grandparent->right == curr_parent && curr_parent->left == curr_node) {
                        doubleLRR(curr_grandparent);
                    }
                    if (curr_grandparent->right == curr_parent && curr_parent->right == curr_node) {
                        singleRR(curr_grandparent);
                    }
                    if (curr_node->parent->color == BLACK) {
                        return;
                    }
                }
                else {
                    swapColor(curr_uncle);
                    swapColor(curr_parent);
                    swapColor(curr_grandparent);
                    if (curr_grandparent == root) {
                        curr_grandparent->color = BLACK;
                        return;
                    }
                }
            }
        }
    }
    else if (toInsert < point->data) {
        insert(toInsert, point->left, point);
    }
    else {
        insert(toInsert, point->right, point);
    }
}
template <class T>
void RBT<T>::insert(const T& toInsert) {
    insert(toInsert, root, nullptr);
}



// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int count = 19;
    for (int i = 0; i < count; i++) {
        b.insert(i);
    }

    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */

    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    //assert(height <= 2 * log2(count));
}