#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * iptr, * outptr;
char record[100];
char starting_address[100];
int recordpointer;
void writetooutputfile();
int main() {
  iptr = fopen("absloaderinput.txt", "r");
  outptr = fopen("outputfile.txt", "w");
  if (iptr == NULL) {
    printf("file not open");
  }
  fgets(record, sizeof(record) / sizeof(char), iptr);
  while (record[0] != 'E') {
    if (record[0] == 'T') {
      strncpy(starting_address, record + (2), 6);
      recordpointer = 12;
      writetooutputfile();
    }
    fgets(record, sizeof(record) / sizeof(char), iptr);
  }
  fclose(iptr);
  fclose(outptr);
  printf("absolute loader has executed successfully\nopen outputfile.txt to see the output");
  return 0;
}

void writetooutputfile() {
  char objectcode[20];
  int address;
  address = strtol(starting_address, NULL, 16);
  while (record[recordpointer] != '\0') {
    fprintf(outptr, "%x\t",address);
      strncpy(objectcode, record + (recordpointer), 6);
      fprintf(outptr, "%s\n", objectcode);
      recordpointer += 7;
      address+=3;
    if (record[recordpointer] == '^') {
      recordpointer++;
    }
  }

}
