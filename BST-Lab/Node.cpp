#include "Node.h"

Node::Node() {
  value = 0;
  *leftChild = NULL;
  *rightChild = NULL;
}
Node::Node(int data) {
  value = data;
  *leftChild = NULL;
  *rightChild = NULL;
}
Node::~Node() {

}

/*
 * Returns the data that is stored in this node
 *
 * @return the data that is stored in this node.
 */
int Node::getData() const {
  return value;
}

/*
 * Returns the left child of this node or null if it doesn't have one.
 *
 * @return the left child of this node or null if it doesn't have one.
 */
NodeInterface * Node::getLeftChild() const {
  return leftChild;
}

/*
 * Returns the right child of this node or null if it doesn't have one.
 *
 * @return the right child of this node or null if it doesn't have one.
 */
NodeInterface * Node::getRightChild() const {
  return rightChild;
}