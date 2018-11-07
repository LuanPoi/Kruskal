#include "Kruskal.h"



Kruskal::Kruskal()
{
}


Kruskal::~Kruskal()
{
}

vector<Arvore*> Kruskal::pegaFloresta()
{
	return floresta;
}

bool Kruskal::colocaFloresta(vector<Arvore*> floresta)
{
	this->floresta = floresta;
}

vector<Aresta*> Kruskal::pegaConjuntoTemporarioDeArestas()
{
	return conjuntoTemporarioDeArestas;
}

bool Kruskal::colocaConjuntoTemporarioDeArestas(vector <Aresta*> conjuntoTemporarioDeArestas)
{
	this->conjuntoTemporarioDeArestas = conjuntoTemporarioDeArestas;
}

vector<Aresta*> Kruskal::pegaConjuntoDeArestasQueFechamCiclos()
{
	return conjuntoDeArestasQueFechamCiclos;;
}

bool Kruskal::colocaConjuntoDeArestasQueFechamCiclos(vector<Aresta*> conjuntoDeArestasQueFechamCiclos)
{
	this->conjuntoDeArestasQueFechamCiclos = conjuntoDeArestasQueFechamCiclos;
	return true;
}

bool Kruskal::criaArvore(string verticeNome)
{
	floresta.push_back(new Arvore(verticeNome));
	return true;
}

Aresta& Kruskal::criaAresta(string de, string para, float peso = 1)
{
	for (auto arvore:floresta) {
		for (auto vertice : arvore->pegaVertices()) {
			vertice->pegaNome();
		}
	}
}
