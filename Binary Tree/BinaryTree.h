#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
  int id;
  string name;
  Node *left;
  Node *right;

  Node()
  {
    left = right = NULL;
  }
};

class BinaryTree
{
public:
  Node *root;

  void insert(int);
  void Delete(int);

  Node *insertRecursive(Node *, int);

  void preOrder();
  void PreOrderRecursive(Node *);

  void inOrder();
  void inOrderRecursive(Node *);

  void postOrder();
  void postOrderRecursive(Node *);

  Node *search(int);
  Node *searchNode(Node *, int);

  Node *findMin();
  Node *findMax();

  BinaryTree()
  {
    root = NULL;
  }
};
