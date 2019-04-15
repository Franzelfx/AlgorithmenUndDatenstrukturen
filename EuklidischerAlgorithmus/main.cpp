/*
 * Übungsaufgabe zum Euklidischen Algorithmus
 * @autor Fabian Franz
 */

#include <iostream>

uint64_t ggT(int64_t a, int64_t b);
uint64_t ggT_v(int64_t a, int64_t b);
uint8_t ggtProgram2();
uint8_t ggtProgramN();

int main(){
	int menu = 0;

	while(!menu) {
		ggtProgramN();
		std::cout << "Abbruch? Ja = 1, Nein = 0" << std::endl;
		std::cout << "Eingabe: ";
		std::cin >> menu;
	}
}
uint8_t ggtProgram2(){
	// => Ermittelt den ggT aus zwei Zahlen inklusive Ein- und Ausgabe.
	int64_t a = 100;
	int64_t b = 36;
	int64_t result = 0;

	std::cout << "GGT zweier Zahlen, gib den Divisor ein: ";
	std::cin >> a;
	std::cout << "Gib den Divident ein: ";
	std::cin >> b;
	result = ggT_v(a,b);
	std::cout << "Ergebnis: " << result << std::endl;
	return 0;
}
uint8_t ggtProgramN(){
	// => Ermittelt den ggT aus n Zahlen inklusive Ein- und Ausgabe.
	int n = 0;
	int64_t *values;
	uint64_t result = 0;

	values = (int64_t*) malloc(sizeof(int64_t));
	std::cout << "ggT-Rechner für n-zahlen" << std::endl;
	std::cout << "Gib die Anzahl der Zahlen ein: ";
	std::cin >> n;
	if(n < 0) n = n * -1;
	for(int i=0; i<n; i++) {
		std::cout << "Gib die " << i + 1 << ". Zahl ein: ";
		std::cin >> values[i];
	}
	result = ggT(values[0], values[1]);
	for(int i=2; i<n; i++) {
		result = ggT(values[i], result);
	}
	std::cout << "Der ggT aus " << n << " Zahlen lautet: " << result << std::endl;
	return 0;
}
uint64_t ggT(int64_t a, int64_t b){
	if(a < 0) a = a * -1;
	if(b < 0) b = b * -1;
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
uint64_t ggT_v(int64_t a, int64_t b){
	if(a < 0) a = a * -1;
	if(b < 0) b = b * -1;
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
