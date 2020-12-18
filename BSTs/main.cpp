#include <bits/stdc++.h>
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "RedBlackTree.h"

using namespace std;

int main(){
  BinarySearchTreeADT *bst = new BinarySearchTree();
  BinarySearchTreeADT *avl = new AVLTree();
  BinarySearchTreeADT *rbt = new RedBlackTree();
  int n;
  cin>>n;
  vector<int> v;
  clock_t begin;
  ofstream out;
  out.open("output.txt",ios_base::out);
  int j = 1;
  for(int i = 1; i <= n; ++i) v.push_back(i);
  //random_shuffle(v.begin(),v.end());
  for(int i = 0; i < v.size(); ++i) cout<<v[i]<<" ";
  for(vector<int>::iterator i = v.begin(); i != v.end(); ++i){
      avl->insert(*i);
  }
  cout<<endl;
  avl->inorder(avl->getRoot());
  while(n < 100000000){
    cout<<n<<endl;
    out<<n<<" ";
    j++;
    for(int i = 1; i <= n; ++i) v.push_back(i);
    //random_shuffle(v.begin(),v.end());

    begin = clock();
    for(vector<int>::iterator i = v.begin(); i != v.end(); ++i){
      avl->insert(*i);
    }
    clock_t end = clock();
    begin = clock();
    for(int i = 0; i < 10000; i++) avl->search(random()%v.size() + 1);
    end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC*10000;
    out<<time_spent<<" ";

    begin = clock();
    for(vector<int>::iterator i = v.begin(); i != v.end(); ++i){
      rbt->insert(*i);
    }
    end = clock();
    begin = clock();
    for(int i = 0; i < 10000; i++) rbt->search(random()%v.size() + 1);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC*10000;
    out<<time_spent<<endl;
    n *= 10;
    v.resize(0);
  }
  cout<<"ajsd"<<endl;
  return 0;
}
