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
    float original; //tamaño del texto original en bytes
    while(getline(text,line)){
        original += line.size()*8;  //se multiplica por 8 por el tamaño de cada char
        for(int i = 0; i <= line.size(); i++){
            if(i != line.size() && line[i] != ' '){ //se usarán espacios o fin de línea como separador de palabras
                word += line[i];    //so va generando la palabra
            }
            else{
                unordered_map<string,int>::iterator it;
                it = freqs.find(word);
                if(it != freqs.end()){  //si se encuentra la palabra se le suma a su frecuencia
                    it->second++;
                }
                else{
                    freqs.insert({word,1}); //si no se encuentra se agrega al diccionario con frecuencia 1
                }
                if( i == line.size()){  //si el caracter fue un salto de línea se agrega al diccionario o se le suma a su frecuencia
                    it = freqs.find("\n");
                    if(it != freqs.end()){
                        it->second++;
                    }
                    else{
                        freqs.insert({"\n",1});
                    }
                }
                else if(line[i] == ' '){    //si el caracter fue un espacio se agrega al diccionario o se le suma a su frecuencia
                    it = freqs.find(" ");
                    if(it != freqs.end()){
                        it->second++;
                    }
                    else{
                        freqs.insert({" ",1});
                    }
                }
                word = "";  //se vacia word para generar una nueva palabra
            }
        }
    }
    priority_queue<Node*, vector<Node*>, Comp > minHeap;    //minHeap para generar el árbol de huffman
    for(auto it = freqs.begin(); it != freqs.end(); it++){
        minHeap.push(setNode(it->first,it->second,nullptr,nullptr));    //se agregan al minheap comparando por frecuencia menor
    }
    while(minHeap.size() != 1){
        //se obtienen los dos nodos con menor frecuencia
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();

        //se realiza la suma de las frecuencias de ambos nodos
        int sum = left->freq + right->freq;
        //se agrega el nodo resultante por la suma de ambos y se le agregan como hijos estos
        minHeap.push(setNode("$",sum,left,right));
    }
    Node *root = minHeap.top();
    unordered_map<string,string> huffmanCode;   //map que contendrá los códigos para comprimir las palabras
    int nodos = 0;
    codificar(root,"",huffmanCode,&nodos);
    float sum = 0;
    for(auto it = huffmanCode.begin(); it != huffmanCode.end(); it++){
        sum += it->second.size() * freqs[it->first];
    }
    out<<(sum/original)*100<<" & "<<nodos<<" & ";
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
    //si se encuentra una hoja se asigna el código resultante por el recorrido hasta esa hoja
    if(!node->left && !node->right){
        huffmanCode[node->str] = str;
    }
    //se va asignando 0 o 1 al código de una palabra hasta encontrarla
    codificar(node->left, str + "0",huffmanCode,nodes);
    codificar(node->right, str + "1",huffmanCode,nodes);
}