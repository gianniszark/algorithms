#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <array>


using namespace std;

/*
 * Given a specific time, determine if we will have entered the 
 * examination by that time.
 * Complexity O(N)
 */
bool is_valid(const int* Delay,int ArraySize, long long Time, int Position_In_Queue) {
	long long PeopleExamined = 0;
	long long temp;
	for (int i = 0; i <= ArraySize - 1; i++) {
		temp = Time / Delay[i];
		PeopleExamined += temp + 1;
	}
	if (PeopleExamined < Position_In_Queue)
		return false;
	else
		return true;
}

/*
 * Perform binary search for the time we will be accepted for examination 
   Complexity = O(logn)*O(is_valid) = O(n*logn)
 */
long long Bin_Search(const int* Delay, int ArraySize, long long LowBound, long long UpperBound, long long Position_In_Queue) {
	long long mid;
	while (LowBound < UpperBound) {
		mid = (UpperBound + LowBound) / 2;
		if (is_valid(Delay,ArraySize, mid, Position_In_Queue)) 
			UpperBound = mid;
		else 
			LowBound = mid + 1;
	}
	return(LowBound);
}

/* 
 * Given the position in queue and the time we will enter to be examined,
 * find the number of our examiner
 * Complexity O(N)
 */
int find_Number(const int* Delay,int ArraySize, long long Time, long long Position_In_Queue) {

	int i;
	for (i = 0; i <= ArraySize - 1; i++)
		if (Time % Delay[i] != 0)
			Position_In_Queue -= Time / Delay[i] + 1;
		else
			Position_In_Queue -= Time / Delay[i];
	for (i = 0; i <= ArraySize-1; i++) {
		if (Time % Delay[i] == 0) {
			Position_In_Queue--;
			if (Position_In_Queue == 0)
				return i;	
		}
	}
	i--;
	return (i);
}

int main() {

	int N;
	long long K;
	
	/*read N = #supervisors*/
	fscanf(stdin,"%d", &N);
	/*read K = my pos in the queue*/
	fscanf(stdin, "%lld", &K);
	/*read d[i]=delay of supervisor i*/
	array<int,100000> Delay;
	for (int i = 0; i <= N - 1; i++)
		fscanf(stdin,"%d", &(Delay[i]));
	/*UpperBound for Binary Search*/
	long long UpperBound = *max_element(Delay, Delay + N - 1) * K;
	/*Time that we will be accepted*/
	long long Entry_Time = Bin_Search(Delay,N, 0, UpperBound,K);
	/*Number of the examiner that will examine us*/
	int Examiner_Number = find_Number(Delay, N, Entry_Time, K);
	/*Time that we'll finish our examination*/
	long long Finish_Time = Entry_Time + Delay[Examiner_Number];

	printf("%d %lld\n", Examiner_Number + 1, Finish_Time);
	return 0;
}
