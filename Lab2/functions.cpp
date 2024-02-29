#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void allocateMemory(struct Subject ***subjects, int *numSubjects) {
    printf("Введите количество элементов массива:");
    scanf("%d", numSubjects);
    *subjects = (struct Subject **)malloc(*numSubjects * sizeof(struct Subject *));
    for (int i = 0; i < *numSubjects; i++) {
        (*subjects)[i] = (struct Subject *)malloc(sizeof(struct Subject));
    }
}

void inputSubjects(struct Subject **subjects, int numSubjects) {
    printf("Введите информацию о предметах:\n");
    for (int i = 0; i < numSubjects; i++) {
        printf("Предмет %d:\n", i + 1);
        printf("Название: ");
        scanf("%s", subjects[i]->name);
        printf("Год: ");
        scanf("%d", &subjects[i]->year);
        printf("Факультет: ");
        scanf("%s", subjects[i]->faculty);
        printf("Кафедра: ");
        scanf("%s", subjects[i]->department);
        printf("Количество часов: ");
        scanf("%d", &subjects[i]->hours);
        printf("-------------------\n");
    }
}

void searchSubject(struct Subject **subjects, int numSubjects) {
    char name[50];

    printf("Введите название предмета для поиска: ");
    scanf("%s", name);
    for (int i = 0; i < numSubjects; i++) {
        if (strcmp(subjects[i]->name, name) == 0) {
            printf("Предмет найден:\n");
            printf("Название: %s\n", subjects[i]->name);
            printf("Год: %d\n", subjects[i]->year);
            printf("Факультет: %s\n", subjects[i]->faculty);
            printf("Кафедра: %s\n", subjects[i]->department);
            printf("Количество часов: %d\n", subjects[i]->hours);
            return;
        }
    }
    printf("Предмет не найден.\n");
}

void sortSubjects(struct Subject **subjects, int numSubjects) {
    for (int i = 0; i < numSubjects - 1; i++) {
        for (int j = 0; j < numSubjects - i - 1; j++) {
            if (strcmp(subjects[j]->name, subjects[j + 1]->name) > 0) {
                struct Subject *temp = subjects[j];
                subjects[j] = subjects[j + 1];
                subjects[j + 1] = temp;
            }
        }
    }
    printf("Массив отсортирован по названию предмета.\n");
}

void editSubject(struct Subject **subjects, int numSubjects) {
    char name[50];

    printf("Введите название предмета для редактирования: ");
    scanf("%s", name);
    for (int i = 0; i < numSubjects; i++) {
        if (strcmp(subjects[i]->name, name) == 0) {
            printf("Введите новую информацию о предмете:\n");
            printf("Год: ");
            scanf("%d", &subjects[i]->year);
            printf("Факультет: ");
            scanf("%s", subjects[i]->faculty);
            printf("Кафедра: ");
            scanf("%s", subjects[i]->department);
            printf("Количество часов: ");
            scanf("%d", &subjects[i]->hours);
            return;
        }
    }
    printf("Предмет не найден.\n");
}

void addSubject(struct Subject ***subjects, int *numSubjects) {
    struct Subject *newSubject = (struct Subject *)malloc(sizeof(struct Subject));
    printf("Введите информацию о новом предмете:\n");
    printf("Название: ");
    scanf("%s", newSubject->name);
    printf("Год: ");
    scanf("%d", &newSubject->year);
    printf("Факультет: ");
    scanf("%s", newSubject->faculty);
    printf("Кафедра: ");
    scanf("%s", newSubject->department);
    printf("Количество часов: ");
    scanf("%d", &newSubject->hours);
    *subjects = (struct Subject **)realloc(*subjects, (*numSubjects + 1) * sizeof(struct Subject *));
    (*subjects)[(*numSubjects)++] = newSubject;
}

void deleteSubject(struct Subject ***subjects, int *numSubjects) {
    char name[50];

    printf("Введите название предмета для удаления: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < *numSubjects; i++) {
        if (strcmp((*subjects)[i]->name, name) == 0) {
            found = 1;
            free((*subjects)[i]);
            for (int j = i; j < *numSubjects - 1; j++) {
                (*subjects)[j] = (*subjects)[j + 1];
            }
            *subjects = (struct Subject **)realloc(*subjects, (*numSubjects - 1) * sizeof(struct Subject *));
            (*numSubjects)--;
            printf("Предмет удален.\n");
            break;
        }
    }
    if (!found)
        printf("Предмет не найден.\n");
}

void insertSubject(struct Subject ***subjects, int *numSubjects) {
    int index;
                printf("Введите индекс для вставки нового элемента: ");
                scanf("%d", &index);
    if (index < 0 || index > *numSubjects) {
        printf("Неверный индекс для вставки.\n");
        return;
    }

    struct Subject *newSubject = (struct Subject *)malloc(sizeof(struct Subject));

    printf("Введите информацию о новом предмете:\n");
    printf("Название: ");
    scanf("%s", newSubject->name);
    printf("Год: ");
    scanf("%d", &newSubject->year);
    printf("Факультет: ");
    scanf("%s", newSubject->faculty);
    printf("Кафедра: ");
    scanf("%s", newSubject->department);
    printf("Количество часов: ");
    scanf("%d", &newSubject->hours);

    *subjects = (struct Subject **)realloc(*subjects, (*numSubjects + 1) * sizeof(struct Subject *));
    for (int i = *numSubjects; i > index; i--) {
        (*subjects)[i] = (*subjects)[i - 1];
    }
    (*subjects)[index] = newSubject;
    (*numSubjects)++;
}

void writeToFile(const char *filename, struct Subject **subjects, int numSubjects) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
       
        return;
    }

    // Запись данных в файл
    for (int i = 0; i < numSubjects; i++) {
        fprintf(file, "%s %d %s %s %d\n", subjects[i]->name, subjects[i]->year, subjects[i]->faculty, subjects[i]->department, subjects[i]->hours);
    }

    fclose(file);
    printf("Массив успешно записан в файл.\n");
}

void readFromFile(const char *filename, struct Subject ***subjects, int *numSubjects) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }

    // Чтение данных из файла
    while (!feof(file)) {
        struct Subject *newSubject = (struct Subject *)malloc(sizeof(struct Subject));
        if (newSubject == NULL) {
            printf("Ошибка выделения памяти.\n");
            fclose(file);
            return;
        }

        if (fscanf(file, "%s %d %s %s %d", newSubject->name, &newSubject->year, newSubject->faculty, newSubject->department, &newSubject->hours) != 5) {
            free(newSubject);
            break;
        }

        *subjects = (struct Subject **)realloc(*subjects, (*numSubjects + 1) * sizeof(struct Subject *));
        (*subjects)[(*numSubjects)++] = newSubject;
    }

    fclose(file);
    printf("Данные успешно считаны из файла.\n");
}

void freeMemory(struct Subject ***subjects, int *numSubjects) {
    for (int i = 0; i < *numSubjects; i++) {
        free((*subjects)[i]);
    }
    free(*subjects);
    *subjects = NULL;
    *numSubjects = 0;
    printf("Память освобождена.\n");
}

void displaySubjects(struct Subject **subjects, int numSubjects) {
    printf("Информация о предметах:\n");
    printf("+----+----------------------+------+-------------+----------------+------+");
    printf("\n|%3s | %-20s | %-4s | %-11s | %-14s | %-3s|\n", "#", "Subject Name", "Year", "Faculty", "Department", "Hours");
    printf("+----+----------------------+------+-------------+----------------+------+");

    for (int i = 0; i < numSubjects; i++) {
        printf("\n| %2d | %-20s | %4d | %-11s | %-14s | %4d |", i + 1, subjects[i]->name, subjects[i]->year, subjects[i]->faculty, subjects[i]->department, subjects[i]->hours);
    }


    printf("\n+----+----------------------+------+-------------+----------------+------+\n");
}

