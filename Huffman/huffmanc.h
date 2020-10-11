#ifndef HUFFMANNC
#define HUFFMANNC
using namespace std;

class huffmanC{
 private:
    struct Node{
        char ch;
        int freq;
        Node *left, *right;
    };
    struct Comp { 
        constexpr bool operator()( 
            Node* const& l, 
            Node* const& r) 
            const noexcept 
        { 
            return l->freq > r->freq; 
        } 
    };
    char *_text;
    int *_arr;
    unordered_map<char,int> freqs;
 public:
    huffmanC(ifstream &text, ofstream&);
    ~huffmanC();
    Node* setNode(char,int,Node*,Node*);
    void codificar(Node* node,string,unordered_map<char,string>&,int*);
};
#endif