/*
 * Übungsaufgabe zum Euklidischen Algorithmus
 * @autor Fabian Franz
 */

#include <iostream>

uint64_t ggT(int64_t a, int64_t b);
uint64_t ggT_v(int64_t a, int64_t b);
uint64_t ggTRekursive(int64_t a, int64_t b, int count);
uint8_t ggtProgram2();
uint8_t ggtProgramN();
uint8_t ggTProgramNRekursive();
uint64_t fak(uint64_t n);

int main(){
	int menu = 0;
	int choose = 0;

	while(!menu) {
		std::cout << "1 = Normal, 2 = Rekursiv" << std::endl;
		std::cout << "Eingabe: ";
		std::cin >> choose;
		switch(choose) {
		case 1: ggtProgramN(); break;
		case 2: ggTProgramNRekursive(); break;
		default:
			std::cout << "Fehler bei der Eingabe" << std::endl;
			break;
		}
		std::cout << "Abbruch? Ja = 1, Nein = 0" << std::endl;
		std::cout << "Eingabe: ";
		std::cin >> menu;
	}
	return 0;
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
	for(int8_t i=0; i<n; i++) {
		std::cout << "Gib die " << i + 1 << ". Zahl ein: ";
		std::cin >> values[i];
	}
	result = ggT_v(values[0], values[1]);
	for(int8_t i=2; i<n; i++) {
		result = ggT_v(values[i], result);
	}
	std::cout << "Der ggT aus " << n << " Zahlen lautet: " << result << std::endl;
	return 0;
}
uint8_t ggTProgramNRekursive(){
	// => Ermittelt den ggT aus n Zahlen inklusive Ein- und Ausgabe.
	int n = 0;
	int64_t *values;
	uint64_t result = 0;

	values = (int64_t*) malloc(sizeof(int64_t));
	std::cout << "ggT-Rechner für n-zahlen" << std::endl;
	std::cout << "Gib die Anzahl der Zahlen ein: ";
	std::cin >> n;
	if(n < 0) n = n * -1;
	for(int8_t i=0; i<n; i++) {
		std::cout << "Gib die " << i + 1 << ". Zahl ein: ";
		std::cin >> values[i];
	}
	result = ggTRekursive(values[0], values[1], 0);
	for(int8_t i=2; i<n; i++) {
		result = ggTRekursive(values[i], result, 0);
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
	static int count = 0;

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
		count++;
		std::cout << "Nächster Dividend: " << b << std::endl;
		std::cout << "Rechendurchlauf: " << count << std::endl;
	}
	return b;
}
uint64_t ggTRekursive(int64_t a, int64_t b, int count){
	count++;
	std::cout << "Nächster Dividend: " << b << std::endl;
	std::cout << "Durchgang: " << count << std::endl;
	if(a < 0) a = a * -1;
	if(b < 0) b = b * -1;
	if(a == 0) a = b;
	if(a < b) {
		uint64_t buf = a;
		a = b;
		b = buf;
	}
	if(a % b) {
		uint64_t times = 0;
		times = a / b;
		b = a - times * b;
		b = ggTRekursive(a, b, count);
	}
	return b;
}
uint64_t fak(uint64_t n){
	if(n == 0) return 1;
	return n * fak(n - 1);
}
