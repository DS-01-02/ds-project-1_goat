#ifndef POSITION_H
#define POSITION_H

#include "TreeNode.h"
#include "BinarySearchTree.h"



class Position
{
public:

    Node * v ;

public:
    Position()
    {
        v = new Node ;
    }
    string & operator * ()
    {
        return v->data ;
    }
    Node * parent () const //return parent
    {
        return v->parent;
    }

    bool isRoot() //root node ?
    {
        return v->parent == nullptr ;
    }
    bool isExternal() // externla node
    {
        return v->children_conatiner.size() == 0 ;
    }

    friend class Tree ;
};


#endif // POSITION_H
