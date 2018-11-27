#include "Aresta.h"

using namespace std;

Aresta::Aresta()
{
}

Aresta::Aresta(Vertice * de, Vertice * para, float peso)
{
	this->de = de;
	this->para = para;
	this->peso = peso;
}

Aresta::~Aresta()
{
}

Vertice &Aresta::pegaDe()
{
	return *de;
}

void Aresta::colocaDe(Vertice * de)
{
	this->de = de;
}

Vertice &Aresta::pegaPara()
{
	return *para;
}

void Aresta::colocaPara(Vertice * para)
{
	this->para = para;
}

float Aresta::pegaPeso()
{
	return peso;
}

void Aresta::colocaPeso(float peso)
{
	this->peso = peso;
}
