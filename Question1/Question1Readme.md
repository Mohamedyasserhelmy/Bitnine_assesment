## Arithmetic Operations Evaluation 
Evaluation of arithmetic operations (+,-,*,/) using Fibonacci Sequence and Tree Data Structure as defined :
`struct Node 
{
TypeTag type;
Node* Left;
Node* Right;
long long int value;     
}`
#### Development Environment : 
- Compiler : GNU GCC Compiler 
- Code Editor : Code Blocks

#### Explanation :
1- We can Construct Node using `Node* constructor(long long value, TypeTag tag, Node* left, Node* right)`

2- Each Node will be constructed using a `value `, `TypeTag`, `Left` and `right` nodes.

3- `NULL` Nodes will be treated as zero valued Nodes.

4- `addNodes, subNodes, multNodes and divNodes` functions are created to perform the operations .

5- `makeFunc` will call each operation based on node type.

6- Finally, `calc` function will print the output based on node type.

7- `fib` function is implemented using dynamic Programming .

#### How to Run :
1- Make sure that you have already c compiler set up already and runs without errors.  

2-Navigate to the directory where the c file is located .

3- Open Command Prompt .

4- Type the Following Command `gcc -o out question1_answer.c`

5- After you run this command you will have  `out.exe` file .

6- run command `out.exe` 
