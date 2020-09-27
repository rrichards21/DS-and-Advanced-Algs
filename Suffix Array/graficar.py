import numpy as np
import matplotlib.pyplot as plt

archivo = open("fijo.txt","r")
elementos = []
lineal = []
binaria = []
bruta = []
while(True):
	linea = archivo.readline()
	if(linea == ''):
		break
	aux = linea.split()
	elementos.append(float(aux[0]))
	binaria.append(float(aux[1]))
	bruta.append(float(aux[2]))
archivo.close()
print(binaria)
print(bruta)

plt.title('Análisis de búsqueda de patrones en Arreglo de Sufijos con string de tamaño 100.000 (tamaño de patrón vs tiempo)')
plt.plot(elementos,binaria,'C1',label='Binaria')
plt.plot(elementos,bruta,'C2',label='Fuerza bruta')
plt.xticks(np.arange(min(elementos),max(elementos) + 1,1000))
plt.legend()
plt.xlabel('Tamaño de patrón')
plt.ylabel('Tiempo de ejecución(milisegundos)')
plt.yscale('log')
plt.show()
