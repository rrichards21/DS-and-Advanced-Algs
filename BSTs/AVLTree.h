#include "BinarySearchTreeADT.h"



class AVLTree: public BinarySearchTreeADT{
 private:
  int _size;
  node *_root;
  bool fixed;

 public:
  AVLTree();
  ~AVLTree();
  void insert(int);
  node *checkRotations(node *n, int val);
  node *rightRotate(node *n);
  node *leftRotate(node *n);
  node *search(int);
  int height(node *n);
  int size();
  void inorder(node *n);
  node *getRoot();
};
