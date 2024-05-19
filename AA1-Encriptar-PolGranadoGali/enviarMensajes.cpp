#include <iostream>
#include <fstream>
#include <string>



void enviarMensajes() {
	std::string respuestaEnviarMensaje; 
	bool bucle = true;

	std::cout << "Que mensaje quieres escribir?" << std::endl;
	std::cout << "(Escribe 'exit' para  salir)" << std::endl;
	
	//Arir el archivo
	std::ofstream file;
	file.open("historial_msg.txt", std::ios::app);

	//Bucle que se dedica a escribir/enviar los mensajes
	while (bucle == true)
	{
		std::cout << "MENSAJE:";
		std::getline(std::cin, respuestaEnviarMensaje);
		//Verificación si es exit o no
		if (respuestaEnviarMensaje == "exit")
		{
			std::cout << "Guardando Datos";
			bucle = false;
		}
		else
		{
			file << respuestaEnviarMensaje << std::endl;
		}
	}
	//Cerramos el archivo
	file.close();

}