#include <iostream>
/*
	FALTA ENTRADA, HAY QUE PREGUTNAR
*/
using namespace std; 

void leeDatos(int v[], int n);
bool ordenado(int v[], int n);
bool ordenadoAux(int v[], int hi, int low); 


int main() {
	
	int *v = NULL; 
	int n; 
	
	do {

		cin >> n;
		v = new int[n]; 

		leeDatos(v, n); 

		if (ordenado(v, n)) {
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

bool ordenado(int v[], int n) {
	return ordenadoAux(v, 0, n -1);
}

bool ordenadoAux(int v[], int low, int hi){

	if (hi - low == 1) {
		return v[hi] >= v[low]; 
	}


	int mid = (hi + low) / 2; 

	return (ordenadoAux(v, mid + 1, hi) && ordenadoAux(v, low, mid)) &&  (v[low]<= v[hi - 1] && v[low + 1] <= v[hi]);
}

/*
	si la izq y la derecha cumplen, pero luego hay que comprobar si los cachos grandes tambiem lo cumplen


*/