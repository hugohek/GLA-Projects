// Queue ADT demonstration file main.cpp
#include "UTQueue.h"
#include <stdio.h>
#include <stdlib.h>

void testStage1(void) {
  const int dataOne[] = {1, 2, 3, 4, 5, 6};
  UTQueue *queueOne = utqueuedup(dataOne, 6);
  printf("Orignal: \n");
  utqueueprint(queueOne);

  // utqueuefree(queueOne);
  // utqueueprint(queueOne); // Bad things can happen here if trying to read
  // from freed memory
  printf("\n Result add 7: \n");
  queueOne = utqueuepush(queueOne, 7);
  utqueueprint(queueOne);

  printf("Result remove 1st 0th element: \n");
  int valueOne = utqueuepop(queueOne);
  utqueueprint(queueOne);

  
  printf("Result reverse array: \n");
  queueOne = utqueuerev(queueOne);
  utqueueprint(queueOne);

  const int dataTwo[] = {3, 4, 5, 6, 7};
  UTQueue *queueTwo = utqueuedup(dataTwo, 5);
  utqueueprint(queueTwo);


  printf("Result : \n");
  queueOne = utqueuecombine(queueOne, queueTwo);
  // utqueueprint(queueTwo); // bad things can also happen here because combine
  // should free queuetwo
  utqueueprint(queueOne);

  const int dataThree[] = {1, 1, 1, 1, 1};
  UTQueue *queueThree = utqueuedup(dataThree, 5);
  utqueueprint(queueThree);

  printf("Queue one: ");
  utqueueprint(queueOne);
  printf("Queue two: ");
  utqueueprint(queueThree);
  printf("swapping\n");
  utqueueswap(queueOne, queueThree);
  printf("Queue one: ");
  utqueueprint(queueOne);
  printf("Queue two: ");
  utqueueprint(queueThree);
  
  printf("\nResult copy src [0, 1, 2, 3] into queueOne\n");
  const int copyOne[] = {};
  queueOne = utqueuecpy(queueOne, copyOne, 4);
  utqueueprint(queueOne);

  const int copyTwo[] = {5, 80, 200, 11111, 42, 21};
  queueOne = utqueuecpy(queueOne, copyTwo, 6);
  utqueueprint(queueOne);

  utqueuefree(queueOne);
  utqueuefree(queueThree);
}

int main(void) {
  testStage1();
  return 0;
}
