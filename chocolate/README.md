## Chocolate

- **Problem Description** :

Uncle Scrooge wants to get into the chocolate business, as he believes it will be very profitable around Christmas. He 
collected enough information so that he is able to predict the price of chocolate for each of the next N days remaining until
Christmas. He has recorded the sequence of prices p[1], p[2], ..., p[n] and wants to find out when to sell in order to 
maximize his profit ! Every time he will buy and sell the same amount of chocolate, so he wants to maximize his profit per
tonne of chocolate. Because he doesn't want to raise suspicion, every purchase will be followed by a sale and he can only
make a maximum of K trades. We want to compute the maximum profit he can muster !


- **Input** :

First line is comprised of two numbers, N and K, which correspond to number of days remaining and maximum number of
trades. </br>
Second line is comprised of N numbers, the price p[i] of chocolate at the i-th day.


- **Output** :</br>

Maximum profit that can be achieved.

- **Constraints** :

1 <= N <= 10^5 </br>
1 <= K <= 10^3 </br>
1 <= p[i] <= 10^4 </br>
Time :  1 sec </br>
Memory :  64mb

**Examples** :

Input : </br>
10  3 </br>
12  12  7  10  15  8  3  4  8  8

Output: </br>
13


Input: </br>
5  2  </br>
10  9  8  7  6 

Output : </br>
0
