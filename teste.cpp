#include "teste.h"
#include <string>
#include <iostream>

using namespace std;

void valor(Teste*);
void referencia(Teste**);

int main(int argc, char** argv)
{
	Teste* t = new Teste();
	t->valor="Valor";
	cout << "Pointer value: " << t << endl << endl;
	
	valor(t);
	cout << "Object internal value: " << t->valor << endl;
	cout << "Pointer value: " << t << endl <<endl ;
	
	referencia(&t);
	cout << "Object internal value: " << t->valor << endl;
	cout << "Pointer value " << t << endl << endl;
	
	delete t;
	return 0;
}

void valor (Teste* t) {
	t = new Teste();
	t-> valor = "alterado";
	cout 
	<< "Dentro da função valor:" << endl
	<< t->valor << endl;
	delete t;
}

void referencia (Teste** t) {
	/* AVISO: Perigo de memory leak - não tem gc em c++, e não existe 
	   mais referência para o objeto original */
	/* WARNING: memory leak danger here - there is no gc in c++, and the reference 
	   for the original object is no more */
	delete (*t);
	(*t) = new Teste();
	(*t)-> valor = "alterado";
	cout 
	<< "Dentro da função referencia" << endl
	<< (*t)->valor << endl;
}
