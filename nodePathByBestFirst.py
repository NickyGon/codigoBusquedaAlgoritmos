ListaNodos ={ 'A':[['B',3],['C',2]], 'B':[['A',5],['C',2],['D',2],['E',3]], 
'C':[['A',5],['B',3],['F',2],['G',4]], 'D':[['H',1],['I',99]],
'F': [['J',99]],'G':[['K',99],['L',3]]}
Inicio='A'
Objetivo='H'
Closed = list()
SUCCESS=True
FAILURE=False
Estado=FAILURE

#Generando una expansión del nodo hijo
def MOVEGEN(N):
	New_list=list()
	if N in ListaNodos.keys():
		New_list=ListaNodos[N]
	
	return New_list

# Verificando que el nodo seleccionado ser
def GOALTEST(N):
	if N == Objetivo:
		return True
	else:
		return False

# Añadir un elemento a la lista como una cola
def APPEND(L1,L2):
	New_list=list(L1)+list(L2)
	return New_list

# Ordenar la lista según el valor de los costos	
def SORT(L):
	L.sort(key = lambda x: x[1]) 
	return L 

#codigo de búsqueda por Primero El Mejor
def BestFirstSearch():
    #Empezamos por el nodo inicial en la lista OPEN, 
    #la lista CLOSED vacía, y el estado en falso
	OPEN=[[Inicio,5]]
	CLOSED=list()
	global Estado
	global Closed
    # Mientras que OPEN no esté vacío o no haya un resultado positivo
	while (len(OPEN) != 0) and (Estado != SUCCESS):
		print("------------")
		N= OPEN[0]
		print("N=",N)
		del OPEN[0] #Sacar el primer nodo de la cola OPEN

        #Si el nodo obtenido es igual al objetivo, determinar el
        #resultado como positivo
		if GOALTEST(N[0])==True:
			Estado = SUCCESS
            #Siempre añadir el nodo actual a CLOSED, no importa el caso
			CLOSED = APPEND(CLOSED,[N])
			print("CLOSED=",CLOSED)
        #Si el nodo obtenido no es el objetivo, extraer a sus descendientes
		else:
			CLOSED = APPEND(CLOSED,[N])
			print("CLOSED=",CLOSED)
			CHILD = MOVEGEN(N[0])
			print("SUCESOR=",CHILD)
            #Verisicar que los sucesores no esten en las listas OPEN o CLOSED,
            #y añadirlos a OPEN
			for val in CLOSED:
				if val in CHILD:
					CHILD.remove(val)
			for val in OPEN:
				if val in CHILD:
					CHILD.remove(val)
			OPEN = APPEND(CHILD,OPEN)
			print("Unsorted OPEN=",OPEN)
			SORT(OPEN)
			print("Sorted OPEN=",OPEN)
			
	Closed=CLOSED
	return Estado
	
#Invocando al código para realizar la búsqueda
result=BestFirstSearch() 
gotIt = "Se encontro el nodo" if Estado else "No se pudo encontrar el nodo"
print("Recorrido realizado del nodo ",Inicio, " para llegar al nodo ", Objetivo)
print(Closed)
print(gotIt)