#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <sys/time.h>

using namespace std;

long obtenerTiempo(){
    struct timeval inicio;
    gettimeofday(&inicio, NULL);
    return inicio.tv_sec*1000000+inicio.tv_usec;
}

void obtener_lista(vector <int> &lista,string dir){
    string s;
    ifstream dataset;

    dataset.open(dir,ios::in);
    while(getline(dataset,s,' ')) {
        lista.push_back(stoi(s));
    }
    dataset.close();
}
/*
int main(){
    long inicio, final, tiempoEnMicrosegundos;
    double tiempoEnSegundos;
    inicio = obtenerTiempo(); // instancia inicial

    //Algoritmo

    final = obtenerTiempo(); // instancia final
    
    tiempoEnMicrosegundos = final - inicio;
    tiempoEnSegundos = tiempoEnMicrosegundos * pow(10, -6);

    // tiempo en microsegundos y segundos
    cout<<"Tiempo: "<<tiempoEnMicrosegundos<<" microsecond."<<endl;
    cout<<"        "<<tiempoEnSegundos<<" second."<<endl;
    return 0;
}*/