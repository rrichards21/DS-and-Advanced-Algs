#include <bits/stdc++.h>
#include "Busqueda.h"

using namespace std;

Busqueda::Busqueda(int n) {
  this->vec = new int[n];
    
  srand(time(NULL));

  for(int i=0;i<n;i++) {
    this->vec[i] = rand() % n + 1;
  }
  this->tam = n;
  sort(this->vec,this->vec + this->tam);
  
  
  for(int i=0;i<this->tam;i++) cout<<this->vec[i]<<" ";
  puts("");

}

Busqueda::~Busqueda(){
  delete this->vec;
}
int Busqueda::size(){
  return this->tam;
}

int Busqueda::lineal(int num){
  for(int i=0;i<this->tam;i++){
    if(this->vec[i]==num) return i;
  }
  return -1;
}

int Busqueda::binariaRecursiva(int num,int l,int r){
  int m=(l+r)/2;
  if(this->vec[m]==num) return m;
  else if(this->vec[m]!=num && r<=l) return -1; //cuando el numero no está
  else if(this->vec[m]>num) return binariaRecursiva(num,l,m-1);
  else return binariaRecursiva(num,m+1,r);
}

int Busqueda::binariaIterativa(int num){
  int l=0;
  int r=this->tam-1;
  while(l<=r){
    int m=(l+r)/2;
    if(this->vec[m]==num) return m;
    if(this->vec[m]>num) r=m-1;
    if(this->vec[m]<num) l=m+1;
  }
  return -1;

}
