#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>



int main(int argc, char *argv[]) {

setlocale(LC_ALL, "Rus");

    FILE *file1, *file2;
    char line1[100], line2[100];

    // проверяем, переданны ли аргументы с именами файлов
    if (argc != 3) {
        printf("Usage: file1 file2");
        return 1;
    }

    // открываем файлы
    file1 = fopen(argv[1], "r");
    file2 = fopen(argv[2], "r");

    // пока строки можно читать из обоих файлов
    while (fgets(line1, 100, file1) != NULL && fgets(line2, 100, file2) != NULL) {
        printf("%s%s", line1, line2); // выводим строки в перемешку
    }

    // если остались строки только в первом файле
    while (fgets(line1, 100, file1) != NULL) {
        printf("%s", line1); // выводим оставшиеся строки из первого файла
    }

    // если остались строки только во втором файле
    while (fgets(line2, 100, file2) != NULL) {
        printf("%s", line2); // выводим оставшиеся строки из второго файла
    }

    // закрываем файлы
    fclose(file1);
    fclose(file2);

    return EXIT_SUCCESS;
}




