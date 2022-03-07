// Ejercicio_Planificacion_HDD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

std::vector<int> ordenLlegada;
std::vector<int> colaPlanificacion;

class Disk {
public:
    int numeroPistas;
};

//simulador disco

Disk DiskSimulation() {
    //crear nuevo disco
    Disk disco;
    int pistas;
    cout << "ingrese el numero de pistas del disco: " << endl;
    cin >> pistas;
    disco.numeroPistas = pistas;

    return disco;
}

//simulador que llena la cola de orden de llegada

void FillQueue(int p) {
    
  //crear array aleatorio

    int* arr = new int[p];

    for (int i = 0; i < p; i++) {
        arr[i] = (rand() % 10);
    }


    cout << "****************" << endl;

    //fill vector with array values

    for (int j = 0; j < p; j++) {
        ordenLlegada.push_back(arr[j]);
    }

    for (int k : ordenLlegada) {
        cout << k << endl;
    }
    

    auto rng = default_random_engine{};
    shuffle(begin(ordenLlegada), end(ordenLlegada), rng);

    cout << "****************" << endl;

    for (int m : ordenLlegada) {
        cout << m << endl;
    }

}

//metodo para planificar la cola

void QueueScheduler(vector<int> colaPlanificacion) {

}

int main()
{
    Disk disk = DiskSimulation();

    int pistas = disk.numeroPistas;

    FillQueue(pistas);
  
}

