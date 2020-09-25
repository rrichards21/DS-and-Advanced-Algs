#include <bits/stdc++.h>
#include "suffixArray.h"

using namespace std;

bool comp(int i, int j){
  return i>j;
}

suffixArray::suffixArray(const string &text) {
  cout<<"pasando"<<endl;  
  _text = new char[text.size()+1];
  cout<<"aqui muere"<<endl;
  strcpy(_text,text.c_str());
  _arr = new int[text.size()+1];
  for(int i = 0; i <= text.size(); i++){
    _arr[i] = i;
  }
  sort(_arr,_arr+text.size()+1,[this](const int i, const int j){return strcmp(this->_text+i,this->_text+j) <= 0 ? true : false;});
  // for(int i = 0; i <= text.size(); i++){
  //   cout<<_text+i<<" ";
  // }
  // cout<<endl;
  // for(int i = 0; i <= text.size(); i++){
  //   cout<<_arr[i]<<" ";
  // }
  // cout<<endl;
  // for(int i = 0; i <= text.size(); i++){
  //   cout<<_text+_arr[i]<<" ";
  // }
  // cout<<endl;
}

suffixArray::~suffixArray(){
  delete[] this->_arr;
  delete[] this->_text;
}


int suffixArray::search(const string &pattern)const{
  int l = 0;
  int r = strlen(_text);
  while (l<=r)
  {
    int m = (l+r)/2;
    if(strcmp(_text+_arr[m],pattern.c_str()) == 0) return _arr[m];
    if(strcmp(_text+_arr[m],pattern.c_str()) > 0) r = m-1;
    else if(strcmp(_text+_arr[m],pattern.c_str()) < 0) l = m+1;
  }
  return -1;
  
}

int suffixArray::patternMatching(const string &pattern)const{
  for(int i = 0; i < strlen(_text); i++){
    for(int j = 0; j < pattern.size(); j++){

    }
  }
}