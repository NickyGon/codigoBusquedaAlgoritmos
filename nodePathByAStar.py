def aStarAlgo(nodoInicial, nodoFinal):
        open_set = set(nodoInicial) 
        closed_set = set()
        g = {} #La primera distancia del nodo inicial
        nodosPadres = {}# mapa de adyacencia de todos los nodos 
        #La distancia del nodo principal es 0
        g[nodoInicial] = 0
        #El nodo principal es colocado como su propio padre
        nodosPadres[nodoInicial] = nodoInicial
         
        #mientras que el set de nodos OPEN no esté vacío, realizar la búsqueda
        while len(open_set) > 0:
            n = None
            #encontrar el nodo con el menor valor de f(n)
            #f(n)=g(n) (distancia hacia otro nodo) + h(n) valor heurístico 
            for v in open_set:
                if n == None or g[v] + heuristic(v) < g[n] + heuristic(n):
                    n = v
            #Si se llegó al nodo objetivo o no hay información disponible, saltar         
            if n == nodoFinal or nodosGrafo[n] == None:
                pass
            else:
                for (m, weight) in get_neighbors(n):
                    #añadir a los nodos vecinos de n que no estén dentro
                    #de OPEN o CLOSE, siendo n su padre
                    if m not in open_set and m not in closed_set:
                        open_set.add(m)
                        nodosPadres[m] = n
                        g[m] = g[n] + weight
                    #comparar la distancia de los nodos hijos desde el inicial, pasando
                    #por el nodo n
                    else:
                        if g[m] > g[n] + weight:
                            #Actualizar el costo g[hijo] y establecer a n como padre
                            g[m] = g[n] + weight
                            nodosPadres[m] = n       
                            #Si el nodo hijo esta en CLOSED, sacarlo de la cola y
                            #colocarlo en OPEN
                            if m in closed_set:
                                closed_set.remove(m)
                                open_set.add(m)
            if n == None:
                print('No hay camino al nodo objetivo!')
                return None
            # Si el nodo actual es el que buscamos, reconstruir su camino
            # hasta el nodo inicial y revertirlo para su entrega final
            if n == nodoFinal:
                path = []
                while nodosPadres[n] != n:
                    path.append(n)
                    n = nodosPadres[n]
                path.append(nodoInicial)
                path.reverse()
                print('El camino encontrado es: {}'.format(path), " con ", g[m], " de costo")
                return path
            # Sacar al nodo actual de OPEN y ponerlo en CLOSED ya que sus
            # descendientes han sido inspeccionados
            open_set.remove(n)
            closed_set.add(n)
 
        print('No hay camino al nodo objetivo!')
        return None

#Revelar un vecino del nodo actual con su distancia         
def get_neighbors(v):
    if v in nodosGrafo:
        return nodosGrafo[v]
    else:
        return None

# Lista de los valores heurísiticos de los nodos
def heuristic(n):
        H_dist = {
            'A': 11,
            'B': 6,
            'C': 99,
            'D': 1,
            'E': 7,
            'G': 0,    
        }
        return H_dist[n]
 
#Generando el grafo e invocando a la función
nodosGrafo = {
    'A': [('B', 2), ('E', 3)],
    'B': [('C', 1),('G', 9)],
    'C': None,
    'E': [('D', 6)],
    'D': [('G', 1)],   
}
aStarAlgo('A', 'G')