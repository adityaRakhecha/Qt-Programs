#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>

double firstNum;
bool uSecNum = false;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(released()), this,SLOT(digit_clicked()));
    connect(ui->pushButton_1, SIGNAL(released()), this,SLOT(digit_clicked()));
    connect(ui->pushButton_2, SIGNAL(released()), this,SLOT(digit_clicked()));
    connect(ui->pushButton_3, SIGNAL(released()), this,SLOT(digit_clicked()));
    connect(ui->pushButton_4, SIGNAL(released()), this,SLOT(digit_clicked()));
    connect(ui->pushButton_5, SIGNAL(released()), this,SLOT(digit_clicked()));
    connect(ui->pushButton_6, SIGNAL(released()), this,SLOT(digit_clicked()));
    connect(ui->pushButton_7, SIGNAL(released()), this,SLOT(digit_clicked()));
    connect(ui->pushButton_8, SIGNAL(released()), this,SLOT(digit_clicked()));
    connect(ui->pushButton_9, SIGNAL(released()), this,SLOT(digit_clicked()));
    connect(ui->pushButton_plusminus, SIGNAL(released()), this,SLOT(unaryOperatorClicked()));
    connect(ui->pushButton_mod, SIGNAL(released()), this,SLOT(unaryOperatorClicked()));
    connect(ui->pushButton_plus, SIGNAL(released()), this,SLOT(binaryOperatorClicked()));
    connect(ui->pushButton_minus, SIGNAL(released()), this,SLOT(binaryOperatorClicked()));
    connect(ui->pushButton_multiply, SIGNAL(released()), this,SLOT(binaryOperatorClicked()));
    connect(ui->pushButton_divide, SIGNAL(released()), this,SLOT(binaryOperatorClicked()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digit_clicked(){
 QPushButton *button = (QPushButton*)sender();
double lnumber;
QString newlnumber;
 if((ui->pushButton_plus->isChecked() || ui->pushButton_minus->isChecked() ||
         ui->pushButton_multiply->isChecked() || ui->pushButton_divide->isChecked()))// && (!uSecNum))
{
     lnumber = button->text().toDouble();
     uSecNum = true;
     newlnumber = QString::number(lnumber,'g',15);
 }
 else if(ui->label->text().contains('.') && button->text() == "0"){
     newlnumber = ui->label->text() + button->text();

     }

 else{
      lnumber = (ui->label->text() + button->text()).toDouble();

      newlnumber = QString::number(lnumber,'g',15);

          }

ui->label->setText(newlnumber);
}

void MainWindow::on_pushButton_decimal_released()
{
    ui->label->setText(ui->label->text() + '.');
}

void MainWindow::unaryOperatorClicked(){
     QPushButton *button = (QPushButton*)sender();
     if(button->text() == "+/-"){
         double lnumber = ui->label->text().toDouble();
         lnumber = lnumber * (-1);
         QString newlnumber = QString::number(lnumber,'g',15);
         ui->label->setText(newlnumber);
     }
     else if(button->text() == "%"){
         double lnumber = ui->label->text().toDouble();
         lnumber = lnumber * (0.01);
         QString newlnumber = QString::number(lnumber,'g',15);
         ui->label->setText(newlnumber);
     }

}



void MainWindow::on_pushButton_clear_released()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    uSecNum = true;

    ui->label->setText("0");
}


void MainWindow::on_pushButton_equal_released()
{

    double lnum, secNum;
    QString labelNum;
    secNum = ui->label->text().toDouble();
    if(ui->pushButton_plus->isChecked()){
        lnum = firstNum + secNum;
        labelNum = QString::number(lnum,'g',15);
        ui->label->setText(labelNum);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked()){

        lnum = firstNum - secNum;
        labelNum = QString::number(lnum,'g',15);
        ui->label->setText(labelNum);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_multiply->isChecked()){

        lnum = firstNum * secNum;
        labelNum = QString::number(lnum,'g',15);
        ui->label->setText(labelNum);
        ui->pushButton_multiply->setChecked(false);
    }
    else if(ui->pushButton_divide->isChecked()){

        lnum = firstNum / secNum;
        labelNum = QString::number(lnum,'g',15);
        ui->label->setText(labelNum);
        ui->pushButton_divide->setChecked(false);
    }
    uSecNum = true;
}

void MainWindow::binaryOperatorClicked(){
    QPushButton *button = (QPushButton*)sender();
    button->setChecked(true);
    firstNum = ui->label->text().toDouble();
}
