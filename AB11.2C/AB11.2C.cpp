#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CreateBIN(char* fname) {
    FILE* fout;
    fopen_s(&fout, fname, "wb");
    if (fout == NULL) {
        printf("Error opening file %s for writing\n", fname);
        return;
    }

    char ch;
    char s[100];
    do {
        fflush(stdin);
        printf("enter line: ");
        fgets(s, sizeof(s), stdin);
        for (size_t i = 0; i < strlen(s); i++)
            fwrite(&s[i], sizeof(char), 1, fout);
        printf("continue? (y/n): ");
        if (scanf_s(" %c", &ch) != 1) {
            printf("Error reading input\n");
            fclose(fout);
            return;
        }
    } while (ch == 'y' || ch == 'Y');
    fclose(fout);
    printf("\n");
}

void PrintBIN(char* fname) {
    FILE* fin;
    fopen_s(&fin, fname, "rb");
    if (fin == NULL) {
        printf("Error opening file %s for reading\n", fname);
        return;
    }

    char c;
    while (fread(&c, sizeof(char), 1, fin) == 1)
        printf("%c\n", c);

    fclose(fin);
    printf("\n");
}

void ProcessBIN1(char* fname, char* evenname, char* oddname) {
    FILE* f, * e, * o;
    fopen_s(&f, fname, "rb");
    fopen_s(&e, evenname, "wb");
    fopen_s(&o, oddname, "wb");

    if (f == NULL || e == NULL || o == NULL) {
        printf("Error opening files for processing\n");
        if (f != NULL) fclose(f);
        if (e != NULL) fclose(e);
        if (o != NULL) fclose(o);
        return;
    }

    char c;
    while (fread(&c, sizeof(char), 1, f) == 1) {
        if ((int)c % 2 == 0)
            fwrite(&c, sizeof(char), 1, e);
        else
            fwrite(&c, sizeof(char), 1, o);
    }

    fclose(f);
    fclose(e);
    fclose(o);
}

int main() {
    char fname[100];
    printf("enter file name 1: ");
    scanf_s("%s", fname, sizeof(fname));
    CreateBIN(fname);
    PrintBIN(fname);

    char evenname[100];
    printf("enter file name 2: ");
    scanf_s("%s", evenname, sizeof(evenname));

    char oddname[100];
    printf("enter file name 3: ");
    scanf_s("%s", oddname, sizeof(oddname));

    ProcessBIN1(fname, evenname, oddname);

    printf("Even numbers : \n");
    PrintBIN(evenname);

    printf("Odd numbers : \n");
    PrintBIN(oddname);

    return 0;
}
