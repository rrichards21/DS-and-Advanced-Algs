#include <bits/stdc++.h>
#include "suffixArray.h"

using namespace std;

int main(){
	string s = "banana";
	string pattern = "ana";
	for(int i = 0; i < 100; i++){
		cout<<i<<" creando sa de tamaño: "<<s.size()<<endl;
		suffixArray sa(s);
		cout<<"creado sa"<<endl;
		// sa.search(pattern);
		//sa.patternMatching(pattern);
		// cout<<i<<endl;
		s += s;
		// cout<<"añadido mas"<<endl;
		// pattern = s.substr(rand()%i);
		sa.~suffixArray();
		// cout<<pattern<<endl;
		cout<<"fin"<<endl;
	}
	return 0;
}
