#ifndef AREA_H
#define AREA_H


// 結構 chap09
struct Student {
    char name[50];
    int id;
    float scores[3];
};

// 函式聲明 chap07
void inputStudentData(struct Student* s);
void displayStudentData(struct Student* s);
float calculateAverage(struct Student* s);
void writeToFile(struct Student* s);
void readFromFile();
void readFromFileAndSort();
void sortStudentsByAverage(struct Student studentArray[], int size);

#endif // AREA_H
