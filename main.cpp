#include "Lanchas.h"
#include <iostream>
// Respuesta
std::string respuesta;
int velocidad;
std::string nombreGanador;

// TIRAR DADO TEXTO PULSAR
void input(){
    std::cout << "\033[1;95mPresione \"ENTER\" para lanzar el dado \033[0m";
    std::cin.ignore();
}

//CREAMOS 1 DADO ALEATORIO
int tirardado(){
    int ran;
    ran = rand() % 6 + 1;
    input();
    std::cout << "\n\033[1;33mOBTUVO " << ran << "\033[0m" << std::endl;
    return ran;
}

// HACEMOS QUE EL NITRO NOS DE 0 O 1 Y LO SUMAMOS O DIVIDIMOS A LA VELOCIDAD TOTAL

int nit(Lanchas& lancha) {
    int nit = rand() % 2;
    int Vel = lancha.getVelocidad();
    Vel = lancha.nitro(nit, Vel);
    lancha.setVelocidad(Vel);
    if (nit == 0) {
        std::cout << "\033[1;31mEl nitro fallo,\033[0m ";
    }
    else {
        std::cout << "\033[1;32mEl nitro ha funciona a la perfeccion,\033[0m ";
    }
    return lancha.getVelocidad();
}
int dis(Lanchas& lancha) {
    int dis = lancha.getDistancia();
    int Vel = lancha.getVelocidad();
    dis = dis + Vel * 100;
    lancha.setDistancia(dis);
    return dis;
}

// CREAMOS LOS TURNOS Y AÑADIMOS EL NITRO
void turnos(Lanchas& lancha) {
    int dado1 = tirardado();
    lancha.sumaVelocidad(dado1);
    std::cout << "La Lancha " << lancha.getName() << " va a \033[1;92m" << lancha.getVelocidad() << "Km/h\033[0m" << std::endl;
    if (lancha.getNitro() == 1) {
    std::cout << lancha.getName() << " quieres usar Nitro? (si / no) " << std::endl;
    std::cin >> respuesta;
    if (respuesta == "si" || respuesta == "SI" || respuesta == "Si") {
        lancha.setNitro(0);
        velocidad = nit(lancha);
    std::cout << "la velocidad de " << lancha.getName() << " es de \033[1;92m" << velocidad << "Km/h\033[0m" << std::endl;
    }
    }
    std::cout << "La distancia recorrida es de \033[1;94m" << dis(lancha) << "m\033[0m" << std::endl;
 }

std::string ganador(Lanchas& lancha1, Lanchas& lancha2) {
    int distancia1 = lancha1.getDistancia();
    int distancia2 = lancha2.getDistancia();
    if (distancia1 > distancia2) {
        return lancha1.getName();
    }
    else if (distancia2 > distancia1) {
        return lancha2.getName();
    }
    else {
        return "Empate";
    }
}

int main() {
    srand(time(0));
// CREAMOS 2 LANCHAS 
    Lanchas Lancha1("Javi", 0, 0, 1), Lancha2("Ramon", 0, 0, 1);
    std::cout << "La carrera entre " << Lancha1.getName() << " y " << Lancha2.getName() << " va ha comenzar" << std::endl;
    std::cout << "El jugador " << Lancha1.getName() << " tira primero y despues el jugador " << Lancha2.getName() << " tirara" << std::endl;

// CREAMOS UN BUCLE DE 5 TURNOS
    for (size_t i = 0; i < 5; i++)
    {
        turnos(Lancha1);
        turnos(Lancha2);
    }

 // DESPUES DE LOS 5 TURNOS SE DETERMINA QUIEN GANA
    nombreGanador = ganador(Lancha1, Lancha2);
    if (nombreGanador == "Empate") {
        std::cout << "La carrera ha terminado en empate." << std::endl;
    }
    else {
        std::cout << "El ganador de la carrera es:\033[1;32m" << nombreGanador << "!\033[0m\n" << std::endl;
    }
}