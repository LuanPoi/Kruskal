#include "Vertice.h"

using namespace std;

Vertice::Vertice()
{
}

Vertice::Vertice(char nome)
{
	this->nome = nome;
}


Vertice::~Vertice()
{

}

char Vertice::pegaNome()
{
	return nome;
}

void Vertice::colocaNome(char nome)
{
	this->nome = nome;
}
