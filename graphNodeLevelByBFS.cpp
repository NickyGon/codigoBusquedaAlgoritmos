
#include <bits/stdc++.h>
using namespace std;


void printLevels(vector<int> graph[], int V, int x)
{
	//array colanodos guarda el nivel de descendencia por índice (nodo)
	int nivelArbol[V];
    //array en booleano colanodos guarda el estado de visita por índice (nodo)
	bool visitados[V];
	// cola para guardar los nodos a visitar, partiendo de la raíz
	queue<int> colanodos;
	// agregar el primer nodo o raíz del grafo a la cola de visitas
	colanodos.push(x);
	// inicializar el primer nodo con un nivel 0 (raíz) y como visitado para evitar ciclos
	nivelArbol[x] = 0;
	visitados[x] = true;

	// iteración a repetir hasta colanodos la cola quede vacía (no haya nodos padres e hijos por visitar del grafo)
	while (!colanodos.empty()) {
		// Al ser BFS, tomar en órden los nodos de la cola, empezando secuencialmente con el frente y sacándolo de esta 
		x = colanodos.front();
		colanodos.pop();
		//explorando los hijos posibles del nodo x, omitiendo si no tuviera un vecino de un nivel más bajo
		for (int i = 0; i < graph[x].size(); i++) {
			// Sacando el primer vecino de x
			int b = graph[x][i];
			// Si el vecino b existe y no está como marcado en el array de visitados, 
            // es empujado a la cola de nodos a visitar, su nivel en el árbol se incrementa a 1
            // con respecto al del nodo padre x, y se almacena como marcado.
			if (!visitados[b]) {
				colanodos.push(b);
				nivelArbol[b] = nivelArbol[x] + 1;
				visitados[b] = true;
			}
		}
	}

	// Al salir de la iteración, utilizar el array de niveles para extraer información de los niveles
    // de cada nodo en el árbol
	cout << "Nodos"
		<< " "
		<< "Nivel en árbol" << endl;
	for (int i = 0; i < V; i++)
		cout << " " << i << " -------> " << nivelArbol[i] << endl;
}


int main()
{
	// grafo en árbol sin ciclos, sin pesos de conexión y sin direcciones específicas entre nodos, solo conexiones
	int V = 8;
	vector<int> graph[V];

	graph[0].push_back(1);
	graph[0].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(4);
	graph[1].push_back(5);
	graph[2].push_back(5);
	graph[2].push_back(6);
	graph[6].push_back(7);

	// Utilizando el grafo con un tamaño equivalente al numero de nodos y empezando del nodo raíz
	printLevels(graph, V, 0);

	return 0;
}
