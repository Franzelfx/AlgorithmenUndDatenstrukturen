/*
 * Programm zur iterativen berechnung der Nullstellen einer Funktion
 * @autor FabianFranz
 */

#include <iostream>

double function(double x);
double derivation(double x);
double newton(double eps, int x0);

int main(){
	float eps;
	int x0;
	std::cout << "Geben sie x0 ein: ";
	std::cin >> x0;
	std::cout << "Geben sie das Epsilon ein";
	std::cin >> eps;
	std::cout << "Das Ergebniss lautet: ";
	std::cout << newton(eps, x0);
	return 0;
}

double function(double x){
	return x * x * x * x + 3 * x * x * x - x - 10;
}
double derivation(double x){
	return 4 * x * x * x + 9 * x * x - 1;
}
double newton(double eps, double x0){
	while(function(x0) > eps) {
		if(derivation(x0) == 0) return -1;
		x0 = x0 - function(x0) / derivation(x0);
	}
	return x0;
}
