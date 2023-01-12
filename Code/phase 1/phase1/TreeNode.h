#ifndef TREENODE_H
#define TREENODE_H

#include "iostream"
#include "string.h"
#include "vector"

using namespace std ;

class Node
{
public:
    string data ;
    Node * parent ;
    vector<Node *> children_conatiner ;

};



#endif // TREENODE_H
