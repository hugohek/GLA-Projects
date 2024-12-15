#include "Recursion.h"
#include "story.h"
#include <stdio.h>
#include <stdlib.h>

int testIntro()
{
  int calls1 = 0, calls2 = 0;
  int shelf1[] = {1, 4, 0, 5, 6, 17, 12, 9, 15};
  int shelf2[] = {31, 4, 39, 58, 19, 47, 63, 91, 45, 1, 22};
  int magic1 = sumNums1(shelf1, 9, &calls1);
  int magic2 = sumNums2(shelf2, 11, &calls2);

  printf("The first magic number is: %d (calls: %d)\n", magic1, calls1);
  printf("The second magic number is: %d (calls: %d)\n\n", magic2, calls2);

  if (magic1 == 69 && magic2 == 420)
  {
    if ((calls1 >= 5 && calls1 <= 20) && (calls2 >= 10 && calls2 <= 40))
    {
      return 0;
    }
    else
    {
      return 2;
    }
  }
  else
  {
    return 1;
  }
}

bool testReverse()
{
  int dummy = 0;
  bool testReverse = 1;
  testReverse &= (reverse(17, 2, &dummy) == 71);
  testReverse &= (reverse(12345, 5, &dummy) == 54321);
  testReverse &= (reverse(3141, 4, &dummy) == 1413);
  testReverse &= (reverse(565656, 6, &dummy) == 656565);
  testReverse &= (reverse(101, 3, &dummy) == 101);
  testReverse &= (reverse(987654321, 9, &dummy) == 123456789);
  return testReverse;
}

bool testRemove()
{
  int dummy = 0;
  int testRemove = 1;
  Node *head = (Node *)malloc(sizeof(Node));
  head->data = 'P';
  head->next = NULL;
  Node *curr = head;
  for (int i = 1; i < 11; i++)
  {
    Node *next = (Node *)malloc(sizeof(Node));
    next->data = (char)(i + 'P');
    next->next = NULL;
    curr->next = next;
    curr = next;
  }
  head = remove_nodes(head, 'X', &dummy);
  int list_length = 0;
  curr = head;
  while (curr != NULL)
  {
    list_length++;
    testRemove &= (curr->data != 'X');
    curr = curr->next;
  }
  testRemove &= (list_length == 10);
  for (int i = 0; i < 8; i++)
  {
    head = remove_nodes(head, (char)(i + 'P'), &dummy);
  }
  list_length = 0;
  curr = head;
  while (curr != NULL)
  {
    list_length++;
    curr = curr->next;
  }
  testRemove &= (list_length == 2);
  head = remove_nodes(head, 'Y', &dummy);
  head = remove_nodes(head, 'Z', &dummy);
  head = remove_nodes(head, 'Z', &dummy);
  testRemove &= (head == NULL);
  return testRemove;
}

bool testWeight()
{
  int dummy = 0;
  int weights[] = {1, 5, 7, 9, 10, 11, 4, 3};
  bool testWeight = 1;
  testWeight &= (knapsack(weights, 8, 2, &dummy) == 1);
  testWeight &= (knapsack(weights, 8, 16, &dummy) == 16);
  testWeight &= (knapsack(weights, 8, 50, &dummy) == 50);
  testWeight &= (knapsack(weights, 8, 0, &dummy) == 0);
  testWeight &= (knapsack(weights, 8, 1000, &dummy) == 50);
  return testWeight;
}

bool testTree()
{
  int calls = 0;
  BinaryNode a = {5, NULL, NULL};

  BinaryNode b = {10, NULL, NULL};
  BinaryNode c = {2, NULL, NULL};
  a.left = &b;
  a.right = &c;

  BinaryNode d = {500, NULL, NULL};
  BinaryNode e = {15, NULL, NULL};
  b.left = &d;
  b.right = &e;

  BinaryNode f = {1, NULL, NULL};
  BinaryNode g = {20, NULL, NULL};
  c.left = &f;
  c.right = &g;

  BinaryNode h = {14, NULL, NULL};
  e.left = &h;

  BinaryNode i = {11, NULL, NULL};
  g.left = &i;

  BinaryNode j = {3, NULL, NULL};
  i.left = &j;

  int test = least_weight_path(&a, &calls);
  return test == 8;
}

void print_board1(char board[3][3])
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

void playGame(int calls)
{
  char board[3][3] = {{'O', ' ', 'X'},
                      {'O', ' ', 'X'},
                      {'X', 'O', ' '}};
  // print_board(board);

  calls += 1;
  // Start the game, alternating starting player
  Record result_from_X = tic_tac_toe(board, true, &calls);
  //Record result_from_O = tic_tac_toe(board, false, &calls);

  printf("X has %d possible wins\n", result_from_X.x_wins);
  printf("O has %d possible wins\n", result_from_X.o_wins);
  printf("There are %d draws\n", result_from_X.draws);
  printf("Total function calls: %d\n", calls);
  /*printf("X has %d possible wins\n", result_from_X.x_wins);
  printf("O has %d possible wins\n", result_from_X.o_wins + result_from_O.o_wins);
  printf("There are %d draws\n", result_from_X.draws);
  printf("Total function calls: %d\n", calls);*/
}

int main(void)
{
  /*PrintIntro();
   PrintTutorial();

   int intro = testIntro();
   if (intro == 0)
   {
     PrintTutorialSumSuccess();
   }
   else if (intro == 1)
   {
     PrintTutorialSumFailValue();
     return 0;
   }
   else
   {
     PrintTutorialSumFailCount();
     return 0;
   }

   PrintChapterOne();
   int reverse = testReverse();
   if (!reverse)
   {
     PrintReverseFail();
     return 0;
   }
   else
   {
     PrintReverseSuccess();
   }

   PrintChapterTwo();
   int remove = testRemove();
   if (!remove)
   {
     PrintRemoveFail();
     return 0;
   }
   else
   {
     PrintRemoveSuccess();
   }

   PrintChapterThree();
   int weight = testWeight();
   if (!weight)
   {
     PrintWeightFail();
     return 0;
   }
   else
   {
     PrintWeightSuccess();
   }

   PrintChapterFour();
   int tree = testTree();
   if (!tree)
   {
     PrintTreeFail();
     return 0;
   }
   else
   {
     PrintTreeSuccess();
   }

   PrintConclusion();*/
  int tic_calls = 0;
  playGame(tic_calls);

  return 0;
}
