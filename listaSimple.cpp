
#include <iostream>
using namespace std;

class nodo {
   public:
    nodo(int v)
    {
       valor = v;
       siguiente = NULL;
    }

nodo(int v, nodo * signodo)
    {
       valor = v;
       siguiente = signodo;
    }

   private:
    int valor;
    nodo *siguiente;
    
        
   friend class lista;
};

typedef nodo *pnodo;

class lista {
   public:
    lista() { primero = NULL; }
    ~lista();
    
    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    void Buscar(int elem);
    void BuscarPos(int Elem,int Pos);
    void Sumar ( lista L1,lista L2);
    void SumarListasTamD(lista Lista1,lista Lista2);
    
   private:
    pnodo primero;
   
};

lista::~lista()
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   
}

int lista::largoLista(){
    int cont=0;

    pnodo aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }
    
}

void lista::InsertarInicio(int v)
{
  
   if (ListaVacia())
     primero = new nodo(v);
   else
      primero=new nodo (v,primero);
}
     
 
void lista::InsertarFinal(int v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     { pnodo aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo(v);
      }    
}


void lista::InsertarPos(int v,int pos)
{
   if (ListaVacia())
     primero = new nodo(v);
   else{
        if(pos <=1){
          pnodo nuevo = new nodo(v);
          nuevo->siguiente= primero;
          primero= nuevo;     
        }      
        else{
             pnodo aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodo(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             
        }
        }
}
      
void lista::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
                primero= NULL;
            } else {

                pnodo aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }
                
              pnodo temp = aux->siguiente;
              aux->siguiente= NULL;

                
                delete temp;
            }
        }
}

void lista::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
                primero= NULL;
            } else {

                pnodo aux = primero;
                primero=primero->siguiente;                
                delete aux;
            }
        }
}



void lista:: borrarPosicion(int pos){
     if(ListaVacia()){
              cout << "Lista vacia" <<endl;
    }else{
         if((pos>largoLista())||(pos<0)){
        cout << "Error en posicion" << endl;
        }else{
        if(pos==1){
        primero=primero->siguiente;
        }else{
          int cont=2;
            pnodo aux=  primero;
            while(cont<pos){
             aux=aux->siguiente;
             cont++;
            }
            aux->siguiente=aux->siguiente->siguiente;
            }
        }
     }

}
 

void lista::Mostrar()
{
   nodo *aux;
   
   aux = primero;
   while(aux) {
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
   }
   cout << endl;
}



/*EJERCICIOS DE LA TAREA*/

/*BUSCAR UN ELEMENTO */  
void lista::Buscar(int elem)
{
  pnodo aux= primero;
  while ((aux->siguiente!=NULL) &&( aux->valor!=elem ))
		aux=aux->siguiente;
  if(aux->valor==elem)
     cout<<"Elemento si se encuentra"<<endl;
  else	 
 	 cout<<"Elemento no se encuentra"<<endl;
}

/*BUSCAR UN ELEMENTO EN UNA POSICION */
void lista::BuscarPos (int Elem,int Pos)
{
	pnodo aux=primero;
	int i;

	if(!( ListaVacia()))
	{
		i=1;
		while ((i!= Pos) &(aux->siguiente !=NULL))
		{
			aux = aux->siguiente;
			i++;
	    }
	    if ((i==Pos)& (aux->valor ==Elem))
	    	cout<<"Elemento si encontrado"<<endl;
	    else
         	cout<<"Elemento no encontrado"<<endl;
	}
	else
		cout<<"Lista vacia"<<endl;

}
/*SUMA DOS LISTAS DE IGUAL TAMA�O*/    
void lista::Sumar(lista Lista1, lista Lista2){
	if ((Lista1.primero == NULL) || (Lista2.primero == NULL)){// ListaVacia(L1)
		cout<<"Algunas lista esta vacia"<<endl;
	}
	else{
		int largo1 = Lista1.largoLista();
		int largo2 = Lista2.largoLista();
		
		if(largo1 == largo2)
        {
			
			pnodo Aux1 = Lista1.primero;
			pnodo Aux2 = Lista2.primero;
			int suma=0;
			while(Aux1!=NULL)
            {
				suma= Aux1->valor+Aux2->valor;
				InsertarFinal(suma);
				Aux1= Aux1->siguiente;
				Aux2= Aux2->siguiente;
			}
		}
		else{
			cout<<"Las listas no son iguales"<<endl;
		}
	}
}     
/*SUMA DOS LISTA DE DIFERENTE TAMA�O */
void lista::SumarListasTamD(lista Lista1,lista Lista2)
{

	pnodo Aux1=Lista1.primero;
	pnodo Aux2=Lista2.primero;
	
	while(Aux1!=NULL || Aux2!=NULL)
    {
	  if(Aux1==NULL && Aux2!= NULL)
      { 
          InsertarFinal(Aux2->valor);
		  Aux2=Aux2->siguiente;
	  }
	  else 
	  {
          if(Aux1!=NULL && Aux2==NULL)
          {
			InsertarFinal(Aux1->valor);
			Aux1=Aux1->siguiente;
		  }
		  else
          {
            int suma=0;
            suma= Aux1->valor+Aux2->valor;
			InsertarFinal(suma);
			Aux1=Aux1->siguiente;
			Aux2=Aux2->siguiente;
   		  }
		
   	 }

    }
}    

int main()
{
   lista Lista1, Lista2,Lista3,Lista4,Lista5;
   
    
   
   Lista1.InsertarFinal(4);
   Lista1.InsertarFinal(8);
   Lista1.InsertarFinal(3);
   
   Lista2.InsertarFinal(9);
   Lista2.InsertarFinal(2);
   Lista2.InsertarFinal(5);
   Lista2.InsertarFinal(9);
   
   Lista3.InsertarFinal(9);
   Lista3.InsertarFinal(2);
   Lista3.InsertarFinal(5);
   Lista3.InsertarFinal(10);
   Lista3.InsertarFinal(13);
   Lista3.InsertarFinal(19);

   Lista1.Mostrar();
   Lista2.Mostrar(); 
   Lista3.Mostrar();
  //metodo Buscar
  // Lista1.Buscar(8);
   //metodo Buscar en Pos
//  Lista1.BuscarPos(2,3);
 // Lista2.BuscarPos(2,4);
  //metodo Sumar
  // Lista4.Sumar(Lista1,Lista2);
   //Lista4.Mostrar();
   // metodo sumar diferente tama�o
  // Lista5.SumarListasTamD(Lista1,Lista2);

   cin.get();
   return 0;
creo que lo logre 
