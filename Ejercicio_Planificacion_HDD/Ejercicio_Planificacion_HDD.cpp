// Ejercicio_Planificacion_HDD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Disco.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <windows.h>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

std::vector<int> ordenLlegada;
std::vector<int> colaPlanificacion;

Disco DiskSimulation() {
    //crear nuevo disco
    Disco disco;
    int numeroPistas;
    cout << "ingrese el numero de pistas del disco: " << endl;
    cin >> numeroPistas;
    disco.pistas = numeroPistas;

    return disco;
}

//simulador que llena la cola de orden de llegada

void FillQueue(int p) {
    
  //crear array aleatorio

    int* arr = new int[p];

    for (int i = 0; i < p; i++) {
        arr[i] = (rand() % 10 + 1);
    }




    //fill vector with array values

    for (int j = 0; j < p; j++) {
        ordenLlegada.push_back(arr[j]);
    }

    //for (int k : ordenLlegada) {
    //    Sleep(1400);
    //    cout << k << endl;
    //}
    //

    auto rng = default_random_engine{};
    shuffle(begin(ordenLlegada), end(ordenLlegada), rng);

    for (int m : ordenLlegada) {
        colaPlanificacion.push_back(m);
    }

    cout << "******LLENANDO COLA ORDEN DE LLEGADA CON VALORES ALEATORIOS******" << endl;

    for (int n : ordenLlegada) {
        Sleep(1400);
        cout << n << endl;
    }

    ordenLlegada.clear();

}

//metodo para planificar la cola FIFO

void QueueSchedulerFIFO() {
    

    cout << "*****orden de planificacion FIFO*****" << endl;


    for (int i: colaPlanificacion) {
        Sleep(1400);
        cout << i << endl;
    }
    
    colaPlanificacion.clear();
}

//metodo para planificar la cola FIFO

void QueueSchedulerSSTF() {

}

//metodo para planificar la cola FIFO

void QueueSchedulerCSCAN() {

}

int main()
{
    auto finish = system_clock::now() + 1min;

    Disco disco = DiskSimulation();

    int pistas = disco.pistas;

    do{

        FillQueue(pistas);

        QueueSchedulerFIFO();

    } while (system_clock::now() < finish);


}

