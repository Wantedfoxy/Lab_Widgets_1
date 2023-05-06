#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    // Создаем элементы пользовательского интерфейса, которые были размещены на форме
    ui->setupUi(this);
    begin();
    // Устанавливаем соединения сигналов и слотов (кнопок и методов)
    connect(ui->exitButton,SIGNAL(clicked(bool)),
            this,SLOT(close()));
    connect(ui->nextButton,SIGNAL(clicked(bool)),
            this,SLOT(begin()));
    connect(ui->inputEdit,SIGNAL(returnPressed()),
            this,SLOT(calc()));
    connect(ui->inputEdit, SIGNAL(editingFinished()), this, SLOT(calc()));
}

Widget::~Widget()
{
    // Освобождаем память, выделенную для ui
    delete ui;
}

void Widget::begin()
{
    // Очищаем поле ввода inputEdit
    ui->inputEdit->clear();
    // Отключаем кнопку nextButton
    ui->nextButton->setEnabled(false);
    ui->nextButton->setDefault(false);
    // Включаем поле ввода inputEdit
    ui->inputEdit->setEnabled(true);
    // Скрываем метку вывода outputLabel
    ui->outputLabel->setVisible(false);
    // Скрываем поле вывода outputEdit
    ui->outputEdit->setVisible(false);
    ui->outputEdit->setEnabled(false);
    // Устанавливаем фокус на поле ввода inputEdit
    ui->inputEdit->setFocus();
};

void Widget::calc()
{
    // Инициализируем переменные
    // Ok отвечает за то, чтобы сообщить, валидна ли введенная строка
    // a необходима для реализации проверки на валидность введенной строки
    bool Ok=true; float a;
    // Считываем текст из поля ввода inputEdit
    QString str=ui->inputEdit->text();
    // Преобразуем его в число типа float и проверяем, удалось ли это сделать с помощью флага Ok
    a=str.toDouble(&Ok);
    // Если преобразование удалось
    if (Ok)
    {
        // Вычисляем квадрат введенного числа и преобразуем результат в строку
        str.setNum(a*a);
        //Записываем результат в поле вывода outputEdit
        ui->outputEdit->setText(str);
        // Отключаем поле ввода inputEdit
        ui->inputEdit->setEnabled(false);
        // Jтображаеv метку вывода outputLabel и поле вывода outputEdit
        ui->outputLabel->setVisible(true);
        ui->outputEdit->setVisible(true);
        // Активируем кнопку nextButton и сбрасывает фокус на эту кнопку
        ui->nextButton->setDefault(true);
        ui->nextButton->setEnabled(true);
        ui->nextButton->setFocus();
    }
    // Если преобразование не удалось
    else
        // Если строка не совсем пустая
        if (!str.isEmpty())
        {
            // Выводим сообщение об ошибке в QMessageBox
            QMessageBox meesageBox(QMessageBox::Information,
                               "Возведение в квадрат.",
                               "Введено неверное значение.",
                               QMessageBox::Ok);
            // Запускаем диалоговое окно сообщения msgBox и блокирует дальнейшее выполнение
            // программы до тех пор, пока пользователь не закроет это окно
            meesageBox.exec();
        }
};
