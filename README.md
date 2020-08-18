# Hill Climbing Algorithm

The Hill Climbing Algorithm is a simple heuristic method which simulates the behavior of human beings during mountain climbing.

Pros:
1. More efficient than Exhaustive Search, due to the avoidance of overall search.

Cons:
1. High chance being stuck in local optima.

# One-max problem

The one-max problem is a basic problem.

Given a bit string of  0's and 1's, the aim is to find a bit string which contains the most 1's.

# Usage

        make
1. Run directly in the terminal by typing the following:

        #./main [algo] [runs] [iter] [bits] [filename]
        ./main es 30 20000 100 ""
    
2. Or if you want to run multiple times, just by opening the search.sh and add whatever you want to run.  

# Customize

You can change the iteration block by modifying 

        const int block=100;
in "execute.h".

# Results

![alt text]()

