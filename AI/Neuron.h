#pragma once
#include <iostream>

class Neuron {
public:
	float axon;
	int sinopsis[10][10];
	std::string symbol;

	Neuron(int M, int N) {
		this->axon = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				this->weights[i][j] = 0;
				this->sinopsis[i][j] = 0;
			}
		}
	};

	void read_file(std::ifstream& ifs);

	void write_weights(std::ofstream& ofs);

	void read_weights(std::ifstream& ifs);

	void update_weigts();

	bool getAxon();
	float weights[10][10];
private:
	 
	 
	 void decrease_weights();
	 void increase_weights();
};
