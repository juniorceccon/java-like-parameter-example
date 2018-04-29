#include "teste.h"
#include <string>
#include <iostream>

using namespace std;

void valor(Teste*);
void referencia(Teste**);

int main(int argc, char** argv)
{
	Teste* t = new Teste();
	t->valor="Olaa";
	cout << "Valor do ponteiro atual " << t << endl;
	
	valor(t);
	cout << t->valor << endl;
	cout << "Valor do ponteiro atual " << t << endl;
	
	referencia(&t);
	cout << t->valor << endl;
	cout << "Valor do ponteiro atual " << t << endl;
	
	delete t;
	return 0;
}

void valor (Teste* t) {
	t = new Teste();
	t-> valor = "alterado";
	cout 
	<< "Dentro da função valor:" << endl
	<< t->valor << endl;
}

void referencia (Teste** t) {
	/* memory leak aqui - não tem gc em c++ */
	(*t) = new Teste();
	(*t)-> valor = "alterado";
	cout 
	<< "Dentro da função referencia" << endl
	<< (*t)->valor << endl;
}

void Teste::calcular() 
{
	cout << "Ola de calcular" << endl;
}