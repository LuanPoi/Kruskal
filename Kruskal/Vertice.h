#pragma once

using namespace std;

class Vertice
{
private:
	char nome;

public:
	Vertice();
	Vertice(char nome);
	~Vertice();
	char pegaNome();
	void colocaNome(char nome);
};

