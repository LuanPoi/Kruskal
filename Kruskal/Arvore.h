#pragma once
#include "Vertice.h"
#include "Aresta.h"
#include <vector>

using namespace std;

class Arvore
{
private:
	vector <Vertice*> vertices;
	vector <Aresta*> arestas;

public:
	Arvore();
	~Arvore();
	vector<Vertice*> pegaVertices();
	bool colocaVertices(vector<Vertice*> vertices);
	vector<Aresta*> pegaArestas();
	bool colocaArestas(vector<Aresta*> arestas);
};

