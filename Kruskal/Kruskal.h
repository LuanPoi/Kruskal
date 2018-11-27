#pragma once
#include <stdexcept>
#include <vector>
#include <iostream>
#include <string>
#include "Arvore.h"
#include "Vertice.h"
#include "Aresta.h"

class Kruskal
{
private:
	//string enderecoArquivoFonte;
	vector <Arvore*> floresta;
	vector <Aresta*> conjuntoTemporarioDeArestas;

public:
	Kruskal();
	~Kruskal();
	int posicaoMenorAresta;
	vector <Arvore*> pegaFloresta();
	vector <Aresta*> pegaConjuntoTemporarioDeArestas();
	void executar();
	void criaArvore(string verticeNome);
	Aresta* criaAresta(string de, string para, float peso = 1);
	Aresta* retornaMenorAresta(vector <Aresta*> arestas);
	void mostrarResultado();
	void grafoTeste();
};

