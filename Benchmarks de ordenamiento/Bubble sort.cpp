#include <iostream>
#include <vector>
#include <utility>

#include </mnt/c/Users/ryzen 7/OneDrive - Universidad Técnica Federico Santa María/Codigos/AlgoCo/tarea 1/general.h>

using namespace std;

void swap(int &a,int &b){
    int aux = a;
    a = b;
    b = aux;
}

void bubblesort(vector <int> &lista){
    for(unsigned int i=0;i<lista.size()-1;i++){
        for(unsigned int j=0;j<lista.size()-i-1;j++){
            if (lista[j]>lista[j+1]) swap(lista[j],lista[j+1]);
        }
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
        for(int j=0;j<2;j++){
            vector <int> lista;
            string p = dir+data[i].first+data[i].first+data[j].second;
            obtener_lista(lista,p);
            inicio = obtenerTiempo(); // instancia inicial
            
            bubblesort(lista);

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

