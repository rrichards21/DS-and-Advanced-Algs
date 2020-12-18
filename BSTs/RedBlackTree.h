#include "BinarySearchTreeADT.h"
#include <bits/stdc++.h>


class RedBlackTree: public BinarySearchTreeADT{
 private:
  node *_root=NULL;
  node *_nulo=NULL;
  int _size;
  void VerificarInsercion(node *n);
  void RotarDerecha(node *n);
  void RotarIzquierda(node *n);

 public:
  RedBlackTree();
  ~RedBlackTree();
  void insert(int);
  node *search(int);
  int size();
  void inorder(node *n);
  node *getRoot();
};
