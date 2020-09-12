#destruyendo
def promedio (lista):
  if lista ==[]:
      return 0
  else:
      return promedio_aux(lista,len(lista),0)

def promedio_aux(lista,largo,suma):
    if lista ==[]:
        return suma/largo
    else:
        return promedio_aux(lista[1:],largo,suma+lista[0])

#sin destruir
def promedio1 (lista):
  if lista ==[]:
      return 0
  else:
      return promedio1_aux(lista,len(lista),0,0)

def promedio1_aux(lista,largo,suma,i):
    if i== largo:
        return suma/largo
    else:
        return promedio1_aux(lista,largo,suma+lista[i],i+1)
    
#Pila sin destruir

def promedio2(lista):
    largo= len(lista)
    if lista ==[]:
        return 0
    else:
        return promedio2_aux(lista,0,largo)/len(lista)
    
def promedio2_aux(lista,i,largo):
    if i==largo:
        return 0
    else:
        return lista[i]+promedio2_aux(lista,i+1,largo)

#Pila destruir

def promedio3(lista):
    largo= len(lista)
    if lista ==[]:
        return 0
    else:
        return promedio3_aux(lista)/largo
    
def promedio3_aux(lista):
    if lista==[]:
        return 0
    else:
        return lista[0]+promedio3_aux(lista[1:])
