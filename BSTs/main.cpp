#include <bits/stdc++.h>
#include "BinarySearchTree.h"
#include "AVLTree.h"

using namespace std;

int main(){
  BinarySearchTreeADT *bst = new BinarySearchTree();
  BinarySearchTreeADT *avl = new AVLTree();
  //BinarySearchTreeADT *rbt = new RedBlackTree();
  int n;
  cin>>n;
  vector<int> v;
  clock_t begin;
  ofstream out;
  out.open("output.txt",ios_base::out);
  int j = 1;
  for(int i = 1; i <= n; ++i) v.push_back(i);
  random_shuffle(v.begin(),v.end());
  for(vector<int>::iterator i = v.begin(); i != v.end(); ++i){
    avl->insert(*i);
    cout<<*i<<" "<<j++<<endl;
  }

  /*
  while(n <= 100000000){
    cout<<n<<endl;
    out<<j<<" ";
    j++;
    for(int i = 1; i <= n; ++i) v.push_back(i);
    random_shuffle(v.begin(),v.end());

    begin = clock();
    for(vector<int>::iterator i = v.begin(); i != v.end(); ++i){
      avl->insert(*i);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    out<<time_spent<<" ";
    /*
    beging = clock();
    for(vector<int>::iterator i = v.begin(); i != v.end(); ++i){
      rbt->insert(*i);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    out<<time_spent<<endl;
    v.resize(0);
    out<<endl;
    n *= 10;
  }
  */


  cout<<"jaksd"<<endl;
  //avl->inorder(avl->getRoot());
  return 0;
}
