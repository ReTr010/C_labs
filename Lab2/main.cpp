#include "header.h"
#include <stdio.h>

int main() {
    int choice;
    
    struct Subject **subjects = NULL;
    int numSubjects = 0;

    do {
        printf("\nМеню операций:\n");
        printf("1. Динамическое выделение памяти для массива структур.\n");
        printf("2. Ввод элементов массива с клавиатуры.\n");
        printf("3. Поиск элемента массива.\n");
        printf("4. Сортировка массива.\n");
        printf("5. Редактирование элемента массива.\n");
        printf("6. Добавление нового элемента в конец.\n");
        printf("7. Удаление указанного элемента из массива.\n");
        printf("8. Вставка нового элемента.\n");
        printf("9. Запись элементов массива в файл.\n");
        printf("10. Считывание элементов массива из файла.\n");
        printf("11. Вывод элементов массива на экран.\n");
        printf("12. Освобождение памяти, выделенной для массива.\n");
        printf("13. Окончание работы программы.\n");

        printf("Выберите операцию: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                allocateMemory(&subjects, &numSubjects);
                break;
            case 2:
                inputSubjects(subjects, numSubjects);
                break;
            case 3:
                
                searchSubject(subjects, numSubjects);
                break;
            case 4:
                sortSubjects(subjects, numSubjects);
                break;
            case 5:
                
                editSubject(subjects, numSubjects);
                break;
            case 6:
                addSubject(&subjects, &numSubjects);
                break;
            case 7:
                
                deleteSubject(&subjects, &numSubjects);
                break;
            case 8:
                
                insertSubject(&subjects, &numSubjects);
                break;
            case 9:
                writeToFile("subjects.txt", subjects, numSubjects);
                break;
            case 10:
                readFromFile("subjects.txt", &subjects, &numSubjects);
                break;
            case 11:
                displaySubjects(subjects, numSubjects);
                break;
            case 12:
                freeMemory(&subjects, &numSubjects);
                break;
            case 13:
                if (subjects!=NULL){
                    freeMemory(&subjects, &numSubjects);
                }
                printf("Программа завершена.\n");
                break;
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
        printf("-------------------\n");
    } while (choice != 13);

    return 0;
}
