#include <bits/stdc++.h>
using namespace std;
int main(){
	string linea;
	ifstream input;
	input.open("dna",ios_base::in);
	ofstream inp;
	inp.open("input",ios_base::out);
	string s2;
	int j;
	for(int i = 0; i < 15; i++) getline(input,linea);
	for(int i = 0; i <= 100000; i += 5000){
		getline(input,linea);
		for(j = 0; j < i; j++){
			s2 += linea[j];
		}
		s2 += '\n';
		cout<<s2.size()<<endl;
		inp<<s2;
		s2 = "";
	}

	return 0;
}