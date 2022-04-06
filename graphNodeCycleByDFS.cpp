#include<iostream>
#include <list>
#include <limits.h>
using namespace std;

//creando un grafo como una estructura con atributos únicos por clase
class Grafo
{
	
	// Número de nodos
	int Nodos;

	// lista de adyacencias en forma de arrays
	list<int> *adj;
    // booleano para determinar la existencia de ciclo en el grafo
	bool ciclosRecursivo(int v, bool visitados[],
							int parent);
public:

	//Declarando el grafo
	Grafo(int Nodos);

	//Método para añadir un nodo con padre v y nodo adjacente w
	void ponerConexion(int v, int w);

	// Metodo declarado en la clase del Grafo para determinar un ciclo existente en él
	bool tieneCiclo();
};

//inicialización del grafo
Grafo::Grafo(int Nodos)
{
	this->Nodos = Nodos;
	adj = new list<int>[Nodos];
}

//metodo para añadir nodos a la lista de vectores adyacentes, con un índice v siendo el nodo padre
//y w siendo el nodo vecino. Como es un grafo sin direcciones, se asigna de manera dual
void Grafo::ponerConexion(int v, int w)
{
	
	// Añadiendo el nodo w a la lista del nodo v, y viceversa
	adj[v].push_back(w);
	adj[w].push_back(v);
}

//función recursiva que toma un array de estados visitados por índice, un nodo actual y un nodo padre
//para verificar ciclos
bool Grafo::ciclosRecursivo(int v,
				bool visitados[], int parent)
{
	
	// Marcando el nodo actual como visitado
	visitados[v] = true;

	// Visitar la lista de nodos adyacentes del nodo actual, iterando hasta llegar al último elemento
	list<int>::iterator i;
	for (i = adj[v].begin(); i !=
					adj[v].end(); ++i)
	{
		
		// Si el nodo adyacente no ha sido visitado, ingresarlo dentro de una llamada recursiva al 
        // código como nodo actual
		if (!visitados[*i])
		{
		if (ciclosRecursivo(*i, visitados, v))
			return true;
		}

		//Si el nodo adyacente ha sido visitado y no es el nodo padre, existe un ciclo para ese nodo, 
        // y se debe retornar de la función como verdadero
		else if (*i != parent)
		return true;
	}
	return false;
}

//Funcion que invoca al método DFS antes explicado para todos los vértices, y el que le proporciona
//los datos al principio

bool Grafo::tieneCiclo()
{
	
	//Creación del arreglo de nodos visitados mediante un estado booleano por índice, con
    //una inicialización de todos los espacios como "falso"
	bool *visitados = new bool[Nodos];
	for (int i = 0; i < Nodos; i++)
		visitados[i] = false;
        
        //Llamado del método DFS recursivo para todos los vértices del grafo, tomando en cuenta aquellos
        //que hayan sido visitados
	for (int u = 0; u < Nodos; u++)
	{
	
		// Para aquellos nodos no visitados, invocar al método como un comparador lógico que saldrá de la
        // función si existiera una respuesta verdadera (hay ciclo). De lo contrario, se proseguirá hasta terminar con
        // la iteración (no hay ciclo)
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
