#include <stdio.h>


/**
 * @brief Выводит текстовый фрейм 28x28 в определенной позиции экрана
 * @param row Ряд экрана терминала
 * @param col Колонка экрана терминала
 */

void displayImageFrame(int y, int x);




/**
 * @brief Выводит изображение MNIST размером 28x28 в виде символов ("." И "X")
 * @param img Указатель на MNIST изображение
 * @param row Ряд экрана терминала
 * @param col Колонка экрана терминала
 */

void displayImage(MNIST_Image *img, int y, int x);




/**
 * @brief Выводит прогресс чтения при обработке изображений для обучения MNIST
 * @param imgCount Количество изображений, уже прочитанных из файла MNIST
 * @param y Ряд экрана терминала
 * @param x Колонка экрана терминала
 */

void displayLoadingProgressTraining(int imgCount, int y, int x);




/**
 * @brief Выводит прогресс чтения при обработке изображений тестирования MNIST
 * @param imgCount Количество изображений, уже прочитанных из файла MNIST
 * @param y Ряд экрана терминала
 * @param x Колонка экрана терминала
 */

void displayLoadingProgressTesting(int imgCount, int y, int x);




/**
 * @brief Выводит прогресс распознавания изображения и количество ошибок
 * @param imgCount Количество уже обработанных изображений
 * @param errCount Количество изображений, которые НЕ были правильно определены
 * @param y Ряд экрана терминала
 * @param x Колонка экрана терминала
 */

void displayProgress(int imgCount, int errCount, int y, int x);
