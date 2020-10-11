#include <bits/stdc++.h>
#include "huffman.h"
using namespace std;

struct Comp { 
    constexpr bool operator()( 
        pair<string, int> const& a, 
        pair<string, int> const& b) 
        const noexcept 
    { 
        return a.second > b.second; 
    } 
}; 

huffmanS::huffmanS(ifstream &text, ofstream &out){
    string word = "";
    string line;
    float original;
    while(getline(text,line)){
        original += line.size()*8;
        for(int i = 0; i <= line.size(); i++){
            if(i != line.size() && line[i] != ' '){
                word += line[i];
            }
            else{
                unordered_map<string,int>::iterator it;
                it = freqs.find(word);
                if(it != freqs.end()){
                    it->second++;
                }
                else{
                    freqs.insert({word,1});
                }
                if( i == line.size()){
                    it = freqs.find("\n");
                    if(it != freqs.end()){
                        it->second++;
                    }
                    else{
                        freqs.insert({"\n",1});
                    }
                }
                else if(line[i] == ' '){
                    it = freqs.find(" ");
                    if(it != freqs.end()){
                        it->second++;
                    }
                    else{
                        freqs.insert({" ",1});
                    }
                }
                word = "";
            }
        }
    }
    priority_queue<Node*, vector<Node*>, Comp > minHeap;
    for(auto it = freqs.begin(); it != freqs.end(); it++){
        minHeap.push(setNode(it->first,it->second,nullptr,nullptr));
    }
    while(minHeap.size() != 1){
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();

        int sum = left->freq + right->freq;
        minHeap.push(setNode("$",sum,left,right));
    }
    Node *root = minHeap.top();
    unordered_map<string,string> huffmanCode;
    int nodos = 0;
    codificar(root,"",huffmanCode,&nodos);
    float sum = 0;
    for(auto it = huffmanCode.begin(); it != huffmanCode.end(); it++){
        sum += it->second.size() * freqs[it->first];
    }
    out<<(sum/original)*100<<" "<<nodos<<" ";
}

huffmanS::~huffmanS(){
    
}

huffmanS::Node* huffmanS::setNode(string str, int freq, Node* left, Node* right){
    Node *node = new Node();
    node->str = str;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}
void huffmanS::codificar(Node* node, string str, unordered_map<string,string> &huffmanCode,int *nodes){
    if(node == nullptr) return;
    (*nodes)++;
    if(!node->left && !node->right){
        huffmanCode[node->str] = str;
    }
    codificar(node->left, str + "0",huffmanCode,nodes);
    codificar(node->right, str + "1",huffmanCode,nodes);
}