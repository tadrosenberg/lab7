#include "BST.h"

using namespace std;

BST::BST()
{
}
BST::~BST()
{
}

// Please note that the class that implements this interface must be made
// of objects which implement the NodeInterface

/*
 * Returns the root node for this tree
 *
 * @return the root node for this tree.
 */
NodeInterface *BST::getRootNode() const
{
  return root;
}

/*
 * Attempts to add the given int to the BST tree
 *
 * @return true if added
 * @return false if unsuccessful (i.e. the int is already in tree)
 */
bool BST::add(int data)
{
  return addHelper(data, root);
}

bool BST::addHelper(int data, Node *&node)
{
  if (node == NULL)
  {
    node = new Node(data);
    return true;
  }
  if (node->value == data)
  {
    return false;
  }
  else if (data > node->value)
  {
    return addHelper(data, node->rightChild);
  }
  else
  {
    return addHelper(data, node->leftChild);
  }
}

/*
 * Attempts to remove the given int from the BST tree
 *
 * @return true if successfully removed
 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
 */
bool BST::remove(int data)
{
  return removeHelper(data, root);
}

bool BST::removeHelper(int data, Node *&node)
{
  if (node == NULL)
  {
    return false;
  }
  if (node->value == data)
  {
    Node* temp = node->leftChild;
    Node* parent = node;
    if (node->rightChild != NULL && node->leftChild != NULL) // two children
    {                                  
      while (temp->rightChild != NULL) // while there is still a right child, go another layer down to right (find greatest of the left subtree)
      {
        parent = temp;
        temp = temp->rightChild;
      }
      parent->rightChild = temp->leftChild;
      node = temp;
      delete temp;
      return true;
    }

    else if (node->rightChild == NULL || node->leftChild == NULL) // one child
    {
      Node *temp;
      temp = node->leftChild;
      if (node->leftChild == NULL)
      {
        temp = node->rightChild;
      }
      delete node;
      node = temp;
      return true;
    }

    else
    { // no children (leaf node)
      delete node;
      node = NULL;
    }

    return true;
  }
  else if (data > node->value)
  {
    return removeHelper(data, node->rightChild);
  }
  else
  {
    return removeHelper(data, node->leftChild);
  }
}

/*
 * Removes all nodes from the tree, resulting in an empty tree.
 */
void BST::clear()
{
  clearHelper(root);
  root = NULL;
}

void BST::clearHelper(Node *&node)
{
  if (node == NULL)
    {
      return;
    }
    if (node->leftChild != NULL)
    {
        clearHelper(node->leftChild);
    }
    if (node->rightChild != NULL)
    {
      clearHelper(node->rightChild);
    }

    delete node;
    return;
}