#include <bits/stdc++.h>
#include "huffmanc.h"
using namespace std;


huffmanC::huffmanC(ifstream &text, ofstream &out){
    string line;
    float original = 0;
    while(getline(text,line)){
        original += line.size()*8;
        for(int i = 0; i < line.size(); i++){
            unordered_map<char,int>::iterator it = freqs.find(line[i]);
            if(it != freqs.end()){
                it->second++;
            }
            else{
                freqs.insert({line[i],1});
            }
        }
    }
    priority_queue<Node*, vector<Node* >, Comp > minHeap;
    for(auto it = freqs.begin(); it != freqs.end(); it++){
        minHeap.push(setNode(it->first,it->second,nullptr,nullptr));
    }
    while(minHeap.size() != 1){
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();

        int sum = left->freq + right->freq;
        minHeap.push(setNode('$',sum,left,right));
    }
    Node *root = minHeap.top();
    unordered_map<char,string> huffmanCode;
    int nodos = 0;
    codificar(root,"",huffmanCode,&nodos);
    float sum = 0;
    for(auto it = huffmanCode.begin(); it != huffmanCode.end(); it++){
        sum += it->second.size() * freqs[it->first];
    }
    out<<(sum/original)*100<<" & "<<nodos<<endl;
}

huffmanC::~huffmanC(){
}

huffmanC::Node* huffmanC::setNode(char ch, int freq, Node* left, Node* right){
    Node *node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}
void huffmanC::codificar(Node* node, string str, unordered_map<char,string> &huffmanCode,int *nodos){
    if(node == nullptr) return;
    (*nodos)++;
    if(!node->left && !node->right){
        huffmanCode[node->ch] = str;
    }
    codificar(node->left, str + "0",huffmanCode,nodos);
    codificar(node->right, str + "1",huffmanCode,nodos);
}