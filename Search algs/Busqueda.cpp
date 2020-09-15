#include <bits/stdc++.h>
#include "Busqueda.h"

using namespace std;

Busqueda::Busqueda(int n) {
  this->vec = new int[n];
    
  srand(time(NULL));

  for(int i=0;i<n;i++) {
    this->vec[i] = i;
  }
  this->tam = n;
  //sort(this->vec,this->vec + this->tam);
  
  
  //for(int i=0;i<this->tam;i++) cout<<this->vec[i]<<" ";
  //puts("");

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


int Busqueda::binaria(int num){
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

int Busqueda::doblada(int num){
  if(this->vec[0] == num) return 0;
  int lim = 1;
  while(lim < this->tam-1 && this->vec[lim] <= num){
    lim *= 2;
  }
  int l=lim/2;
  lim = min(lim,this->tam-1);
  while(l<=lim){
    int m=(l+lim)/2;
    if(this->vec[m]==num) return m;
    if(this->vec[m]>num) lim=m-1;
    if(this->vec[m]<num) l=m+1;
  }
  return -1;

}