const int NumberOfDays = 101000;
const int MaxTrades = 1100;

#include <iostream>
#include <stdlib.h>
#include <algorithm>


int N, K;
long OPT[2][NumberOfDays], ChocoPrice[NumberOfDays];

int main() {

	long min, Result;
	int i, j;
	/* Input Number of Trading Days (N) and Maximum Trades Allowed (K)*/
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++) {
		scanf("%ld", &(ChocoPrice[i]));
	}

	/*
	 * Recurrence :
	 * opt[trade][day] = max ( opt[trade][day - 1], price[j] - min for trade<k<j ( price[k] - opt[trade - 1][k - 1]) )
	 */

	min = ChocoPrice[0];
	OPT[0][0] = 0;
	for (j = 1; j < N; j++) {
		min = std::min(ChocoPrice[j - 1], min);
		OPT[0][j] = std::max(OPT[0][j - 1], ChocoPrice[j] - min);
	}

	if (OPT[0][N - 1] == 0) {
		printf("0\n");
		return(0);
	}
	else
		Result = OPT[0][N - 1];

	long *curr = OPT[1];
	long *prev = OPT[0];

	for (i = 1; i < K; i++) {
		min = INT32_MAX;
		for (j = 2 * i + 1; j < N; j++) {
			min = std::min(ChocoPrice[j - 1] - prev[j - 2], min);
			curr[j] = std::max(curr[j - 1], ChocoPrice[j] - min);
		}
		Result = std::max(Result, curr[N - 1]);
		std::swap(curr, prev);
	}

	printf("%ld\n", Result);
	return(0);

}
