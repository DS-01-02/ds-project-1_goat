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

//void Tree::LevelOrderTraversal(Node *root, bool flag)
//{
//    if ( root == nullptr)
//    {
//        return ;
//    }
//    fstream tree_node ;
//    //For checking whether it is from ZippingProcess.cpp or not .
//    if(flag)
//    {
//        tree_node.open("tree_property.txt" , ios::out);
//        if (tree_node.is_open())
//        {
//            tree_node << root->key << endl;
//        }
//        else
//        {
//            cerr << "File could not open\n" ;
//        }
//        tree_node.close() ;
//    }

//    //cout << root->key << endl;

//    //Standard level order traversal code
//    //using queue
//    queue <Node *> Queue ;
//    Node * current = root->child ;
//    Queue.push(current) ;
//    while(!Queue.empty())
//    {

//        //Take our an item from the queue
//        current = Queue.front();
//        Queue.pop();
//        // Print next level of taken out item and enqueue next level's children
//        while (current != nullptr)
//        {
//            //cout << current->key << " " ;
//            if (flag)
//            {
//                tree_node.open("tree_property.txt" , ios::app);
//                if (tree_node.is_open())
//                {
//                    tree_node << current->key << endl;
//                }
//                else
//                {
//                    cerr << "File could not open\n" ;
//                }
//                tree_node.close() ;
//            }
//            if (current->child != nullptr)
//            {
//                Queue.push(current->child);
//            }
//            current = current->next ;
//        }

//    }
//}



//void Tree::TreeInorder(Node *node)
//{
//    if(node->child->next == nullptr)
//    {
//        cerr <<node->child->key << " ";
//        cerr << node->key << " " ;
//        return ;
//    }
//    Node * current = node ->child ;
//    while ( current->next->next != nullptr)
//    {
//        cerr << current->key << " " ;
//        current = current->next ;
//    }
//    cerr<<current->key << " " ;
//    cerr<<node->key << " " ;
//    current = current->next ;
//    TreeInorder(current) ;




//}

//void Tree::inorder(Node *node , int children_count )
//{

//    if (node == nullptr)
//    {
//        return ;
//    }
//    //All the children except the last one
//    for (int i = 0 ; i < children_count -1 ; i ++)
//    {
//        inorder(node->child ,children_count) ;
//    }
//    cout<< node->key << " ";
//    inorder(node->child ,children_count) ;


//}

