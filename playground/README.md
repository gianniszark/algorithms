## Playground

- **Problem Description** :

The mayor of SquareTown decided to keep his election promise and build a playground inside the town park. The park can be 
modeled as a N x N grid and the playground as a rectangle inside the park, given by two pairs of natural numbers, (a,b) for
the upper left corner of the playground and (c,d) for the bottom right, with 1 <= a <= N and 1 <= b <= d <= N. In the park
there are trees and each square of the N x N grid either contains a tree ( marked by "1" ), or contains no trees ( marked
by "0"). We want to build our playground so that it contains exactly K trees. Our goal is to compute the number of different
ways we can build our playground.


- **Input** :

First line is comprised of two numbers, N and K. </br>
Next N lines are comprised of N numbers, "1" if the corresponding square in the park contains a tree or "0" if it doesn't.


- **Output** :

Number of different rectangles in which we can build our playground, so that it contains exactly K trees.

- **Constraints** :

2 <= N <= 700 </br>
1 <= K <= 6 </br>
Time :  2 sec </br>
Memory :  64mb

**Example** :

Input : </br>
3  1 </br>
001 </br>
010 </br>
000

Output: </br>
17
