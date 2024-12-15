// ECE 312 PA1
// <Favour Onafeso>
// <foo326>
// Slip days used: 0
// Spring 2023
// Santacruz

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_WORDS 100

int isSpace(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

int strlen(char *word)
{
    int length = 0;
    while (word[length] != '\0')
    {
        length++;
    }
    return length;
}

/*
    Wring a function to sort the words in 'words[]' and then print them to the console.
*/
void printSortedWords(char words[])
{
    // TODO: Your code here
    int k = 0; // LOOP INDEX
    int currIndex = 0, endIndex = 0, len = strlen(words);

    // char whtSpace[] = {' ', '\t', '\n', '\0'};
    char *sort[MAX_WORDS];
    int cnt[MAX_WORDS] = {0};

    // printf("Length: %d\n", len);
    // current and endInex have to be less that the length of array.
    while (currIndex < len && words[currIndex] != '\0')
    {
        // first valid char of word
        while (currIndex < len && isSpace(words[currIndex]))
        {
            currIndex++;
        }

        if (currIndex >= len)
            break;
        // sort[k] = &words[currIndex]; // store pointer
        // k++;
       

        // Find the ending index of the current word
        endIndex = currIndex;
        while (endIndex < len && !isSpace(words[endIndex])) // if this is isSpace then take the last index
        {
            endIndex++;
        }
         // make memmory
        int wrdlen = endIndex - currIndex;
        sort[k] = (char *)malloc(wrdlen + sizeof(char));

        // Copy the word character by character
        for (int i = 0; i < wrdlen; i++)
        {
            sort[k][i] = words[currIndex + i]; // sort[0][0] = words -> apple
        }
        sort[k][wrdlen] = '\0'; // add null  //sort[0][5] = '\0' -> apple\0
        k++;

        currIndex = endIndex; // next word
    }
    for (int a = 0; a < k-1; a++){
        for (int b = a + 1; b < k; b++){
            int c = 0;
            //  if (strcmp(sort[a], sort[b]) > 0) // check how strcmp works? if a > b rtrn > 0 or a < b rtrn < 0
            while ((sort[a][c] == sort[b][c]) && (sort[a][c] != '\0' && sort[b][c] != '\0'))
            {
                c++;
            }
            if (sort[a][c] > sort[b][c]){
                char *temp = sort[a];
                sort[a] = sort[b];
                sort[b] = temp;
            }
          //only print(duplicate count) item
        }
    }
    //count duplicates
     /*for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            int p = 0;
            while (sort[i][p] == sort[j][p] && sort[i][p] != '\0') {
                p++;
            }
            if (sort[i][p] == sort[j][p]) {
                cnt[i]++;
            }
        }
    }*/
    // printf("%s\n", sort[0]);
    for (int i = 0; i < k; i++){ // print sorted words
        printf("%s\n", sort[i]);
        free(sort[i]);
    }
    //   free(sort); keep getting error
}

