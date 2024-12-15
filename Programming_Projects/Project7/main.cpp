#include "UTString.h"
#include <stdio.h>
#include <stdio.h>  // declarations of FILE and printf
#include <stdlib.h> // includes declaration of exit()
#include <string>
// #include "MemHeap.h"

#include "CustomerDB.h"
/*
struct CheckMemoryLeaks {
    ~CheckMemoryLeaks(void) {
        if (! isSaneHeap()) {
            printf("oh goodness! you've corrupted the heap, naughty naughty\n");
            return;
        }
        if (! isEmptyHeap()) {
            printf("Uh Oh! you have a memory leak somewhere, better find it\n");
            return;
        } printf("The heap is all clean, good work!\n");
    }
} MemoryChecker;
*/
FILE *input_stream;
UTString inventory_cmd_name = UTString("Inventory");
UTString purchase_cmd_name = UTString("Purchase");
UTString return_cmd_name = UTString("Return");
UTString summarize_cmd_name = UTString("Summarize");
UTString quit_cmd_name = UTString("Quit");

void readNum(int &x) {
  int val;
  fscanf(input_stream, "%d", &val);
  x = val;
}

void readString(UTString &x) {
  char buff[BUFSIZ];
  fscanf(input_stream, "%s", buff);
  x = UTString(buff);
}

void displayTailAndClose() {
  char *rval;
  char buff[BUFSIZ];

  rval = fgets(buff, BUFSIZ, input_stream);
  while (rval != 0) {
    printf(buff);
    rval = fgets(buff, BUFSIZ, input_stream);
  }
  fclose(input_stream);
}

void readInput(const char *file_name) {
  UTString next_command;
  bool all_done = false;

  /* open the file */
  input_stream = fopen(file_name, "r");
  if (input_stream == 0) {
    printf("sorry, I could not open %s for reading\n", file_name);
    exit(-1);
  }

  /* main loop, read commands from input file */
  do {
    readString(next_command);
    if (next_command == inventory_cmd_name) {
      processInventory();
    } else if (next_command == purchase_cmd_name) {
      processPurchase();
    } else if (next_command == return_cmd_name) {
      processReturn();
    } else if (next_command == summarize_cmd_name) {
      processSummarize();
    } else if (next_command == quit_cmd_name) {
      all_done = true;
    } else {
      printf("Encountered an error in input file\n");
      printf("The offending line has been ignored\n");
    }
  } while (!all_done);

  displayTailAndClose();
}

int main(void) {
  readInput("test_extra1.txt");
  reset();
  readInput("test_extra2.txt");
  reset();
  readInput("test_extra3.txt");
  reset();
  readInput("test_extra4.txt");
  reset();
  readInput("test_extra5.txt");
  reset();
  return 0;
}
