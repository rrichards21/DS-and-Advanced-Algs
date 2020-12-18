#ifndef BST_H
#define BST_H
struct node{
  int num;
  int height;
  node* parent;
  node *left;
  node *right;
  bool isRed;
};
class BinarySearchTreeADT {

 public:
  virtual void insert(int) = 0;
  virtual node* search(int) = 0;
  virtual int size() = 0;
  virtual void inorder(node *n) = 0;
  virtual node* getRoot() = 0;
};

#endif
