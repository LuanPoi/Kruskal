#pragma once
#include <iostream>

using namespace std;

class Vertice
{
private:
	

public:
	string nome;
	Vertice();
	Vertice(string nome);
	~Vertice();
	string pegaNome();
	void colocaNome(string nome);
};

