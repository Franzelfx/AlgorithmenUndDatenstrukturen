/*
 * Programm zur iterativen berechnung der Nullstellen einer Funktion
 * @autor FabianFranz
 */

#include <iostream>

double newt_(double eps, double x0, int &counter);
double fabs_(double x);
double function(double x);
double derivation(double x);

int main(){
	double eps;
	double x0;
	int count;
	std::cout << "Geben sie x0 ein: ";
	std::cin >> x0;
	std::cout << "Geben sie das Epsilon ein: ";
	std::cin >> eps;
	std::cout << "Das Ergebniss lautet: " << std::endl;
	std::cout << newt_(eps, x0, count);
	std::cout << "Anzahl der Iterationen: " << count << std::endl;
	return 0;
}

double function(double x){
	return x * x * x * x + 3 * x * x * x - x - 10;
}
double derivation(double x){
	return 4 * x * x * x + 9 * x * x - 1;
}
double fabs_(double x){
	if(x < 1) x = x * -1;
	return x;
}
double newt_(double eps, double x0, int &counter){
	int maxCounter = 0;

	while(function(x0) > eps) {
		if(derivation(x0) == 0) return -1;
		x0 = x0 - function(x0) / derivation(x0);
		counter++;
		maxCounter++;
		if(maxCounter > 10000) return -1;
	}
	return x0;
}
