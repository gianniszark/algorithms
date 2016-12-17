#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <array>

const int N_Max = 750;

short int Playground[N_Max][N_Max];
int SumTable[N_Max][N_Max];
int N,K;
char buffer[N_Max];


/* Counts the number of rectangles with exactly K trees in the rectangle strip
 * starting from start_row and ending at end_row.
 * Complexity O(N)
 */
long long RectangleCount(int start_row,int end_row) {
	int i1 = 0, i2 = 0,j;
	long long sum = 0;
	for (j = 0; j <= N; j++) {
		//find min i1
		while (!((SumTable[end_row][j] - SumTable[start_row - 1][j]) - (SumTable[end_row][i1] - SumTable[start_row - 1][i1])<=K)) {
			i1++;
			if (i1 == N + 1) break;
		}
		if (!((SumTable[end_row][j] - SumTable[start_row - 1][j]) - (SumTable[end_row][i2] - SumTable[start_row - 1][i2])>=K))
			continue;
		else {
			while (((SumTable[end_row][j] - SumTable[start_row - 1][j]) - (SumTable[end_row][i2] - SumTable[start_row - 1][i2]) >= K) && (i2 <= N))
				i2++;
			i2--;
			sum += i2 - i1 + 1;
		}
	}
	return sum;
}

/* Function creates a table in which
 * table[i][j] is the number of Trees contained
 * by the rectangle with upper left corner at (0,0)
 * and lower right corner at (i,j) of Playground
 */
void Create_Sum_Table() {
	for (int i = 0; i <= N - 1; i++)
		SumTable[i][0] = 0;
	for (int j = 0; j <= N; j++)
		SumTable[0][j] = 0;
	for (int j = 1; j <= N; j++)
		SumTable[1][j] = Playground[0][j - 1] + SumTable[1][j - 1];
	int temp;
	for (int i = 2; i <= N; i++) {
		temp = 0;
		for (int j = 1; j <= N ; j++) {
			temp += Playground[i - 1][j - 1];
			SumTable[i][j] = SumTable[i - 1][j]  + temp;
		}
	}
}



int main() {

	/*Read Size of NxN Playground*/
	scanf("%d", &N);
	/*Read Number of Trees wanted in our Playground*/
	scanf("%d", &K);
	/*Read Playground*/
	fgets(buffer, N_Max, stdin);
	for (int i = 0; i <= N - 1; i++) {
		fgets (buffer, N_Max, stdin);
		for (int j = 0; j <= N - 1; j++)
			Playground[i][j] = buffer[j] - '0';
	}
	Create_Sum_Table();
	/* Count the number of rectangles
	 * in every possible strip of the Playground
	 */
	long long sum = 0;
	for (int start_row = 1; start_row <= N; start_row++) {
		for (int end_row = N; end_row >= start_row; end_row--) {
			if (SumTable[end_row][N] - SumTable[start_row - 1][N] < K) break;
			sum += RectangleCount(start_row,end_row);
		}
	}
	printf("%lld\n",sum);
	return 0;
}
