import numpy as np
import matplotlib.pyplot as plt

archivo = open("output.txt","r")
elementos = []
avl = []
rbt = []
while(True):
	linea = archivo.readline()
	if(linea == ''):
		break
	aux = linea.split()
	elementos.append(float(aux[0]))
	avl.append(float(aux[1]))
	rbt.append(float(aux[2]))
archivo.close()
print(avl)
print(rbt)

plt.title('AVL vs RBT búsqueda')
plt.plot(elementos,avl,'C1',label='Avl')
plt.plot(elementos,rbt,'C2',label='RBT')
plt.xticks(np.arange(min(elementos),max(elementos) + 1,1000000))
plt.legend()
plt.xlabel('Cantidad de nodos')
plt.ylabel('Tiempo de ejecución(milisegundos)')
plt.yscale('log')
plt.show()
