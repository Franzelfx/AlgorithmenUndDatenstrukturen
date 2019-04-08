/*
 * Übungsaufgabe zum Euklidischen Algorithmus
 * @autor Fabian Franz
 */

#include <iostream>

uint64_t ggT(uint64_t a, uint64_t b);
uint64_t ggT_v(uint64_t a, uint64_t b);

int main(){
	uint64_t a = 100;
	uint64_t b = 36;
	uint64_t result = 0;

	std::cout << "GGT zweier Zahlen, gib den Divisor ein: ";
	std::cin >> a;
	std::cout << "Gib den Divisor ein: ";
	std::cin >> b;
	result = ggT_v(a,b);
	std::cout << "Ergebnis: " << result << std::endl;
	return 0;
}

uint64_t ggT(uint64_t a, uint64_t b){
	if(a == 0) a = b;
	if(a < b) {
		uint64_t buf = a;
		a = b;
		b = buf;
	}

	while(a % b) {
		uint64_t times = 0;
		times = a / b;
		b = a - times * b;
	}
	return b;
}

uint64_t ggT_v(uint64_t a, uint64_t b){
	if(a == 0) a = b;
	if(a < b) {
		uint64_t buf = a;
		a = b;
		b = buf;
	}

	while(a % b) {
		uint64_t times = 0;
		times = a / b;
		b = a - times * b;
		std::cout << "Nächster Dividend: " << b << std::endl;
	}
	return b;
}
