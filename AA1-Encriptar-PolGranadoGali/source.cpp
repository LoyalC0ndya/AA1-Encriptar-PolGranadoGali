
#include "enviarMensaje.h"
#include "recuperarConversación.h"


void main() {
    std::vector <std::string> mensajes;
    std::ifstream file("historial_msg.txt");
    file.open("historial_msg.txt");
    char respuestaEncontrado;

    if (file.is_open()){ //Documentar verificación de si esta abierto

        std::cout << "Archivo encontrado" << std::endl;
        std::cout << "Quiere recuperar los mensajes? Y/N" << std::endl;
        std::cin >> respuestaEncontrado;
        file.close();
        if (respuestaEncontrado == 'Y' or respuestaEncontrado == 'y')
        {
            std::cout << "Recuperando" << std::endl;
            recuperarConvers(mensajes);
            enviarMensajes(mensajes, true);
        }
        else
        {
            enviarMensajes(mensajes);
        }
    }
    else {

        std::cout << "Creando archivo" << std::endl;
        enviarMensajes(mensajes);
    }
}