import pandas as pd

inp = open("output","r")
nombre = []
ratioS = []
nodosS = []
ratioC = []
nodosC = []
while(True):
    linea = inp.readline()
    if(linea == ''):
        break
    linea = linea.split()
    nombre.append(linea[0])
    ratioS.append(linea[1])
    nodosS.append(linea[2])
    ratioC.append(linea[3])
    nodosC.append(linea[4])
data = {"Archivo":nombre,"Ratio palabras":ratioS,"Nodos palabras":nodosS,"Ratio char":ratioC,"Nodos char":nodosC}
export = pd.DataFrame(data)
print(export)
export.to_csv("tabla",sep=',')