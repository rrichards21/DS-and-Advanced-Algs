#include <bits/stdc++.h>
#include "Busqueda.h"

using namespace std;

int main(){

	int pos;
	double time;
	int rep=100;

	ofstream out;
	out.open("output.txt",ios_base::out);

	for(int k = 0; k <= 100000; k+=5000){
		Busqueda b(k);
		out<<k<<" ";
		clock_t start = clock();
		for(int i=0;i<rep;i++)  pos = b.lineal(k-1);
		time = ((double)clock() - start) / CLOCKS_PER_SEC;
		//printf("Lineal: %d\n%.10f\n\n",pos, time/(double)rep);
		out<<(time*1000)/(double)rep<<" ";

		start = clock();
		for(int i=0;i<rep;i++)  pos = b.binaria(k-1);
		time = ((double)clock() - start) / CLOCKS_PER_SEC;
		//printf("Binaria: %d\n%.10f\n\n",pos, time/(double)rep);
		out<<(time*1000)/(double)rep<<" ";

		start = clock();
		for(int i=0;i<rep;i++)  pos = b.doblada(k-1);
		time = ((double)clock() - start) / CLOCKS_PER_SEC;
		//printf("Doblada %d\n%.10f\n\n",pos, time/(double)rep);
		out<<(time*1000)/(double)rep<<endl;
	}

	return 0;
}
