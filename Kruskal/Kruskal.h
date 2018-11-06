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
	vector <Arvore*> pegaFloresta();
	bool colocaFloresta();
	vector <Aresta*> pegaConjuntoTemporarioDeArestas();
	bool colocaConjuntoTemporarioDeArestas();
	vector <Aresta*> pegaConjuntoDeArestasQueFechamCiclos();
	bool colocaConjuntoDeArestasQueFechamCiclos();
	bool selecionaArquivoFonte();
	bool executar();
	bool criaFloresta();
	bool criaArestas();
	bool criaArvore(string verticeNome);
	bool criaAresta(string de, string para);
	bool removeArvore(Arvore arvore);
	bool removeAresta(Aresta aresta);
	Aresta* retornaMenorAresta();
	Arvore* retornaArvores();
	void mostrarResultado();

};

