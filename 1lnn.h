#include <stdio.h>

#define NUMBER_OF_INPUT_CELLS 784   ///< используем 28*28 входных ячеек (= кол-ву пикселей на изображении MNIST)
#define NUMBER_OF_OUTPUT_CELLS 10   ///< используем 10 выходных ячеек для моделирования 10 цифр (0-9)

#define LEARNING_RATE 0.05          ///< Постепенное увеличение для изменения весов 



typedef struct Cell Cell;
typedef struct Layer Layer;
typedef struct Vector Vector;




/**
 * @brief Основная единица нейронной сети (нейрон и синапсы)
 */

struct Cell{
    double input [NUMBER_OF_INPUT_CELLS];
    double weight[NUMBER_OF_INPUT_CELLS];
    double output;
    double bias;
};




/**
 * @brief Единственный (выходной) слой этой сети (слой с числом ячеек)
 */

struct Layer{
    Cell cell[NUMBER_OF_OUTPUT_CELLS];
};




/**
 * @brief Структура данных, содержащая определенное количество целочисленных значений (выходной вектор содержит значения от 0 до 9)
 */

struct Vector{
    int val[NUMBER_OF_OUTPUT_CELLS];
};




/**
 * @brief Возвращает выходной вектор с targetIndex, установленным в 1, все остальные в 0
 * @param targetIndex Индекс выхода, который должен быть установлен в 1
 */

Vector getTargetOutput(int targetIndex);




/**
 * @brief Инициализируем слой, установив все веса в случайные значения [0-1]
 * @param l Указатель на слой нейронной сети
 */

void initLayer(Layer *l);




/**
 * @brief Возвращает индекс ячейки с наибольшим выходом
 * @param l Указатель на слой нейронной сети
 */

int getLayerPrediction(Layer *l);




/**
 * @brief Устанавливаем вход ячейки в соответствии с пикселями данного изображения MNIST
 * @param c Указатель на ячейку
 * @param img Указатель на MNIST картинку
 */

void setCellInput(Cell *c, MNIST_Image *img);




/**
 * @brief Вычисляет выход ячейки путем суммирования всех входных произведений весов 
 * @param c Ячейка слоя нейронной сети
 */

void calcCellOutput(Cell *c);




/**
 * @brief Возвращает разницу между целевым значением и выходом ячейки
 * @param c Ячейка, чей вывод сравнивается
 * @param target Желаемое значение (правильный ответ в контролируемом обучении)
 */

double getCellError(Cell *c, int target);




/**
 * @brief Обновляет вес ячейки на основе указанной ошибки и LEARNING_RATE
 * @param c Ячейка, вес которой должен быть обновлен
 * @param err Ошибка (разница между желаемым выходом и фактическим выходом)
 */

void updateCellWeights(Cell *c, double err);




/**
 * @brief Выполняет алгоритм обучения
 * @param c Указатель на ячейку, которая должна быть обучена
 * @param img Указатель на изображение, которое должно быть обработано
 * @param target Желаемое выходное значение
 */

void trainCell(Cell *c, MNIST_Image *img, int target);




/**
 * @brief Проводит тестирование обученной сети
 * @param c Указатель на ячейку, которая должна быть обучена
 * @param img Указатель на изображение, которое должно быть обработано
 * @param target Желаемое выходное значение
 */


void testCell(Cell *c, MNIST_Image *img, int target);

