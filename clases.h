#ifndef _clases_H
#define _clases_H

#include <iostream>
#include <string>
#include "ADT_OBJ_DIN_LISTA.h"
#include "ADT_OBJ_DIN_LISTACIRCULARDOBLE.h"
#include "ADT_OBJ_DIN_LISTACIRCULAR.h"
#include "ADT_OBJ_DIN_ARBOL_AVL.h"

using namespace std;

class valores;
class campos;
class datos;
class tabla;
class index;
ostream& operator <<(ostream&, const valores&);
ostream& operator <<(ostream&, const campos&);
ostream& operator <<(ostream&, const datos&);
ostream& operator <<(ostream&, const tabla&);

class valores{
      public:
             string valor;
             int orden;
             valores();
             valores(string);
             ~valores();
             void setvalue(string);
             void setorden();
             string getvalue();
             
             bool operator <(valores);
             bool operator >(valores);
             bool operator <=(valores);
             bool operator >=(valores);
             bool operator ==(valores);
             bool operator !=(valores);
             friend ostream& operator <<(ostream&, const valores&);
};

class campos{
      public:
             string nombre, descripcion, tipo;
             int orden;
             campos();
             campos(string);
             ~campos();
             void setname(string);
             void setdesc(string);
             void getord();
             void setord(int);
             void settype(string);
             string getname();
             string getdesc();
             string gettype();
             int gorden();
             
             bool operator < (campos);
             bool operator > (campos);
             bool operator <= (campos);
             bool operator >= (campos);
             bool operator == (campos);
             bool operator != (campos);
             friend ostream& operator <<(ostream&, const campos&);
};

class datos{
      public:
             int data;
             Lista<valores> lval;
             datos();
             datos(int);
             ~datos();
             int getdata();
             int setdata(int);
             
             bool operator < (datos);
             bool operator > (datos);
             bool operator <= (datos);
             bool operator >= (datos);
             bool operator == (datos);
             bool operator != (datos);
             friend ostream& operator <<(ostream&, const datos&);
      
};

class tabla{
      public:
             string nombre, descripcion, tipo;
             ListaCrcDob<campos> lcam;
             Lista<datos> ldat;
             ArbolAVL<string> lind;
             tabla();
             tabla(string);
             ~tabla();
             void setname(string);
             void setdesc(string);
             void settype(string);
             string getname();
             string getdesc();
             string gettype();
             
             bool operator < (tabla);
             bool operator > (tabla);
             bool operator <= (tabla);
             bool operator >= (tabla);
             bool operator == (tabla);
             bool operator != (tabla);
             friend ostream& operator <<(ostream&, const tabla&);
      
};

class index{
      public:
             string algo;
             index();
             index(string);
             ~index();
             void getalgo(string);
             
             bool operator < (index);
             bool operator > (index);
             bool operator <= (index);
             bool operator >= (index);
             bool operator == (index);
             bool operator != (index);
      
};

valores::valores(){}

valores::valores(string s){
       valor = s;
}

valores::~valores(){}

void valores::setvalue(string s){
     valor = s;     
}

void valores::setorden(){
     orden = orden + 1;     
}

string valores::getvalue(){
       return valor;       
}

bool valores:: operator < (valores v){
     if(valor < v.valor){
             return true;
     }else{
           return false;
     }     
}

bool valores:: operator > (valores v){
     if(valor > v.valor){
             return true;
     }else{
           return false;
     }     
}

bool valores:: operator <= (valores v){
     if(valor <= v.valor){
             return true;
     }else{
           return false;
     }     
}

bool valores:: operator >= (valores v){
     if(valor >= v.valor){
             return true;
     }else{
           return false;
     }     
}

bool valores:: operator == (valores v){
     if(valor == v.valor){
             return true;
     }else{
           return false;
     }     
}

bool valores:: operator != (valores v){
     if(valor != v.valor){
             return true;
     }else{
           return false;
     }     
}

ostream& operator << (ostream& out, const valores& v){
         out << "El orden de tu valor es: "<<v.orden<<"y el valor es: "<<v.valor<<endl;
         return out;
}

campos::campos(){}

campos::campos(string s){
       nombre = s;                                     
}

campos::~campos(){}

void campos::setname(string s){
     nombre = s;
}

void campos::setdesc(string s){
     descripcion = s;     
}

void campos::getord(){
     orden = orden + 1;
}

int campos::gorden(){
    return orden;    
}

void campos::setord(int n){
     orden = n;
}

void campos::settype(string s){
          tipo = s;
}

string campos::getname(){
       return nombre;       
}

string campos::getdesc(){
       return descripcion;       
}

string campos::gettype(){
       return tipo;       
}

bool campos::operator< (campos c){
     if(nombre < c.nombre){
          return true;
     }else{
           return false;
     }     
}

bool campos::operator> (campos c){
     if(nombre > c.nombre){
          return true;
     }else{
           return false;
     }     
}

bool campos::operator<= (campos c){
     if(nombre <= c.nombre){
          return true;
     }else{
           return false;
     }     
}

bool campos::operator>= (campos c){
     if(nombre >= c.nombre){
          return true;
     }else{
           return false;
     }     
}

bool campos::operator== (campos c){
     if(nombre == c.nombre){
          return true;
     }else{
           return false;
     }     
}

bool campos::operator!= (campos c){
     if(nombre != c.nombre){
          return true;
     }else{
           return false;
     }     
}

ostream& operator <<(ostream& out, const campos& c){
         out << "El nombre del campos es: "<<c.nombre<<endl
             << "La descripcion del campo es: "<<c.descripcion<<endl
             << "El tipo de campo es: "<<c.tipo<<endl
             << "Este campo es el numero: "<<c.orden<<endl<<endl<<endl;
         return out;
}

datos::datos(){}

datos::datos(int n){
     data = n;                             
}

datos::~datos(){}

int datos::getdata(){
    data = data + 1;
    return data;
}

int datos::setdata(int n){
    data = n;
    return data;
}

bool datos::operator <(datos d){
     if(data < d.data){
          return true;
     }else{
           return false;
     }     
}

bool datos::operator >(datos d){
     if(data > d.data){
          return true;
     }else{
           return false;
     }     
}

bool datos::operator <=(datos d){
     if(data <= d.data){
          return true;
     }else{
           return false;
     }     
}

bool datos::operator >=(datos d){
     if(data >= d.data){
          return true;
     }else{
           return false;
     }     
}

bool datos::operator ==(datos d){
     if(data == d.data){
          return true;
     }else{
           return false;
     }     
}

bool datos::operator !=(datos d){
     if(data != d.data){
          return true;
     }else{
           return false;
     }     
}

ostream& operator <<(ostream& out, const datos& d){
         out << "La posicion de tu dato es: "<<d.data<<endl;
         return out;
}

tabla::tabla(){}

tabla::tabla(string s){
     nombre = s;                    
}

tabla::~tabla(){}

void tabla::setname(string s){
     nombre = s;
}

void tabla::setdesc(string s){
     descripcion = s;
}

void tabla::settype(string s){
     tipo = s;
}

string tabla::getname(){
       return nombre;       
}

string tabla::getdesc(){
       return descripcion;       
}

string tabla::gettype(){
       return tipo;       
}

bool tabla::operator < (tabla t){
     if(nombre < t.nombre){
          return true;
     }else{
           return false;      
     }     
}

bool tabla::operator > (tabla t){
     if(nombre > t.nombre){
          return true;
     }else{
           return false;      
     }     
}

bool tabla::operator <= (tabla t){
     if(nombre <= t.nombre){
          return true;
     }else{
           return false;      
     }     
}

bool tabla::operator >= (tabla t){
     if(nombre >= t.nombre){
          return true;
     }else{
           return false;      
     }     
}

bool tabla::operator == (tabla t){
     if(nombre == t.nombre){
          return true;
     }else{
           return false;      
     }     
}

bool tabla::operator != (tabla t){
     if(nombre != t.nombre){
          return true;
     }else{
           return false;      
     }     
}

ostream& operator << (ostream& out, const tabla& t){
         out << "'''''''''''''''''''''''''''Tabla "<<t.nombre<<"''''''''''''''''''''''''''"<<endl;
         out << "\tEl nombre de tu tabla es: "<<t.nombre<<endl
             << "\tLa descripcion de tu tabla es: "<<t.descripcion<<endl
             << "\tEl tipo de tu tabla es: "<<t.tipo<<endl<<endl<<endl;
         return out;
}

index::index(){}

index::index(string s){
      algo = s;                                  
}

index::~index(){}

bool index::operator < (index i){
     if(algo < i.algo){
          return true;
     }else{
           return false;      
     }     
}

bool index::operator > (index i){
     if(algo > i.algo){
          return true;
     }else{
           return false;      
     }     
}

bool index::operator >= (index i){
     if(algo >= i.algo){
          return true;
     }else{
           return false;      
     }     
}

bool index::operator <= (index i){
     if(algo <= i.algo){
          return true;
     }else{
           return false;      
     }     
}

bool index::operator == (index i){
     if(algo == i.algo){
          return true;
     }else{
           return false;      
     }     
}

bool index::operator != (index i){
     if(algo != i.algo){
          return true;
     }else{
           return false;      
     }     
}

void index::getalgo(string n){
     algo = n;
}

#endif
