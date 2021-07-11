#include "Neuron.h"
#include <fstream>

void Neuron::read_file(std::ifstream& ifs)
{
	char symbol;
//	int* pointer = &this->sinopsis[0];
	int i = 0;
	int j = 0;
	while (!ifs.eof()) {
		ifs >> symbol;
		this->sinopsis[j][i] = (int)(symbol - '0');
		i++;
		if (i % 10 == 0) {
			j++;
			i=0;
		}
	}
	
}

void Neuron::update_weigts()
{
	
	int isA = this->getAxon();
	if (this->symbol != "A" && isA == true) {
		this->decrease_weights();
	}
	if (this->symbol == "A" && isA == false) {
		this->increase_weights();
	}
	
}

void Neuron::read_weights(std::ifstream& ifs)
{
	char symbol;
	int i = 0;
	int j = 0;
	while (!ifs.eof()) {
		ifs >> symbol;
		j++;
		if (j % 10 == 0) {
			i++;
			j = 0;
		}
		this->weights[i][j] = (int)(symbol - '0');
		i++;
	}
	ifs.close();
}

void Neuron::write_weights(std::ofstream& ofs)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			ofs << this->weights[i][j];
		}
		ofs << "\n";
	}
	ofs.close();
}

bool Neuron::getAxon()
{
	this->axon = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			this->axon += this->sinopsis[i][j] * this->weights[i][j];
		}
	}
	if (this->axon != 36)return false;
	return true;
}

void Neuron::decrease_weights()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			float w = this->sinopsis[i][j];
			w /= 10;
			this->weights[i][j] -= w;
		}
	}
}

void Neuron::increase_weights()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			float w = this->sinopsis[i][j];
			w /= 10;
			this->weights[i][j] += w;
		}
	}
}


