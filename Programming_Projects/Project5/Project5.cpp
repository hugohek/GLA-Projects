// Set <Project5.cpp>
// ECE 312 Project 5 submission by
// Favour Onafeso
// foo326
// Slip days used: <1>
// Fall 2023

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Set.h"

/*
 * Several of the required functions have been written already
 * You may use these functions as-is or you may modifya them in any way.
 * Please NOTE, you are responsible for ensuring that the functions work correctly in
 * your project solution. Just because the function works correctly in my solution does
 * NOT mean that the function will work correctly in yours.
 */

/*
 * Design NOTES:
 *
 * The design provided in this starter kit assumes
 * (1) empty sets will be represented with length == 0 and elements == nullptr (i.e., address 0)
 * (2) amortized doubling is not used, and capacity is ignored/unused. Functions should assume that
 * the amount of storage available in the elements[] array is equal to length
 */

/* done for you already */
void destroySet(Set *self)
{
    free(self->elements);
}

/* done for you already */
void createEmptySet(Set *self)
{
    self->len = 0;
    self->elements = nullptr;
}

/* done for you already */
void createSingletonSet(Set *self, int x)
{
    self->elements = (int *)malloc(sizeof(int));
    self->elements[0] = x;
    self->len = 1;
}

/* done for you already */
void createCopySet(Set *self, const Set *other)
{
    self->elements = (int *)malloc(other->len * sizeof(int));
    for (int k = 0; k < other->len; k += 1)
    {
        self->elements[k] = other->elements[k];
    }
    self->len = other->len;
}

/* done for you already */
void assignSet(Set *self, const Set *other)
{
    if (self == other)
    {
        return;
    }

    destroySet(self);
    createCopySet(self, other);
}

/* return true if x is an element of self */
bool isMemberSet(const Set *self, int x)
{
    int start = 0;
    int end = self->len - 1;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (x == self->elements[mid])
            return true;
        if (x < self->elements[mid])
        {
            end = mid - 1;
            continue;
        }
        else
            start = mid + 1;
    }
    return false;
}

/*
 * add x as a new member to this set.
 * If x is already a member, then self should not be changed
 * Be sure to restore the design invariant property that elemnts[] remains sorted
 * (yes, you can assume it is sorted when the function is called, that's what an invariant is all about)
 */
void insertSet(Set *self, int x)
{
    for (int i = 0; i < self->len; i++)
    {
        if (self->elements[i] == x)
        {
            return;
        }
    }
    if (isEmptySet(self))
    {
        self->len = 1;
        self->elements = (int *)malloc(sizeof(int));
        self->elements[0] = x;
        return;
    }
    self->elements = (int *)realloc(self->elements, sizeof(int) * (self->len + 1));
    self->elements[self->len] = x;
    // overwrite and swap
    for (int i = self->len - 1; i >= 0; i--)
    {
        if (self->elements[i] > x)
        {
            self->elements[i + 1] = self->elements[i];
            self->elements[i] = x;
        }
    }
    self->len++;
}

/*
 * don't forget: it is OK to try to remove an element
 * that is NOT in the set.
 * If 'x' is not in the set 'self', then
 * removeSet should do nothing (it's not an error)
 * Otherwise, ('x' IS in the set), remove x. Be sure to update self->length
 * It is not necessary (nor recommended) to call malloc -- if removing an element means the
 * array on the heap is "too big", that's almost certainly OK, and reallocating a smaller array
 * is almost definitely NOT worth the trouble
 */
void removeSet(Set *self, int x)
{
    if (self->len == 0)
    {
        return;
    }
    int idx = 0;
    while (self->elements[idx] != x && idx < self->len)
    {
        if (self->elements[idx] > x)
        {
            return;
        }
        idx++;
    }
    // at this point, idx is the index we want to remove
    for (int i = idx; i < self->len - 1; i++)
    {
        // overwrite previous element, scooting every element over
        self->elements[i] = self->elements[i + 1];
    }
    self->len--;
}

/* done for you already */
void displaySet(const Set *self)
{
    int k;

    printf("{");

    if (self->len == 0)
    {
        printf("}");
    }
    else
    {
        for (k = 0; k < self->len; k += 1)
        {
            if (k < self->len - 1)
            {
                printf("%d,", self->elements[k]);
            }
            else
            {
                printf("%d}", self->elements[k]);
            }
        }
    }
}

/* return true if self and other have exactly the same elements */
bool isEqualToSet(const Set *self, const Set *other)
{
    if (self->len != other->len)
    {
        return false;
    }

    for (int i = 0; i < self->len; i++)
    {
        if (self->elements[i] != other->elements[i])
        {
            return false;
        }
    }
    return true;
}

/* return true if every element of self is also an element of other */
bool isSubsetOf(const Set *self, const Set *other)
{
    // this time complexity is wrong fix it
    // edge case: empty set is subset of every set
    if (isEmptySet(self))
    {
        return true;
    }
    // edge case other cannot be empty
    if (isEmptySet(other))
    {
        return false;
    }
    // edge case if self is greater length than other
    if (self->len > other->len)
    {
        return false;
    }

    int i = 0;
    int j = 0;
    while (i < self->len && j < other->len)
    {
        if (self->elements[i] == other->elements[j])
        {
            i++;
        }
        j++;
    }
    return i == self->len;
}

/* done for you */
bool isEmptySet(const Set *self)
{
    return self->len == 0;
}

/* remove all elements from self that are not also elements of other */
void intersectFromSet(Set *self, const Set *other)
{
    // empty case
    if (isEmptySet(other) || isEmptySet(self))
    { // nothing to subtract
        destroySet(self);
        self->len = 0;
        self->elements = NULL;
        return;
    }

    int i = 0, j = 0, k = 0;
    int *arr = (int *)malloc(sizeof(int) * (self->len + other->len));
    int len = self->len;

    while (i < self->len && j < other->len)
    {
        if (self->elements[i] == other->elements[j])
        {
            arr[k] = self->elements[i];
            i++;
            j++;
            k++;
        }
        else if (self->elements[i] > other->elements[j])
        {
            j++;
        }
        else
        {
            i++;
            len--;
        }
    }
    destroySet(self);
    self->elements = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < k; i++)
    {
        self->elements[i] = arr[i];
    }
    self->len = k;
   free(arr);
}

/* remove all elements from self that are also elements of other */
void subtractFromSet(Set *self, const Set *other)
{
    int i = 0, j = 0, k = 0;

    // empty case
    if (isEmptySet(other) || isEmptySet(self))
    {
        // nothing to subtract
        return;
    }
    // edge case, subtract self with self
    if (isEqualToSet(self, other))
    {
        self->len = 0;
        free(self->elements);
        self->elements = nullptr;
        return;
    }

    int *arr = (int *)malloc(sizeof(int) * (self->len));

    while (i < self->len && j < other->len)
    { // what to do if smaller element in other is not in list but larger element is
        if (self->elements[i] > other->elements[j])
        {
            j++;
        }
        else if (self->elements[i] < other->elements[j])
        {
            arr[k] = self->elements[i];
            i++;
            k++;
        }
        else
        {
            j++;
            i++;
        }
    }
    while (i < self->len)
    {
        arr[k] = self->elements[i];
        k++;
        i++;
    }

    destroySet(self);
    self->elements = (int *)malloc(sizeof(int) * k);
    for (int l = 0; l < k; l++)
    {
        self->elements[l] = arr[l];
    }
    self->len = k;
    free(arr);
}

/* add all elements of other to self (obviously, without creating duplicate elements) */
void unionInSet(Set *self, const Set *other)
{
    int i = 0, j = 0, k = 0;
    // special case: if self is empty
    if (isEmptySet(self))
    {
       createCopySet(self, other);
        return;
    }
    int *merge = (int *)malloc(sizeof(int) * (self->len + other->len));

    while (i < self->len && j < other->len)
    {
        if (self->elements[i] < other->elements[j])
        {
            merge[k] = self->elements[i];
            k++;
            i++;
        }
        else if (self->elements[i] > other->elements[j])
        {
            merge[k] = other->elements[j];
            k++;
            j++;
        }
        else
        {
            // if self and other equal each other, just save one copy
            merge[k] = other->elements[j];
            k++;
            i++;
            j++;
        }
    }
    if (i == self->len)
    {
        while (j < other->len)
        {
            merge[k] = other->elements[j];
            j++;
            k++;
        }
    }
    else if (j == other->len)
    {
        while (i < self->len)
        {
            merge[k] = self->elements[i];
            i++;
            k++;
        }
    }
    destroySet(self);
    self->elements = (int *)realloc(merge, sizeof(int) * k);
    self->len = k;
}
