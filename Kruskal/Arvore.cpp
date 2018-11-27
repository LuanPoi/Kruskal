#include "Arvore.h"

using namespace std;

Arvore::Arvore()
{

}


Arvore::Arvore(Vertice* vertice)
{
	vertices.push_back(vertice);
	if (vertices.empty())
		if (vertices.empty()) throw exception("Arvore não criada.");
}

Arvore::~Arvore()
{
}

vector<Vertice*> Arvore::pegaVertices()
{
	return vertices;
}

void Arvore::adicionaVertices(vector<Vertice*> vertices)
{
	int verticeSize1 = vertices.size();
	int verticeSize2 = this->vertices.size();
	while(!(vertices.empty())) {
		this->vertices.push_back(vertices.back());
		vertices.pop_back();
	}	
	if ((verticeSize1 + verticeSize2) != this->vertices.size())
		throw exception("Adição incorreta de Vertices.");
}

vector<Aresta*> Arvore::pegaArestas()
{
	return arestas;
}

void Arvore::adicionaArestas(vector<Aresta*> arestas)
{
	int arestaSize1 = arestas.size();
	int arestaSize2 = this->arestas.size();
	for (int i = 0; i < arestas.size(); i++) {
		this->arestas.push_back(arestas.back());
		arestas.pop_back();
	}
	if ((arestaSize1 + arestaSize2) != this->arestas.size())
		throw exception("Adição incorreta de Arestas.");
}
