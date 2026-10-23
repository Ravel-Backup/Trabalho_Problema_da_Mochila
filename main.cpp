#include <iostream>
#include <vector>
#include <algorithm>
#include "binario.h"
#include "genetico.h"

int iniciar();

//int iterador(unsigned short int receber[], int tamanho);
int main() {
	iniciar();
}

int iniciar() {
	int preco = 0;

	std::vector <Bag> solutionsBag; // Árvore responsável por guardar a quantidade soluções definida para o usuário digitar.
	std::vector<Binario> binarioBag; // Árvore resposável por guardar em binario se há valor em cada algarismo das soluções.
	std::vector<Binario> binarioBag_fitness;
	std::vector<Binario> fitness;
	
	solutionsBag.resize(7);
	binarioBag.resize(7);
	fitness.resize(4);

	int tamanho = sizeof(unsigned int) * 4;

	// Guarda 6 soluções, como solucao é um unsigned char, transferimos a responsabilidade do armazenamento de
	// 6 arrays char para um vector que também é unsigned char.
	// Obtém a correspondecia binaria de cada uma das soluções.
	// Prepara a entrada para receber o valor do usuario;

	for (int index = 0; index < 6; index++) {
		unsigned int solucao = 0;
		// Guarda as entradas que o usuario com limite de 16 algarismos dentro de solucao.
		std::cout << "Digite a solucao de numero " << index << ": "; std::cin >> solucao;
		
		//Structs aninhados com vectors que guardam separadamente em indice de 0 a 5 os arrays.

		solutionsBag[index].tempSolucao.push_back(solucao);
		binarioBag[index].tempBinario.push_back(conversor(solucao));
	}
	fitness[0].tempBinario.push_back(bitsGene_PontoUnico(solutionsBag));
	fitness[1].tempBinario.push_back(bitsGene_Aritimetico(solutionsBag));
	fitness[2].tempBinario.push_back(bitsGene_Mutacao(solutionsBag));
	fitness[3].tempBinario.push_back(bitsGene_MutacaoDupla(solutionsBag));
	
	bool rodar = true;
	while (rodar) {
		std::cout << "Resultado da Avaliacao:"
			<< "\n_________________________________\n";
		resultado(binarioBag, tamanho);
		std::cout << "\n_________________________________\n";
		resultado(fitness, tamanho, 4);
		std::cout << "\n_________________________________\n";
		rodar = false;
	}

	return 0;
}

std::vector<unsigned int> conversor(unsigned int receber) {
	std::vector<unsigned int> armazen;
	armazen.push_back(receber);
	return armazen;
}

void resultado(std::vector<Binario>bag, int tamanho, int numero_deSolucao) {
	std::vector <unsigned int> bagTemporario, binarioTemporario, invioTemporario;
	unsigned short int mochila[16] = { 12,3,5,4,9,1,2,3,4,1,2,4,5,2,4,1 };
	unsigned short int preco[16] = { 4,4,8,10,15,3,1,1,2,10,20,15,10,3,4,12 };

	unsigned int somatorio = 0, mochilaSomatorio = 0;
	for (int index = 0; index < numero_deSolucao; index++) {

		invioTemporario = bag[index].tempBinario[0];
		unsigned int invioBinarioTemp = invioTemporario[0];
		//bagTemporario = separarDigitos(invioBinarioTemp);
		binarioTemporario = (descobrirBinario(invioBinarioTemp, tamanho));

		/*
		for (int i = 0; i < bagTemporario.size(); i++) {
			somatorio += bagTemporario[i]; // somatório do preço.
		}
		*/

		for (int i = 0; i < tamanho; i++){
			if (binarioTemporario[i]) {
				somatorio += preco[i]; // somatório do preço.
				mochilaSomatorio += mochila[i]; // somatório do peso da mochila.
			}
		}
		
		bool definidor = evaluation(mochilaSomatorio);
		
		// ___________________________________ //

		std::cout << invioBinarioTemp << " - $" << somatorio << " - " << mochilaSomatorio << "Kg - ";
		if (!definidor) {
			std::cout << "\033[32m" << "OK\n" << "\033[0m";
		}
		else {
			std::cout << "\033[4;31m" << "X\n" << "\033[0m";
		}
		somatorio = 0;
		mochilaSomatorio = 0;
	}
}
