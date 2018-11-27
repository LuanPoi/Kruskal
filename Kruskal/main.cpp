#include "Kruskal.h"
#include <iostream>

int main() {
	Kruskal kruskal;
	kruskal.grafoTeste();
	try {
		kruskal.executar();
	}
	catch (string erro) {
		std::cout << "Erro: " << erro << std::endl;
	}
	kruskal.mostrarResultado();
	return 0;
}