#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "area.h"  

void inputStudentData(struct Student* s) {//使用指標變數s指向struct Student 可以直接修改結構內的變數 改變作用在整個程式 而非只有在函數內修改 Chap07 08 09
    printf("輸入學生姓名: ");
    scanf(" %49[^\n]", s->name); //chap03 最大包含49個字元 可以讀取除了換行符 \n 之外的所有字符
    printf("輸入學生學號: ");
    scanf("%d", &s->id);// 當訪問一般結構體的時候使用. 當結構體是指標的時候使用->
    getchar();  // chap03 消耗輸入緩衝區中的換行符 
    printf("輸入三科的成績:(1=國文 2=英文 3=數學)\n");
    for (int i = 0; i < 3; i++) { //for迴圈 chap06
        printf("科目 %d: ", i + 1);
        scanf("%f", &s->scores[i]);
    }
}

void displayStudentData(struct Student* s) {//顯示學生資料的函式
    printf("\n學生資訊\n");
    printf("姓名: %s\n", s->name);
    printf("學號: %d\n", s->id);
    printf("成績:(1=國文 2=英文 3=數學)\n ");
    for (int i = 0; i < 3; i++) {
        printf("%d: %.2f ",i+1, s->scores[i]);
    }
    printf("\n");
}

float calculateAverage(struct Student* s) { //計算平均分數的函式
    float sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += s->scores[i]; //chap04 算數運算子 
    }
    return sum / 3.0;
}

void writeToFile(struct Student* s) {
    FILE* file = fopen("student_data.txt", "a");//chap10以附加模式開啟檔案
    if (file != NULL) {
        fprintf(file, "%s %d %.2f %.2f %.2f\n", s->name, s->id, s->scores[0], s->scores[1], s->scores[2]);
        fclose(file);
        printf("學生資料成功寫入檔案。\n");
    }
    else {
        printf("開啟檔案寫入時發生錯誤。\n");
    }
}

void readFromFile() {
    FILE* file = fopen("student_data.txt", "r");//chap10以唯獨模式開啟檔案
    if (file != NULL) {
        struct Student studentFromFile;//chap09 

        while (fscanf(file, "%s %d %f %f %f", studentFromFile.name, &studentFromFile.id, //chap 05 10 fscanf 成功讀取了所有的數據（5個項目），進入迴圈內
            &studentFromFile.scores[0], &studentFromFile.scores[1], &studentFromFile.scores[2]) == 5) {//當還能讀取到5個項目時會一直觸發迴圈，直到文件結尾不足以同時讀到五個項目

            printf("\n從檔案中讀取的學生資訊\n");
            displayStudentData(&studentFromFile);
           
        }

        fclose(file);
    }
    else {
        printf("開啟檔案讀取時發生錯誤。\n");
    }
}

//從檔案讀取並排序的函式
void readFromFileAndSort() {
    FILE* file = fopen("student_data.txt", "r");
    if (file != NULL) {
        struct Student studentArray[60];  // 固定大小的陣列 設定為文檔內的學生最多只能60個
        int size = 0;

        while (size < 60/*size < 60：確保 studentArray 的陣列大小不超過 60，防止溢出。*/&& fscanf(file, "%s %d %f %f %f", studentArray[size].name, &studentArray[size].id,
            &studentArray[size].scores[0], &studentArray[size].scores[1], &studentArray[size].scores[2]) == 5)//和上面一樣，如果可以讀到5個項目就會不停讀
        {
            size++;
            
        }

        fclose(file);

        // 依據平均分數排序陣列
        sortStudentsByAverage(studentArray, size);

        // 顯示排序後的資訊
        for (int j = 0; j < size; j++) {
            printf("\n學生%d", j + 1);
            displayStudentData(&studentArray[j]);
            printf("平均分數: %.2f\n", calculateAverage(&studentArray[j]));
        }
    }
    else {
        printf("開啟檔案讀取時發生錯誤。\n");
    }
}

// 依據平均分數排序學生的函式
void sortStudentsByAverage(struct Student studentArray[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (calculateAverage(&studentArray[j]) < calculateAverage(&studentArray[j + 1])) {
                // 若平均分數順序錯誤，則交換學生資料
                struct Student temp = studentArray[j];
                studentArray[j] = studentArray[j + 1];
                studentArray[j + 1] = temp;
            }
        }
    }
}


