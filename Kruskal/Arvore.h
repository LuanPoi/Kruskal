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
	Arvore();

public:
	Arvore(string verticeNome);
	~Arvore();
	vector<Vertice*> &pegaVertices();
	bool colocaVertices(vector<Vertice*> vertices);
	bool adicionaVertices(vector<Vertice*> vertices);
	vector<Aresta*> &pegaArestas();
	bool adicionaArestas(vector<Aresta*> arestas);
	bool colocaArestas(vector<Aresta*> arestas);
};

