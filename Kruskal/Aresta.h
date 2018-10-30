#pragma once
#include "Vertice.h"

using namespace std;

class Aresta
{
private:
	Vertice *de;
	Vertice *para;
	float peso;
	Aresta();

public:
	Aresta(Vertice *de, Vertice *para, float peso=1);
	~Aresta();
	Vertice &pegaDe();
	void colocaDe(Vertice *de);
	Vertice &pegaPara();
	void colocaPara(Vertice *para);
	float pegaPeso();
	void colocaPeso(float peso);
};
