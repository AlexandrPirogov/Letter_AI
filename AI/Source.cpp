#include <iostream>
#include <fstream>
#include "Neuron.h"

using namespace std;

int main() {
	std::string chars[] = { "A", "B", "C", "D", "E", "F" };

	
	Neuron* neuron = new Neuron(10, 10);
	for (int count = 0; count < 10000; count++)
	{
		for (int i = 0; i < 6; i++) {
			std::string filename = chars[i];
			neuron->symbol = filename;
			ifstream is(filename + ".txt");
			neuron->read_file(is);
			neuron->update_weigts();

		}

	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << neuron->weights[i][j];
		}
		std::cout << std::endl;
	}
}