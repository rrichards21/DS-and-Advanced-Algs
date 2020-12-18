#include "BinarySearchTreeADT.h"


class BinarySearchTree: public BinarySearchTreeADT{
 private:
  node *_root=NULL;
  int _size;

 public:
  BinarySearchTree();
  ~BinarySearchTree();
  void insert(int);
  node *search(int);
  int size();
  void inorder(node *n);
  node* getRoot();
};
