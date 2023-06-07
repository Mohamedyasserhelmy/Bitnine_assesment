## Recurrence Relation Implementation in 3 different Ways 
Implementing the recurrence realtion defined as `F(0) = 0, F(1) = 1, F(2) = 2`
and the recursive case `F(n) = F(n-3) + F(n-2)`
#### Development Environment : 
- Compiler : GNU GCC Compiler 
- Code Editor : Code Blocks

#### 1- Recursive Approach  :
##### Advantages : 
- Simplicity : Code is easy to develop and understand just base case and recursive case .
- Readability : code is easy to read than iterative way , also some problems are recursive by nature .
##### Disadvantages :
- Complexity : O(2^n) which grows very fast according to n values .
- Memory Usage : Each recursive call requires additional memory usage on stack 
#### 2- Dynamic Programming Approach (Memoization) :
##### Advantages : 
- Improved Performance : O(n) because redundant values stored in `memo` array .
- Memory Efficient : storing values in array reduced memory usages instead of multiple function calls .
##### disadvantages :
- Space Complexity : Dynamic Programming uses more space in memory to store values O(n).
- Implementation Complexity : sometimes dynamic programming is hard to implement.
- Not a best solution for small inputs .
#### Dynamic Programming (Bottom Up Approach)
##### Advantages :
- Reduced Time Complexity O(n).
- Enhanced space Complexity O(1) beacuse we replaced array with variables.
##### disadvantages :
- Implementation Complexity .
- Not good for small inputs.
- difficulty in handling changes .
#### How to Run :
1- Make sure that you have already c compiler set up already and runs without errors. 
2-Navigate to the directory `Question2` where the c file is located .
3- Open Command Prompt .
4- Type the Following Command `gcc -o out question2_answer.c`
5- After you run this command you will have `out.exe` file .
6- run command `out.exe` 
