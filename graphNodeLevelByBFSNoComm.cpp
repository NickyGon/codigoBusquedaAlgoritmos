
#include <bits/stdc++.h>
using namespace std;


void printLevels(vector<int> graph[], int V, int x)
{
	int nivelArbol[V];
	bool visitados[V];
	queue<int> colanodos;
	colanodos.push(x);
	nivelArbol[x] = 0;
	visitados[x] = true;
	while (!colanodos.empty()) {
		x = colanodos.front();
		colanodos.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int b = graph[x][i];
			if (!visitados[b]) {
				colanodos.push(b);
				nivelArbol[b] = nivelArbol[x] + 1;
				visitados[b] = true;
			}
		}
	}
	cout << "Nodos"<< " "<< "Nivel en árbol" << endl;
	for (int i = 0; i < V; i++)
		cout << " " << i << " -------> " << nivelArbol[i] << endl;
}


int main()
{
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
	printLevels(graph, V, 0);

	return 0;
}
