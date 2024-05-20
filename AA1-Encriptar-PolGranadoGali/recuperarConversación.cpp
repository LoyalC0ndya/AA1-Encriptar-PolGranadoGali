

#include "recuperarConversación.h"

void recuperarConvers(std::vector<std::string>& mensajes) {

	std::ifstream file("historial_msg.txt");

	if (file.is_open())
	{
		int cheksumEntrada;
		int cheksumChek = 0;
		std::vector<std::string> mensajesRecuperados;

		file >> cheksumEntrada;

		while (!file.eof())//El "eof" signfica el final del fichero para no tener que hardcodear el final del bucle
		{
			std::string palabraEncriptadaEntrada;
			std::string palabraRecuperada;

			file >> palabraEncriptadaEntrada;

			for (short i = 0; i < palabraEncriptadaEntrada.length(); i++)
			{
				char letrasPalabras = palabraEncriptadaEntrada[i];
				cheksumChek += (int)letrasPalabras; 

				letrasPalabras = letrasPalabras - 1052;
				palabraRecuperada += letrasPalabras;
			}			
			mensajesRecuperados.push_back(palabraRecuperada);
		}
		if (cheksumChek == cheksumEntrada)
		{
			for (short i = 0; i < mensajesRecuperados.size(); i++)
			{
				std::cout << mensajesRecuperados[i] << std::endl;
			}
			mensajes = mensajesRecuperados;
		}
		else
		{
			std::cout << "ERROR: Checksum no coincide";
		}
		
		file.close();
	}
	else
	{
		exit(0);
	}

}