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

vector<Aresta*> Kruskal::pegaConjuntoTemporarioDeArestas()
{
	return conjuntoTemporarioDeArestas;
}

void Kruskal::criaArvore(string verticeNome)
{
	floresta.push_back(new Arvore(new Vertice(verticeNome)));
	if(floresta.empty()) throw exception("Arvore não adicionada.");
}

Aresta* Kruskal::criaAresta(string de, string para, float peso)
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
                return &Aresta(Vde, Vpara, peso);
            }
		}
	}
	if (Vde == nullptr)
		throw exception("Falha na criação da Aresta Vde = nullptr");
	if (Vpara == nullptr)
		throw exception("Falha na criação da Aresta Vpara = nullptr");
}

Aresta* Kruskal::retornaMenorAresta(vector <Aresta*> arestas)
{
    Aresta* menorAresta = nullptr;
	int count = -1;
    float menorArestaPeso = INFINITY;
    for(Aresta* aresta : arestas){
		count++;
		if (aresta->peso < menorArestaPeso) {
			menorArestaPeso = aresta->peso;
			menorAresta = conjuntoTemporarioDeArestas[count];
			posicaoMenorAresta = count;
		}
    }
	if(menorArestaPeso == INFINITY)
			throw exception("Menor aresta não encontrada.");
    return menorAresta;
}

void Kruskal::mostrarResultado()
{
	for (Arvore* arvore : floresta) {
		std::cout << "--Arvore--" << std::endl;
		std::cout << "Vertices:" << std::endl;
		for (Vertice* vertice : arvore->vertices) {
			std::cout << vertice->nome << " |";
		}
		std::cout << std::endl;
		std::cout << "Arestas:" << std::endl;
		for (Aresta* aresta : arvore->arestas) {
			std::cout << aresta->de->nome << " --- " << aresta->para->nome << std::endl;
		}
		std::cout << std::endl;
	}
}

void Kruskal::executar() {
	int cont = 0, a1count = -1, controlador = 0;
	string nome;
	if((conjuntoTemporarioDeArestas.empty()))
		throw exception("Conjunto temporario de arestas Vazio.");
	while (!(conjuntoTemporarioDeArestas.empty())) {
		a1count = -1;
		Aresta* menorAresta = retornaMenorAresta(conjuntoTemporarioDeArestas);
		for (Arvore* arvore : floresta) {
			cont = 0, a1count++, controlador = 0;
			for (Vertice* vertice : arvore->vertices) {
				if (vertice->nome == (menorAresta->de)->nome || vertice->nome == (menorAresta->para)->nome) {
					if (vertice->nome == (menorAresta->de)->nome) {
						nome = (menorAresta->para)->nome;
						cont++;
						break;
					}
					if (vertice->nome == (menorAresta->para)->nome) {
						nome = (menorAresta->de)->nome;
						cont++;
						break;
					}					
					if (cont == 2) {
						delete retornaMenorAresta(conjuntoTemporarioDeArestas);
						break;
					}
				}
			}
			if (cont == 1) {
				int a2count = -1;
				for (Arvore* arvore2 : floresta) {
					a2count++;
					int v2count = -1;
					for (Vertice* vertice2 : arvore2->vertices) {
						v2count++;
						if (vertice2->nome == nome && (arvore != arvore2)) {
							floresta[a1count]->adicionaVertices(floresta[a2count]->vertices);
							floresta[a1count]->adicionaArestas(floresta[a2count]->arestas);
							floresta.erase(floresta.begin()+a2count);
							floresta[a1count]->arestas.push_back(conjuntoTemporarioDeArestas[posicaoMenorAresta]);
							conjuntoTemporarioDeArestas.erase(conjuntoTemporarioDeArestas.begin() + posicaoMenorAresta);
							controlador = 1;
						}
						if (vertice2->nome == nome && (arvore == arvore2)) {
							conjuntoTemporarioDeArestas.erase(conjuntoTemporarioDeArestas.begin() + posicaoMenorAresta);
						}
						if (controlador == 1) {
							break;
						}
					}
					if (controlador == 1) {
						break;
					}
				}
				if (cont == 2) {
					break;
				}
			}
			if (cont == 1 || cont == 2) {
				break;
			}
		}
	}
	if (!conjuntoTemporarioDeArestas.empty())
		throw exception("Não foram tratadas todas as arestas.");
}

void Kruskal::grafoTeste(){
	string nome;
    floresta.push_back(new Arvore(new Vertice(nome = "A")));
	floresta.push_back(new Arvore(new Vertice(nome = "B")));
	floresta.push_back(new Arvore(new Vertice(nome = "C")));
	floresta.push_back(new Arvore(new Vertice(nome = "D")));
	floresta.push_back(new Arvore(new Vertice(nome = "E")));
	floresta.push_back(new Arvore(new Vertice(nome = "F")));
	floresta.push_back(new Arvore(new Vertice(nome = "G")));
    conjuntoTemporarioDeArestas.push_back(new Aresta(floresta[0]->vertices[0] , floresta[1]->vertices[0], 7.0));
    conjuntoTemporarioDeArestas.push_back(new Aresta(floresta[1]->vertices[0], floresta[2]->vertices[0], 8.0));
    conjuntoTemporarioDeArestas.push_back(new Aresta(floresta[2]->vertices[0], floresta[4]->vertices[0], 5.0));
    conjuntoTemporarioDeArestas.push_back(new Aresta(floresta[4]->vertices[0], floresta[1]->vertices[0], 7.0));
    conjuntoTemporarioDeArestas.push_back(new Aresta(floresta[1]->vertices[0], floresta[3]->vertices[0], 9.0));
    conjuntoTemporarioDeArestas.push_back(new Aresta(floresta[3]->vertices[0], floresta[0]->vertices[0], 5.0));
    conjuntoTemporarioDeArestas.push_back(new Aresta(floresta[3]->vertices[0], floresta[4]->vertices[0], 15.0));
    conjuntoTemporarioDeArestas.push_back(new Aresta(floresta[3]->vertices[0], floresta[5]->vertices[0], 6.0));
    conjuntoTemporarioDeArestas.push_back(new Aresta(floresta[4]->vertices[0], floresta[5]->vertices[0], 8.0));
    conjuntoTemporarioDeArestas.push_back(new Aresta(floresta[5]->vertices[0], floresta[6]->vertices[0], 11.0));
    conjuntoTemporarioDeArestas.push_back(new Aresta(floresta[4]->vertices[0], floresta[6]->vertices[0], 9.0));
}
