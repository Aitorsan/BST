//
//  main.cpp
//  Binary_Search_Tree
//
//  Created by Aitorsf on 06/03/2018.
//  
//


#include "BST.cpp"
int main() {
   
    
    BST tree;

    int array[10]{8,5,29,43,67,20,19,290,6,10};

    for( int i = 0;i < 10;++i)
         tree.addLeaf(array[i]);


    tree.print_in_order();


    for( int i = 0;i < 10;++i){
       tree.print_children(array[i]);

    }
    
    std::cout << tree.find_Smallest();
    return 0;
}
