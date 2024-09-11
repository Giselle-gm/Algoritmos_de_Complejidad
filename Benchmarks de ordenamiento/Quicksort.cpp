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

int particion(vector<int>&lista,int inicio, int fin){
    int pivote = lista[inicio];
    int i = inicio + 1;
    for(int j = i; j <= fin; j++){
        if(lista[j] < pivote){
            swap(lista[i],lista[j]);
            i++;
        }
    }
    swap(lista[inicio],lista[i-1]);
    return i-1;
}

void quicksort(vector<int>&lista, int inicio, int fin){
    if(inicio < fin){
        int pivote = particion(lista,inicio,fin);
        quicksort(lista,inicio,pivote-1);
        quicksort(lista,pivote+1,fin);
    }
}

int main(){
    long inicio, final, tiempoEnMicrosegundos;
    double tiempoEnSegundos;

    string dir = "/mnt/c/Users/ryzen 7/OneDrive - Universidad Técnica Federico Santa María/Codigos/AlgoCo/tarea 1";
    
    vector <pair <string,string>> data(3);
    data[2].first = "/Dataset Desordenado";
    data[0].first = "/Dataset Mitad Ordenado";
    data[1].first = "/Dataset Ordenado";
    data[0].second = " 10000.txt";
    data[1].second = " 100000.txt";
    data[2].second = " 1000000.txt";

    for(int i=1;i<3;i++){
        for(int j=0;j<3;j++){
            vector <int> lista;
            string p = dir+data[i].first+data[i].first+data[j].second;
            obtener_lista(lista,p);
            inicio = obtenerTiempo(); // instancia inicial

            quicksort(lista,0,lista.size()-1);

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