#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "area.h"



int main() {
    int choice;
    struct Student studentArray[5];  // 使用結構陣列 chap09

    do { //迴圈的架構與 do...while chap06
        printf("\n學生管理系統\n"); //資料的輸出 chap03
        printf("1. 輸入學生資料\n");
        printf("2. 顯示學生資料\n");
        printf("3. 計算平均分數\n");
        printf("4. 寫入檔案\n");
        printf("5. 從檔案讀取\n");
        printf("6. 以平均分排序\n");
        printf("0. 離開\n");
        printf("請輸入選擇: ");
        scanf("%d", &choice);// 資料的輸入 chap03

        switch (choice) { //switch-case 多重選擇敘述 chap05
        case 1:
            for (int i = 0; i < 5; i++) {
                inputStudentData(&studentArray[i]);  // 使用迴圈輸入多位學生資料 chap06 10 07
            }
            break; 
        case 2:
            for (int i = 0; i < 5; i++) {
                displayStudentData(&studentArray[i]);  // 使用迴圈顯示多位學生資料 chap06 10 7
            }
            break;
        case 3:
            for (int i = 0; i < 5; i++) {
                printf("學生%d的平均分數: %.2f\n", i + 1, calculateAverage(&studentArray[i]));  // 使用迴圈計算多位學生平均分數 chap06 10 07 04
            }
            break;
        case 4:
            for (int i = 0; i < 5; i++) {
                writeToFile(&studentArray[i]);  // 使用迴圈將多位學生資料寫入檔案 chap06 chap10 chap7
            }
            break;
        case 5:

            readFromFile();  // 從檔案讀取多位學生資料 chap10 chap07

            break;
        case 6:
            
            readFromFileAndSort();  // 從檔案讀取多位學生資料並按照平均分高至低排序 chap10 07 06
            
            break;
        case 0:
            printf("結束程式。再見！\n");
            break;
        default: 
            printf("無效選擇。請輸入有效選項。\n");
        }
    } while (choice != 0);

    return 0;
}
