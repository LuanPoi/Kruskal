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
	bool Bde = false, Bpara = false;
	Vertice* Vde = nullptr;
    Vertice* Vpara = nullptr;
	for (Arvore* arvore:floresta) {
		for (Vertice* vertice : arvore->pegaVertices()) {
			if(vertice->pegaNome() == de){
                Vde = vertice;
                Bde = true;
			}
            if(vertice->pegaNome() == para){
                Vpara = vertice;
                Bpara = true;
            }
            if(Bde && Bpara){
                return Aresta(de, para, peso);
            }
		}
		return nullptr;
	}
}

bool removeArvore(Arvore* arvore)
{
    delete arvore;
}

bool removeAresta(Aresta* aresta)
{
    delete aresta;
}

Aresta* retornaMenorAresta()
{
    Aresta* menorAresta = nullptr;
    float menorArestaPeso = 0;
    for(Aresta* aresta = conjuntoTemporarioDeArestas.begin ; aresta < conjuntoTemporarioDeArestas.end ; aresta++){
        if(aresta.pegaPeso() < menorArestaPeso)
            menorArestaPeso = aresta.pegaPeso();
            menorAresta = aresta;
    }
    return menorAresta;
}

bool executar(){
    int cont = 0;
    grafoTeste();

    while(!(conjuntoTemporarioDeArestas.empty)){
        for (Arvore* arvore:floresta) {
            cont = 0;
            for (Vertice* vertice : arvore->pegaVertices()) {
                if(*vertice == *retornaMenorAresta().de || *vertice == *retornaMenorAresta().para){
                    cont++;
                    if(cont == 2)
                        break;
                }
            }
            if(cont == 2)
                        break;
        }

    }
}

void grafoTeste(){
    floresta.push_back(Arvore("A"));
    floresta.push_back(Arvore("B"));
    floresta.push_back(Arvore("C"));
    floresta.push_back(Arvore("D"));
    floresta.push_back(Arvore("E"));
    floresta.push_back(Arvore("F"));
    floresta.push_back(Arvore("G"));
    conjuntoTemporarioDeArestas.push_back(Aresta(floresta[0].vertices[0], floresta[1].vertices[0], 7.0));
    conjuntoTemporarioDeArestas.push_back(Aresta(floresta[1].vertices[0], floresta[2].vertices[0], 8.0));
    conjuntoTemporarioDeArestas.push_back(Aresta(floresta[2].vertices[0], floresta[4].vertices[0], 5.0));
    conjuntoTemporarioDeArestas.push_back(Aresta(floresta[4].vertices[0], floresta[1].vertices[0], 7.0));
    conjuntoTemporarioDeArestas.push_back(Aresta(floresta[1].vertices[0], floresta[3].vertices[0], 9.0));
    conjuntoTemporarioDeArestas.push_back(Aresta(floresta[3].vertices[0], floresta[0].vertices[0], 5.0));
    conjuntoTemporarioDeArestas.push_back(Aresta(floresta[3].vertices[0], floresta[4].vertices[0], 15.0));
    conjuntoTemporarioDeArestas.push_back(Aresta(floresta[3].vertices[0], floresta[5].vertices[0], 6.0));
    conjuntoTemporarioDeArestas.push_back(Aresta(floresta[4].vertices[0], floresta[5].vertices[0], 8.0));
    conjuntoTemporarioDeArestas.push_back(Aresta(floresta[5].vertices[0], floresta[6].vertices[0], 11.0));
    conjuntoTemporarioDeArestas.push_back(Aresta(floresta[4].vertices[0], floresta[6].vertices[0], 9.0));
}
