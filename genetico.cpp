#include <iostream>
#include <vector>
#include <algorithm>
#include "genetico.h"

// Essa função é do tipo vector porque precisa retornar um vector para ser armazenado em quem a chama
// daria para resolver tudo em uma linha mas deixei assim para ser mais legível.
// Primeiro temos que definir mascaras para bits baixos e altos, aqui eu defino 255 e inverto
// o valor porque 255 = 11111111. Nisso quando invertemos o resultado é igual a 0, ideal para
// apagar alguma informação do tamanho de 1 byte no valor do numero dentro de solutionsBag
// em questão. 
// Nosso final, com os valores de bits baixos da solução 0 e bits altos da solução 1 "apagados
// podemos fundir os resultados, como com "OR", o 0 e 1 o resultado é igual a 1, como também 0 e 0 o resultado é igual a 0
// isso permite que o resultado seja o que esperamos de um ponto unico = AAAAAAAABBBBBBBB

std::vector<unsigned int> bitsGene_PontoUnico(std::vector<Bag>solutionsBag) {
	std::vector <unsigned int> bits;
	unsigned int tempBitsAltos = 0;
	unsigned int tempBitsBaixos = 0;
	unsigned int mascaraBaixa = ~(255 << 8);
	unsigned short int mascaraAlta = ~(255);
	unsigned int solucaoAlta = solutionsBag[0].tempSolucao[0];
	unsigned int solucaoBaixa = solutionsBag[1].tempSolucao[0];
	tempBitsBaixos = solucaoBaixa & mascaraBaixa;
	tempBitsAltos = solucaoAlta & mascaraAlta;
	bits.push_back(tempBitsBaixos | tempBitsAltos);
	return bits;
}

// Aritimético:
std::vector<unsigned int> bitsGene_Aritimetico(std::vector<Bag>solutionsBag) {
	std::vector <unsigned int> bits;
	unsigned int solucao = solutionsBag[2].tempSolucao[0];
	unsigned int solucao2 = solutionsBag[3].tempSolucao[0];
	unsigned int extraido = (solucao & (1 << 12)) | (solucao & (1 << 5));
	unsigned int extraido2 = (solucao2 & (1 << 12)) | (solucao2 & (1 << 5));
	unsigned int resposta = extraido | extraido2;
	bits.push_back(resposta);
	return bits;
}

// Mutação:
std::vector<unsigned int> bitsGene_Mutacao(std::vector<Bag>solutionsBag) {
	std::vector <unsigned int> bits;
	unsigned int solucao = solutionsBag[4].tempSolucao[0];
	unsigned int extraido = (solucao ^ (1 << 9));
	//std::cout << "extraido: " << extraido;
	bits.push_back(extraido);
	return bits;
}

std::vector<unsigned int> bitsGene_MutacaoDupla(std::vector<Bag>solutionsBag) {
	std::vector <unsigned int> bits;
	unsigned int solucao = solutionsBag[5].tempSolucao[0];
	unsigned int extraido = (solucao ^ (1 << 12));
	extraido = (extraido ^ (1 << 3));
	//std::cout << "extraido: " << extraido;
	bits.push_back(extraido);
	return bits;
}

bool evaluation(unsigned int somatorio) { //tamanho = sizeof(unsigned int) * 4 por padrão.
	int resposta = (somatorio > 20) ? 1 : 0;
	return resposta;
}
