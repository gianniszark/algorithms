## Examination

- **Problem Description** :

In our chemical lab, there are N dangerous substances, chemical waste from our experiments, that must be place in K 
metallic tanks for transportation. Substances are numbered from 1 to N and for safety reasons must be placed in tanks
in that order. Tanks are big enough in order to not have storage issues (all substances can fit in a tank). There is, however, 
the danger of chemical reaction between the substances. More specifically, for a pair of substances, i and j, the amount of
energy release from their reaction will be A[i][j]. The procedure for filling the tanks is the following: </br>
Substances 1, ..., t(1) are placed in tank 1, substances t(1) + 1, ..., t(2) are placed in tank 2 and so on until all substances
are placed inside the K tanks. The total energy of a tank is equal to: </br>
sum for all {i,j} where t(i) <= i <= j <= t(i+1) of A[i][j] </br>
We want to calculate the least possible amount of energy for all tanks.


- **Input** :

First line is comprised of two numbers, N and K, corresponding to the number of substances and number of tanks. </br>
Next N-1 lines where i-th line contains N-i integers. The j-th element of the i-th line corresponds to the energy
A[i][j+i] (A is symmetric).  


- **Output** :

Minimum amount of total energy that can be achieved.

- **Constraints** :

1 <= K <= 700 </br>
K <= N <= 2500 </br>
1 <= A[i][j] <= 99 </br>
Time :  1 sec </br>
Memory :  64mb

**Example** :

Input : </br>
3   2 </br>
3  2
4

Output: </br>
3
