#include "Vertice.h"
#include <string>
using namespace std;

Vertice::Vertice()
{
}

Vertice::Vertice(string nome)
{
	this->nome = nome;
}

Vertice::~Vertice()
{

}

string Vertice::pegaNome()
{
	return nome;
}

void Vertice::colocaNome(string nome)
{
	this->nome = nome;
}
