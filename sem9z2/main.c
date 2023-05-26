#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>



int main(int argc, char *argv[]) {

setlocale(LC_ALL, "Rus");

    FILE *file1, *file2;
    char line1[100], line2[100];

  
    if (argc != 3) {
        printf("Usage: file1 file2");
        return 1;
    }

   
    file1 = fopen(argv[1], "r");
    file2 = fopen(argv[2], "r");

    
    while (fgets(line1, 100, file1) != NULL && fgets(line2, 100, file2) != NULL) {
        printf("%s%s", line1, line2); 
    }

    
    while (fgets(line1, 100, file1) != NULL) {
        printf("%s", line1); 
    }

    
    while (fgets(line2, 100, file2) != NULL) {
        printf("%s", line2); 
    }

   
    fclose(file1);
    fclose(file2);

    return EXIT_SUCCESS;
}




