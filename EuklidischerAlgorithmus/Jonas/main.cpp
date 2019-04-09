// by Jonas Quinque


#include <iostream>

int ggT(int a, int b);
int ggT_v(int a, int b);
int ggT_recursively(int a, int b);


int main() {
	while(true) {

		int *a;
		int result, programm, num;
		std::cout << "ggT-Rechner" << '\n';
		std::cout << "Bitte Variante eingeben (1 normal, 2 rekursiv, Programmende bel. Eingabe)" << '\n';
		std::cin >> programm;
		if(programm != 1 && programm != 2) return 0; // => beende das Programm bei anderen Eingaben als 1 oder 2
		std::cout << "Bitte geben Sie die Anzahl Ihrer Zahlen ein" << '\n';
		std::cin >> num;

		a = (int*) malloc(num*sizeof(int));
		for (size_t i = 0; i < num; i++) {
			std::cout << "Zahl " << i+1 << '\n';
			std::cin >> a[i];
		}

		switch(programm) {
		case 1:
			result = a[0];
			for (size_t i = 1; i < num; i++) {
				result = ggT(a[i], result);
			}
			std::cout << "Der ggT lautet: " << result << '\n';
			break;
		case 2:
			result = a[0];
			for (size_t i = 1; i < num; i++) {
				result = ggT_recursively(a[i], result);
			}
			std::cout << "Der ggT lautet: " << result << '\n';
			break; // => Ohne Break wird immer dieser Zweig gewählt, egal welche Eingabe
		default:
			return 0;  // => Springe aus Programm wenn Fehler auftaucht (nicht nötig aber an vielen Stellen gut)
			break;
		}
		free(a);
	}
}

int ggT_recursively(int a, int b) {
	if(a == 0) {
		return b;
	} else if(b == 0) {
		return a;
	} else if(a > b) {
		return ggT_recursively(a%b, b);
	} else {
		return ggT_recursively(a, b%a);
	}
}

int ggT(int a, int b) {

	if(a < 0) a = a * -1; // => Betrag bilden
	if(b < 0) b = b * -1;
	while(b != 0 && a != 0) {
		if (a > b) {
			a = a % b;
		}
		else{
			b = b % a;
		}
	}
	if (a == 0) {
		return b;
	} else if(b == 0) {
		return a;
	}
	return 0; // => Ohne Return kann es hier zu Fehlern kommen
}
