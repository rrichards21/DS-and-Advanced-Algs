import numpy as np
import matplotlib.pyplot as plt

archivo = open("output.txt","r")
elementos = []
lineal = []
binaria = []
doblada = []
while(True):
	linea = archivo.readline()
	if(linea == ''):
		break
	aux = linea.split()
	elementos.append(float(aux[0]))
	lineal.append(float(aux[1]))
	binaria.append(float(aux[2]))
	doblada.append(float(aux[3]))
archivo.close()
print(lineal)
print(binaria)
print(doblada)


plt.plot(elementos,lineal,'C1',label='lineal')
plt.plot(elementos,binaria,'C2',label='binaria')
plt.plot(elementos,doblada,'C3',label='doblada')
plt.xticks(np.arange(min(elementos),max(elementos) + 1,5000))
plt.legend()
plt.xlabel('Elementos')
plt.ylabel('Tiempo de ejecución(milisegundos)')
plt.yscale('log')
plt.show()
