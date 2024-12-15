/**
 * NAME: Favour Onafeso
 * EID: foo326
 * Spring 2024
 * Santacruz
 */

#include "UTQueue.h"
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * ALREADY DONE FOR YOU
 * Prints the passed in queue to make it easy to visualize.
 */
void utqueueprint(UTQueue *src)
{
  printf("[");
  for (int i = 0; i < src->size - 1; i++)
    printf("%d, ", src->data[i]);
  printf("%d]\n", src->data[src->size - 1]);
}

/*
 * Allocate a UTQueue on the heap.
 * The size of the input array is n.
 * Initialize the queue correctly by copying src
 * Return a pointer to the newly created UTQueue.
 *
 * typedef struct UTQueue {
    uint32_t size;
    int *data;
  } UTQueue;
 */
UTQueue *utqueuedup(const int *src, int n)
{
  if (src == NULL)
    return NULL;
  UTQueue *queue = (UTQueue *)malloc(sizeof(UTQueue));

  queue->size = n;
  queue->data = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++)
  {
    queue->data[i] = src[i];
  }
  return queue;
}

/*
 * Free all memory associated with the given UTQueue.
 */
void utqueuefree(UTQueue *self)
{
  if (self != NULL)
  {
    free(self->data); // free array first then free self
    free(self);
  }
}
/*
 * Push (enqueue) an integer "value" into the queue.
 */
UTQueue *utqueuepush(UTQueue *src, int value)
{
  /*  Increase size by 1
   *   put new int at the end
   */

  src->data = (int *)realloc(src->data, sizeof(int) * (src->size + 1));
  src->data[src->size] = value;
  src->size += 1;
  return src;
}

/*
 * Pop (dequeue) an element from the queue
 * should fail an assertion if the queue is empty
 */
int utqueuepop(UTQueue *src)
{
  assert(src->size != 0); // change false to make this assertion fail only if src has 0
                          // elements.
  int pop = src->data[0];
  for (int i = 0; i < src->size - 1; i++)
  {
    src->data[i] = src->data[i + 1];
  }
  // resize size by 1
  src->size -= 1;
  src->data = (int *)realloc(src->data, src->size * sizeof(int)); // realloc if zero do

  return pop;
}

/*
 * Reverses the queue in src.
 */
UTQueue *utqueuerev(UTQueue *src)
{
  if (src->size != 0)
  {
    int temp = 0, front = 0, back = src->size - 1;
    //[1, 2, 3, 4, 5] -> [5, 4, 3, 2, 1]
    while (front < back)
    {
      temp = src->data[front];
      src->data[front] = src->data[back]; //[1, 2 ...] ->[5, 2 ...]
      src->data[back] = temp;             //[1, 2 ... 5] -> [5, 2 ... 1]
      front++;
      back--;
      /*  [5, 2 ... 1] -> [5, 4, ... 2, 1]
          [5, 4, 3, 2, 1] -> [5, 4, 3, 2, 1]
      */
    }
  }
  return src;
}

/*
 * combines the elements of UTQueues dst and src INTO dst.
 * src should be deleted after the combination
 */
UTQueue *utqueuecombine(UTQueue *dst, UTQueue *src)
{
  //check fro NULL
  //if(dst == NULL) return src;
  if (src == NULL) return dst;

  int oldSize = dst->size;
  dst->size += src->size;
  dst->data = (int *)realloc(dst->data, dst->size * sizeof(int));
  for (int i = 0; i < src->size; i++)
  {
    dst->data[oldSize + i] = src->data[i];
  }
  utqueuefree(src);
  return dst;
}

/*
 * Swap the two queues.
 * q1 should "have" the contents of q2 and vice verse.
 * There is more than one way to do this
 */
void utqueueswap(UTQueue *q1, UTQueue *q2)
{
  int tempSize = q1->size;
  int *tempData = q1->data;

  q1->size = q2->size;
  q1->data = q2->data;

  q2->size = tempSize;
  q2->data = tempData;
}

/*
 * Copy values from src array into dst.
 * Assume dst is a valid UTQueue.
 * src is an array of numbers.
 * Do not allocate any additional storage: only copy as many numbers
 * as will actually fit into the current UTQueue dst.
 * If all of src can fit into dst, leave the remaining ints in dst.
 * return the pointer to dst with the changes.
 */
UTQueue *utqueuecpy(UTQueue *dst, const int *src, int n)
{
  if(dst == NULL || dst->size == 0 || n == 0 ) return dst;
  int limit = (n < dst->size) ? n : dst->size;

  for (int i = 0; i < limit; i++)
  {
    dst->data[i] = src[i];
  }
  return dst;
}
