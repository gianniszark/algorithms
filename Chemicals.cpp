#include <iostream>
#include <stdlib.h>
#include <algorithm>

void divideConquer(long *curr, long *prev, int left, int right, int low, int high);
long readLong();

#define BSIZE 1<<15
#define MAX_N 2550
#define MAX_K 750

char buffer[BSIZE];
long opt[2][MAX_N], reaction[MAX_N][MAX_N], cost[MAX_N][MAX_N];
int opt_pos[1][MAX_N];
long N, K;
long *curr = opt[1], *prev = opt[0];


int main() {

	int i, j, temp;
	/*Read input*/
	N = readLong();
	K = readLong();

	/*
	 * Make Cost Table
	 * cost[i][j] = cost for having chemicals[i] to [j]
	 * in the same bottle
	 */
	for (i = 0; i < N - 1; i++) {
		cost[i][i] = 0;
		for (j = i + 1; j < N; j++) {
			reaction[i][j] = readLong();
			cost[i][j] = reaction[i][j] + cost[i][j - 1];
		}
	}


	cost[0][0] = 0;
	for (j = N - 1; j >= 1; j--) {
		cost[j][j] = 0;
		for (i = j - 1; i >= 0; i--) {
			cost[i][j] = cost[i][j] + cost[i + 1][j];
		}
	}

	int bottle, chemical;

	opt[0][0] = cost[0][0];
	for (chemical = 0; chemical < N; chemical++)
		opt[0][chemical] = cost[0][chemical];

	/*
	 * Recurrence type :
	 * opt[bottle][chemical] = for temp < chemical : min( cost[temp][chemical] + opt[bottle - 1][temp - 1] )
	*/
	for (bottle = 1; bottle < K; bottle++) {
			curr[N - 1] = INT32_MAX;
			for (temp = bottle; temp <= N - 1; temp++) {
				if (curr[N - 1] > cost[temp][N - 1] + prev[temp - 1]) {
					curr[N - 1] = cost[temp][N - 1] + prev[temp - 1];
					opt_pos[0][N - 1] = temp;
				}
			}
			divideConquer(curr, prev, bottle, N - 1, bottle, opt_pos[0][N - 1]);
			std::swap(curr, prev);
	}

	printf("%ld\n", prev[N - 1]);
	return 0;
}

/*
 * Divide and Conquer Optimization Function
 * Reduces the complexity of the dynamic programming approach
 * from O(N^2*K) to O(N*logN*K)
 */

void divideConquer(long *curr, long *prev, int left, int right, int low, int high) {
	if (left == right) {
		curr[left] = INT32_MAX;
		for (int temp = low; temp <= high; temp++)
			if (curr[left] > cost[temp][left] + prev[temp - 1]) {
				curr[left] = cost[temp][left] + prev[temp - 1];
				opt_pos[0][left] = temp;
			}
		return;
	}

	if (left > right)
		return;
	int mid = (left + right) / 2;
	curr[mid] = INT32_MAX;
	for (int temp = low; temp <= high; temp++)
		if (curr[mid] > cost[temp][mid] + prev[temp - 1]) {
			curr[mid] = cost[temp][mid] + prev[temp - 1];
			opt_pos[0][mid] = temp;
		}
	divideConquer(curr, prev, left, mid - 1, low, opt_pos[0][mid]);
	divideConquer(curr, prev, mid + 1, right, opt_pos[0][mid], high);

}

/*Function for buffered input- courtesy of Corelab NTUA*/
long bpos = 0L, bsize = 0L;

long readLong(){

	long d = 0L, x = 0L;
	char c;

	while (1) {
		if (bpos >= bsize) {
			bpos = 0;
			if (feof(stdin)) return x;
			bsize = fread(buffer, 1, BSIZE, stdin);
		}
		c = buffer[bpos++];
		if (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); d = 1; }
		else if (d == 1) return x;
	}
	return -1;
}
