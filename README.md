# Hill Climbing Algorithm

The Hill Climbing Algorithm is a simple heuristic method which simulates the behavior of human beings during mountain climbing.

Pros:
1. More efficient than Exhaustive Search, due to the avoidance of overall search.

Cons:
1. High chance of being stuck in local optima.

# One-max problem

The one-max problem is a basic problem.

Given a bit string of  0's and 1's, the aim is to find a bit string which contains the most 1's.

# Usage

Open terminal

        make
        
1. Run directly in the terminal by typing the following:

        #./main [algo] [runs] [iter] [bits] [filename]
        ./main hc 30 20000 100 ""
    
2. Or if you want to run multiple times, just by opening the "search.sh" and add whatever you want and run by typing

        ./search.sh
in the terminal.

# Customize

You can change the iteration block by modifying 

        const int block=100;
in "execute.hpp".

# Results

As you can see from the following image, due to the random point initialization of Hill Climbing Algorithm, it has a better starting point than Exhuastive Search.

However, in this problem, Hill Climbing Algorithm got stuck in a local optimum in early iterations.

![alt text](https://github.com/MarttiWu/hill-climbing-one-max/blob/master/HC_one_max.png)

