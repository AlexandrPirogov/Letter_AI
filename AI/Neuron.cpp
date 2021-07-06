#include "Neuron.h"
#include <fstream>

void Neuron::readFile(std::ifstream& ifs)
{
	char symbol;
//	int* pointer = &this->sinopsis[0];
	int i = 0;
	while (!ifs.eof()) {
		ifs >> symbol;
		this->sinopsis[i] = (int)(symbol - '0');
		i++;
	}
}

float Neuron::getAxon()
{
	int* pointer = &this->sinopsis[0];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			this->axon += this->sinopsis[i*j] * this->weights[i][j];
		}
	}
	if (this->axon < 20 || this->axon > 30)std::cout << "This is not a letter!\n";
	else std::cout << "This is a Letter!\n";
	return this->axon;
}
