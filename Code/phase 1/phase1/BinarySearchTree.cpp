#include "BinarySearchTree.h"

//Node * Tree::newNode(string key)
//{
//    Node * new_node = new Node ;
//    new_node->key = key ;
//    new_node->next = new_node->child = nullptr ;
//    return new_node ;
//}

//Node * Tree::addSibling (Node * node , string data)
//{
//    if (node == nullptr)
//    {
//        return nullptr;
//    }
//    while(node->next)
//    {
//        node = node->next ;
//    }
//    node->next = newNode(data) ;

//    return node->next;
//}

//Node * Tree::addChild(Node * target_node , string data)
//{
//    if (target_node == nullptr)
//    {
//        return nullptr ;
//    }
//    // Check if child list is not empty.
//    if(target_node->child)
//    {
//        return addSibling(target_node->child , data) ;
//    }
//    else
//    {
//        return (target_node->child = newNode(data)) ;
//    }

//}



