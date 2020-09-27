#include <bits/stdc++.h>
#include "suffixArray.h"

using namespace std;


suffixArray::suffixArray(string &text) {
  _text = new char[text.size()+1];
  strcpy(_text,text.c_str());
  _arr = new int[text.size()+1];
  for(int i = 0; i <= text.size(); i++){
    _arr[i] = i;
  }
  sort(_arr,_arr+text.size()+1,[this](const int i, const int j){return strcmp(this->_text+i,this->_text+j) <= 0 ? true : false;});
}

suffixArray::~suffixArray(){
  delete[] this->_arr;
  delete[] this->_text;
}


int suffixArray::search(const string &pattern)const{
  int n = (int)strlen(pattern.c_str());
  int l = 0;
  int r = strlen(_text);
  int m;
  pair<int,int> lim;
  while (l<r)
  {
    m = (l+r)/2;
    int comp = strncmp(_text+_arr[m],pattern.c_str(),n);
    if(comp >= 0) r = m;
    else l = m+1;
  }
  if(strncmp(_text+_arr[l],pattern.c_str(),n) != 0) return -1;
  lim.first = l;
  r = strlen(_text);
  while(l<r){
  	m = (l+r)/2;
    int comp = strncmp(_text+_arr[m],pattern.c_str(),n);
    if(comp > 0) r = m;
    else l = m+1;
  }
  if(strncmp(_text+_arr[r],pattern.c_str(),n) != 0) r--;
  lim.second = r;
  return lim.second-lim.first+1;
}

int suffixArray::patternMatching(const string &pattern)const{
  int j;
  int ocurrencias = 0;
  int n = (int)strlen(pattern.c_str());
  for(int i = 0; i < strlen(_text); i++){
    for(j = 0; j < pattern.size(); j++){
    	//cout<<i<<".- compare: "<<_text[i+j]<<","<<pattern[j]<<endl;;
      if(_text[i+j] != pattern[j]) break;
    }
    if(j == pattern.size()){
      ocurrencias++;
    }
  }
  return ocurrencias;
}
