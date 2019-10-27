#include <iostream>

using namespace std; 

void leeDatos(int v[], int n);
bool caucasicos(int v[], int n);
bool caucasicosAux(int v[], int low, int hi, int &pares);

/*
	Creo que esta bien todo. 

	el paso por referencia ayuda para ir contando los pares que hay en cada mitad. como se hace una copia de las variables parIzq y parDcha estas van a
	acumular los pares que haya en la etapa siguiente. 

	quien guarda los pares de la etapa actual(suma de la izquierda y la derecha ) es la variable pasada por referencia. 

*/


int main() {

	int *v = NULL;
	int n;

	do {

		cin >> n;
		v = new int[n];

		leeDatos(v, n);

		if (caucasicos(v, n)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}

		delete[] v;
		v = NULL;


	} while (n != 0);




	return 0;
}

void leeDatos(int v[], int n) {
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

}
bool caucasicos(int v[], int n) {
	
	int aux = 0; 

	if (n <= 4) {
		return true; 
	}

	return caucasicosAux(v, 0, n - 1, aux); 
	
}

bool caucasicosAux(int v[], int low, int hi, int &pares) {
	if (hi - low == 1) {

		if (v[hi] % 2 == 0) {
			pares++; 
		}
		if (v[low] % 2 == 0) {
			pares++; 
		}
		return true; 
	}


	int mid = (hi + low) / 2; 

	int parIzq, parDcha; 
	parDcha = 0;
	parIzq = 0;

	if (!caucasicosAux(v, low, mid, parIzq)) {
		return false; 
	}
	if (!caucasicosAux(v, mid + 1, hi, parDcha)) {
		return false; 
	}

	pares = parDcha + parIzq; 

	return abs(parDcha - parIzq) <= 2; 

}