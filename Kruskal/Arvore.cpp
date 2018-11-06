#include "Arvore.h"

using namespace std;

Arvore::Arvore()
{
}


Arvore::~Arvore()
{
}

vector<Vertice*> Arvore::pegaVertices()
{
	return this->vertices;
}

bool Arvore::colocaVertices(vector<Vertice*> vertices)
{
	for (int i = 0; i < vertices.size(); i++) {
		this->vertices.push_back(vertices.back());
		vertices.pop_back();
	}	
	return true;
}

vector<Aresta*> Arvore::pegaArestas()
{
	return arestas;
}

bool Arvore::colocaArestas(vector<Aresta*> arestas)
{
	for (int i = 0; i < arestas.size(); i++) {
		this->arestas.push_back(arestas.back());
		arestas.pop_back();
	}
	return true;
}
