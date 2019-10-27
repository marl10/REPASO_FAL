#include <iostream>
#include <math.h>

using namespace std; 


int primerNoNulo(long long n);
int sumPrimeros(int n);
int noNuloAux(long long n);


int main() {

	int n; 

	do {

		cin >> n; 
		if (n > 0 && n < pow(10, 15)) {
			cout << noNuloAux(n) << endl; 
		}
	} while (n != 0);

	return 0; 
}


int noNuloAux(long long n) {

	if (n < 10) {
		return sumPrimeros(n); 
	}

		return 45 + noNuloAux(n - 10) + primerNoNulo(n - n%10);
}

int primerNoNulo(long long  n) {

	int num = n; 
	

	while (num % 10 == 0) {
		num = num / 10; 
	}

	return num % 10; 
}

int sumPrimeros(int n) {

	int suma = 0; 
	for (int i = 1; i <= n; i++) {
		suma += i; 
	}

	return suma; 
}
