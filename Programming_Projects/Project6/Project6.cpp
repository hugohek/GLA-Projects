#include "Recursion.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Return the sum of the elements in array x[]
 * there are n elements in x[] (x[0].. x[n-1])
 * solve the problem recursively and
 * use an "n-1" type of decomposition
 *
 * NOTE: This function will NOT be graded and is merely provided for practice.
 */
int sumNums1(int x[], int n, int *calls)
{
  *calls += 1;
  // TODO: Your code here
  if (n == 0)
    return 0;
  // if(n -1 < *calls) sumNums1(x[], n-1, *calls);
  return x[n - 1] + sumNums1(x, n - 1, calls);
}

/*
 * Return the sum of the elements in array x[]
 * there are n elements in x[] (x[0].. x[n-1])
 * n may be either odd or even
 * solve the problem recursively and
 * use an "n/2" type of decomposition
 *
 * NOTE: This function will NOT be graded and is merely provided for practice.
 */
int sumNums2(int x[], int n, int *calls)
{
  *calls += 1;
  // TODO: Your code here
  // Base case: If there is zero element and if theres only one element return 1.
  if (n == 0)
  {
    return 0;
  }
  else if (n == 1)
  {
    return x[0];
  }

  int mid = n / 2;
  // find sum of left side + right side
  return sumNums2(x, mid, calls) + sumNums2(x + mid, n - mid, calls);
}

/*
 * Write a recursive function that revereses a positive n-digit integer x.
 * For example, if x = 12345, the function should return 54321.
 * Hint: use pow() from math.h
 */
int reverse(int x, int n, int *calls)
{
  *calls += 1;
  // TODO: Your code here
  if (n == 0)
    return 0;
  int lastDigit = x % 10;
  int remainder = x / 10;

  return lastDigit * pow(10, n - 1) + reverse(remainder, n - 1, calls);
}

/*
 * Given a linked list, remove all nodes that contain the character val
 * Don't forget to free memory for any nodes you remove
 */
Node *remove_nodes(Node *head, char val, int *calls)
{
  *calls += 1;
  // TODO: Your code here
  // Base case: if the list is empty, return NULL
  if (head == NULL)
  {
    return NULL;
  }

  // Recursive case
  head->next = remove_nodes(head->next, val, calls);

  // Check if the current node needs to be removed
  if (head->data == val)
  {
    Node *temp = head->next;
    free(head);  // Free the node
    return temp; // Return the next node to link it to the previous node
  }
  else
  {
    return head; // Return the current node if it doesn't match val
  }

  return head;
}

/* You are given a list of item weights that represent the weight of the ith
 * index item You are also given a maximum weight that your bag can hold.
 * Return the total weight of the subset of items that maximize the total weight
 * of the bag without going over the maximum weight
 */
int knapsack(int weights[], int n, int max_weight, int *calls)
{
  *calls += 1;
  // TODO: Your code here
  // Base cases
  if (n == 0 || max_weight == 0)
  {
    return 0;
  }

  // If nth item weight is more than max_weight
  if (weights[n - 1] > max_weight)
  {
    return knapsack(weights, n - 1, max_weight, calls);
  }
  else
  {
    int item_in_bag = weights[n - 1] + knapsack(weights, n - 1, max_weight - weights[n - 1], calls);
    int item_notIn_bag = knapsack(weights, n - 1, max_weight, calls);
    return item_in_bag > item_notIn_bag ? item_in_bag : item_notIn_bag;
  }
  return 0;
}

// Given a binary tree, return the weight of the least weight path (the path
// with the smallest sum of node values)
int least_weight_path(BinaryNode *root, int *calls)
{
  *calls += 1;
  // TODO: Your code here
  // Base case:
  if (root == NULL)
  {
    return -1;
  }
  // Base case: if it's a leaf node, return its value
  if (root->left == NULL && root->right == NULL)
  {
    return root->data;
  }

  // Recursive case
  int left_min = least_weight_path(root->left, calls);
  int right_min = least_weight_path(root->right, calls);

  return root->data + (left_min < right_min ? left_min : right_min);
  // return 0;
}

bool is_win(char board[3][3], char player)
{
  // (Optional but recommended) TODO: Your code here
  // check row
  for (int i = 0; i < 3; i++)
  {
    if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
        (board[0][i] == player && board[1][i] == player && board[2][i] == player))
    {
      return true;
    }
  }

  // check diagonals
  return ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
          (board[0][2] == player && board[1][1] == player && board[2][0] == player));
}

/*
 * Given a tic-tac-toe board, return a Record struct that contains the number of
 * ways that X can win, the number of ways that O can win, and the number of
 * draws from the current board position.
 * The possible values of the board are 'X', 'O', and ' ' (space character for empty)
 */
bool is_full(char board[3][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (board[i][j] == ' ')
      {
        return false;
      }
    }
  }
  return true;
}

void print_board(char board[3][3])
{
  printf("\nCurrent board:\n");
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf(" %c ", board[i][j] == ' ' ? ' ' : board[i][j]);
      if (j < 2)
        printf("|");
    }
    printf("\n");
    if (i < 2)
      printf("---+---+---\n");
  }
  printf("\n");
}

Record tic_tac_toe(char board[3][3], bool is_x_turn, int *calls)
{
  *calls += 1;
  // TODO: Your code here
  Record result = {0, 0, 0};
  // print_board(board);

  // Check win
  if (is_win(board, 'X'))
  {
    result.x_wins++;
    return result;
  }
  if (is_win(board, 'O'))
  {
    result.o_wins++;
    return result;
  }
  if (is_full(board))
  {
    result.draws++;
    return result;
  }

  // Determine the current player based on the number of moves
  int x_count = 0, o_count = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (board[i][j] == 'X')
      {
        x_count++;
      }
      else if (board[i][j] == 'O')
      {
        o_count++;
      }
    }
  }

  char current_player = (x_count <= o_count) ? 'X' : 'O';
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (board[i][j] == ' ')
      {
        board[i][j] = current_player;
        Record outcome = tic_tac_toe(board, !is_x_turn, calls);

        result.x_wins += outcome.x_wins;
        result.o_wins += outcome.o_wins;
        result.draws += outcome.draws;
        // backtrack
        board[i][j] = ' ';
      }
    }
  }
  return result;
}
