#pragma once

using namespace std;

class Vertice
{
private:
	string nome;

public:
	Vertice();
	Vertice(string nome);
	~Vertice();
	string pegaNome();
	void colocaNome(string nome);
};

