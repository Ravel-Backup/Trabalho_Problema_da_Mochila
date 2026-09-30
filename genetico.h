#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

struct Bag {
	std::vector <unsigned int> tempSolucao;
};

struct Binario {
	std::vector<std::vector<unsigned int>> tempBinario;
};

std::vector<unsigned int> conversor(unsigned int);

std::vector<unsigned int> bitsGene_PontoUnico(std::vector<Bag>);
std::vector<unsigned int> bitsGene_Aritimetico(std::vector<Bag>);
std::vector<unsigned int> bitsGene_Mutacao(std::vector<Bag>);
std::vector<unsigned int> bitsGene_MutacaoDupla(std::vector<Bag>);


bool evaluation(unsigned int);
//std::vector<unsigned int>separarDigitos(unsigned int receber);
void resultado(std::vector<Binario>bag, int tamanho = sizeof(unsigned int) * 4, int numero_deSolucao = 6);