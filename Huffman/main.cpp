#include <bits/stdc++.h>
#include "huffman.h"
#include "huffmanc.h"

using namespace std;

int main(int argc, char *argv[]){
    if(argc <= 2){
        cout<<"No se ingresaron los argumentos necesarios"<<endl;
        return -1;
    }
    ifstream text;
    text.open(argv[1],ios_base::in);
    ofstream output;
    output.open("output",ios_base::app);
    if(strcmp(argv[2],"-wl") == 0){
        output<<argv[1]<<" & ";
        huffmanS *huff = new huffmanS(text,output);
        delete huff;
    }
    else  if (strcmp(argv[2],"-c") == 0) {
        huffmanC *huff = new huffmanC(text,output);
        delete huff;
    }
    else{
        cout<<"Opción ingresada incorrecta."<<endl;
        return -1;
    }
    return 0;
}