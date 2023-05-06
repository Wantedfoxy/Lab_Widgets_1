#ifndef WIDGET_H
#define WIDGET_H
// Подключаем основные библиотеки
#include <QWidget>
#include <QValidator>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    // Слот начальной настройки интерфейса
    void begin();
    // Слот реализации вычислений
    void calc();

private:
    // Указатель на объект интерфейса
    Ui::Widget *ui;
};

#endif // WIDGET_H
