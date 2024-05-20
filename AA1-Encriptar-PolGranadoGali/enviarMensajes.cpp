#include "enviarMensaje.h"


void enviarMensajes(std::vector<std::string>& mensajes, bool haRecuperado) {
	std::string respuestaEnviarMensaje;
	bool bucle = true;

	std::cout << "Que mensaje quieres escribir?" << std::endl;
	std::cout << "(Escribe 'exit' para  salir)" << std::endl;
	
	//Arir el archivo
	std::ofstream file;
	
	file.open("historial_msg.txt", std::ios::trunc); //De esta manera abriremos el archivo y sobreescribimos
	
	int cheksumSalida = 0;

	std::vector<std::string> mensajesEncriptados;
	{
		for (short i = 0; i < mensajes.size(); i++)
		{
			std::string palabraEncriptada;
			//Creando una variable
			char letrasPalabras;

			for (short j = 0; j < mensajes[i].length(); j++)
			{
				letrasPalabras = mensajes[i].at(j);
				letrasPalabras = letrasPalabras + 1052; // Forma de encriptar sumando 1052 
				cheksumSalida = cheksumSalida + (int)letrasPalabras;//Añadir el valor a al letra encriptada al cheksum, si ponemos el (int) convertimos en una variable int rapidamente
				palabraEncriptada += letrasPalabras;
			}
			mensajesEncriptados.push_back(palabraEncriptada);
		}
	}

	//Bucle que se dedica a escribir/enviar los mensajes
	while (bucle == true)
	{
		std::getline(std::cin, respuestaEnviarMensaje);
		//Verificación si es exit o no
		if (respuestaEnviarMensaje == "exit")
		{
			std::cout << "Guardando Datos";
			bucle = false;

			//Escribimos en el archivo las palabras encriptadas
			file << cheksumSalida << std::endl;

			for (short i = 0; i < mensajesEncriptados.size(); i++)
			{
				file << mensajesEncriptados[i] << std::endl;
			}

		}
		else
		{	
			std::string palabraEncriptada;
			//Creando una variable
			char letrasPalabras;

			for (short i = 0; i < respuestaEnviarMensaje.length(); i++) 
			{
				letrasPalabras = respuestaEnviarMensaje[i];
				letrasPalabras = letrasPalabras + 10; // Forma de encriptar sumando 1052 
				cheksumSalida = cheksumSalida + (int)letrasPalabras;//Añadir el valor a al letra encriptada al cheksum, si ponemos el (int) convertimos en una variable int rapidamente
				palabraEncriptada += letrasPalabras;

			}

			mensajesEncriptados.push_back(palabraEncriptada);
			mensajes.push_back(respuestaEnviarMensaje);
		}
	}
	//Cerramos el archivo
	file.close();

}