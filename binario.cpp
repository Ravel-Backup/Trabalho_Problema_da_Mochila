#include <iostream>
#include <vector>
#include <algorithm>
#include "binario.h"


// Uma função vector é a unica capaz de retornar vector, o que precisamos.
// Se por exemplo unsigned char recebe = 246, logo seu 
// binário = 11110110, sendo então a mascara um valor com bit shifting
// em i, como i igual a 1, logo mascara = 00000001, ao usar o
// operador binário & e comparar todas as casas, nenhum valor
// entrarar em correspondência, dessa forma o resultado é 0,
// portanto é false porque todos os valores se divergem
// mas se tiver ao menos 2 valores iguais a 1
// esse dará o resultado do if como um numero diferente
// de 0, e tudo que não é zero é true em c++.

std::vector<unsigned int> descobrirBinario(unsigned int receber, int tamanho) { // tamanho = sizeof(unsigned int) * 4 por padrão
	std::vector<unsigned int> binarioTemporario;
	//std::cout << " Binario: ";

	for (int index_bit = tamanho - 1; index_bit >= 0; index_bit--) {
		unsigned int bit = testarBit(receber, index_bit);

		binarioTemporario.push_back(bit);
		//std::cout << bit;
	}
	//std::cout << std::endl;
	return binarioTemporario;
}

int testarBit(unsigned int receber, int index_bit) {
	unsigned int mascara = 1 << index_bit;
	unsigned int estado = receber;
	return (estado & mascara) ? 1 : 0;
}
