#include <iostream>
#include <fstream>
#include <string>

#include "function_encript.h"
#include "historialConversación.h"


using namespace std;

void main() {

	short respuestaMenu;


	cout << "Bienvenido elige una de las opciones:" << endl;
	cout << "1--> Enviar mensajes" << endl;
	cout << "2--> Recuperar conversacion" << endl;
	cout << "Respuesta:";

	cin >> respuestaMenu;

	switch (respuestaMenu)
	{

	case 1:
		enviarMensajes();
		break;


	default:
		break;
	}
}