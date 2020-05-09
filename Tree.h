// Version 2
#ifndef TREE_H
#define TREE_H
#include<iostream>
#include <cstddef>
using namespace std;
template<typename TreeType> class TreeNode
{
      public:
        //TreeNode<TreeType>();
        //TreeNode<TreeType>(TreeType k);
        // TreeNode(ink, <type> v); // if you were working with multiple values
        ~TreeNode<TreeType>();
        // research virtual
        // virtual ~TreeNode(); - when working with a template class

        // key contains the unique key id
        unsigned int key;
        TreeType *classNode;
        TreeNode<TreeType> *left;
        TreeNode<TreeType> *right;
        TreeNode<TreeType> *parent;
    // treenode implementation
    TreeNode<TreeType>()
    {
       key = 0;
       left = NULL;
       right = NULL;
       parent = NULL;

    }
    TreeNode<TreeType>(unsigned int k, TreeType *data)
    {
      key = k;
      classNode = data;
      left = NULL;
      right = NULL;
      parent = NULL;

    }
};

// TODO implementation of destructor

template<typename TreeType> class BST
{
      //private:
        //TreeNode<TreeType> *root;
      public:
        TreeNode<TreeType> *root;


    BST<TreeType>()
    {
      root = NULL; // EMPTY TREE bc no nodes
    }

    ~BST<TreeType>()
    {
      // todo:
    }

    // This will print the keys by using recursion
    void printTreeRecursive(TreeNode<TreeType> *node)
    {
      if(node == NULL )
      {
        return;
      }
      printTreeRecursive(node->left);
      cout << node->key<< endl;
      printTreeRecursive(node->right);
    }
    void printTree()
    {
      cout << "Printing Tree" << endl;
      printTreeRecursive(root);
    }

    // prints the Tree node
    void printTreeNodeRecursive(TreeNode<TreeType> *node)
    {
      if(node == NULL )
      {
        return;
      }
      printTreeNodeRecursive(node->left);
      //cout << "ID: " << node->key << " " << *node->classNode << endl;
      cout << *node->classNode << endl;
      printTreeNodeRecursive(node->right);
    }
    void printTreeNodes()
    {
      cout << "==Printing Tree Node Information==" << endl;
      printTreeNodeRecursive(root);
    }

    void printTreeNode(unsigned int id)
    {
      cout << *get(id) << endl;

    }

    TreeType getMax()
    {
      TreeNode<TreeType> *curr = root;
      if(root == NULL)
      {
        return NULL;
      }
      while(curr->right != NULL)
      {
        curr = curr->right;
      }
      return curr->key;// you could return the value return curr->value;
    }

    bool isEmpty()
    {
      return(root == NULL);
    }


    void insert(unsigned int key, TreeType *classNode)
    {
      cout << "===========Start=============" << endl;
      TreeNode<TreeType>* node = new TreeNode<TreeType>(key, classNode);
      //cout << "inserting value: " << value << endl;
      if(search(key))
      {
        cout << "key already exists" << endl;
        return;
      }
      if(isEmpty())
      {
        // empty tree
        cout << "It's empty so adding root"<< endl;
        root = node;
      }
      else
      {
        // not an empty tree
        TreeNode<TreeType> *curr = root; // start at the root
        TreeNode<TreeType> *parent;
        while(true)
        {
          parent = curr;

          if(key < curr->key)
          {
            cout << "going left" << endl;
            // go left
            curr = curr->left;
            if(curr == NULL)
            {
              cout << "Current is null" << endl;
              parent->left = node;
              node->parent = parent;
              cout << "Now parent is on left" << endl;
              // added this break
              break;
            }

          }
          else
          {
            cout << "In else statement: going right" << endl;
              // go right
              curr = curr->right;
              if(curr == NULL)
              {
                cout << "In right: NULL" << endl;
                parent->right = node;
                node->parent = parent;
                // need break otherwise you will segfault
                break;
              }

          }
        }
      }
    }
   // TODO: create another function and rename search to check tree.
    bool search(unsigned int value)
    {
      if(isEmpty())
         return false;
      else{
        // its not an empty tree
        TreeNode<TreeType> *current = root;
        while(current->key != value){
           if(value < current->key)
             current = current->left;
           else
             current = current->right;
           if(current == NULL) // we didn't find value
              return false;
        }
      }
     return true; // we found it

    }

    // get - given the student ID, it returns the node
    TreeType *get (unsigned int id)
    {
      TreeNode<TreeType> *current = root;
      if(isEmpty())
         return NULL;
      else{
        // its not an empty tree
        while(current->key != id){
           if(id < current->key)
             current = current->left;
           else
             current = current->right;
           if(current == NULL) // we didn't find value
              return NULL;
        }
      }
     return current->classNode; // we found it
    }


    // cases to delete node
    // 1. leaf node - easy
    // 2. has 2 children- hard
    bool deleteNode(unsigned int k)
    {
      if(isEmpty())
          return false;
      TreeNode<TreeType> *parent = root;
      TreeNode<TreeType> *current = root;
      bool isLeft = true;

      while(current->key != k)
      {
        parent = current;
        if(k < current->key)
        {
          isLeft = true;
          current = current->left;
        }
        else
        {
          isLeft = false;
          current = current->right;
        }
        // check if it's not in the tree
        if(current == NULL)
           return false;
      }
      // if we make it here, we found the value not let's proceed to delete
      // case1: leaf node - no children
      if(current->left == NULL && current->right == NULL)
      {
        // then we have a leaf treenode
        // 1. determine if its a root
        if(current == root)
        {
          root = NULL;
        }
        // we had more than one node in the tree
        else if(isLeft)
        {
          parent->left = NULL;
        }
        else
        {
          parent->right = NULL;
        }
      }
      // determine if the node we are deleting has 1 child but it is not a left child
      // 1 child and its a left child
      else if(current->right == NULL)// NO RIGHT CHILD, SO IT MUST HAVE A LEFT CHILD
      {
        if(current == root)
        {
          root = current->left;
        }
        else if(isLeft)
        {
          parent->left = current->left;
        }
        else
        {
          parent->right = current->left;
        }

      }
       // no left child, so it must have a right child
       // this else if determines position of chiuldren of node to be deleted
      else if(current->left == NULL)// NO LEFT CHILD, SO IT MUST HAVE A LEFT CHILD
      {
        if(current == root)
        {
          root = current->right;
        }
        else if(isLeft)
        {
          parent->left = current->right;
        }
        else
        {
          parent->right = current->right;
        }

      }
      // 2 children
      else{
        // the node to be deleted has two children
        TreeNode<TreeType> *successor = getSuccessor(current);
        if(current == root)
        {
          root = successor;
        }
        else if(isLeft)
        {
          parent->left = successor;
        }
        else
        {
          parent->right = successor;
        }
        // connect/link successor to current's(d) left child
        successor->left = current->left;
      }
    }

  // get child node with min value of specified node
  // keep going down left hand side of subtree
  TreeNode<TreeType>*  getMinNode(TreeNode<TreeType> *node)
  {
    TreeNode<TreeType> *curr = node;
    if(root == NULL)
    {
      return NULL;
    }
    // loop down to find the left most leaf node
    while(curr->left != NULL)
    {
      curr = curr->left;
    }
    return curr;
  }

  // testing getSuccessor
  TreeNode<TreeType>* getSuccessor(TreeNode<TreeType> *node)
  {
       // if we can get the minimum of the right subtree; that will be the successor.
        if(node->right != NULL)
        {
          return getMinNode(node->right);
        }

      // otherwise, we have to move up the tree to find the sucessor
        TreeNode<TreeType> *p = node->parent;
        while(p != NULL && node == p->right)
        {
          node = p;
          p = p->parent;
        }
        return p;
}
// alternative way to approach get successor
#if 0
    // the parameter d represents the node to be deleted
    TreeNode<TreeType> *current = node->right;
    // sp - successor's parent
    TreeNode<TreeType> *sp = node;
    TreeNode<TreeType> *successor = node;
    while(current != NULL)
    {
      sp = successor;
      successor = current;
      // until current equal's NULL we go all the way left
      current = current->left;
    }
    // if the successor is not the right child of the node to be
    // deleted then we do this (if is the right child then it is the node)
    if(successor != node->right)
    {
      sp->left = successor->right;
      successor->right = node->right;
    }
    return successor;
  }// end of class

#endif

};
#endif
