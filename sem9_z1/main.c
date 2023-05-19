#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void tail(char *filename, int n);

int main(int argc, char *argv[]) {
if(argc < 2) {
printf("Usage: %s filename [n]\n", argv[0]);
exit(EXIT_FAILURE);
}


char *filename = argv[1];
int n = 5;

if(argc >= 3) {
    n = atoi(argv[2]);
}

tail(filename, n);

return 0;
}

void tail(char *filename, int n) {
FILE *file = fopen(filename, "r");


if(file == NULL) {
    printf("Error opening file %s\n", filename);
    exit(EXIT_FAILURE);
}

char lines[n][MAX_LINE_LENGTH];
int current_line = 0;

while(fgets(lines[current_line % n], MAX_LINE_LENGTH, file) != NULL) {
    current_line++;
}

int i;
int start = current_line - n;
if(start < 0) {
    start = 0;
}

for(i = start; i < current_line; i++) {
    printf("%s", lines[i % n]);
}

fclose(file);
}

