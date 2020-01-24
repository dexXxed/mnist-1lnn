#include <stdint.h>
#include <stdio.h>


#define MNIST_TRAINING_SET_IMAGE_FILE_NAME "data/train-images-idx3-ubyte" ///< Учебный файл изображений MNIST в папке data/
#define MNIST_TRAINING_SET_LABEL_FILE_NAME "data/train-labels-idx1-ubyte" ///< Учебный файл метки MNIST в папке data/

#define MNIST_TESTING_SET_IMAGE_FILE_NAME "data/t10k-images-idx3-ubyte"  ///< Файл тестирования изображения MNIST в папке data/
#define MNIST_TESTING_SET_LABEL_FILE_NAME "data/t10k-labels-idx1-ubyte"  ///< Файл тестирования метки MNIST в папке data/



#define MNIST_MAX_TRAINING_IMAGES 60000                     ///< количество изображений+меток в файле TRAIN 
#define MNIST_MAX_TESTING_IMAGES 10000                      ///< количество изображений+меток в файле TEST 
#define MNIST_IMG_WIDTH 28                                  ///< ширина изображения в пикселях
#define MNIST_IMG_HEIGHT 28                                 ///< высота изображения в пикселях



typedef struct MNIST_ImageFileHeader MNIST_ImageFileHeader;
typedef struct MNIST_LabelFileHeader MNIST_LabelFileHeader;

typedef struct MNIST_Image MNIST_Image;
typedef uint8_t MNIST_Label;



/**
 * @brief Блок данных, определяющий изображение MNIST
 */
struct MNIST_Image{
    uint8_t pixel[28*28];
};




/**
 * @brief Блок данных, определяющий заголовок файла изображения MNIST
 */

struct MNIST_ImageFileHeader{
    uint32_t magicNumber;
    uint32_t maxImages;
    uint32_t imgWidth;
    uint32_t imgHeight;
};




/**
 * @brief Блок данных, определяющий заголовок файла метки MNIST
 */

struct MNIST_LabelFileHeader{
    uint32_t magicNumber;
    uint32_t maxImages;
};




/**
 * @brief Прочитать заголовок файла MNIST IMAGE
 */

FILE *openMNISTImageFile(char *fileName);




/**
 * @brief Прочитать заголовок файла метки MNIST
 */

FILE *openMNISTLabelFile(char *fileName);



/**
 * @brief Возвращает следующее изображение в данном файле изображения MNIST
 */

MNIST_Image getImage(FILE *imageFile);




/**
 * @brief Возвращает следующую метку в данном файле меток MNIST
 */

MNIST_Label getLabel(FILE *labelFile);
