#include <stdio.h>

///definim INF ca un numar foarte mare
#define INF 99999

///numarul total de monede
#define N 3

///suma care trebuie schimbata utilizand monedele
#define A 13

void coinChange(int d[N+1], int C[A+1], int S[A+1]) {
	int iterator, p, min, coin;

	///cand suma este 0, numarul de monede necesare e 0
	C[0] = 0;
	S[0] = 0;

	for(p = 1; p <= A; p++) {
		min = INF;
		for(iterator = 1; iterator <= N; iterator++) {
			if(d[iterator] <= p) {
				if(1 + C[p - d[iterator]] < min) {
					min = 1 + C[p - d[iterator]];
					coin = iterator;
				}
			}
		}
		C[p] = min;
		S[p] = coin;
	}
}

void coinSet(int d[N+1], int S[A+1]) {
	int iterator = A;
	while(iterator > 0) {
		printf("Use coin of denomination: %d\n", d[S[iterator]]);
		iterator = iterator - d[S[iterator]];
	}
}

void display(int arr[A+1]) {
	int c;
	for(c = 0; c <= A; c++) {
		printf("%5d", arr[c]);
	}
	printf("\n");
}


int main() {
	///vectorul care contine monedele
	///vom incepe de la indicele 1
	///deci indicele 0 o sa fie 0
	int d[N+1] = {0, 1, 2, 5};

	///vectorul care contine numarul minim de monede necesare
	int C[A+1];

	///vectorul care contine indicele monedei care urmeaza sa fie inclusa in soluția optima
	int S[A+1];

	///calculam numarul minim de monede necesare
	coinChange(d, C, S);

	///afisarea vectorului C
	printf("\nC[p]\n");
	display(C);

	///afisarea vectorului S
	printf("\nS[p]\n");
	display(S);

	///afisarea numarului minim de monede necesare
	printf("\nMin. no. of coins required to make change for amount %d = %d\n", A, C[A]);

	///afisarea solutiei optime
	printf("\nCoin Set\n");
	coinSet(d, S);

	return 0;
}

