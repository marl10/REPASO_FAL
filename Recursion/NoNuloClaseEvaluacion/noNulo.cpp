#include <iostream>
#include <math.h>

using namespace std; 


int primerNoNulo(long long n);
int noNulo(long long n);
int sumPrimeros(int n);
int noNuloAux(int n);


int main() {

	int n; 

	do {

		cin >> n; 
		if (n > 0 && n < pow(10, 15)) {
			cout << noNulo(n) << endl; 
		}
	} while (n != 0);

	return 0; 
}


int noNulo(long long n) {

	int rest = 0; 
	if (n % 10 != 0 || n < 10) {
		rest = sumPrimeros(n % 10); 
	}

	if (n > 9) {
		rest += noNuloAux(n - n%10); 
	}
	return rest;
}

int noNuloAux(int n) {

	if (n  == 0) {

	}

	/*
	else if (n < 10) {
		if (n == 1) {

		}
	}
	*/



		return 45 + noNulo(n - 10) + primerNoNulo(n);
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

/*
else if (n == 2) {

		}
		else if (n == 3) {

		}
		else if (n == 4) {

		}
		else if (n == 5) {

		}
		else if (n == 2) {

		}
		else if (n == 3) {

		}
		else if (n == 4) {

		}
		else if (n == 5) {

		}

*/