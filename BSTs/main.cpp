#include <bits/stdc++.h>
#include "BinarySearchTree.h"
#include "AVLTree.h"

using namespace std;

int main(){
  //BinarySearchTreeADT *bst1 = new BinarySearchTree();
  BinarySearchTreeADT *avl = new AVLTree();
  int n;
  cin>>n;
  vector<int> v;
  //cin>>n;

  for (int i = 1; i <= n; ++i) v.push_back(i);
  random_shuffle(v.begin(),v.end());
  for(int i = 0; i < v.size(); i++) cout<<v[i]<<" ";
  cout<<endl;
  for (vector<int>::iterator i = v.begin(); i != v.end(); ++i){
    avl->insert(*i);
  }
  avl->inorder(avl->getRoot());
  return 0;
}
