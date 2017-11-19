#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void digit_clicked();

    void on_pushButton_decimal_released();

    void unaryOperatorClicked();
    void on_pushButton_clear_released();
    void on_pushButton_equal_released();

    void binaryOperatorClicked();
};

#endif // MAINWINDOW_H
