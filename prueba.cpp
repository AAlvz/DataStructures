#include <iostream>
#include <string>
#include "ADT_OBJ_DIN_LISTACIRCULAR.h"
#include "ADT_OBJ_DIN_LISTA.h"
#include "ADT_OBJ_DIN_LISTACIRCULARDOBLE.h"
#include "ADT_OBJ_DIN_ARBOL_AVL.h"
#include "clases.h"

ListaCrc<tabla> ta;
ListaCrc<tabla> *ata;
Nodo<tabla> nta;
Nodo<tabla> *anta;
tabla tab;
tabla *atab;

ListaCrcDob<campos> ca;
ListaCrcDob<campos> *aca;
NodoC<campos> nca;
NodoC<campos> *anca;
campos cam;
campos *acam;

Lista<datos> da;
Lista<datos> *ada;
Nodo<datos> nda;
Nodo<datos> *anda;
datos dat;
datos *adat;

Lista<valores> va;
Lista<valores> *ava;
Nodo<valores> nva;
Nodo<valores> *anva;
valores val;
valores *aval;

ArbolAVL<string> in;
ArbolAVL<string> *ain;
NodoAVL<string> nin;
NodoAVL<string> *anin;
index ind;
index *aind;

using namespace std;

int main(){
    int op=0;
	while (op!=4)
	{
		cout<<""<<endl
		<<"                                    TRABAJO FINAL"<<endl
		<<"                            Administrador de base de datos"<<endl
		//<<"________________________________________________________________________________"<<endl<<endl
		<<"             ___________________________________________________________"<<endl<<endl
		<<"                      [ 1  ]         Acceder a Tablas       [  1 ]              "<<endl
		<<"                      [ 2  ]           Meter Campo          [  2 ]              "<<endl
		<<"                      [ 3  ]          Ir a Registros        [  3 ]              "<<endl
		<<"                      [ 4  ]              Salir             [  4 ]              "<<endl
		<<endl<<endl
		<<"                                      Elijoooo: ";
		
		cin>>op;
		system("cls");

		if (op==1)
		{
            int opc;
            string nom;
                     cout <<"-------------------------------------------------------------------"<<endl
                          <<"                         Menu Tablas                               "<<endl
                          <<"-------------------------------------------------------------------"<<endl
                          <<endl
                          <<endl
                          <<"        (11)       Buscar o Crear Tabla         (11)       "<<endl<<endl
                          <<"        (12)         Modificar Tabla            (12)       "<<endl<<endl
                          <<"        (13)           Ir a Campos              (13)       "<<endl<<endl
                          <<"        (14)          Imprimir Tablas           (14)       "<<endl<<endl
                          <<"        (15)              Index                 (15)       "<<endl<<endl
                          <<"        (16)           Borrar Tabla             (16)       "<<endl<<endl
                          <<"        (17)     Ordenar Tablas por nombre      (17)       "<<endl<<endl
                          <<"        (18)             Regresar               (18)       "<<endl<<endl
                          <<endl
                          <<"--------------------------------------------------------------------"<<endl
                          <<endl;
                     cin >> opc;
                     system("cls");
                     
                     if(opc == 11){
                          cout <<"'''''''''''''''''''''''''''''''NOMBRE'''''''''''''''''''''''''''''"<<endl;  
                          cout <<"Nombre de la tabla: "<<endl;
                          cin >> nom;
                          tab.setname(nom);
                          anta = ta.buscar(nom);
                          if(anta != NULL){
                               cout <<"Esta tabla ya existe:" <<endl<<endl<<endl;
                               tab = anta ->dato;
                               cout<<tab;
                               system("pause");
                               system("cls");
                          }else{
                                cout <<"Esa tabla no existe, sera creada"<<endl
                                     <<endl<<endl<<endl
                                     <<"''''''''''''''''''''''''''''''DESCRIPCION''''''''''''''''''''''''''"<<endl
                                     <<"Que descripcion tendra tu tabla?"<<endl;
                                     cin >> nom;
                                     tab.setdesc(nom);
                                cout <<endl<<endl<<endl<<"'''''''''''''''''''''''''''''''''TIPO''''''''''''''''''''''''''''"<<endl;
                                cout <<"Que tipo es tu tabla?"<<endl;
                                     cin >> nom;
                                cout<<endl<<endl<<endl;
                                     tab.settype(nom);
                                     ta.setFin(tab);
                                cout <<"Tu tabla ah sido creada exitosamente!"<<endl;
                                system("pause");
                                system("cls");
                          }//fin else de if(anta!= NULL)
                     }//fin opc 11
                     
                     
                     if(opc == 12){
                          cout <<"'''''''''''''''''''''''''''''''NOMBRE'''''''''''''''''''''''''''''"<<endl
                               <<endl
                               <<"Nombre de la tabla que quieres modificar: "<<endl;
                          cin >> nom;
                          anta = ta.buscar(nom);
                          if(anta != NULL){
                               atab = &anta -> dato;
                               cout <<"Nuevo nombre para tu tabla: "<<endl;
                               cin >> nom;
                               atab->setname(nom);
                               cout <<endl<<endl<<endl;
                               cout <<"''''''''''''''''''''''''''''''DESCRIPCION''''''''''''''''''''''''''"<<endl
                                    <<"Nueva descripcion para tu tabla: "<<endl;
                               cin >> nom;
                               atab->setdesc(nom);
                               cout <<endl<<endl<<endl;
                               cout <<"'''''''''''''''''''''''''''''''''TIPO''''''''''''''''''''''''''''"<<endl;
                               cout <<"Nuevo tipo para tu tabla: "<<endl;
                               cin >> nom;
                               atab->settype(nom);
                               cout <<endl<<endl<<endl;
                               cout << "Tu tabla ah sido modificada con éxito!"<<endl;
                               system("pause");
                               system("cls");
                          }else{
                                cout <<"Lo siento, tabla con dicho nombre no existe!"<<endl;
                                system("pause");
                                system("cls");
                          }
                     }//fin opc12
                     
                     if(opc == 13){
                          int opci;
                          
                          cout <<""<<endl
                               <<"............................... Menu Campos.........................."<<endl
                               <<""<<endl
                               <<endl
                               <<endl
                               <<"              -31-            Imprimir campos           -31-       "<<endl<<endl
                               <<"              -32-          Crear campo en Tabla        -32-       "<<endl<<endl
                               <<"              -33-             Modificar Campo          -33-       "<<endl<<endl
                               <<"              -34-              Borrar Campo            -34-       "<<endl<<endl
                               <<"              -35-        Ordenar campos por nombre     -35-       "<<endl<<endl
                               <<"              -36-                Regresar              -36-       "<<endl<<endl
                               <<"              -37-        Seleccionar Orden de Campos   -37-       "<<endl<<endl
                               <<endl
                               <<endl
                               <<"...................................................................."<<endl
                               <<endl
                               <<endl;
                          cin >> opci;
                          system("cls");
                          
                          if(opci == 31){   
                               cout <<"De que tabla deseas los campos??"<<endl;
                               cin >> nom;
                               anta = ta.buscar(nom);
                               if(anta != NULL){
                                    atab = &anta -> dato;
                                    tab = anta -> dato;
                                    aca = &atab -> lcam;
                                    if(aca->longitud() == 0){
                                         cout << "No tienes campos aun en la tabla" <<endl<<tab<<endl;
                                         system("pause");
                                         system("cls");
                                    }else{
                                         cout << "Tus campos son: "<<endl<<endl; 
                                         aca->print();
                                         cout <<endl<<endl;
                                         system("pause");
                                         system("cls");      
                                    }
                               }else{
                                   cout <<"Lo siento, esta tabla no existe!"<<endl;
                                   system("pause");
                                   system("cls");
                               }
                          }//fin opci 31
                          
                          if(opci == 32){
                                  cout << "Vas a crear campos, pero... en cual tabla?"<<endl;
                                  cin >> nom;
                                  anta = ta.buscar(nom);
                                  if(anta != NULL){
                                       cout <<"Si existe esta tabla!"<<endl;
                                       atab = &anta -> dato;
                                       cout <<"Tabla: "<<atab->nombre<<endl;
                                       aca = &atab -> lcam;
                                       cout << "Ahora veamos si tu campo ya existe..."<<endl;
                                       cout <<"'''''''''''''''''''''''''''''''NOMBRE'''''''''''''''''''''''''''''"<<endl;
                                       cout << "Nombre para tu campo: "<<endl;
                                       cin >> nom;
                                       anca = aca->buscar(nom);
                                       if(anca != NULL){
                                            cout<<"Este campo ya existe!, no puedes crear otro igual..."<<endl;
                                            system("pause");
                                            system("cls");
                                       }else{
                                             cout << "Este campo no existe, creemos lo demas..."<<endl<<endl<<endl;
                                             acam = &anca -> dato;
                                             cam.setname(nom);
                                             cout <<"''''''''''''''''''''''''''''''DESCRIPCION''''''''''''''''''''''''''"<<endl;
                                             cout <<"Descripcion de tu campo: "<<endl;
                                             cin >> nom;
                                             cam.setdesc(nom);
                                             cout <<"'''''''''''''''''''''''''''''''''TIPO''''''''''''''''''''''''''''"<<endl;
                                             cout <<"Tipo de campo: "<<endl;
                                             cin >> nom;
                                             cam.settype(nom);
                                             cam.getord();
                                             aca->setFin(cam);
                                             cout <<"Felicidades, has creado un campo con éxito..."<<endl;
                                             system("pause");
                                             system("cls");
                                       }
                                  }else{
                                        cout <<"Esa Tabla no existe, amigo!"<<endl;
                                        system("pause");
                                        system("cls");
                                  }
                               
                          }//fin opci 32
                          
                          if(opci == 33){
                               cout << "En que tabla esta el campo que quieres modificar?"<<endl;
                               cin >> nom;
                               anta = ta.buscar(nom);
                               if(anta != NULL){
                                    cout <<"Si existe esa tabla suertudote!, ahora... cual campo quieres modificar??"<<endl;
                                    cin >> nom;
                                    atab = &anta -> dato;
                                    aca = &atab -> lcam;
                                    anca = aca->buscar(nom);
                                    if(anca != NULL){
                                            cout <<"'''''''''''''''''''''''''''''''NOMBRE'''''''''''''''''''''''''''''"<<endl;
                                         cout <<"Si existe el campo que buscas, cual sera su nuevo nombre??"<<endl;
                                         cin >> nom;
                                         acam = &anca -> dato;
                                         acam->setname(nom);
                                         cout <<endl<<endl;
                                         cout <<"''''''''''''''''''''''''''''''DESCRIPCION''''''''''''''''''''''''''"<<endl;
                                         cout <<"Su nueva descripcion: "<<endl;
                                         cin >> nom;
                                         acam->setdesc(nom);
                                         cout <<endl<<endl;
                                         cout <<"'''''''''''''''''''''''''''''''''TIPO''''''''''''''''''''''''''''"<<endl;
                                         cout <<"Su nuevo tipo: "<<endl;
                                         cin >> nom;
                                         acam->settype(nom);
                                         cout <<"Felicidades! tu campo se modifico bien!"<<endl;
                                         system("pause");
                                         system("cls");
                                    }else{
                                          cout<<"Este campo no existe, chavo!"<<endl;
                                          system("pause");
                                          system("cls");      
                                    }
                               }else{
                                     cout<<"Esta tabla no existe, mi chavo!"<<endl;
                                     system("pause");
                                     system("cls");
                               }
                          }//fin opci33
                          
                          if(opci == 34){
                               cout <<"Ahora vas a borrar un campo, y como siempre..... de que tabla??"<<endl;
                               cin >> nom;
                               anta = ta.buscar(nom);
                               if(anta != NULL){
                                    cout<<"Esa tabla si existe!, que campo de ahi??"<<endl;
                                    cin >> nom;
                                    atab = &anta -> dato;
                                    aca = &atab -> lcam;
                                    anca = aca->buscar(nom);
                                    if(anca != NULL){
                                         cout <<"Se va a eliminar el campo "<<nom<<"...Quieres continuar?(usa minusculas)"<<endl<<endl;
                                         string p;
                                         cin >> p;
                                         if(p != "si"){
                                              cout <<"No dijiste que si... vamonos de aqui..."<<endl;
                                              system("pause");
                                              system("cls");
                                         }else{
                                               cout <<"..................................................."<<endl
                                                    <<"..................................................."<<endl
                                                    <<"..................................................."<<endl<<endl<<endl;
                                                    aca -> getElem(nom);
                                                    cout <<"Se borro el campo!"<<endl;
                                                    system("pause");
                                                    system("cls");
                                                    
                                         }
                                    }else{
                                          cout <<"Ese campo no existe en esta tabla!"<<endl;
                                          system("pause");      
                                          system("cls");
                                    }
                               }else{
                                   cout<<"Mmmm... al parecer no existe esa tabla..."<<endl;
                                   system("pause");
                                   system("cls");
                               }
                          }//fin opci 34
                          
                          if(opci == 35){
                               cout << "Vas a ordenar los campos por su nombre!, de que tabla?"<<endl;
                               cin >> nom;
                               anta = ta.buscar(nom);
                               if(anta != NULL){
                                    cout <<"Si existe la tabla"<<endl;
                                    tab = anta -> dato;
                                    ca = tab.lcam;
                                    aca = &tab.lcam;
                                    cout <<"Queres ordenar los campos de la tabla "<<nom<<" ?(escribe con minusculas)"<<endl;
                                    string p;
                                    cin >> p;
                                    if(p != "si"){
                                         cout <<"No dijste que si, vamonos..."<<endl;
                                         system("pause");
                                         system("cls");  
                                    }else{
                                          cout <<"..................................................."<<endl
                                               <<"..................................................."<<endl
                                               <<"..................................................."<<endl<<endl<<endl;
                                          aca->ordenar2();
                                          cout <<"Tus campos ya fueron ordenados..."<<endl;
                                          system("pause");
                                          system("cls");
                                    }
                               }else{
                                     cout << "Esa tabla no existe"<<endl;
                                     system("pause");
                                     system("cls");      
                               }
                          }//fin opcio 35
                          
                          if(opci == 36){
                               system("cls");
                          }//fin opcio 36
                          
                          if(opci == 37){
                               cout << "Vas a seleccionar el orden en que quieres que se impriman tus datos."<<endl<<endl;
                               cout <<"De que tabla deseas los campos??"<<endl;
                               cin >> nom;
                               anta = ta.buscar(nom);
                               if(anta != NULL){
                                    atab = &anta -> dato;
                                    tab = anta -> dato;
                                    aca = &atab -> lcam;
                                    if(aca->longitud() == 0){
                                         cout << "No tienes campos aun en la tabla" <<tab<<endl;
                                         system("pause");
                                         system("cls");
                                    }else{
                                         cout << "Tus campos son: "<<endl<<endl;
                                         int n = aca -> longitud();
                                         anca = aca -> getPri();
                                         for(int i=1; i<=n; i++){
                                              acam = &anca -> dato;
                                              cout <<i<<".- "<<acam -> nombre<<endl;
                                              anca = anca -> sig;
                                         }
                                         cout << "Elige el nombre en el orden que quieres que se impriman: "<<endl;
                                         anca = aca -> getPri();
                                         campos *vec;
                                         vec = new campos[n+1];
                                         for(int j = 1; j<=n;j++){
                                                 cout <<j<< ".- ";
                                                 cin >> nom;
                                                 //vec[j] = nom;
                                                 cam = anca -> dato;
                                                 cam.setname(nom);
                                                 cam.setord(j);
                                                 vec[j] = cam;
                                                 anca = anca -> sig;                               
                                         }
                                         aca -> eliminar();
                                         for(int f = 1; f<=n;f++){
                                             campos e;  
                                             e = vec[f];
                                             aca -> setFin(e);  
                                         }
                                         //aca -> ordenar();
                                         cout << "Ahora tus campos tienen este orden:"<<endl;
                                         aca->print();
                                         cout <<endl<<endl;
                                         
                                         system("pause");
                                         system("cls");      
                                    }
                               }else{
                                   cout <<"Lo siento, esta tabla no existe!"<<endl;
                                   system("pause");
                                   system("cls");
                               }
                               
                          }//fin opcio 37
                          
                     }//fin opc13
                     
                     if(opc == 14){
                            if(ta.longitud()==0){
                                cout <<"No tienes tablas"<<endl;
                                system("pause");
                                system("cls");
                            }else{
                                cout <<"Tus tablas son: "<<endl;
                                ta.print();
                                cout<<endl<<endl;
                                system("pause");  
                                system("cls");
                            }
                     }//fin opc 14
                     
                     if(opc == 15){
                            int opcion;
                            cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡    INDEX    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl<<endl<<endl
                                 << "                        {51}      Crear Index      {51}"<<endl<<endl
                                 << "                        {52}     Borrar Index      {52}"<<endl<<endl
                                 << "                        {53}  Reconstruir Index    {53}"<<endl<<endl<<endl<<endl
                                 << "                                Quieroo: ";
                            cin >> opcion;
                            system("cls");
                            
                            if(opcion == 51){
                            
                                      //cout <<"Aqui debe de ir el index"<<endl;
                                      cout << "_________________________________INDEX__________________________________"<<endl<<endl;
                                      cout << "De que tabla quieres hacer el index? si has creado antes, primero borra"<<endl
                                           << " el anterior,o habra un index que no quieres... osea, si es nuevo index, borralo!..."<<endl;
                                      cin >> nom;
                                      anta = ta.buscar(nom);
                                       if(anta != NULL){
                                               cout << "Se encontro tu tabla... ahora.. de que campo quieres hacer el index?"<<endl;
                                               cin >> nom;
                                               atab = &anta -> dato;
                                               aca = &atab -> lcam;
                                               anca = aca -> getPri();
                                               int k, c;
                                               c = 0;
                                               k = aca -> longitud();
                                               if(anca != NULL){
                                                        cout << "Se encontro tu campo!... a continuacion el index:"<<endl;
                                                        acam = &anca -> dato;
                                                        string nomCam;
                                                        nomCam = acam -> getname();
                                                        cout << nomCam<<"'s: "<<endl;
                                                        for(int i = 0; i < k; i++){
                                                                acam = &anca -> dato;
                                                                if(acam -> nombre == nom){
                                                                        i = k;
                                                                }else{
                                                                      anca = anca -> sig;
                                                                      c = c+1;      
                                                                }
                                                        }//fin for
                                                        int l;
                                                        ada = &atab -> ldat;
                                                        l = ada -> longitud();
                                                        anda = ada -> getPri();
                                                        for(int hl = 0; hl<l;hl++){
                                                                adat = &anda -> dato;
                                                                ava = &adat -> lval;
                                                                anva = ava -> getPri();
                                                                for(int jk = 0; jk < c; jk++){
                                                                        anva = anva -> sig;
                                                                }
                                                                aval = &anva -> dato;
                                                                string fgh;
                                                                fgh = aval -> getvalue();
                                                                in.setElem(fgh);
                                                                anda = anda-> sig;
                                                        }
                                                        in.inOrden1();
                                                        //ind.eliminar1();
                                                        system("pause");
                                                        system("cls");
                                    
                                               }else{
                                                     cout <<"Este campo no existe! checalos en imprimir campo!"<<endl;
                                                     system("pause");
                                                     system("cls");
                                               }
                                    }else{
                                          cout << "Esta tabla no existe!"<<endl;
                                          system("pause");
                                          system("cls");
                                    }
                            }//fin opcion 51
                            
                            
                            if(opcion == 52){
                                 cout << "Vas a eliminar el index. Quieres continuar?? Escribe en minusculas"<<endl;
                                 string p;
                                 cin >> p;
                                 if(p == "si"){
                                      in.eliminar1();
                                      cout <<endl<<endl<< "Tu index ah sido borrado"<<endl;
                                      system("pause");
                                      system("cls");
                                 }else{
                                       cout << "No dijiste que si, no se borrara nda..."<<endl;
                                       system("pause");
                                       system("cls");
                                 }
                            }// fin opcion 52
                            
                            if(opcion == 53){
                                 cout <<"Para reconstruir tu index debes borrar el index anterior.. quieres continuar?"<<endl;
                                 string p;
                                 cin >> p;
                                 if(p == "si"){
                                      in.eliminar1();
                                      cout << "Index borrado"<<endl;
                                      system("pause");
                                      system("cls");
                                      cout << "_________________________________INDEX__________________________________"<<endl<<endl;
                                      cout << "De que tabla quieres hacer el index? "<<endl;
                                      cin >> nom;
                                      anta = ta.buscar(nom);
                                       if(anta != NULL){
                                               cout << "Se encontro tu tabla... ahora.. de que campo quieres hacer el index?"<<endl;
                                               cin >> nom;
                                               atab = &anta -> dato;
                                               aca = &atab -> lcam;
                                               anca = aca -> getPri();
                                               int k, c;
                                               c = 0;
                                               k = aca -> longitud();
                                               if(anca != NULL){
                                                        cout << "Se encontro tu campo!... a continuacion el index:"<<endl;
                                                        acam = &anca -> dato;
                                                        string nomCam;
                                                        nomCam = acam -> getname();
                                                        cout << nomCam<<"'s: "<<endl;
                                                        for(int i = 0; i < k; i++){
                                                                acam = &anca -> dato;
                                                                if(acam -> nombre == nom){
                                                                        i = k;
                                                                }else{
                                                                      anca = anca -> sig;
                                                                      c = c+1;      
                                                                }
                                                        }//fin for
                                                        int l;
                                                        ada = &atab -> ldat;
                                                        l = ada -> longitud();
                                                        anda = ada -> getPri();
                                                        for(int hl = 0; hl<l;hl++){
                                                                adat = &anda -> dato;
                                                                ava = &adat -> lval;
                                                                anva = ava -> getPri();
                                                                for(int jk = 0; jk < c; jk++){
                                                                        anva = anva -> sig;
                                                                }
                                                                aval = &anva -> dato;
                                                                string fgh;
                                                                fgh = aval -> getvalue();
                                                                in.setElem(fgh);
                                                                anda = anda-> sig;
                                                        }
                                                        in.inOrden1();
                                                        //ind.eliminar1();
                                                        system("pause");
                                                        system("cls");
                                    
                                               }else{
                                                     cout <<"Este campo no existe! checalos en imprimir campo!"<<endl;
                                                     system("pause");
                                                     system("cls");
                                               }
                                    }else{
                                          cout << "Esta tabla no existe!"<<endl;
                                          system("pause");
                                          system("cls");
                                    }
                                 }else{
                                       cout << "No dijiste que si..."<<endl;
                                       system("pause");
                                       system("cls");
                                 }//fin opc 
                                 
                                 
                            }//fin opcion 53
                     }//fin opc15
                     
                     if(opc == 16){
                          cout <<"Vas a borrar una tabla, cual quieres borrar?"<<endl;
                          cin >> nom;
                          anta = ta.buscar(nom);
                          if(anta != NULL){
                               cout <<"Vas a borrar la tabla "<<nom<<", quieres continuar?(escribe con minusculas)"<<endl;
                               string p;
                               cin >> p;
                               if(p != "si"){
                                    cout <<"Decidiste no continuar... vamos de regreso..."<<endl;
                                    system("pause");
                                    system("cls");
                               }else{
                                     cout <<"Se borrara la tabla "<<nom<<endl;
                                     cout <<"..................................................."<<endl
                                          <<"..................................................."<<endl
                                          <<"..................................................."<<endl<<endl<<endl;
                                     atab = &anta -> dato;
                                     aca = &atab -> lcam;
                                     aca -> eliminar();
                                     ada = &atab -> ldat;
                                     ada -> eliminar();
                                     ta.getElem(nom);
                                     cout <<"Se ah borrado la tabla.... cual?... ah.. se borro..."<<endl<<endl<<endl;
                                     system("pause");
                                     system("cls");
                               }
                          }else{
                                cout <<"Sorry!, no existe esa tabla!"<<endl;
                                system("pause");
                                system("cls");
                          }
                     }//fin opc 16
                     
                     if(opc == 17){
                          cout <<"Vas a ordenar tus tablas por nombre, deseas continuar?(usa minusculas)"<<endl;
                          string p;
                          cin >> p;
                          if(p != "si"){
                               cout <<"No deseas continuar?... bueeeno..."<<endl;
                               system("pause");
                               system("cls");
                          }else{
                                cout <<"Se ordenaran tus tablas...."<<endl;
                                cout <<"..................................................."<<endl
                                     <<"..................................................."<<endl
                                     <<"..................................................."<<endl<<endl<<endl;
                              ta.ordenar();
                              cout <<"Tus tablas se ordenaron exitosamente!"<<endl;
                              system("pause");
                              system("cls");
                          }
                     }//fin opc 17
                     
                     if(opc == 18){
                          system("cls");
                     }//fin opc 18
        }//fin opc1
        
        if(op == 2){
              string nom;
              cout << "Vas a crear campos, pero... en cual tabla?"<<endl;
              cin >> nom;
              anta = ta.buscar(nom);
              if(anta != NULL){
                      cout <<"Si existe esta tabla!"<<endl;
                      atab = &anta -> dato;
                      cout <<"Tabla: "<<atab->nombre<<endl;
                      aca = &atab -> lcam;
                      cout << "Ahora veamos si tu campo ya existe..."<<endl;
                      cout <<"'''''''''''''''''''''''''''''''NOMBRE'''''''''''''''''''''''''''''"<<endl;
                      cout << "Nombre para tu campo: "<<endl;
                      cin >> nom;
                      anca = aca->buscar(nom);
                      if(anca != NULL){
                              cout<<"Este campo ya existe!, no puedes crear otro igual..."<<endl;
                              system("pause");
                              system("cls");
                      }else{
                            cout << "Este campo no existe, creemos lo demas..."<<endl<<endl<<endl;
                            acam = &anca -> dato;
                            cam.setname(nom);
                            cout <<"''''''''''''''''''''''''''''''DESCRIPCION''''''''''''''''''''''''''"<<endl;
                            cout <<"Descripcion de tu campo: "<<endl;
                            cin >> nom;
                            cam.setdesc(nom);
                            cout <<"'''''''''''''''''''''''''''''''''TIPO''''''''''''''''''''''''''''"<<endl;
                            cout <<"Tipo de campo: "<<endl;
                            cin >> nom;
                            cam.settype(nom);
                            cam.getord();
                            aca->setFin(cam);
                            cout <<"Felicidades, has creado un campo con éxito..."<<endl;
                            system("pause");
                            system("cls");
                      }//fin if1
              }else{
                    cout <<"Esa Tabla no existe, amigo!"<<endl;
                    system("pause");
                    system("cls");
              }//fin if1
        }//fin op 2
        
        if(op == 3){
             string nom; 
             int opcio; 
             cout <<endl<< "                                     Registros                                    "  <<endl
                  << "'*~-.-~*''*~-.-~*''*~-.-~*''*~-.-~*''*~-.-~*''*~-.-~*''*~-.-~*''*~-.-~*''*~-.-~* "  <<endl
                  <<endl
                  << "             | 20 |             Meter un Registro               | 20 | "  <<endl<<endl
                  << "             | 21 |             Sacar un Registro               | 21 | "  <<endl<<endl
                  << "             | 22 |            Buscar un Registro               | 22 | "  <<endl<<endl
                  << "             | 23 |           Modificar un Registro             | 23 | "  <<endl<<endl
                  << "             | 24 |            Imprimir  Registros              | 22 | "  <<endl<<endl                  
                  << endl
                  << "                       -  25  - Cargar una Tabla -  25  -                   "  <<endl<<endl
                  << "                     -  26  - Descargar una Tabla -  26  -                  "  <<endl<<endl<<endl
                  << "                         | 29 |     Regresar    | 29 | "  <<endl
                  <<endl;
             cin >> opcio;
             system("cls");
                           
                      if(opcio == 20){
                           cout << "Vas a meter un registro... en cual tabla será? " <<endl;
                           cin >> nom;
                           anta = ta.buscar(nom);
                           if(anta != NULL){
                                cout << "La tabla que buscas si existe!, ahora meteras el registro..."<<endl<<endl;
                                int n, j;
                                atab = &anta -> dato;
                                aca = &atab -> lcam;
                                n = aca -> longitud();
                                if(n == 0){
                                     cout << "No tienes campos! no puedes meter registros...."<<endl;
                                     system("pause");
                                     system("cls");
                                }else{
                                      anca = aca -> getPri();
                                      ada = &atab -> ldat;
                                      j = ada -> longitud();
                                      cout << "Tienes "<<j<<" registros en esta tabla"<<endl;
                                      int gd;
                                      gd = dat.getdata();
                                      ada -> setFin(gd);
                                      //ada -> setFin(j+1);
                                      anda = ada -> buscar(gd);
                                      //anda = ada -> buscar(j+1);
                                      adat = &anda -> dato;
                                      //k = (adat -> getdata())-1;
                                      //k = gd;
                                      //adat ->getdata();
                                      cout << "Numero de registro: " << gd <<endl;
                                      ava = &adat -> lval;
                                      anva = ava -> getPri();
                                      anca = aca -> getPri();
                                      for(int i = 0; i < n; i++){
                                              string nc;
                                              acam = &anca -> dato;
                                              nc = acam -> nombre;
                                              cout << nc <<": "<<endl;
                                              cin >> nom;
                                              val.setvalue(nom);
                                              val.setorden();
                                              ava -> setFin(val);
                                              cout << "Llevas el valor "<<i+1<<endl;
                                              anca = anca -> sig;
                                      }//fin for
                                }//fin if2
                                cout << "Has acabado de introducir registros, gracias"<<endl;
                                system("pause");
                                system("cls");
                           }else{
                                 cout <<"Lo siento, esa tabla no existe..."<<endl;
                                 system("pause");
                                 system("cls");
                           }//fin if1
                      }//fin opcio20
                      
                      if(opcio == 21){
                           cout << "Ahora sacaras un registro... en cual tabla esta?"<<endl;
                           cin >> nom;
                           anta = ta.buscar(nom);
                           if(anta != NULL){
                                int k;
                                atab = &anta -> dato;
                                ada = &atab -> ldat;
                                k = ada -> longitud();
                                cout << "Si esta esa tabla! Que numero de registro deseas quitar?"<<endl;
                                cout << "Tienes "<<k <<" registros"<<endl;   
                                int num;
                                cin >> num;
                                //num = num + 1;
                                anda = ada->buscar(num);
                                if(anda != NULL){
                                     cout <<"Se ah encontrado el registro que buscas!"<<endl;
                                     adat = &anda -> dato;
                                     ava = &adat -> lval;
                                     anva = ava -> getPri();
                                     aval = &anva -> dato;
                                     aca = &atab -> lcam;
                                     anca = aca -> getPri();
                                     acam = &anca -> dato;
                                     string nc, nv;
                                     nc = acam -> nombre;
                                     nv = aval -> valor;
                                     cout <<"Este registro es de: "<<nc<<": "<<nv<<"."<<endl;
                                     cout <<"Seguro que quieres borrarlo?(usa minusculas)"<<endl;
                                     string p;
                                     cin >> p;
                                     if(p != "si"){
                                          cout <<"No dijiste que si, entonces no se borrara..."<<endl;
                                          system("pause");
                                          system("cls");
                                     }else{
                                           cout <<"Entonces despídete de tu registro!"<<endl;
                                           cout <<".................................................."<<endl
                                                <<".................................................."<<endl
                                                <<".................................................."<<endl<<endl;
                                           ava -> eliminar();
                                           ada -> getElem(num);
                                           anda = ada -> buscar(num+1);
                                           for(int tf = num-1; tf < k ; tf++){
                                                 cout << "hola"<<endl;
                                                 dat = anda -> dato;///////////////////////////////////
                                                 cout << "hola"<<endl;
                                                 dat.setdata(tf);
                                                 cout << "hola"<<endl;
                                                 if(anda -> sig != NULL){
                                                         anda = anda -> sig;
                                                 }cout << "hola"<<endl;
                                           }
                                           cout <<"Se ah borrado ese registro!"<<endl;
                                           system("pause");
                                           system("cls");
                                     }
                                }else{
                                    cout <<"No hay tal registro. No se borro nada."<<endl;
                                    system("pause");
                                    system("cls");
                                }
                           }else{
                                 cout << "Lo siento, la tabla que dices no existe. "<<endl;
                                 system("pause");
                                 system("cls");
                           }
                      }//fin opcio 21
                      
                      if(opcio == 22){
                           int num;
                           cout <<"Vas a buscar un registro, en que tabla esta ese registro?"<<endl;
                           cin >>nom;
                           anta = ta.buscar(nom);
                           if(anta != NULL){
                                int k;
                                atab = &anta -> dato;
                                ada = &atab -> ldat;
                                k = ada -> longitud();
                                cout <<"Tabla encontrada... que numero de registro deseas?"<<endl;
                                cout << "Tienes "<<k <<" registros"<<endl;   
                                int num;
                                cin >> num;
                                num = num + 1;
                                anda = ada->buscar(num);
                                if(anda != NULL){
                                     cout <<"Se ah encontrado el registro que buscas!"<<endl;
                                     int f;
                                     string nc, nv;
                                     adat = &anda -> dato;
                                     ava = &adat -> lval;
                                     anva = ava -> getPri();
                                     aca = &atab -> lcam;
                                     anca = aca -> getPri();
                                     f = ava -> longitud();
                                     for(int i = 0; i < f; i++){
                                           aval = &anva -> dato;
                                           acam = &anca -> dato;
                                           nc = acam -> nombre;
                                           nv = aval -> valor;
                                           cout <<"Dato "<<i+1<<" es de: "<<nc<<": "<<nv<<"."<<endl;
                                           if(anva -> sig == NULL){}
                                           else{
                                                 anva = anva -> sig;
                                                 anca = anca -> sig;
                                           }
                                     }
                                     system("pause");
                                     system("cls");
                                }else{
                                      cout <<"Ese numero de registro no existe!"<<endl;
                                      system("pause");
                                      system("cls");
                                }
                                
                           }else{
                               cout <<"Esa tabla no existe!"<<endl;
                               system("pause");      
                               system("cls");
                           }
                      }//fin opcio 22
                      
                      if(opcio == 23){
                           int num;
                           cout << "Modificaras un registro!... En que tabla esta?"<<endl;
                           cin >> nom;
                           anta = ta.buscar(nom);
                           if(anta != NULL){
                                cout << "Tabla, encontrada... ahora a encontrar el registro... que numero es?"<<endl;
                                cin >> num;
                                num = num + 1;
                                atab = &anta -> dato;
                                ada = &atab -> ldat;
                                anda = ada -> buscar(num);
                                if(anda != NULL){
                                        string nc, nv;
                                     cout << "Numero de registro encontrado:"<<endl;
                                     adat = &anda -> dato;
                                     ava = &adat -> lval;
                                     anva = ava -> getPri();
                                     aca = &atab -> lcam;
                                     anca = aca -> getPri();
                                     int k = aca -> longitud();
                                     for(int i = 0; i < k; i++){
                                           acam = &anca -> dato;
                                           aval = &anva -> dato;
                                           nc = acam -> nombre;
                                           nv = aval -> valor;
                                           cout <<nc<<": "<<nv<<endl;
                                           if(anca -> sig == NULL){
                                                   i = k;        
                                           }
                                           else{
                                                anca = anca -> sig;
                                                anva = anva -> sig;
                                           }                                           
                                     }//fin for
                                     cout << "Seguro quieres modifiar ese registro?"<<endl;
                                     string p;
                                     cin >> p;
                                     if(p != "si"){
                                          cout << "No dijiste que si... no se modifica"<<endl;
                                          system("pause");
                                          system("cls");
                                     }else{
                                           cout << "Nuevos datos:"<<endl;
                                           ada = &atab -> ldat;
                                           anda = ada -> buscar(num);
                                           adat = &anda -> dato;
                                           ava = &adat -> lval;
                                           anva = ava -> getPri();
                                           aca = &atab -> lcam;
                                           anca = aca -> getPri();
                                           int h = aca -> longitud();
                                           for(int y=0;y<h;y++){
                                                   acam = &anca -> dato;
                                                   aval = &anva -> dato;
                                                   cout <<"Nuevo valor de "<<acam -> nombre<<": "<<endl;
                                                   cin >> nom;
                                                   aval -> setvalue(nom);///////////////////////////////////
                                                   if(anca -> sig != NULL){
                                                        anca = anca -> sig;
                                                        anva = anva -> sig;
                                                   }//fin if en for
                                           }//fin for
                                           cout << "Felicidades, has modificado ese registro!"<<endl;
                                     }//fin if p
                                     system("pause");
                                     system("cls");
                                }else{
                                    cout << "No tienes ese numero de dato!"<<endl;
                                    system("pause");
                                    system("cls");
                                }//fin anda if
                           }else{
                                 cout <<"Esta tabla no existe!, srry!"<<endl;
                                 system("pause");
                                 system("cls");
                           }//inf anta if
                      }//fin opcio 23
                      
                      if(opcio == 24){
                           cout << "Ahora imprimiras tooodos los registros... preparate..."<<endl<<endl;
                           cout << "uf.. casi se me va preguntar... em.. de que tabla?? "<<endl;
                           cin >> nom;
                           anta = ta.buscar(nom);
                           if(anta != NULL){
                                   cout << "ok... ahora si preparate..."<<endl<<endl<<endl;
                                   atab = &anta -> dato;
                                   aca = &atab -> lcam;
                                   ada = &atab -> ldat;
                                   anda = ada -> getPri();
                                   int ld, lc;
                                   ld = ada -> longitud();
                                   lc = aca -> longitud();
                                   for(int i = 0; i < ld; i++){
                                         adat = &anda -> dato;
                                         ava = &adat -> lval;
                                         anca = aca -> getPri();
                                         anva = ava -> getPri();
                                         for(int j = 0; j < lc; j++){
                                               string  nc, nv;
                                               acam = &anca -> dato;
                                               nc = acam -> nombre;
                                               aval = &anva -> dato;
                                               nv = aval -> valor;///////////////////////////////////////////
                                               cout << nc<<": "<<nv<<endl;
                                               if(anva -> sig != NULL){
                                                    anva = anva -> sig;
                                                    anca = anca -> sig;
                                               }
                                         }//fin for2
                                         cout <<"_________________________________________"<<endl<<endl;
                                         if(anda -> sig != NULL){
                                                anda = anda -> sig;
                                         }
                                   }//fin for 1
                                   system("pause");
                                   system("cls");
                           }else{
                                 cout << "Esa tabla no existe chavo! te salvaste..."<<endl;
                                 system("pause");
                                 system("cls");
                           }
                           
                      }//fin opcio24
        }//fin op 3
        
        
     }//fin while  
     system("pause");
     return 0;
}
