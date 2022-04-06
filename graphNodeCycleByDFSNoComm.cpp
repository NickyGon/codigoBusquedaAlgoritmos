#include<iostream>
#include <list>
#include <limits.h>
using namespace std;

class Grafo
{
	int Nodos;
	list<int> *adj;
	bool ciclosRecursivo(int v, bool visitados[],int parent);
public:
	Grafo(int Nodos);
	void ponerConexion(int v, int w);
	bool tieneCiclo();
};

Grafo::Grafo(int Nodos)
{
	this->Nodos = Nodos;
	adj = new list<int>[Nodos];
}

void Grafo::ponerConexion(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

bool Grafo::ciclosRecursivo(int v,
				bool visitados[], int parent)
{
	visitados[v] = true;
	list<int>::iterator i;
	for (i = adj[v].begin(); i !=
					adj[v].end(); ++i)
	{
		if (!visitados[*i])
		{
		if (ciclosRecursivo(*i, visitados, v))
			return true;
		}
		else if (*i != parent)
		return true;
	}
	return false;
}

bool Grafo::tieneCiclo()
{

	bool *visitados = new bool[Nodos];
	for (int i = 0; i < Nodos; i++)
		visitados[i] = false;

	for (int u = 0; u < Nodos; u++)
	{
		if (!visitados[u])
		if (ciclosRecursivo(u, visitados, -1))
			return true;
	}
	return false;
}

int main()
{
	Grafo g1(5);
	g1.ponerConexion(1, 0);
	g1.ponerConexion(0, 2);
	g1.ponerConexion(2, 1);
	g1.ponerConexion(0, 3);
	g1.ponerConexion(3, 4);
	g1.tieneCiclo()? cout << "El grafo tiene un ciclo\n": cout << "El grafo no tiene un ciclo\n";

	Grafo g2(3);
	g2.ponerConexion(0, 1);
	g2.ponerConexion(1, 2);
	g2.tieneCiclo()? cout << "El grafo tiene un ciclo\n": cout << "El grafo no tiene un ciclo\n";

	return 0;
}
