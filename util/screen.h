typedef enum Color {WHITE, RED, GREEN, YELLOW, BLUE, CYAN} Color;

static const Color DEFAULT_TEXT_COLOR = WHITE;




/**
 * @brief Очистим экран терминала, напечатав escape-последовательность
 */

void clearScreen(void);




/**
 * @brief Установим цвет текста в терминале, напечатав escape-последовательность
 */

void setColor(Color c);




/**
 * @brief Установить позицию курсора для заданных координат в окне терминала
 * @param row Номер строки на экране терминала
 * @param col Номер столбца на экране терминала
 */

void locateCursor(const int row, const int col);
