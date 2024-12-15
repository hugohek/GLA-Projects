#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define ONE_MB (1 << 20)
#define BUFFER_SIZE ONE_MB

char words[BUFFER_SIZE];

void printSortedWords(char words[]); // This is the function you write

void readFile(const char file_name[], char buffer[]) {
    FILE *file = fopen(file_name, "r");
    if (file == 0)
    {
        printf("unable to open file \"%s\"\n", file_name);
        abort();
    }

    for (uint32_t k = 0; k < BUFFER_SIZE; k += 1)
    {
        buffer[k] = 0;
    }

    uint32_t bytes_read = fread(buffer, 1, BUFFER_SIZE, file);
    buffer[bytes_read] = 0;
}

void simpleTest(void) {
    printf("******* Starting Base Test #1 (simpleTest) *******\n");
    char words[] = "make Me an alibi ";
    printSortedWords(words);
    printf("****DONE****\n");
}

void generalTest(void) {
    printf("\n\n******* Starting Base Test #2 (generalTest) *******\n");
    readFile("input.txt", words);
    printSortedWords(words);
    printf("****DONE****\n");
}

int main(void) {
    simpleTest();
    generalTest();
}

