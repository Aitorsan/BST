//
//  BST.hpp
//  Binary_Search_Tree
//
//  Created by Aitorsf on 06/03/2018.

//

#ifndef BST_hpp
#define BST_hpp
#include <iostream>

class BST{
    
    struct Node{
        Node* m_left;
        Node* m_right;
        int m_key;
        Node():m_left(nullptr),m_right(nullptr){}
        ~Node(){delete m_left; delete m_right;}
        void show(){
            std::cout << "[" << m_key << "]";
        }
    };
   
    Node* m_root;
public:
    
    BST();
    ~BST();
    void addLeaf(int key);
    void print_in_order();
    void print_children( int* key);
    void print_children( int key);
    int* get_Root_key();
    int find_Smallest();
    void delete_node(int key);
private:
     int find_Smallest(Node* ptr);
    Node* get_node( int key,Node* ptr);
    Node* createLeaf(int key);
    void addLeaf_private(int key, Node* ptr);
    void print_in_order( Node* ptr);
    void delete_node(int key, Node*ptr);
};
#endif /* BST_hpp */
