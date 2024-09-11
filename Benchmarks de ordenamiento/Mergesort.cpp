#include <iostream>
#include <vector>
#include <utility>

#include "/mnt/c/Users/ryzen 7/OneDrive - Universidad Técnica Federico Santa María/Codigos/AlgoCo/tarea 1/general.h"

using namespace std;

void merge(vector<int> &lista,int inicio, int mitad, int final){
    int i = 0,j = 0,k = inicio;
    int cant_izquierda,cant_derecha;

    cant_izquierda = mitad-inicio+1;
    cant_derecha = final-mitad;

    vector<int> izquierda(cant_izquierda);
    vector<int> derecha(cant_derecha);

    for(int h=0;h<cant_izquierda;h++) izquierda[h]=lista[inicio+h];
    for(int h=0;h<cant_derecha;h++) derecha[h]=lista[mitad+1+h];
    
    while(i<cant_izquierda && j<cant_derecha){
        if (izquierda[i] <=derecha[j]){
            lista[k] = izquierda[i];
            i++;
        } else {
            lista[k] = derecha[j];
            j++;
        }
        k++;
    }

    while(j<cant_derecha){
        lista[k] = derecha[j];
        j++;
        k++;
    }
    while(i<cant_derecha){
        lista[k] = izquierda[i];
        i++;
        k++;
    }
}

void mergesort (vector<int> &lista, int inicio, int final){
    
    if(inicio<final){
        int mitad = inicio + (final -inicio)/2;
        mergesort(lista,inicio,mitad);
        mergesort(lista,mitad+1,final);
        merge(lista,inicio,mitad,final);
    }
}

int main(){
    long inicio, final, tiempoEnMicrosegundos;
    double tiempoEnSegundos;

    string dir = "/mnt/c/Users/ryzen 7/OneDrive - Universidad Técnica Federico Santa María/Codigos/AlgoCo/tarea 1";
    
    vector <pair <string,string>> data(3);
    data[0].first = "/Dataset Desordenado";
    data[1].first = "/Dataset Mitad Ordenado";
    data[2].first = "/Dataset Ordenado";
    data[0].second = " 10000.txt";
    data[1].second = " 100000.txt";
    data[2].second = " 1000000.txt";

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            vector <int> lista;
            string p = dir+data[i].first+data[i].first+data[j].second;
            obtener_lista(lista,p);
            inicio = obtenerTiempo(); // instancia inicial

            mergesort(lista,0,lista.size()-1);

            final = obtenerTiempo(); // instancia final
            
            tiempoEnMicrosegundos = final - inicio;
            tiempoEnSegundos = tiempoEnMicrosegundos * pow(10, -6);

            // tiempo en microsegundos y segundos
            cout<<data[i].first+data[j].second<<endl;
            
            cout<<"Tiempo: "<<tiempoEnMicrosegundos<<" microsecond."<<endl;
            cout<<"        "<<tiempoEnSegundos<<" second."<<endl<<endl;
        }
    }
    return 0;
}