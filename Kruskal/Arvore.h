#pragma once
#include "Vertice.h"
#include "Aresta.h"
#include <vector>

using namespace std;

class Arvore
{
private:
	vector <Vertice*> 
	vector <Aresta*> arestas;

public:
	Arvore();
	~Arvore();
	vector<Vertice*> pegaVertices();
};

