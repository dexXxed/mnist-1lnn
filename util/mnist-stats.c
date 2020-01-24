#include <string.h>

#include "screen.h"
#include "mnist-utils.h"
#include "mnist-stats.h"


/**
 * @details Выводит текстовый фрейм 28x28 в определенной позиции экрана
 */

void displayImageFrame(int row, int col){
    
    if (col!=0 && row!=0) locateCursor(row, col);

    printf("------------------------------\n");
    
    for (int i=0; i<MNIST_IMG_HEIGHT; i++){
        for (int o=0; o<col-1; o++) printf(" ");
        printf("|                            |\n");
    }

    for (int o=0; o<col-1; o++) printf(" ");
    printf("------------------------------");
    
}


/**
 * @details Выводит изображение MNIST размером 28x28 в виде символов ("." И "X")
 */

void displayImage(MNIST_Image *img, int row, int col){

    char imgStr[(MNIST_IMG_HEIGHT * MNIST_IMG_WIDTH)+((col+1)*MNIST_IMG_HEIGHT)+1];
    strcpy(imgStr, "");
    
    for (int y=0; y<MNIST_IMG_HEIGHT; y++){
        
        for (int o=0; o<col-2; o++) strcat(imgStr," ");
        strcat(imgStr,"|");
        
        for (int x=0; x<MNIST_IMG_WIDTH; x++){
            strcat(imgStr, img->pixel[y*MNIST_IMG_HEIGHT+x] ? "X" : "." );
        }
        strcat(imgStr,"\n");
    }
    
    if (col!=0 && row!=0) locateCursor(row, 0);
    printf("%s",imgStr);
}


/**
 * @details Выводит прогресс чтения при обработке изображений для обучения MNIST
 */

void displayLoadingProgressTraining(int imgCount, int y, int x){
    
    float progress = (float)(imgCount+1) / (float)(MNIST_MAX_TRAINING_IMAGES) * 100;
    
    if (x!=0 && y!=0) locateCursor(y, x);
    
    printf("1: Обучение: Чтение изображения No. %5d из %5d изображений [%d%%]",(imgCount+1),MNIST_MAX_TRAINING_IMAGES,(int)progress);
    
}




/**
 * @details Выводит прогресс чтения при обработке изображений тестирования MNIST
 */

void displayLoadingProgressTesting(int imgCount, int y, int x){
    
    float progress = (float)(imgCount+1)/(float)(MNIST_MAX_TESTING_IMAGES)*100;
    
    if (x!=0 && y!=0) locateCursor(y, x);
    
    printf("2: Тестирование:  Чтение изображения No. %5d из %5d изображений [%d%%]\n                                  ",(imgCount+1),MNIST_MAX_TESTING_IMAGES,(int)progress);
    
}




/**
 * @details Выводит прогресс распознавания изображения и количество ошибок
 */

void displayProgress(int imgCount, int errCount, int y, int x){
    
    double successRate = 1 - ((double)errCount / (double)(imgCount+1));
    
    if (x!=0 && y!=0) locateCursor(y, x);
    
    printf("Результат: Правильно=%5d  Неправильно=%5d  Успешность=%5.2f%% \n",imgCount+1-errCount, errCount, successRate*100);
    
    
}

