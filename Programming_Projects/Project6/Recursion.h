#ifndef _Recursion_h
#define _Recursion_h 1

/*
 * DO NOT MODIFY THIS FILE
 */

int sumNums1(int[], int, int*);
int sumNums2(int[], int, int*);

int reverse(int, int, int*);
int knapsack(int[], int, int, int*);


typedef struct Record {
  int x_wins;
  int draws;
  int o_wins;
} Record;

Record tic_tac_toe(char[3][3], bool, int*);

typedef struct Node {
  char data;
  Node* next;
} Node;

Node* remove_nodes(Node*, char, int*);

typedef struct BinaryNode {
  int data;
  BinaryNode* left;
  BinaryNode* right;
} BinaryNode;

int least_weight_path(BinaryNode*, int*);

#endif // !_Recursion_h
