/*** Seccion: Declaracion
     Descripcion: La declaracion de la clase        ***/
     
/*** Programa: ADT_OBJ_DIN_ARBOL_AVL.h
     Programa Base: Ninguno
     Programador: Alfonso Alvarez Sánchez
     Fecha: 09 - Abr - 09
     Hora: 11:00 pm
     Descripcion: Crear la estructura arbol avl con Objetos
     con los siguientes métodos:
         Constructor
         Destructor
         Vacia
         Llena
         set Elemento
         get Elemento
         recorridos:
           -inorden
           -preorden
           -postorden
         recorridos inversos
           -inorden
           -preorden
           -postorden
         buscar
         sucesor
         predecesor
         hijos
         padre
         camino
         nivel del nodo
         altura
         eliminar
         rotaciones
           -simple derecha
           -simple izquierda
           -doble derecha
           -doble izquierda 
         operador   <<	imprime en inOrden los elementos en pantalla
         Operador   >> 	mete el elemento al arbol
         operador   + 	mete todos los elementos del segundo arbol
         operador   -	elimina los elementos del segundo árbol
         operador   =	elimina los elementos del primer árbol y mete los del segundo
         operador   <, <=, >, >=, ==	Tomando como referencia el número de elementos
                                   
         Factor de balanceo
         pibote
         balanceo                          
                                                           ***/ 
         
/** Uitilerias **/
#include <iostream>
#include "nodos.h"

#ifndef _ADT_OBJ_DIN_ARBOL_AVL_H
#define _ADT_OBJ_DIN_ARBOL_AVL_H
using namespace std;

/***    Elemento: clase nodo
        Descripcion: declaracion de la clase nodo   

template<class T> class Nodo{
               public:
                       T dato, fb;
                       Nodo<T> *izq, *der;
                       
               public:
                      Nodo() : izq(NULL), der(NULL){}
                      Nodo(T e): dato(e), izq(NULL), der(NULL), fb(0){}
}; // fin clase nodo
/*** Fin del elemento ***/

/***    Elemento: clase Arbol
        Descripcion: declaracion de la clase Arbol   ***/

template <class T> class ArbolAVL : NodoAVL<T> {
      //Variables de Instancia
      public:
              NodoAVL<T> *a;
              //int num;
      
      //Metodos de la clase        
      public:
              ArbolAVL();
              ~ArbolAVL();
              bool vacio();
              bool full();
              bool setElem(T);
              bool getElem(T);
              void inOrden(NodoAVL<T> *apt);
              void preOrden(NodoAVL<T> *apt);
              void postOrden(NodoAVL<T> *apt);
              void inOrdenInv(NodoAVL<T> *apt);
              void preOrdenInv(NodoAVL<T> *apt);
              void postOrdenInv(NodoAVL<T> *apt);
              NodoAVL<T> * buscar(T);
              NodoAVL<T> * sucesor(T);
              NodoAVL<T> * predecesor(T);
              void hijos(T);
              NodoAVL<T> * padre(T);
              void camino(T);
              void nivel(T);
              int altura(NodoAVL<T> *apt);
              void eliminar(NodoAVL<T> *apt);
              void rsi(NodoAVL<T> *apt);
              void rsd(NodoAVL<T> *apt);
              void rdi(NodoAVL<T> *apt);
              void rdd(NodoAVL<T> *apt);
              void facb(NodoAVL<T> *apt); 
              void pivote(NodoAVL<T> *apt);
              void balanceo(NodoAVL<T> *apt);
              
              void inOrden1();
              void preOrden1();
              void postOrden1();
              void inOrdenInv1();
              void preOrdenInv1();
              void postOrdenInv1();
              
              void eliminar1();
              void facb1();
              void altura1();
};// fin clase lista
/*** Fin elemento ***/

/***
Elemento: Constructor
        Descripcion: inicializa el arbol
        Entrada: ninguna
        Salida: Ninguna
        Pre Condicion: Ninguna
        PostCondicion: arbol Inicializado              ***/
template<class T> ArbolAVL<T>:: ArbolAVL(){
               a = NULL;               
}//FIn metodo constructor
/** FIn elemento ***/

/***
Elemento: Destructor
        Descripcion: desetruye el arbol
        Entrada: ninguna
        Salida: Ninguna
        Pre Condicion: arbol creado
        PostCondicion: arbol destruido              ***/
template<class T> ArbolAVL<T>:: ~ArbolAVL(){
               eliminar1();               
}//FIn metodo destructor
/** FIn elemento ***/

/***
Elemento: vacío
        Descripcion: checa si esta vacio o no
        Entrada: nada
        Salida: T/F si vacio o no
        Pre Condicion: Arbol creado
        PostCondicion: nada              ***/
template<class T> bool ArbolAVL<T>:: vacio(){
               if(a == NULL){
                       return true;
               }else{
                       return false;      
               }
}//FIn metodo vacio
/** FIn elemento ***/

/***
Elemento: lleno
        Descripcion: dice si esta lleno o no
        Entrada: nada
        Salida: t/F si lleno o no
        Pre Condicion: arbol creado
        PostCondicion: nada              ***/
template<class T> bool ArbolAVL<T>:: full(){
               //variables locales
               NodoAVL<T> * tmp;
               
                    tmp = new NodoAVL<T>();
                    if(tmp == NULL){
                         return true;
                    }else{
                          delete tmp;
                          return false;      
                    }
}//FIn metodo lleno
/** FIn elemento ***/

/***
        Elemento: set elem
        Descripcion: mete nuevo elemento
        Entrada: elem
        Salida: t/F si entra o no
        Pre Condicion: arbol creado
        PostCondicion: arbol con nuevo elemento              ***/
template<class T> bool ArbolAVL<T>:: setElem(T e){
               //variable locales
               NodoAVL<T> * apt, *tmp;
               NodoAVL<T> * aux;
               
               if(!full()){
                         if(a != NULL){
                              apt = a;
                              while(apt != NULL && apt -> dato != e){
                                 aux = apt;
                                 if(apt -> dato > e){
                                        apt = apt -> izq;     
                                 }else{
                                       apt = apt -> der;
                                 }
                              }
                              if(apt != NULL){
                                     return false;
                              }else{
                                    tmp = new NodoAVL<T>(e);
                                    if(aux -> dato > e){
                                         aux -> izq = tmp;
                                    }else{
                                          aux -> der = tmp;      
                                    }
                                    facb1();
                                    pivote(a);
                                    return true;
                              }
                         }else{
                               a = new NodoAVL<T>(e);
                               return true;      
                         }                         
               }else{
                     return false;
               }        
}//FIn metodo destructor
/** FIn elemento ***/

/***
        Elemento: getElem
        Descripcion: saca un elemento
        Entrada: elemento
        Salida: t/F si sale o no
        Pre Condicion: arbol creado
        PostCondicion: arbol con 1 elemento menos               ***/
//template<class T> bool ArbolAVL<T>:: getElem(T e){
  /***             //variables locales
               Nodo<T> * B, *P, *S;
               
               B = buscar(e);
               if(B != NULL){
                    P = predecesor(e);
                    //S = sucesor(e);
                    if(P != NULL){
                         B -> dato = P -> dato;
                         delete P;
                         P = NULL;
                    }else{
                          S = sucesor(e);
                          if(S != NULL){
                               B -> dato = S -> dato;
                               delete S;
                               S = NULL;
                          }else{
                                delete B;
                                B = NULL;
                                facb1();
                                //balanceo(a);
                                pivote(a);
                                return true;  
                          }
                    }
                    facb1();
                    //balanceo();
                    pivote(a);
               }else{
                     return false;      
               }
               
}//FIn metodo sacarelem  ***/

template <class T> bool ArbolAVL<T>::getElem(T e){
   NodoAVL<T> *b, *p, *s, *aux;
    b = buscar(e);
    if(b != NULL){
      p = predecesor(b -> dato);
      if(p != NULL){
        aux = padre(p->dato);
        b->dato = p->dato;
        if(aux->dato < p->dato){
          aux->der = NULL;               
        }else{
          aux->izq = NULL;    
        }
        delete p;
        facb(a);
        pivote(a);
        return true;
           
      }else{
        s = sucesor(b -> dato);
        if(s != NULL){
          aux = padre(s->dato);
          b->dato = s->dato;
          if(aux->dato < s->dato){
            aux->der = NULL;               
          }else{
            aux->izq = NULL;    
          }
          delete s;
          facb(a);
          pivote(a);
          return true;     
        }else{
          aux = padre(b->dato);
          if(aux->dato < b->dato){
            aux->der = NULL;               
          }else{
            aux->izq = NULL;    
          }
          delete b;
          facb(a);
          pivote(a);
          return true;      
        }      
      }
    }else{
      return false;      
    }
}//Fin del metodo sacar
/** FIn elemento ***/

/***
        Elemento: InOrden
        Descripcion: imprime en inOrden
        Entrada: apuntador
        Salida: nada
        Pre Condicion:arbol creado
        PostCondicion: nada              ***/
template<class T> void ArbolAVL<T>:: inOrden(NodoAVL<T> *apt){
               //Variables Locales
               //Nodo<T> *apt;
               
               if(apt != NULL){
                      inOrden(apt -> izq);
                      cout << apt -> dato <<" - " ;
                      inOrden(apt -> der);
                      return;
               }else{
                     return;     
               }
}//FIn metodo inOrden
/** FIn elemento ***/

/***
        Elemento: PreOrden
        Descripcion: imprime en preOrden
        Entrada: apuntador
        Salida: nada
        Pre Condicion:arbol creado
        PostCondicion: nada              ***/
template<class T> void ArbolAVL<T>:: preOrden(NodoAVL<T> *apt){
               //Variables Locales
               //Nodo<T> * apt;
               
               if(apt != NULL){
                      cout << apt -> dato <<" - " ;
                      preOrden(apt -> izq);                      
                      preOrden(apt -> der);
                      return;
               }else{
                     return;     
               }
}//FIn metodo preOrden
/** FIn elemento ***/

/***
        Elemento: PostOrden
        Descripcion: imprime en postOrden
        Entrada: apuntador
        Salida: nada
        Pre Condicion:arbol creado
        PostCondicion: nada              ***/
template<class T> void ArbolAVL<T>:: postOrden(NodoAVL<T> *apt){
               //Variables Locales
               //Nodo<T> * apt;
               
               if(apt != NULL){
                      postOrden(apt -> izq);                      
                      postOrden(apt -> der);
                      cout << apt -> dato <<" - " ;
                      return;
               }else{
                     return;     
               }
}//FIn metodo postOrden
/** FIn elemento ***/

/***
        Elemento: InOrdenInv
        Descripcion: imprime en inOrdenInv
        Entrada: apuntador
        Salida: nada
        Pre Condicion:arbol creado
        PostCondicion: nada              ***/
template<class T> void ArbolAVL<T>:: inOrdenInv(NodoAVL<T> *apt){
               //Variables Locales
               //Nodo<T> * apt;
               
               if(apt != NULL){
                      inOrdenInv(apt -> der);
                      cout << apt -> dato <<" - " ;
                      inOrdenInv(apt -> izq);
                      return;
               }else{
                     return;     
               }
}//FIn metodo inOrdenInv
/** FIn elemento ***/

/***
        Elemento: PreOrdenInv
        Descripcion: imprime en preOrdenInv
        Entrada: apuntador
        Salida: nada
        Pre Condicion:arbol creado
        PostCondicion: nada              ***/
template<class T> void ArbolAVL<T>:: preOrdenInv(NodoAVL<T> *apt){
               //Variables Locales
               //Nodo<T> * apt;
               
               if(apt != NULL){
                      cout << apt -> dato <<" - " ;
                      preOrdenInv(apt -> der);                      
                      preOrdenInv(apt -> izq);
                      return;
               }else{
                     return;     
               }
}//FIn metodo preOrdenInv
/** FIn elemento ***/

/***
        Elemento: PostOrden
        Descripcion: imprime en postOrden
        Entrada: apuntador
        Salida: nada
        Pre Condicion:arbol creado
        PostCondicion: nada              ***/
template<class T> void ArbolAVL<T>:: postOrdenInv(NodoAVL<T> *apt){
               //Variables Locales
               //Nodo<T> * apt;
               
               if(apt != NULL){
                      postOrdenInv(apt -> der);                      
                      postOrdenInv(apt -> izq);
                      cout << apt -> dato <<" - " ;
                      return;
               }else{
                     return;     
               }
}//FIn metodo postOrden
/** FIn elemento ***/


/***
        Elemento: Buscar
        Descripcion: busca elemento
        Entrada: elemento
        Salida: apuntador
        Pre Condicion: arbol creaado
        PostCondicion: nada              ***/
template<class T> NodoAVL<T> * ArbolAVL<T>:: buscar(T e){
               // variables locales
               NodoAVL<T> * apt;
               
               if(!vacio()){
                    apt = a;
                    while(apt != NULL && apt -> dato != e){
                            if(apt -> dato > e){
                                 apt = apt -> izq;
                            }else{
                                  apt = apt -> der;
                            }
                    }
                    if(apt == NULL){
                           cout << "No esta ese elemento"<<endl;
                           return NULL;     
                    }else{
                          cout << "Elemento encontrado!"<<endl;
                          return apt;
                    }
               }else{
                     return NULL;      
               }
               
               
}//FIn metodo buscar
/** FIn elemento ***/


/***
        Elemento: Sucesor
        Descripcion: busca el sucesor de un elemento
        Entrada: elemnto
        Salida: apuntador
        Pre Condicion: arbol creado
        PostCondicion: nada              ***/
template<class T> NodoAVL<T> * ArbolAVL<T>::sucesor(T e){
         /***      //variables locales
               Nodo<T> * apt, *B;
               
               B = buscar(e);
               if(B != NULL){
                    apt = B;
                    apt = apt -> der;
                    while(apt != NULL){
                            apt = apt -> izq;
                    }
                    return apt;
               }else{
                     return NULL;      
               }
}//FIn metodo sucesor ***/

//variables locales
               NodoAVL<T> * apt, *B;
               
               B = buscar(e);
               if(B != NULL){
                    apt = B;
                    if(apt -> der != NULL){
                           apt = apt -> der;
                    }else{
                          return NULL;      
                    }
                    while(apt -> izq != NULL){
                            apt = apt -> izq;
                    }
                    return apt;
               }else{
                     return NULL;      
               }
}//FIn metodo sucesor
/** FIn elemento ***/


/***
        Elemento: predecesor
        Descripcion: busca el predeceesor
        Entrada: elemento
        Salida: apuntador
        Pre Condicion: arbol creaado
        PostCondicion: nada               ***/
/***template<class T> Nodo<T> * ArbolAVL<T>::predecesor(T e){
               //variables locales
               Nodo<T> * apt;
               
               apt = buscar(e);
               if(apt != NULL){
                         apt = apt -> izq;
                         while(apt != NULL){
                                   apt = apt -> der;          
                         }
                         return apt;
               }else{
                     return NULL;      
               }    
}//FIn metodo predecesor ***/

template<class T> NodoAVL<T> * ArbolAVL<T>::predecesor(T e){
               //variables locales
               NodoAVL<T> * apt;
               
               apt = buscar(e);
               if(apt != NULL){
                  if(apt -> izq != NULL){
                               apt = apt -> izq;
                               while(apt -> der != NULL){
                                             apt = apt -> der;          
                               }
                               return apt;
                  }else{
                     return NULL;      
                  }
               }else{
                    return NULL;     
               }    
}//FIn metodo predecesor
/** FIn elemento ***/


/***
        Elemento: Hijos
        Descripcion: te dice los hijos
        Entrada: nodo
        Salida: hijos
        Pre Condicion: arbol creado
        PostCondicion: nada               ***/
template<class T> void ArbolAVL<T>:: hijos(T e){
               //variables locales
               NodoAVL<T> * apt;
               
               apt = buscar(e);
               if(apt != NULL){
                      if(apt -> der == NULL){
                           if(apt -> izq == NULL){
                                cout <<"No tiene hijos!... soltero? XD"<<endl;
                           }else{
                                 cout <<"Solo tiene hijo izquierdo! y es: " << apt -> izq -> dato << endl;      
                           }
                      }else{
                            if(apt -> izq == NULL){
                                 cout <<"Solo tiene hijo derecho! y es: " << apt -> der -> dato <<endl;
                            }else{
                                  cout << "El hijo derecho es " << apt -> der -> dato << endl << "El hijo izquierdo es " << apt -> izq -> dato << endl;      
                            }      
                      }
               }else{
                     cout << "No esta el elemento"<<endl;
                     return;      
               }
               
}//FIn metodo hijo
/** FIn elemento ***/


/***
        Elemento: padre
        Descripcion: busca al padre de un elemento
        Entrada: 
        Salida: 
        Pre Condicion: 
        PostCondicion:               ***/
template<class T> NodoAVL<T> * ArbolAVL<T>:: padre(T n){
               //variables locales
               NodoAVL<T> * apt, *aux;
               
               apt = a;
               if(!vacio()){
                    if(n != apt -> dato){
                         aux = apt;
                         if(apt -> dato > n){
                              apt = apt -> izq;
                         }else{
                               apt = apt -> der;      
                         }
                         while(apt !=  NULL && apt -> dato != n){
                                 aux = apt;
                                 if(apt -> dato > n){
                                      apt = apt -> izq;
                                 }else{
                                       apt = apt -> der;      
                                 }
                         }
                         if(n == apt->dato){
                              return aux;  
                         }else{
                               return NULL;   
                         }
                    }else{
                         return NULL;    
                    }  
               }else{
                     return NULL;   
               }
               
}//FIn metodo padre
/** FIn elemento ***/


/***
        Elemento: camino
        Descripcion: te dice por donde paso
        Entrada: elemento
        Salida: camino impreso
        Pre Condicion: arbol creado
        PostCondicion: nada              ***/
template<class T> void ArbolAVL<T>:: camino(T n){
               //variables locales
               NodoAVL<T> * apt;
               
               if(!vacio()){
                    apt = a;
                    while(apt != NULL && apt -> dato != n){
                            if(apt -> dato > n){
                                 apt = apt -> izq;
                            }else{
                                  apt = apt -> der;      
                            }
                            cout << apt -> dato << " - " ;
                    }
                    if(apt == NULL){
                         cout << "No esta" <<endl;
                         return;
                    }else{
                          cout << n;     
                    }
               }else{
                     cout <<"vacio"<<endl;
                     return;      
               }
               
}//FIn metodo camino
/** FIn elemento ***/


/***
        Elemento: nivel
        Descripcion: te da el nivel de un nodo
        Entrada: nada
        Salida: nivel
        Pre Condicion: arbol creado
        PostCondicion: nada              ***/
template<class T> void ArbolAVL<T>:: nivel(T n){
               //variables locales
               NodoAVL<T> * apt;
               int k;
               
               apt = a;
               k = 0;
               while(apt != NULL && apt -> dato != n){
                       if(apt -> dato > n){
                            apt = apt -> izq;
                       }else{
                             apt = apt -> der;      
                       }
                       k = k + 1;
               }
               if(apt == NULL){
                    cout <<"No esta" << endl;
                    return;
               }else{
                     cout <<"El Nivel es "<<k<<endl;
                     return;      
               }
               
}//FIn metodo nivel
/** FIn elemento ***/


/***
        Elemento: altura
        Descripcion: te da la altura de un nodo
        Entrada: apuntador
        Salida: entero (altura)
        Pre Condicion: arbol creado
        PostCondicion: nada               ***/
template<class T> int ArbolAVL<T>:: altura(NodoAVL<T> * apt){
               //variables locales
               int x, y;
               
               if(apt != NULL){
                    x = altura(apt -> der);
                    y = altura(apt -> izq);
                    if(x > y){
                         return x+1;
                    }else{
                          return y+1;      
                    }
               }else{
                     return 0;      
               }
               
}//FIn metodo altura
/** FIn elemento ***/


/***
        Elemento: eliminar
        Descripcion: borra elementos del arbol y libera espacio en memoria
        Entrada: apuntador(raiz)
        Salida: nada
        Pre Condicion: arbol creado
        PostCondicion: arbol borrado    ***/
template<class T> void ArbolAVL<T>:: eliminar(NodoAVL<T> * apt){
               //variables locales
               //Nodo<T> * apt;
               
               if(apt != a){
                    eliminar(apt -> izq);
                    eliminar(apt -> der);
                    delete apt;
               }else{
                     delete a;
                     a = NULL;    
               }
               
               
}//FIn metodo eliminar
/** FIn elemento ***/


/***
        Elemento: rotacion simple izquierda
        Descripcion: da la rotacion
        Entrada: apuntador pibote
        Salida: nada
        Pre Condicion: arbol creado y desbalance
        PostCondicion: rotacion echa para controlar desbalance              ***/
template<class T> void ArbolAVL<T>:: rsi(NodoAVL<T> * A){
               //variables locales
               NodoAVL<T> * P, * B;
               
               P = padre(A -> dato);
               B = A -> der;
               if(P != NULL){
                    P -> der = B;
                    A -> der = B -> izq;
                    B -> izq = A;
                    return;
               }else{
                     a = B;
                     A -> der = B -> izq;
                     B -> izq = A;
                     return;
               }
}//FIn metodo rsi
/** FIn elemento ***/

/***
        Elemento: rotacion simple derecha
        Descripcion: da la rotacion
        Entrada: apuntador pibote
        Salida: nada
        Pre Condicion: arbol creado y desbalance
        PostCondicion: rotacion echa para controlar desbalance              ***/
template<class T> void ArbolAVL<T>:: rsd(NodoAVL<T> * A){
               //variables locales
               NodoAVL<T> * P,* B;
               
               P = padre(A -> dato);
               B = A -> izq;
               if(P != NULL){
                    P -> izq = B;
                    A -> izq = B -> der;
                    B -> der = A;
                    return;
               }else{
                     a = B;
                     A -> izq = B -> der;
                     B -> der = A;
                     return;
               }
}//FIn metodo rsd
/** FIn elemento ***/


/***
        Elemento: rotacion doble izquierda
        Descripcion: da la rotacion doble
        Entrada: apuntador A
        Salida: nada
        Pre Condicion: arbol creado
        PostCondicion: arbol rotado              ***/
template<class T> void ArbolAVL<T>:: rdi(NodoAVL<T> * A){
               //variables locales
               NodoAVL<T> * P,* B,* C,* apt,* apt2;
               
               P = padre(A -> dato);
               B = A -> der;
               C = B -> izq;
               if(P != NULL){
                    P -> der = C;
                    apt = C -> izq;
                    apt2 = C -> der;
                    C -> izq = A;
                    C -> der = B;
                    A -> der = apt;
                    B -> izq = apt2;
                    return;
               }else{
                     a = C;
                     apt = C -> izq;
                     apt2 = C -> der;
                     C -> izq = A;
                     C -> der = B;
                     A -> der = apt;
                     B -> izq = apt2;
                     return;      
               }
               
}//FIn metodo rdi
/** FIn elemento ***/

/***
        Elemento: rotacion doble izquierda
        Descripcion: da la rotacion doble
        Entrada: apuntador A
        Salida: nada
        Pre Condicion: arbol creado
        PostCondicion: arbol rotado              ***/
template<class T> void ArbolAVL<T>:: rdd(NodoAVL<T> * A){
               //variables locales
               NodoAVL<T> * P,* B,* C,* apt,* apt2;
               
               P = padre(A -> dato);
               B = A -> izq;
               C = B -> der;
               if(P != NULL){
                    P -> izq = C;
                    apt = C -> izq;
                    apt2 = C -> der;
                    C -> izq = B;
                    C -> der = A;
                    B -> der = apt;
                    A -> izq = apt2;
                    return;
               }else{
                     a = C;
                     apt = C -> izq;
                     apt2 = C -> der;
                     C -> izq = B;
                     C -> der = A;
                     B -> der = apt;
                     A -> izq = apt2;
                     return;      
               }
               
}//FIn metodo rdi
/** FIn elemento ***/


/***
        Elemento: factor de balanceo
        Descripcion: actualiza el factor de balanceo de cada nodo
        Entrada: apuntador (raiz)
        Salida: nada
        Pre Condicion: arbol creadp
        PostCondicion: fb's actualuzados             ***/
template<class T> void ArbolAVL<T>:: facb(NodoAVL<T> * nodo){
               //variables locales
               //Nodo<T> * nodo;
               
               if(nodo != NULL){
                    nodo -> fb = altura(nodo -> der) - altura(nodo -> izq);
                    facb(nodo -> der);
                    facb(nodo -> izq);
                    return;
               }else{
                     return;      
               }
               
}//FIn metodo fb
/** FIn elemento ***/


/***
        Elemento: pivote
        Descripcion: te da el pivote(el q esta desbalanceado primero de abajo hacia arriba)
        Entrada: nodo(raiz)
        Salida: apintador
        Pre Condicion: arbol creado
        PostCondicion: nada              ***/
template<class T> void ArbolAVL<T>:: pivote(NodoAVL<T> * nodo){
               //variables locales
               //Nodo<T> * nodo;
               if(nodo != NULL){
                    pivote(nodo -> der);
                    pivote(nodo -> izq);
                    if(nodo -> fb > 1 || nodo -> fb < -1){
                            balanceo(nodo);
                         return;
                    }
               }
               
}//FIn metodo pivote
/** FIn elemento ***/


/***
        Elemento: balanceo
        Descripcion: balancea eligiendo q rotacion usar
        Entrada: nada
        Salida: nada
        Pre Condicion: arbol creado
        PostCondicion: arbol BALANCEADO              ***/
template<class T> void ArbolAVL<T>:: balanceo(NodoAVL<T> *A){
               //variables locales
               NodoAVL<T> *b;
               
               //A = pivote(a);
               if(A != NULL){
                    if(A -> fb > 1){
                         b = A -> der;
                         if(b -> fb >= 0){
                              rsi(A);
                         }else{
                               rdi(A);
                         }
                    }else{
                          b = A -> izq;
                          if(b -> fb >= 0){
                               rdd(A);
                          }else{
                                rsd(A);      
                          }
                    }
                    facb(a);
                    //pivote(a);
                    //balanceo();
                    return;
               }else{
                     return;      
               }
               
               
}//FIn metodo balanceo
/** FIn elemento ***/

template<class T> void ArbolAVL<T>::inOrden1(){
               inOrden(a);                              
}

template<class T> void ArbolAVL<T>::preOrden1(){
               preOrden(a);                              
}

template<class T> void ArbolAVL<T>::postOrden1(){
               postOrden(a);                              
}

template<class T> void ArbolAVL<T>::inOrdenInv1(){
               inOrdenInv(a);                              
}

template<class T> void ArbolAVL<T>::preOrdenInv1(){
               preOrdenInv(a);                              
}

template<class T> void ArbolAVL<T>::postOrdenInv1(){
               postOrdenInv(a);                              
}

template<class T> void ArbolAVL<T>::eliminar1(){
               eliminar(a);                              
}

template<class T> void ArbolAVL<T>::facb1(){
               facb(a);                              
}

template<class T> void ArbolAVL<T>::altura1(){               
              cout <<"La Altuura de tu arbol es " << altura(a)<<endl;               
}

#endif
        /**fin de seccion **/
