#ifndef UTQUEUE_H
#define UTQUEUE_H 1

#include <stdint.h>

typedef struct UTQueue {
  uint32_t size;
  int *data;
} UTQueue;

void utqueueprint(UTQueue *src);

UTQueue *utqueuedup(const int *src, int n);

void utqueuefree(UTQueue *self);

UTQueue *utqueuepush(UTQueue *src, int value);

int utqueuepop(UTQueue *src);

UTQueue *utqueuerev(UTQueue *src);

UTQueue *utqueuecombine(UTQueue *dst, UTQueue *src);

void utqueueswap(UTQueue *q1, UTQueue *q2);

UTQueue *utqueuecpy(UTQueue *dst, const int *src, int n);

#endif // !UTQUEUE_H
