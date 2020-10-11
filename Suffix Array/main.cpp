#include <bits/stdc++.h>
#include "suffixArray.h"

using namespace std;

vector<string> generarInput(ifstream& input){
	string linea;
	string pattern;
	getline(input,linea);
	vector<string> inp;
	inp.push_back(linea);
	int index = linea.size()/((rand()%100) + 1);
	int rnd = (rand()%100) + 10;
	int k = 0, c = 0;
	while(k < rnd){
		pattern += linea[c+index];
		k++;
		c++;
		if(c+index >= linea.size()) c = 0;

	}
	inp.push_back(pattern);
	return inp;
}

string generarPatron(string linea,int tam){
	string pattern;
	int index = linea.size()/((rand()%100) + 1);
	int k = 0, c = 0;
	while(k < tam){
		pattern += linea[c+index];
		k++;
		c++;
		if(c+index >= linea.size()) c = 0;

	}
	return pattern;
}

int main(){
	int ocurrences;
	int rep = 100;
	clock_t start;
	double time;

	string s;
	string pattern;

	suffixArray *sa;
	
	ifstream input;
	input.open("input",ios_base::in);

	ofstream out;
	out.open("creciente.txt",ios_base::out);

	string patron;

	//n creciente y patrones aleatorios
	vector<string> inp;
	for(int i = 0; i <= 100000; i += 5000){

		inp = generarInput(input);

		sa = new suffixArray(inp[0]);
		out<<inp[0].size()<<" ";
		cout<<inp[0].size()<<endl;
		start = clock();
		for(int i=0;i<rep;i++)  ocurrences = sa->search(inp[1]);
		time = ((double)clock() - start) / CLOCKS_PER_SEC;
		out<<(time*1000)/(double)rep<<" ";

		start = clock();
		for(int i=0;i<rep;i++)  ocurrences = sa->patternMatching(inp[1]);
		time = ((double)clock() - start) / CLOCKS_PER_SEC;
		out<<(time*1000)/(double)rep<<endl;

		sa->~suffixArray();
	}

	//n fijo y patrones aleatorios
	ofstream out2;
	out2.open("fijo.txt",ios_base::out);
	cout<<inp[0].size()<<endl;
	sa = new suffixArray(inp[0]);

	for(int i = 0; i <= 10000; i += 1000){
		cout<<inp[0].size()<<endl;
		out2<<i<<" ";
		patron = generarPatron(inp[0],i);
		start = clock();
		for(int i=0;i<rep;i++)  ocurrences = sa->search(patron);
		time = ((double)clock() - start) / CLOCKS_PER_SEC;
		out2<<(time*1000)/(double)rep<<" ";

		start = clock();
		for(int i=0;i<rep;i++)  ocurrences = sa->patternMatching(patron);
		time = ((double)clock() - start) / CLOCKS_PER_SEC;
		out2<<(time*1000)/(double)rep<<endl;

	}
	sa->~suffixArray();

	return 0;
}
