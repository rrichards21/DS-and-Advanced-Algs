#include <bits/stdc++.h>
#include "huffman.h"
#include "huffmanc.h"

using namespace std;

int main(int argc, char *argv[]){
    if(argc == 0){
        cout<<"No se ingresaron los argumentos"<<endl;
        return -1;
    }
    ifstream text;
    text.open(argv[1],ios_base::in);
    ofstream output;
    output.open("output",ios_base::app);
    if(strcmp(argv[2],"-wl") == 0){
        output<<argv[1]<<" ";
        huffmanS *huff = new huffmanS(text,output);
    }
    else  if (strcmp(argv[2],"-c") == 0) {
        huffmanC *huff = new huffmanC(text,output);
    }
    return 0;
}