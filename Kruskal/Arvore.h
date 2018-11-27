#pragma once
#include "Vertice.h"
#include "Aresta.h"
#include <vector>

using namespace std;

class Arvore
{
private:
	
	Arvore();

public:
	vector <Vertice*> vertices;
	vector <Aresta*> arestas;
	Arvore(Vertice* vertice);
	~Arvore();
	vector<Vertice*> pegaVertices();
	void adicionaVertices(vector<Vertice*> vertices);
	vector<Aresta*> pegaArestas();
	void adicionaArestas(vector<Aresta*> arestas);
};

