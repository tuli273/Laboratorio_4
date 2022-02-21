#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<limits>
#include <fstream>
#include<conio.h>
#include<stdlib.h>
#include "routers.h"

using namespace std;
routers r;
char ori;
vector<string> rut={""};
vector<int> cost= {90000000};
int j;

string leer(string nombre_archivo){
    string data;
    string texto;
    // Abre el archivo en modo lectura
    ifstream infile;
    string direccion="../practica_4/rutas/";
    direccion+=nombre_archivo;
    // Se pone de manera explicita la ruta relativa donde se encuentra el archivo
    infile.open(direccion);

    // Se comprueba si el archivo fue abierto exitosamente
    if (!infile.is_open())
    {
        cout << "Error abriendo el archivo" << endl;
        exit(1);
    }
    while(!infile.eof()){
        infile>>data;
        if (texto==""){
            texto= data;
        }
        else{
            texto= texto+ " " + data;
        }
        //cout<<texto<<"-"<<endl;
    }
    //cout << "Leyendo el archivo" << endl;
    //cout<<texto<<"#"<<endl;
    //    infile >> data;

    // Se escribe el dato en la pantalla
    //cout << data << endl;
    //cout << "longitud: " << data.length() << endl;

    //cout << "Impresion caracter a caracter" << endl;
    //    for (unsigned int i = 0; i < data.length(); i++) {
    //        cout << data.at(i) << endl;
    //    }

    // Se cierra el archivo abierto
    infile.close();
    //cout << texto << endl;
    return texto;
}
void Actualizar(){

}
void AgregarRouter(){
    /*esta funcion tiene como objetivo agragar todos los routers que el usuario desee agregar al
archivo donde se tienen guardadas las rutas*/
    string router;
    ofstream Guardar;
    Guardar.open("../practica_4/rutas/rutas.txt",ios::app);
    while (router!="-1") {
        cout<<"PORFAVOR INGRESELO DE LA FORMA "
              "<NUEVO><VIEJO>-<COSTO> (CON UN ENTER O SALTO DE LINEA) "<<endl<<"Y VISEVERSA "
              "<VIEJO><NUEVO>-<COSTO> (CON UN ENTER O SALTO DE LINEA) "
              ";EJEMPLO <AZ-9> Y <ZA-9>."<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*      INGRESE EL NUEVO ROUTER ASI         *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*                                          *"<<endl;
        cout<<"*      <ROUTER 1><ROUTER 2>-<COSTO>        *"<<endl;
        cout<<"*                                          *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*             O -1 PARA SALIR              *"<<endl;
        cout<<"********************************************"<<endl;
        cin>>router;
        if(router!="-1"){
            router+=".";
            Guardar<<router<<endl;
            system("CLS");
        }
    }

    Guardar.close();

}
void AgregarRouter2(string doc){
    /*esta funcion tiene como objetivo agragar todos los routers que el usuario desee agregar al
archivo donde se tienen guardadas las rutas*/
    string router,k;
    ofstream Guardar;
    k="../practica_4/rutas/";
    k+=doc;
    Guardar.open(k,ios::app);
    while (router!="-1") {
        cout<<"PORFAVOR INGRESELO DE LA FORMA "
              "<NUEVO><VIEJO>-<COSTO> (CON UN ENTER O SALTO DE LINEA) "<<endl<<"Y VISEVERSA "
              "<VIEJO><NUEVO>-<COSTO> (CON UN ENTER O SALTO DE LINEA) "
              ";EJEMPLO <AZ-9> Y <ZA-9>."<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*      INGRESE EL NUEVO ROUTER ASI         *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*                                          *"<<endl;
        cout<<"*      <ROUTER 1><ROUTER 2>-<COSTO>        *"<<endl;
        cout<<"*                                          *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*             O -1 PARA SALIR              *"<<endl;
        cout<<"********************************************"<<endl;
        cin>>router;
        if(router!="-1"){
            router+=".";
            Guardar<<router<<endl;
            system("CLS");
        }
    }

    Guardar.close();

}
void BorrarRouter(){
    /*esta función tiene el propósito de eliminar el Reuter elegido por el usuario,
se hace siguiendo estos pasos
1) extraer los enlaces y ubicarlos en un mapa
2) buscar con ayuda de un iterador si el Reuter que dio el usuario está en el mapa
en la parte de key en la cual están los nombres de los Reuters conectados y si se encuentra que
esta el Reuter que dio el usuario se elimina dicho componente del mapa
3)se agrega a un archivo temporal la información editada*/
    int x=0,pos,posinicio=0,posaux1=0,posaux2;
    string temp1,temp2,txtau,neu,temporal,txtguia;char router,ru=' ';
    ofstream Guardar;
    ofstream temp_txt;
    Guardar.open("../practica_4/rutas/rutas.txt",ios::app);
    temp_txt.open("../practica_4/rutas/temporal.txt",ios::app);
    map<string,short> enlaces;
    map<string,short>::iterator it;
    string sacado=leer("rutas.txt");
    pos =sacado.find_first_of('.');
    for(unsigned int i=0;i<sacado.length();i++){
        if(i<pos){
            txtguia+=sacado.at(i);
        }

    }
    txtguia+=".";
    temp_txt<<txtguia<<endl;
    while(true){
        for(int i=posinicio;i < pos;i++){
            if(posinicio==0){
                for(unsigned int i=0;i<sacado.length();i++){
                    if(i>pos){
                        temp2+=sacado.at(i);
                    }

                }sacado=temp2;
                temp2="";
                pos=0;
                break;
            }
            else if(sacado.at(i)!=' '){
                temp1+=sacado.at(i);
            }
        }
        if (temp1!=""){
            posaux1=temp1.find_first_of("-");
            for(unsigned int i=0;i<temp1.length();i++){
                if(i>posaux1){
                    temp2+=temp1.at(i);
                }else if(temp1.at(i)!='-'){
                    txtau+=temp1.at(i);
                }
            }
            double num_double = std::stod(temp2);
            enlaces[txtau]=num_double;
        }

        posinicio=pos+1;

        for(unsigned int i=0;i<sacado.length();i++){
            if(i>pos){
                neu+=sacado.at(i);
            }

        }
        posaux2=neu.find_first_of('.');
        pos +=posaux2+1;
        neu="";
        temp2="";
        temp1="";
        txtau="";
        if(posaux2==-1){
            break;
        }
    }
    while (router!='1') {
        cout<<"********************************************"<<endl;
        cout<<"*      INGRESE EL ROUTER A ELIMINAR        *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*                                          *"<<endl;
        cout<<"*                <ROUTER>                  *"<<endl;
        cout<<"*                                          *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*             O 1 PARA SALIR               *"<<endl;
        cout<<"********************************************"<<endl;
        cin>>router;
        if(router!='1'){
            if(ru!=router){
                for(it=enlaces.begin();it!=enlaces.end();it++){
                    if(it->first[0]==router || it->first[1]==router){}
                    else{temporal+=it->first+"-" + to_string(it->second)+".";
                        temp_txt<<temporal<<endl;
                        temporal="";
                    }

                }

            }
            ru=router;
            temp_txt.close();
            Guardar.close();
            remove("../practica_4/rutas/rutas.txt");
            rename("../practica_4/rutas/temporal.txt","../practica_4/rutas/rutas.txt");
            cout<<"EL ROUTER "<<router<<" fue eliminado"<<endl;
            _sleep(3500);
            system("CLS");
        }
    }
}
void BorrarRouter2(string doc){
    /*esta función tiene el propósito de eliminar el Reuter elegido por el usuario,
se hace siguiendo estos pasos
1) extraer los enlaces y ubicarlos en un mapa
2) buscar con ayuda de un iterador si el Reuter que dio el usuario está en el mapa
en la parte de key en la cual están los nombres de los Reuters conectados y si se encuentra que
esta el Reuter que dio el usuario se elimina dicho componente del mapa
3)se agrega a un archivo temporal la información editada*/
    int x=0,pos,posinicio=0,posaux1=0,posaux2;
    string temp1,temp2,txtau,neu,temporal,txtguia,k;char router,ru=' ';
    ofstream Guardar;
    ofstream temp_txt;
    k="../practica_4/rutas/";
    k+=doc;
    Guardar.open(k,ios::app);
    temp_txt.open("../practica_4/rutas/temporal.txt",ios::app);
    map<string,short> enlaces;
    map<string,short>::iterator it;
    string sacado=leer(doc);
    pos =sacado.find_first_of('.');
    for(unsigned int i=0;i<sacado.length();i++){
        if(i<pos){
            txtguia+=sacado.at(i);
        }

    }
    txtguia+=".";
    temp_txt<<txtguia<<endl;
    while(true){
        for(int i=posinicio;i < pos;i++){
            if(posinicio==0){
                for(unsigned int i=0;i<sacado.length();i++){
                    if(i>pos){
                        temp2+=sacado.at(i);
                    }

                }sacado=temp2;
                temp2="";
                pos=0;
                break;
            }
            else if(sacado.at(i)!=' '){
                temp1+=sacado.at(i);
            }
        }
        if (temp1!=""){
            posaux1=temp1.find_first_of(",");
            for(unsigned int i=0;i<temp1.length();i++){
                if(i>posaux1){
                    temp2+=temp1.at(i);
                }else if(temp1.at(i)!='-'){
                    txtau+=temp1.at(i);
                }
            }
            double num_double = std::stod(temp2);
            enlaces[txtau]=num_double;
        }

        posinicio=pos+1;

        for(unsigned int i=0;i<sacado.length();i++){
            if(i>pos){
                neu+=sacado.at(i);
            }

        }
        posaux2=neu.find_first_of('.');
        pos +=posaux2+1;
        neu="";
        temp2="";
        temp1="";
        txtau="";
        if(posaux2==-1){
            break;
        }
    }
    while (router!='1') {
        cout<<"********************************************"<<endl;
        cout<<"*      INGRESE EL ROUTER A ELIMINAR        *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*                                          *"<<endl;
        cout<<"*                <ROUTER>                  *"<<endl;
        cout<<"*                                          *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*             O 1 PARA SALIR               *"<<endl;
        cout<<"********************************************"<<endl;
        cin>>router;
        if(router!='1'){
            if(ru!=router){
                for(it=enlaces.begin();it!=enlaces.end();it++){
                    if(it->first[0]==router || it->first[1]==router){}
                    else{temporal+=it->first+"-" + to_string(it->second)+".";
                        temp_txt<<temporal<<endl;
                        temporal="";
                    }

                }

            }
            ru=router;
            temp_txt.close();
            Guardar.close();
            remove("../practica_4/rutas/topologia.txt");
            rename("../practica_4/rutas/temporal.txt","../practica_4/rutas/topologia.txt");
            cout<<"EL ROUTER "<<router<<" fue eliminado"<<endl;
            _sleep(3500);
            system("CLS");
        }
    }
}




//void busquedaRutas(const map<string, short>& rts,const string inicio,const char fin,short costotl,routers _r){

//    short lTamInicio=inicio.size();
//    for(auto enl : rts){
//        if(inicio[lTamInicio-1]==enl.first[0] && inicio[lTamInicio-2]!= enl.first[1]){
//            cout<<inicio<<"-"<<enl.first<<"["<<enl.second<<"]"<<endl;
//            size_t found = inicio.find(enl.first);
//            if(found != std::string::npos){
//                cout<<"cadena repetida"<<endl;
//                return;
//            }
//            if(enl.first.back()==fin){
//                if(costotl+enl.second< _r.getCostoMinimo()){
//                    _r.setRuta(inicio+enl.first,costotl+enl.second );
//                }
//                return;
//            }
//            busquedaRutas(rts,string(inicio+enl.first),fin,costotl+enl.second,_r);
//        }
//    }

//}
void fu(char origen,char destino,map<string,short> enlaces,string ruta,short costo,routers r){
    map<string,short>::iterator it1;
    string rutaa;
    for (it1=enlaces.begin();it1!=enlaces.end();it1++){
            if(it1->first[0]==origen){
                if(ruta.find(it1->first[1])==-1){
                    ruta+=it1->first;
                    costo+=it1->second;
                    if(it1->first[1]==destino){
                        if(cost[0]>costo){
                            rut[0]="";
                            rut[0]=ruta;
                            cost[0]=costo;
                            ruta="";
                            costo=0;

                            origen=ori;
                            return;
                        }
                    }else{
                        if(ruta[ruta.size()-1]==origen){

                        }else{origen=it1->first[1];
                            fu(origen, destino, enlaces,ruta,costo,r);
                            origen=ruta[ruta.size()-2];
                            for(unsigned int i=0;i<ruta.size();i++){
                                if(i<ruta.size()-2){
                                    rutaa+=ruta.at(i);
                                }

                            }
                            costo-=it1->second;
                            ruta=rutaa;
                        }


                    }
                }

            }

    }
}
void BusquedaRutas(){
    char origen,destino;
    string c,ruta;short costo;
    cout<<"********************************************"<<endl;
    cout<<"*      INGRESE DE LA DIGUIENTE FORMA       *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"*          <ROUTER 1><ROUTER 1>            *"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*             O -1 PARA SALIR               *"<<endl;
    cout<<"********************************************"<<endl;
    cin>>c;
    if (c!="-1"){
        origen=c[0];destino=c[1];ori=c[0];
        int x=0,pos,posinicio=0,posaux1=0,posaux2;
        string temp1,temp2,txtau,neu;
        map<string,short> enlaces;
        string sacado=leer("rutas.txt");
        pos =sacado.find_first_of('.');
        while(true){
            for(int i=posinicio;i < pos;i++){
                if(posinicio==0){
                    for(unsigned int i=0;i<sacado.length();i++){
                        if(i>pos){
                            temp2+=sacado.at(i);
                        }

                    }sacado=temp2;
                    temp2="";
                    pos=0;
                    break;
                }
                else if(sacado.at(i)!=' '){
                    temp1+=sacado.at(i);
                }
            }
            if (temp1!=""){
                posaux1=temp1.find_first_of("-");
                for(unsigned int i=0;i<temp1.length();i++){
                    if(i>posaux1){
                        temp2+=temp1.at(i);
                    }else if(temp1.at(i)!='-'){
                        txtau+=temp1.at(i);
                    }
                }
                double num_double = std::stod(temp2);
                enlaces[txtau]=num_double;
            }

            posinicio=pos+1;

            for(unsigned int i=0;i<sacado.length();i++){
                if(i>pos){
                    neu+=sacado.at(i);
                }

            }
            posaux2=neu.find_first_of('.');
            pos +=posaux2+1;
            neu="";
            temp2="";
            temp1="";
            txtau="";
            if(posaux2==-1){
                break;
            }

        }
        map<string,short>::iterator it1;

       fu(origen, destino, enlaces,ruta,costo,r);
        if(j==0){
            cout<<"el costo minimo es: "<<cost[0]<<endl;
            cost[0]=100000;
        }else if(j==1){
            cout<<"la ruta minima es: "<<rut[0]<<endl;
            rut[0]="";
        }
       }
}
void BusquedaRutas2(string doc){
    char origen,destino;
    string c,ruta;short costo;
    cout<<"********************************************"<<endl;
    cout<<"*      INGRESE DE LA DIGUIENTE FORMA       *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"*          <ROUTER 1><ROUTER 1>            *"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*             O -1 PARA SALIR               *"<<endl;
    cout<<"********************************************"<<endl;
    cin>>c;
    if (c!="-1"){
        origen=c[0];destino=c[1];ori=c[0];
        int x=0,pos,posinicio=0,posaux1=0,posaux2;
        string temp1,temp2,txtau,neu;
        map<string,short> enlaces;
        string sacado=leer(doc);
        pos =sacado.find_first_of('.');
        while(true){
            for(int i=posinicio;i < pos;i++){
                if(posinicio==0){
                    for(unsigned int i=0;i<sacado.length();i++){
                        if(i>pos){
                            temp2+=sacado.at(i);
                        }

                    }sacado=temp2;
                    temp2="";
                    pos=0;
                    break;
                }
                else if(sacado.at(i)!=' '){
                    temp1+=sacado.at(i);
                }
            }
            if (temp1!=""){
                posaux1=temp1.find_first_of("-");
                for(unsigned int i=0;i<temp1.length();i++){
                    if(i>posaux1){
                        temp2+=temp1.at(i);
                    }else if(temp1.at(i)!=','){
                        txtau+=temp1.at(i);
                    }
                }
                double num_double = std::stod(temp2);
                enlaces[txtau]=num_double;
            }

            posinicio=pos+1;

            for(unsigned int i=0;i<sacado.length();i++){
                if(i>pos){
                    neu+=sacado.at(i);
                }

            }
            posaux2=neu.find_first_of('.');
            pos +=posaux2+1;
            neu="";
            temp2="";
            temp1="";
            txtau="";
            if(posaux2==-1){
                break;
            }

        }
        map<string,short>::iterator it1;

       fu(origen, destino, enlaces,ruta,costo,r);
        if(j==0){
            cout<<"el costo minimo es: "<<cost[0]<<endl;
        }else if(j==1){
            cout<<"la ruta minima es: "<<rut[0]<<endl;
        }
       }
}
bool Menu(){
    int opcion;
    cout<<"********************************************"<<endl;
    cout<<"*             QUE QUIERE HECER             *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"*   1.AGREGAR ROUTER                       *"<<endl;
    cout<<"*   2.BORRAR ROUTER                        *"<<endl;
    cout<<"*   3.COSTO ENVIO <R1-R2>                  *"<<endl;
    cout<<"*   4.RUTA ENVIO <Ri-R2>                   *"<<endl;
    cout<<"*   5.SALIR                                *"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"********************************************"<<endl;
    cin>>opcion;
    switch (opcion) {
    case 1:
        system("CLS");
        AgregarRouter();
        break;
    case 2:
        system("CLS");
        BorrarRouter();
        break;
    case 3:
        system("CLS");
        j=0;
        BusquedaRutas();
        _sleep(2000);
        return true;
    case 4:
        system("CLS");
        j=1;
        BusquedaRutas();
        _sleep(2000);
        return true;
    case 5:
        cout<<"********************************************"<<endl;
        cout<<"*           QUE TENGA BUEN DIA             *"<<endl;
        cout<<"********************************************"<<endl;
        return false;
    default: // siempre que no escoga ninguna opcion
        cout<<"********************************************"<<endl;
        cout<<"*             !NO ESCOGIO NADA¡            *"<<endl;
        cout<<"********************************************"<<endl;
        break;
    }

}
bool Menu2(){
    int opcion;
    string doc;
    cout<<"INGRESE NOMBRE DEL DOCUMENTO TERMINADO EN .TXT"<<endl;
    cin>>doc;
    system("CLS");
    cout<<"********************************************"<<endl;
    cout<<"*             QUE QUIERE HECER             *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"*   1.AGREGAR ROUTER                       *"<<endl;
    cout<<"*   2.BORRAR ROUTER                        *"<<endl;
    cout<<"*   3.COSTO ENVIO <R1-R2>                  *"<<endl;
    cout<<"*   4.RUTA ENVIO <Ri-R2>                   *"<<endl;
    cout<<"*   5.SALIR                                *"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"********************************************"<<endl;
    cin>>opcion;
    switch (opcion) {
    case 1:
        system("CLS");
        AgregarRouter2(doc);
        break;
    case 2:
        system("CLS");
        cout<<"INGRESE NOMBRE DEL DOCUMENTO ";
        cin>>doc;
        BorrarRouter2(doc);
        break;
    case 3:
        system("CLS");
        j=0;

        BusquedaRutas2(doc);
        _sleep(2000);
        return true;
    case 4:
        system("CLS");
        j=1;

        BusquedaRutas2(doc);
        _sleep(2000);
        return true;
    case 5:
        cout<<"********************************************"<<endl;
        cout<<"*           QUE TENGA BUEN DIA             *"<<endl;
        cout<<"********************************************"<<endl;
        return false;
    default:
        cout<<"********************************************"<<endl;
        cout<<"*             !NO ESCOGIO NADA¡            *"<<endl;
        cout<<"********************************************"<<endl;
        break;
    }

}
bool Menu_(){
    int opcion;
    bool x;
    cout<<"********************************************"<<endl;
    cout<<"*             QUE QUIERE HECER             *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"*   1.TRABAJAR CON RUTAS.TXT               *"<<endl;
    cout<<"*   2.CARGAR DOCUMENTO                     *"<<endl;
    cout<<"*   3.SALIR                                *"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"********************************************"<<endl;
    cin>>opcion;
    switch (opcion) {
    case 1:
        system("CLS");
        x=Menu();
        return x;
    case 2:
        system("CLS");
        x=Menu2();
        return x;
    case 3:
        cout<<"********************************************"<<endl;
        cout<<"*           QUE TENGA BUEN DIA             *"<<endl;
        cout<<"********************************************"<<endl;
        return false;
    default:
        cout<<"********************************************"<<endl;
        cout<<"*             !NO ESCOGIO NADA¡            *"<<endl;
        cout<<"********************************************"<<endl;
        break;
    }
}
