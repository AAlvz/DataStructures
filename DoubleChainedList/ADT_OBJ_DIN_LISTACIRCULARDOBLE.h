/***     Sección: Declaración
     Descripción: La declaracion de la base                                 ***/



/***     Programa: ADT_OBJ_DIN_LISTA
    Programa Base: ninguno
      Programador: Alfonso Alvarez
            Fecha: 16/Febrero/2008 2:00p.m.
      Descripción: Crear la estructura Lista con objetos
                   con los siguiente métodos:
             -  Constructor
              - Destructor
              - Vacio
              - Lleno
              - set Inicio
               set Final
              - set Elemento Ordenado
             -  get Inicio
             - get Final
             - get Elemento
             - Buscar
             -  Imprimir
             -  Eliminar
             -  Ordenar
             -  Buscar                                                       ***/
               

#ifndef _ADT_OBJ_DIN_LISTADEC_H
#define _ADT_OBJ_DIN_LISTADEC_H

/****  Librerias **************************************************************/
#include <iostream>
#include <string>
#include "nodos.h"
using namespace std;
/***     Elemento: clase nodo
      Descripción: Declara la clase                                      

/***     Elemento: clase lista
      Descripción: Declara la clase                                      ***/
template <class T> class ListaCrcDob : NodoC<T>{
      //Variables de instancia
      private:
          NodoC<T> *lst;
          int num;
      //Metodos de la clase 
      public:
          ListaCrcDob();
          ~ListaCrcDob();
          bool empty();
          bool full();
          bool setIni(T);
          bool setFin(T);
          bool getIni(T &);
          bool getFin(T &);
          bool setOrd(T);
          bool getElem(T);
          NodoC<T>* getPri();
          void print();
          NodoC<T> * buscar(T);
          void ordenar2(){ordenar(true);}
          void ordenar(bool);
          void eliminar();
          int longitud();
      
};//Fin de la clase lista
/***     Fin Elemento                                                       ***/
/***     Fin_Sección                                                        ***/

/***     Sección: Funciones o metodos
     Descripción: se declaran los metodos de la clase                       ***/
     
/***     Elemento: Constructor
      Descripción: Inicializa la lista
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: Ninguna  
   Post-Condicion: Lista Inicializado                                      ***/
template <class T> ListaCrcDob<T>::ListaCrcDob(){
         lst = NULL;     
         num = 0;
}//Fin del metodo constructor
/***     Fin Elemento                                                       ***/

/***     Elemento: Destructor
      Descripción: Elimina la lista
          Entrada: Ninguna
           Salida: Ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista destruido                                         ***/
template <class T> ListaCrcDob<T>::~ListaCrcDob(){
    eliminar();     
}//Fin del metodo destructoir
/***     Fin Elemento                                                       ***/

/***     Elemento: Vacio
      Descripción: checa si esta lleno o no
          Entrada: Ninguna
           Salida: V/F si tiene o no elementos
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Ninguna                                                  ***/
template <class T> bool ListaCrcDob<T>::empty(){
    return lst == NULL ? true : false;     
}//Fin del metodo constructor
/***     Fin Elemento                                                       ***/

/***     Elemento: full
      Descripción: checa si lleno
          Entrada: Ninguna
           Salida: V/F si esta llena o no
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Ninguna                                                  ***/
template <class T> bool ListaCrcDob<T>::full(){
         //Variables local
         NodoC<T> *tmp = new NodoC<T>();
         if(tmp == NULL){
            return true; 
         }
         delete tmp;
    return false;     
}//Fin del metodo constructor
/***     Fin Elemento                                                       ***/

/***     Elemento: Meter inicio
      Descripción: mete un nuevo elemento al inicio del lista
          Entrada: Nuevo elemento
           Salida: V/F si lo pudo meter
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista con un nuevo elemento al inicio                   ***/
template <class T> bool ListaCrcDob<T>::setIni(T e){
         NodoC<T> *tmp = new NodoC<T>(e);
         if(!full()){
              if(empty()){
                   lst = tmp;
                   tmp ->sig = tmp;
                   tmp->ant = tmp;
                   return true;
              }else{
                   tmp->sig = lst;
                   tmp->ant = lst->ant;
                   lst->ant->sig = tmp;
                   lst->ant = tmp;
                   lst = tmp;
                   return true;
              }
         }else{
            return false;   
         }

} 
/***     Fin Elemento                                                       ***/

/***     Elemento: Meter fin
      Descripción: mete un nuevo elemento al fin del lista
          Entrada: Nuevo elemento
           Salida: V/F si lo pudo meter
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista con un nuevo elemento al final                    ***/
template <class T> bool ListaCrcDob<T>::setFin(T e){
       NodoC<T> *tmp = new NodoC<T>(e);  
       if(!full()){
            if(empty()){
                setIni(e);
                return true; 
            }else{
                tmp->sig = lst;
                tmp->ant = lst->ant; 
                lst->ant->sig = tmp;
                lst->ant = tmp;
                return true;  
            }
       }else{
           return false;  
       }
}   
/***     Fin Elemento                                                       ***/

/***     Elemento: getIni
      Descripción: Saca el elemento del inicio
          Entrada: ninguna
           Salida: v/F si lo pudo meter o no
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista sin el primer elemento                             ***/
template <class T> bool ListaCrcDob<T>::getIni(T &e){
         
        NodoC<T> *tmp(lst); 
        if(!empty()){
             if(lst->sig == lst){
                e = lst->dato;
                delete lst;
                lst = NULL;
                return true;  
             }else{
                lst = tmp->sig;
                tmp->ant->sig = tmp->sig;
                tmp->sig = tmp->ant;
                e = tmp->dato;
                
                delete tmp;  
                return true; 
             }
        }else{
            return false;  
        }
}   
/***     Fin Elemento                                                       ***/

/***     Elemento: getFin
      Descripción: Saca el elemento del final
          Entrada: ninguna
           Salida: T/F si lo sacó o no
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista sin el ultimo elemento                             ***/
template <class T> bool ListaCrcDob<T>::getFin(T &e){
        NodoC<T> *tmp;
        if(!empty()){
             if(lst->sig == lst){
                  e = lst->dato;
                  delete lst;
                  lst = NULL;
                  return true;
             }else{
                  tmp = lst->ant;
                  tmp->ant->sig = lst;
                  lst->ant = tmp->ant;
                  delete tmp;
                  return true;
             }
        }else{
            return false;  
        }
}   
/***     Fin Elemento                                                       ***/

/***     Elemento: meter ordenado
      Descripción: mete un elemento de forma ordenada
          Entrada: elemento
           Salida: T/F si lo pudo meter o no
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista con nuevo elemento ordenada                        ***/
template <class T> bool ListaCrcDob<T>::setOrd(T e){
         NodoC<T> *tmp, *aux, *aux2;
         if(!full()){
            tmp = new NodoC<T>(e);
            if(empty()){
                 lst = tmp;
                 tmp->sig = tmp;
                 tmp->ant = tmp;
                 return true;
            }else{
                 aux = lst;
                 aux2 = lst->sig;
                 while(e>aux->sig->dato && aux2 != lst){
                       aux = aux->sig;
                       aux2 = aux2->sig;  
                 }
                 if(aux2!=lst){
                      tmp->sig = aux->sig;
                      tmp->ant = aux;
                      aux->sig->ant = tmp;
                      aux->sig = tmp;
                      return true;
                 }else{
                      tmp->sig = lst;
                      tmp->ant = lst->ant;
                      lst->ant->sig = tmp;
                      lst->ant = tmp;
                      return true; 
                 }
            }
         }else{
            return false;   
         }        
}   
/***     Fin Elemento                                                       ***/

/***     Elemento: sacar elemento
      Descripción: saca un elemento dado por el usuario de la lista
          Entrada: elemento
           Salida: T/F si lo saco o no
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista con un elemento menos                              ***/
template <class T> bool ListaCrcDob<T>::getElem(T e){
         NodoC<T> *apt;
               
               if(!empty()){
                    if(lst -> sig != lst){
                           if(lst -> dato == e){
                                lst -> sig -> ant = lst -> ant;
                                lst -> ant -> sig = lst -> sig;
                                apt = lst -> sig;
                                delete lst; 
                                lst = apt;
                           }else{
                              apt = lst;
                              while(apt -> sig != lst && apt -> dato != e){
                                      apt = apt -> sig;
                              }
                              if(apt -> dato == e){
                                   apt -> ant -> sig = apt -> sig;
                                   apt -> sig -> ant = apt -> ant;
                                   delete apt;
                                   return true;
                              }else{
                                    return false;      
                              }
                           }
                    }else{
                          if(lst -> dato == e){
                                 delete lst;
                                 lst = NULL;
                                 return true;       
                          }else{
                                      return false;
                          }
                    }
               }else{
                     return false;      
               }
}   
/***     Fin Elemento                                                       ***/

/***     Elemento: imprimir
      Descripción: imprime en pantalla los elementos de la lista
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: ninguna                                                  ***/
template <class T> void ListaCrcDob<T>::print(){
         NodoC<T> *tmp;
         if(!empty()){
             tmp = lst;
             do{
                cout<<tmp->dato<<" -> ";
                tmp = tmp->sig; 
             }while(tmp!=lst);
         }
}   
/***     Fin Elemento                                                       ***/

/***     Elemento: buscar
      Descripción: busca un elemento en la lista
          Entrada: elemento
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: ninguna                                                  ***/
template <class T> NodoC<T> * ListaCrcDob<T>::buscar(T e){
         NodoC<T> *tmp;
         bool b;
         if(!empty()){
              b = false;
              tmp = lst;
              do{
                  if(e==tmp->sig->dato){
                      b=true; 
                  }
                  tmp = tmp->sig;
              }while(tmp!=lst && b==false);
              if(tmp == lst){
                   return NULL;  
                   cout<<"no se encontro";
              }else{
                   return tmp; 
                   cout<< tmp; 
              }
         }else{
               return NULL;
         }
}   
/***     Fin Elemento                                                       ***/

/***     Elemento: longitud
      Descripción: dice la longitud de la lista
          Entrada: nignuna
           Salida: ninguna
    Pre-Condicion: Lista inicializada 
   Post-Condicion: ninguna                                                  ***/
template <class T> int ListaCrcDob<T>::longitud(){
         NodoC<T> *tmp;
         if(!empty()){
              if(lst->sig !=lst){
                   int x = 0;
                   tmp = lst;
                   do{
                       tmp = tmp->sig;
                       x++;
                   }while(tmp!=lst);
                   return x;
              }else{
                   return 0; 
              }
         }
}   
/***     Fin Elemento                                                       ***/

/***     Elemento: ordenar
      Descripción: ordena la lista
          Entrada: lista
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista ordenada                                           ***/
template <class T> void ListaCrcDob<T>::ordenar(bool b){
         NodoC<T> *tmp;
         if(!empty()){
              if(b){
                  tmp = lst;
                  b = false;
                  while(tmp->sig != lst){
                       if(tmp->dato > tmp->sig->dato){
                            T a = tmp->dato;
                            tmp->dato = tmp->sig->dato;
                            tmp->sig->dato = a;
                            b = true;
                       }
                       tmp = tmp->sig;   
                  }
                  ordenar(b);
              }
         }
}   
/***     Fin Elemento                                                       ***/

/***     Elemento: eliminar
      Descripción: elimina los lementos de la lista liberando memoria
          Entrada: ninguna
           Salida: ninguna
    Pre-Condicion: Lista inicializado  
   Post-Condicion: Lista sin elementos                                      ***/
template <class T> void ListaCrcDob<T>::eliminar(){
         NodoC<T> * tmp;
         if(!empty()){
            do{ 
              tmp = lst->sig;
              lst->sig = tmp->sig;
              tmp->sig->ant = lst;
              delete tmp;
            }while(lst->sig!=lst);
            delete lst;
            lst = NULL;
         }
}   
/***     Fin Elemento                                                       ***/

template<class T> NodoC<T> *ListaCrcDob<T> :: getPri(){
               NodoC<T> *apt;
               if(empty()){
                    return NULL;
               }else{
                     apt = lst;    
                     return apt;
               }
}

#endif
/***     Fin_Sección                                                        ***/
