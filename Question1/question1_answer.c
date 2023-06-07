#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>

typedef enum TypeTag {Add, Sub, Mul, Div, Fibo, Leaf} TypeTag;

typedef struct Node
{
    long long int value;
    TypeTag identity;
    struct Node* left;
    struct Node* right;

} Node;
/// Assume that null nodes will be constructed with zero
// Struct Constructor
Node* constructor(long long value, TypeTag tag, Node* left, Node* right)
{
    Node* NewNode = (Node*) malloc(sizeof(Node));
    NewNode->value = value;
    NewNode->identity = tag;
    NewNode->left = left;
    NewNode->right = right;
    return NewNode;
}
// Fibonacci Sequence using Tabular(Bottom UP) Dynamic Programming
long long fib(unsigned int n)
{
    long long int *ptr =(long long int*) malloc((n+1)* sizeof(long long int));
    ptr[0] = 0;
    ptr[1] = 1;
    for (int i=2; i <= n; i++)
    {
        ptr[i] = ptr[i-1] + ptr[i-2];
    }
    return ptr[n];
}

// Adding Nodes
Node* addNodes(Node* left, Node* right)
{
    Node* result = NULL;
    if (left == NULL)
    {
        result = right;  // Marking the left node as zero
        return result;
    }
    if (left == NULL)
    {
        result = left;   // Marking right node as zero
        return result;
    }
    long long sum = left->value + right->value;
    result = constructor(sum, Add, left, right);
    return result;
}
// right_node - left_node
Node* subNodes(Node* left, Node* right)
{
    Node* result = NULL;
    if (left == NULL)
    {
        result = right;       // right_node - zero = right_node
        return right;
    }
    else if (right == NULL) // Fibonacci Case
    {
        int un_signed_int = abs(left->value);
        result = constructor(fib(un_signed_int-1), Fibo, left, right);
        return result;
    }
    long long sub = right->value - left->value;
    result = constructor(sub, Sub, left, right);
    return result;
}

Node* multNodes(Node* left, Node* right)
{
    Node* result = NULL;
    if (left == NULL || right == NULL)
    {
        result = constructor(0, Mul, left, right);
        return result;
    }
    else if (left == NULL)
    {
        result = right;
        return result;
    }
    else if (right == NULL)
    {
        result = left;
        return result;
    }
    long long multiplication = left->value * right->value;
    result = constructor(multiplication, Mul, left, right);
    return result;
}

// Following leftNode / RightNode
Node* DivNodes(Node* left, Node* right)
{
    Node* result = NULL;
    // if there is no left or right nodes (Reference to Null)
    if (left == NULL)
    {
        // 0 / x = 0
        result = constructor(0, Div, left, right);
        return result;
    }
    else if (right->value == 0 || right == NULL)
    {
        // Right Node refers to null
        printf("Cannot Divide by Zero !!");
        exit(1);
    }
    long long Division = left->value / right->value;
    result = constructor(Division, Div, left, right);
    return result;
}

Node* (*makeFuncNode(TypeTag op))(Node* , Node*)
{
    switch (op)
    {
    case Add:
        return &addNodes;
    case Sub:
        return &subNodes;
    case Mul:
        return &multNodes;
    case Div:
        return &DivNodes;
    default:
        printf("Error: Invalid operation.\n");
        return NULL;
    }
}

void calc(Node* answer)
{
    switch(answer->identity)
    {
    case Add:
        printf("add : %d\n", answer->value);
        return;
    case Sub:
        printf("sub : %d\n", answer->value);
        return;
    case Mul:
        printf("mul : %d\n", answer->value);
        return;
    case Div:
        printf("div : %d\n", answer->value);
        return;
    case Fibo:
        printf("fibo : %d\n", answer->value);
        return;
    default:
        printf("Invalid Node Value!");
        return;
    }

}

int main()
{
    Node* leaf_1 = constructor(10, Leaf, NULL, NULL);
    Node* leaf_2 = constructor(6, Leaf, NULL, NULL);
    Node* leaf_3 = constructor(5, Leaf, NULL, NULL);
    Node* leaf_4 = constructor(4, Leaf, NULL, NULL);

    Node* add = (*makeFuncNode(Add))(leaf_1,leaf_2);
    Node* mul = (*makeFuncNode(Mul))(leaf_3,leaf_4);
    Node* sub = (*makeFuncNode(Sub))(mul,add);
    Node* fibo = (*makeFuncNode(Sub))(sub,NULL);


    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);
    return 0;
}
