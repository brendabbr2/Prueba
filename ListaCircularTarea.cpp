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
    
        
   friend class listaC;
};

typedef nodo *pnodo;

class listaC {
   public:
    listaC() { primero =  NULL; }
    ~listaC();
    
    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    
   private:
    pnodo primero;
    
};

listaC::~listaC()
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   
}

int listaC::largoLista()
{
   int cont=0;

    pnodo aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux->siguiente!=primero){
         aux=aux->siguiente;
         cont++;
    }
    return cont;
    }
    

}

void listaC::InsertarInicio(int v)
{
    pnodo nuevo;
   
   if (ListaVacia()){
     primero = new nodo(v);
     primero->siguiente=primero;
   }else{
      pnodo aux=primero;
      nuevo = new nodo (v,primero);
      while(aux->siguiente!=primero);
         aux=aux->siguiente;
      aux->siguiente=nuevo;
      primero=nuevo;

   }

   
}
 
void listaC::InsertarFinal(int v)
{
   
  pnodo nuevo;
  if (ListaVacia()){
     primero = new nodo(v);
     primero->siguiente=primero;
   }else{
        pnodo aux = primero;
        while(aux->siguiente!=primero);
            aux=aux->siguiente;
        nuevo = new nodo(v,aux->siguiente);
        nuevo->siguiente=primero;
      }    
}


void listaC::InsertarPos(int v,int pos)
{
   
   pnodo nuevo;
   int cont=0;
   if (ListaVacia()){
     primero = new nodo(v);
     primero->siguiente=primero;
   }else{
        if(pos <=1){
          nuevo = new nodo(v);
          nuevo->siguiente= primero;
          primero->siguiente=nuevo;
          primero = nuevo;     
        }      
        else{
             pnodo aux = primero->siguiente;
             int i = 2;
             while((i != pos )&&(aux->siguiente!= primero)){
                   i++;
                   aux=aux->siguiente;
             }
             nuevo= new nodo(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             primero=nuevo;
             
        }
        }


   
}
      
/*void listaC::BorrarFinal()
{
   
}

void listaC::BorrarInicio()
{
   
}

void listaC:: borrarPosicion(int pos)
{
}
 */




void listaC::Mostrar()
{
   nodo *aux;
   aux = primero;
   while(aux->siguiente!=primero) {
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
   }
   cout << endl;
}
  

int main()
{
  listaC Lista;
    
  Lista.InsertarInicio(10); 
  Lista.InsertarInicio(2);
  Lista.InsertarInicio(30);
  Lista.InsertarInicio(1);  
  Lista.InsertarFinal(11);
  Lista.InsertarPos(5, 3);
  Lista.InsertarPos(6, 4);
  Lista.InsertarPos(17, 1);
  Lista.Mostrar();
/*
  cout<< Lista.largoLista()<<endl;
  cout<<endl;

  Lista.BorrarInicio();
  Lista.Mostrar();
  Lista.BorrarFinal();
  Lista.Mostrar();
  Lista.borrarPosicion(2);
  Lista.Mostrar();
  Lista.borrarPosicion(11);
  Lista.Mostrar();
 */
  
  

   cin.get();
   return 0;
}
