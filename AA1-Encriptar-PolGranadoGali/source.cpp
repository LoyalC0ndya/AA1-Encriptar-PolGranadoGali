#include <iostream>
#include <fstream>
#include <string>

#include "function_encript.h"
#include "enviarMensaje.h"


void main() {
    std::ifstream file("historial_msg.txt");
    file.open("historial_msg.txt");

    if (file.is_open()){

        std::cout << "Archivo encontrado";
    }
    else {

        std::cout << "Creando archivo" << std::endl;
        enviarMensajes();
    }
}