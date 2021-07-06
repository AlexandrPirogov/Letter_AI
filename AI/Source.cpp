#include <iostream>
#include <fstream>
#include "Neuron.h"

using namespace std;

int main() {
	std::string chars[] = { "A", "B", "C", "D", "E", "F", "noA", "noB", "noC", "NoD", "NoE", "NoF"};

	for (int i = 0; i < 12; i++) {
		Neuron* neuron = new Neuron(10, 10);
		std::string filename = chars[i];
		ifstream is(filename+".txt");
		neuron->readFile(is);
		std::cout << filename << " ";
		neuron->getAxon() ;
	}
	
}