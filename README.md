# mnist-1lnn
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/3dec6572000b4175885d02e676a61f55)](https://www.codacy.com/manual/dexXxed/mnist-1lnn?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=dexXxed/mnist-1lnn&amp;utm_campaign=Badge_Grade)\
Простая однослойная нейронная сеть для распознавания рукописных однозначных цифр (0-9) из файлов изображений MNIST.
## Компиляция и запуск исходного кода
В репозитории есть сконфигурированный `makefile`. Компилируется на Windows (32, 64 бита).

Для этого введите команду:
```cpp
$ make
```
Бинарные файлы хранятся в папке `bin`. Для запуска:
```cpp
$ cd bin/
$ ./windows-x64-build.exe # or ./windows-x32-build.exe
```
## Скриншоты
В папке `/screenshots` имеются скриншоты запуска программы.
## База данных MNIST
В папке `/bin/data` хранятся оригинальные файлы базы данных MNIST.
