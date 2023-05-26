//Добавим необходимые заголовочные файлы
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
//получаем аргументы командной строки
    char *filename = argv[1];
    int page_length = 2;
    int line_length = 5;
    if(argc > 2)
    page_length = atoi(argv[2]);
    if(argc > 3)
    line_length = atoi(argv[3]);

//открываем файл и считываем его содержимое

    FILE *file;
    file = fopen(filename, "r");
    if(file == NULL) {
         printf("Error: cannot open file '%s'\n", filename);
    return 1;
    }
    char* line = NULL;
    size_t len = 0;
    size_t read;
    int line_count = 0;
    int page_count = 1;
    printf("- Page %d -\n", page_count);
    // выводим каждую страницу с номерами строк
    while((read = getline(&line, &len, file)) != -1) {
        line_count++;
        if(line_count > page_length) {
            page_count++;
            line_count = 1;
            printf("\n- Page %d -\n", page_count);
    }
        printf("%d: %.*s\n", line_count, line_length, line);
    }
    fclose(file);
    return 0;
    }
