#pragma once
#include <vector>
#include "Arvore.h"

class Kruskal
{
private:
	//string enderecoArquivoFonte;
	vector <Arvore*> floresta;
	vector <Aresta*> conjuntoTemporarioDeArestas;
	vector <Aresta*> conjuntoDeArestasQueFechamCiclos;

public:
	Kruskal();
	~Kruskal();
	//string pegaEnderecoArquivoFonte();
	//bool colocaEnderecoArquivoFonte();
	(vector <Arvore*>)& pegaFloresta();
	bool colocaFloresta(vector<Arvore*> floresta);
	(vector <Aresta*>)& pegaConjuntoTemporarioDeArestas();
	bool colocaConjuntoTemporarioDeArestas(vector <Aresta*> conjuntoTemporarioDeArestas);
	(vector <Aresta*>)& pegaConjuntoDeArestasQueFechamCiclos();
	bool colocaConjuntoDeArestasQueFechamCiclos(vector <Aresta*> conjuntoDeArestasQueFechamCiclos);
	//bool selecionaArquivoFonte();
	bool executar();
	//bool criaFloresta();
	bool criaArvore(string verticeNome);
	Aresta& criaAresta(string de, string para, float peso = 1);
	bool removeArvore(Arvore* arvore);
	bool removeAresta(Aresta* aresta);
	Aresta* retornaMenorAresta();
	void mostrarResultado();

};

