//
//  BST.cpp
//  Binary_Search_Tree
//
//  Created by Aitorsf on 06/03/2018.
//

#include "BST.hpp"
#include <limits>
//Constructor
BST::BST():m_root(nullptr){}
//Destructor
BST::~BST(){
    delete m_root;
    m_root = nullptr;
    
}
    

// creates a new node or leave in the tree
BST::Node* BST::createLeaf(int key){
    Node* n = new Node();
    n->m_key = key;
    return n;
}
//********************************
// Add a new item in the tree
//********************************
void BST::addLeaf(int key){
    
    if( m_root != nullptr){
         addLeaf_private( key, m_root);
    }else{
        m_root = createLeaf(key);
    }
}
//******************************************************
// Add a new item in the tree, recursively
// if the tree is not empty this is an auxiliar function
// hidded from the user
//******************************************************
void BST::addLeaf_private(int key, Node* ptr){
    
        //if the value is less than the value in the node
        // we have to create the node to the left of the
        // actual node and place there the new key.
        if( key < ptr->m_key){
            
            // if the left pointer has already another node
            // we keep looking for a free node or leaf
            // otherwise we create the node and place the
            // new key on the newly created node
            if( ptr->m_left != nullptr)
                addLeaf_private(key, ptr->m_left);
            else
                ptr->m_left = createLeaf(key);
            
          
            //  Otherwise we have to create the node to the right of the
            // actual node and place there the new key.
        }else if( key > ptr->m_key){
           
            // if the right pointer has already another node
            // we keep looking for a free node or leaf
            // otherwise we create the node and place the
            // new key on the newly created node
            if( ptr->m_right != nullptr)
                addLeaf_private(key, ptr->m_right);
            else
                ptr->m_right = createLeaf(key);
        
        }else{
            // if the value or key already exist we prompt
            // the message that the value its already there
            std::cout << "The key: " << key << " already exist on the tree" << std::endl;
        }
// end of the method
}




//********************************
// Print in order (user interface)
//********************************

void BST::print_in_order(){
    
    if( m_root == nullptr){
        std::cout << "The tree is empty" << std::endl;
    }else{
        print_in_order(m_root);
        std::cout << std::endl;
    }
}

//********************************
// Print in order (private )
//********************************

void BST::print_in_order(BST::Node* ptr){
    
    /* 1.if the left pointer its not null
     * we keep seeking for the smallest
     * key value till we can't go down any more
     */
    if( ptr->m_left != nullptr){
        
        print_in_order(ptr->m_left);
        
    }
    //2. then we print the value
    ptr->show();
    /* 3.if the right pointer its not null
     * and after taking care of all the smallest
     * values, we go down to the next node on the right
     * till we can't go down any more
     */
    if( ptr->m_right != nullptr){
        print_in_order(ptr->m_right);
        
 
    }
    
}

//****************************************************
// return a particular node with the given key value
// (Private method)
//**************************************************

BST::Node* BST::get_node( int key,Node* ptr){
    
    if( ptr != nullptr){
        
        if(ptr->m_key == key){
           
            return ptr;
        
        }else if ( key < ptr->m_key){
            
                  return get_node(key,ptr->m_left);
        }else {
              return get_node(key,ptr->m_right);
         }
   
    }else {
        
        return nullptr;
    }
    
}


//****************************************************
// prompt to the screen the value of a parent node and
// its childs node if the node has child nodes
// (Private method)
//**************************************************
void BST::print_children( int* key){
    if( key == nullptr){
        return;
    }
    Node* ptr = get_node(*key, m_root);
    
    if( ptr != nullptr){
        std::cout << "Parent Node = ";
        ptr->show();
        std::cout  << std::endl;
        
        ptr->m_left == nullptr ?
        std::cout << "Left child = nullptr\n":
        std::cout << "Left child = " << ptr->m_left->m_key << std::endl;
        ptr->m_right == nullptr ?
        std::cout << "Right child = nullptr\n":
        std::cout << "Right child = " << ptr->m_right->m_key << std::endl;
    }
    else{
        std::cout << "Key ";
        ptr->show();
        std::cout << " is not in the tree\n";
    }
}

// we get the key value inside root if exist
int* BST::get_Root_key(){

    return &m_root->m_key;
}


//****************************************************
// prompt to the screen the value of a parent node and
// its childs node if the node has child nodes
// (Private method)
//**************************************************
void BST::print_children( int key){

    Node* ptr = get_node(key, m_root);
    
    if( ptr != nullptr){
        std::cout << "Parent Node = ";
        ptr->show();
        std::cout  << std::endl;
        
        ptr->m_left == nullptr ?
        std::cout << "Left child = nullptr\n":
        std::cout << "Left child = " << ptr->m_left->m_key << std::endl;
        ptr->m_right == nullptr ?
        std::cout << "Right child = nullptr\n":
        std::cout << "Right child = " << ptr->m_right->m_key << std::endl;
      
    }
    else{
        std::cout << "Key ";
        ptr->show();
        std::cout << " is not in the tree\n";
    }
      std::cout << std::endl;
}


//**************************************************
// Find the smallest value on the tree
// (Public method)
//**************************************************
int BST::find_Smallest(){
    
    return find_Smallest(m_root);
    
}


//*************************************************
// Find the smallest value on the tree
// (private method)
//*************************************************
int BST::find_Smallest(Node* ptr){
    if( m_root == nullptr){
        std::cout << "The tree is empty\n";
        return std::numeric_limits<int>::min() ;
    }else{
        
        if( ptr->m_left != nullptr){
            return find_Smallest(ptr->m_left);
        }else{
            return ptr->m_key;
        }
        
    }

}


//*************************************************
// Delete a particular node on the tree
// (public method)
//*************************************************
void BST::delete_node(int key){
    if( m_root != nullptr){
        delete_node(key,m_root);
    }else{
        std::cout << "The tree is empty\n" << std::endl;
    }
}

//*************************************************
// Delete a particular node on the tree
// (private method)
//*************************************************
void BST::delete_node(int key, Node*ptr){
    
    if( key  == ptr->m_key &&
       ptr->m_left == nullptr &&
       ptr->m_right == nullptr){
         //TODO
        delete ptr;
        
    }
    
}

















