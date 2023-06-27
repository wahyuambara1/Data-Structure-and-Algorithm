#include <iostream>
#include <string>
#include "BinaryTree.h"

using namespace std;

void BinaryTree::insert(int insertID)
{
  root = insertRecursive(root, insertID);
}

Node *BinaryTree::insertRecursive(Node *currentRoot, int insertID)
{
  if (currentRoot == NULL)
  {
    currentRoot = new Node();
    currentRoot->id = insertID;
    return currentRoot;
  }

  if (insertID < currentRoot->id)
  {
    currentRoot->left = insertRecursive(currentRoot->left, insertID);
  }

  else if (insertID > currentRoot->id)
  {
    currentRoot->right = insertRecursive(currentRoot->right, insertID);
  }

  return currentRoot;
}

Node *BinaryTree::findMin()
{
  Node *node = root;
  while (node != NULL && node->left != NULL)
  {
    node = node->left;
  }

  if (node != NULL)
  {
    cout << "Minimum value: " << node->id << endl;
  }
  else
  {
    cout << "Binary tree is empty." << endl;
  }

  return node;
}

Node *BinaryTree::findMax()
{
  Node *node = root;
  while (node != NULL && node->right != NULL)
  {
    node = node->right;
  }

  if (node != NULL)
  {
    cout << "Maximum value: " << node->id << endl;
  }
  else
  {
    cout << "Binary tree is empty." << endl;
  }

  return node;
}

Node *BinaryTree::searchNode(Node *node, int val)
{
  if (node == NULL || node->id == val)
  {
    return node;
  }
  if (val < node->id)
  {
    return searchNode(node->left, val);
  }
  return searchNode(node->right, val);
}

Node *BinaryTree::search(int val)
{
  Node *result = searchNode(root, val);
  if (result != NULL)
  {
    cout << "Node with value " << val << " found in the tree.";
  }
  else
  {
    cout << "Node with value " << val << " not found in the tree." << endl;
  }
  return result;
}

void BinaryTree::inOrder()
{
  inOrderRecursive(root);
}

void BinaryTree::inOrderRecursive(Node *currentNode)
{
  if (currentNode != NULL)
  {
    inOrderRecursive(currentNode->left);
    cout << currentNode->id << ", ";
    inOrderRecursive(currentNode->right);
  }
}

void BinaryTree::preOrder()
{
  PreOrderRecursive(root);
}

void BinaryTree::PreOrderRecursive(Node *currentRoot)
{
  if (currentRoot != NULL)
  {
    cout << currentRoot->id << ",";
    inOrderRecursive(currentRoot->left);
    inOrderRecursive(currentRoot->right);
  }
}

void BinaryTree::postOrder()
{
  postOrderRecursive(root);
}

void BinaryTree::postOrderRecursive(Node *currentRoot)
{
  if (currentRoot != NULL)
  {
    inOrderRecursive(currentRoot->left);
    inOrderRecursive(currentRoot->right);
    cout << currentRoot->id << ",";
  }
}
