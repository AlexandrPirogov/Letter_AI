#pragma once
#include <iostream>

class Neuron {
public:
	float axon;
	int* sinopsis;
	Neuron(int M, int N) {
		sinopsis = new int[M * N];
		for(int i = 0; i < M*N; i++)
			sinopsis[i] = 0;
		this->axon = 0;
	};

	void readFile(std::ifstream& ifs);

	float getAxon();

private:
	const float weights[10][10] = { 
		{1,1,1,1,1,1,1,1,1,0.8},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.9, 1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0.7,0.7,0.7,0.7,0.7,0.7,0.7,0.7,0.9},
	};

};
