// Подключение заголовочного файла "widget.h", содержащего объявление класса "widget.h"
#include "widget.h"
// Подключение заголовочного файла "QApplication" из QtWidgets, необходимого для создания QApplication
#include <QApplication>
#include <iostream>
// Основная функция программы
int main(int argc, char *argv[])
{
    try {    // Создание объекта QApplication с аргументами командной строки argc и argv
        QApplication a(argc, argv);
        // Создание объекта класса Widget
        Widget w;
        // Задание названия окна
        w.setWindowTitle("Возведение в квадрат");
        // Задание размеров окна
        w.setFixedSize(349, 201);
        // Отображение главного окна
        w.show();
        // Запуск главного цикла приложения
        return a.exec();
    }
    catch (const std::bad_alloc&)
    {
        std::cout << "Error in allocate memory";
    };
};
