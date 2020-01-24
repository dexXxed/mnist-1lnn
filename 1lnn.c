#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "mnist-utils.h"
#include "1lnn.h"




/**
 * @details Возвращает выходной вектор с targetIndex, установленным в 1, все остальные в 0
 */

Vector getTargetOutput(int targetIndex){
    Vector v;
    for (int i=0; i<NUMBER_OF_OUTPUT_CELLS; i++){
        v.val[i] = (i==targetIndex) ? 1 : 0;
    }
    return v;
}




/**
 * @details Инициализируем слой, установив все веса в случайные значения [0-1]
 * @attention На самом деле не имеет значения, инициализированы ли веса постоянной величиной 
 * (например, 0,5) или случайным числом. 
 * Результат (85% точности) существенно не изменится.
 */

void initLayer(Layer *l){
    
    for (int o=0; o<NUMBER_OF_OUTPUT_CELLS; o++){
        
        for (int i=0; i<NUMBER_OF_INPUT_CELLS; i++){
            l->cell[o].input[i]=0;
            l->cell[o].weight[i]=rand()/(double)(RAND_MAX);
        }
        
        l->cell[o].output = 0;
        l->cell[o].bias = 0;
    }
}




/**
 * @details Прогноз получается путем простой сортировки всех выходных значений 
 * и использования индекса (число 0-9) самого высокого значения в прогнозе.
 */

int getLayerPrediction(Layer *l){
    
    double maxOut = 0;
    int maxInd = 0;
    
    for (int i=0; i<NUMBER_OF_OUTPUT_CELLS; i++){
        
        if (l->cell[i].output > maxOut){
            maxOut = l->cell[i].output;
            maxInd = i;
        }
    }
    
    return maxInd;
    
}




/**
 * @details Создает входной вектор длиной NUMBER_OF_INPUT_CELLS 
 * для данного изображения MNIST, устанавливая ячейки входного вектора в [0,1],
 * ссылаясь на пиксели изображения. 
 * Скалярная интенсивность пикселей (оттенки серого) игнорируются, 
 * только 0 или 1 (черный или белый цвет).
 */

void setCellInput(Cell *c, MNIST_Image *img){
    
    for (int i=0; i<NUMBER_OF_INPUT_CELLS; i++){
        c->input[i] = img->pixel[i] ? 1 : 0;
    }
}




/**
 * @details Вычисляет выход ячейки путем 
 * суммирования всех входных весовых произведений и нормализации (0-1).
 */

void calcCellOutput(Cell *c){
    
    c->output=0;
    
    for (int i=0; i<NUMBER_OF_INPUT_CELLS; i++){
        c->output += c->input[i] * c->weight[i];
    }
    
    c->output /= NUMBER_OF_INPUT_CELLS;             // нормализация выхода (0-1)
}




/**
 * @details Возвращает разницу между целевым значением и выходом ячейки
 */

double getCellError(Cell *c, int target){

    double err = target - c->output;

    return err;
}




/**
 * @details Обновляет вес ячейки на основе указанной ошибки и LEARNING_RATE
 */

void updateCellWeights(Cell *c, double err){
    
    for (int i=0; i<NUMBER_OF_INPUT_CELLS; i++){
        c->weight[i] += LEARNING_RATE * c->input[i] * err;
    }
}




/**
 * @details Выполняет алгоритм обучения: 
 * ввод данных, вычисление выхода, вычисление ошибки, обновление весов
 */

void trainCell(Cell *c, MNIST_Image *img, int target){
    
    setCellInput(c, img);
    calcCellOutput(c);
    
    // обучение (осущ. обновлением весов)
    double err = getCellError(c, target);
    updateCellWeights(c, err);
}




/**
 * @details Проводит тестирование обученной сети
 * То же самое, что тренировка ячейки, но без обновления весов (обучения)
 */

void testCell(Cell *c, MNIST_Image *img, int target){
    
    setCellInput(c, img);
    calcCellOutput(c);
    
}
