# Traveling-Salesman

![image](https://user-images.githubusercontent.com/89245846/223502017-cb72eeab-2507-4dc8-8188-fee4ec9265aa.png)

  The Traveling Salesperson Problem
The input to the problem is a collection of n points in the plane. The points have int values.
The goal of the traveling salesperson problem is to find the shortest path that visits every point exactly once and returns to the starting point. That is, we are looking for a cycle in the graph that visits each vertex exactly once, such that the total length is as small as possible.

   <img width="588" alt="Screenshot 2023-03-07 at 9 28 30 AM" src="https://user-images.githubusercontent.com/89245846/223501588-80196599-23d6-4499-b8a9-73fe962a416c.png">

For example, suppose the input is the 4 points
A=(2,2), B=(2,6), C=(5,6),D=(5,9)
Then we may consider each of the following cycles through the 4 points.
  - The length of the cycle on the left ABCD (and back to A) is dist(A,B)+dist(B,C)+dist(C,D)+dist(D,A) = 4 + 3 + 3 + 32 + 72 ≈ 17. 616
- The length of the cycle in the middle ACDB (and back to A) is dist(A,C)+dist(C,D)+dist(D,B)+dist(B,A) = 32 + 42 + 3 + 32 + 32 + 4 ≈ 16. 243
- The length of the cycle on the right ACBD (and back to A) is dist(A,C)+dist(C,B)+dist(B,D)+dist(D,A) = 32 + 42 + 3 + 32 + 32 + 32 + 72 ≈ 19. 858
That is, among these three cycles, the better one is ACDB, whose length is 16.243... In fact, this is the optimal solution for this input.
You will need to design your own classes in C++ to implement a solver for this problem.
      
      
Storing the points:
A class that stores a collection of points. 
Print the list of points:

A = (2,2)
B = (2,6)
C = (5,6)
D = (5,9)

Drawing the points:

-----------
--------D--
-----------
-----------
--B----C--
-----------
-----------
-----------
--A-------
-----------
-----------

TSPSolver:
A heuristic algorithm that finds a solution to the TSP problem. 
main():
Tests (1) provide inputs to the problem (2) print the list using the printList method (3) draw the points (4) run the solver and output the obtained solution: you need to print to screen both the order of the vertices in the cycle and the total length of the cycle.
       
TSP solver

Smallest increase heuristic:

* The input is a list L[0...n-1] of n≥3 points.
* The algorithm starts with the cycle consisting of only the points L[0], L[1], L[2].
* In the first iteration the algorithm takes the point L[3], and adds it to the current cycle in the
location that minimizes the increase in the length.
* In the second iteration the algorithm takes the point L[4], and adds it to the current cycle in
the location that minimizes the increase in the length.
* And so on. When adding the point L[i], we add it to the cycle between C[j] and C[j+1] so
that dist(C[j],L[i]) + dist(L[i],C[j+1]) - dist(C[j+1],C[j]) is minimized.

Example:
Consider the example above with 4 points, and suppose that the list is [C,B,D,A].
1. We start with the cycle consisting of the points C,B,D.
2. In the first iteration, we choose where to add A to the cycle.
➢ IfweaddAbetweenCandB,thentheincreasewillbe dist(C,A) +dist(A,B) - dist(B,C) = 32 + 42 + 4 − 3 = 6
➢ IfweaddAbetweenBandD,thentheincreasewillbe
dist(B,A) +dist(A,D) - dist(D,B) = 4 + 32 + 72 − 32 + 32 = 7. 3731...
➢ IfweaddAbetweenDandC,thentheincreasewillbe
dist(D,A) +dist(A,C) - dist(C,D) = 32 + 72 + 32 + 42 − 3 = 9. 6157...
3. Therefore, it is best to add A between C and B.
4. The resulting cycle will be CABD (and back to C)
