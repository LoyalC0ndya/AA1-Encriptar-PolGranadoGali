#include <iostream>
#include <fstream>
#include <string>

#include "function_encript.h"
#include "historialConversaci�n.h"


void main() {

	std::ifstream file;
	file.open("encryptar.txt");
    if (file.is_open()) {
        std::cout << "Archivo encontrado" << std::endl;
        
    }
    else {
        std::cout << "Creando archivo" << std::endl;
        
    }


}