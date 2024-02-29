#ifndef HEADER_H
#define HEADER_H

#define MAX_SUBJECTS 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Subject {
    char name[50];
    int year;
    char faculty[50];
    char department[50];
    int hours;
};



void allocateMemory(struct Subject ***subjects, int *numSubjects);
void inputSubjects(struct Subject **subjects, int numSubjects);
void searchSubject(struct Subject **subjects, int numSubjects);
void sortSubjects(struct Subject **subjects, int numSubjects);
void editSubject(struct Subject **subjects, int numSubjects);
void addSubject(struct Subject ***subjects, int *numSubjects);
void deleteSubject(struct Subject ***subjects, int *numSubjects);
void insertSubject(struct Subject ***subjects, int *numSubjects);
void writeToFile(const char *filename, struct Subject **subjects, int numSubjects);
void readFromFile(const char *filename, struct Subject ***subjects, int *numSubjects);
void freeMemory(struct Subject ***subjects, int *numSubjects);
void displaySubjects(struct Subject **subjects, int numSubjects);

#endif /* HEADER_H */
