/**
 * @file main.c
 *
 * @mainpage MNIST Однослойная Нейронная Сеть
 *
 * @brief Основные характеристики: только 1 слой (= входной слой), без скрытого слоя. Только прямая связь. Нет функции активации сигмоида. Обратного распространения нет.
 *
 * @details Обучение достигается просто путем постепенного обновления весов соединений на основе сравнения с желаемым целевым выходом (контролируемое обучение).
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include <windows.h>


#include "screen.h"
#include "mnist-utils.h"
#include "mnist-stats.h"
#include "1lnn.h"




/**
 * @details Тренирует слой, проходя в цикле и тренируя его ячейки
 * @param l Указатель на слой, который должен быть обучен
 */

void trainLayer(Layer *l){
    
    // открываем MNIST файлы
    FILE *imageFile, *labelFile;
    imageFile = openMNISTImageFile(MNIST_TRAINING_SET_IMAGE_FILE_NAME);
    labelFile = openMNISTLabelFile(MNIST_TRAINING_SET_LABEL_FILE_NAME);
    
    
    // вывод на экран для мониторинга прогресса
    displayImageFrame(5,5);

    int errCount = 0;
    
    // Перебираем все изображения в файле
    for (int imgCount=0; imgCount<MNIST_MAX_TRAINING_IMAGES; imgCount++){
        
        // мониторим прогресс
        displayLoadingProgressTraining(imgCount,3,5);
        
        // Чтение следующего изображения и соответствующей метки
        MNIST_Image img = getImage(imageFile);
        MNIST_Label lbl = getLabel(labelFile);
        
        // установливаем целевое значение числа, отображаемого на текущем изображении, равным 1, все остальные значения равными 0
        Vector targetOutput;
        targetOutput = getTargetOutput(lbl);
        
        displayImage(&img, 6,6);
     
        // цикл через все выходные ячейки для данного изображения
        for (int i=0; i < NUMBER_OF_OUTPUT_CELLS; i++){
            trainCell(&l->cell[i], &img, targetOutput.val[i]);
        }
        
        int predictedNum = getLayerPrediction(l);
        if (predictedNum!=lbl) errCount++;
        
        printf("\n      Предсказанное: %d   Реальное: %d ",predictedNum, lbl);

        displayProgress(imgCount, errCount, 3, 66);
        
    }
    
    // Закрываем файлы
    fclose(imageFile);
    fclose(labelFile);

}




/**
 * @details Тестирует слой, просматривая и проверяя его ячейки
 * Точно так же, как TrainLayer(), но БЕЗ ОБУЧЕНИЯ
 * @param l Указатель на слой, который должен быть обучен
 */

void testLayer(Layer *l){
    
    // открываем MNIST файлы
    FILE *imageFile, *labelFile;
    imageFile = openMNISTImageFile(MNIST_TESTING_SET_IMAGE_FILE_NAME);
    labelFile = openMNISTLabelFile(MNIST_TESTING_SET_LABEL_FILE_NAME);
    
    
    // вывод на экран для мониторинга прогресса
    displayImageFrame(7,5);
    
    int errCount = 0;
    
    // Перебираем все изображения в файле
    for (int imgCount=0; imgCount<MNIST_MAX_TESTING_IMAGES; imgCount++){
        
        // мониторим прогресс
        displayLoadingProgressTesting(imgCount,5,5);
        
        // Чтение следующего изображения и соответствующей метки
        MNIST_Image img = getImage(imageFile);
        MNIST_Label lbl = getLabel(labelFile);
        
        // устанавливаем целевое значение числа, отображаемого на текущем изображении, равным 1, все остальные значения равными 0
        Vector targetOutput;
        targetOutput = getTargetOutput(lbl);
        
        displayImage(&img, 8,6);
        
        // цикл через все выходные ячейки для данного изображения
        for (int i=0; i < NUMBER_OF_OUTPUT_CELLS; i++){
            testCell(&l->cell[i], &img, targetOutput.val[i]);
        }
        
        int predictedNum = getLayerPrediction(l);
        if (predictedNum!=lbl) errCount++;
        
        printf("\n      Предсказанное: %d   Реальное: %d ",predictedNum, lbl);
        
        displayProgress(imgCount, errCount, 5, 66);
        
    }
    
    // Закрываем файлы
    fclose(imageFile);
    fclose(labelFile);
    
}


/**
 * @details Функция main()
 */

int main() {
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),CONSOLE_FULLSCREEN_MODE,0);


    system("chcp 65001"); // для корректного вывода русских символов

    // запомним текущее время, чтобы рассчитать время обработки в конце
    time_t startTime = time(NULL);
    
    // очистим окно терминального вывода
    clearScreen();
    printf("    Простая однослойная нейронная сеть для распознавания рукописных однозначных цифр (0-9) из файлов изображений MNIST\n");
    
    // инициализируем все веса подключений случайными значениями от 0 до 1
    Layer outputLayer;
    initLayer(&outputLayer);
    trainLayer(&outputLayer);
    
    testLayer(&outputLayer);

    locateCursor(38, 5);
    
    // Рассчитать и распечатать общее время выполнения программы
    time_t endTime = time(NULL);
    double executionTime = difftime(endTime, startTime);
    printf("\n    Завершено! Общее время выполнения: %.1f секунд(-a/-ы)\n\n", executionTime);
    
    system("pause");
    return 0;
}


