#ifndef HUFFMANNS
#define HUFFMANNS
using namespace std;

class huffmanS{
    private:
        struct Node{
            string str;
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
        unordered_map<string,int> freqs;
    public:
        huffmanS(ifstream &text,ofstream&);
        ~huffmanS();
        Node* setNode(string,int,Node*,Node*);
        void codificar(Node* node,string,unordered_map<string,string>&,int*);
};
#endif