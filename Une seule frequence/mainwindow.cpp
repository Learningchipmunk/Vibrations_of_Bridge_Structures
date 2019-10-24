#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "simplelinechart.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->n->setText("40000");
    ui->dt->setText("0.0001");
    ui->omega->setText("333.45");
    ui->ymin->setText("-2");
    ui->ymax->setText("2");

    connectToVerifyInput(ui->n);
    connectToVerifyInput(ui->dt);
    connectToVerifyInput(ui->omega);
    connectToVerifyInput(ui->ymin);
    connectToVerifyInput(ui->ymax);

}

bool MainWindow::connectToVerifyInput(const QLineEdit *lineEdit)
{
    return connect(lineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(verifyInput()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_simulateButton_clicked()
{

    double n = ui->n->text().toDouble();
    double dt = ui->dt->text().toDouble();
    double omega = ui->omega->text().toDouble();
    double ymin = ui->ymin->text().toDouble();
    double ymax = ui->ymax->text().toDouble();

    SimpleLineChart c(this,n, dt, omega, ymin, ymax);

    c.exec();

}

bool inputIsDouble (const QString & text) {
    bool conversionsOk;
    text.toDouble(&conversionsOk);
    return conversionsOk;
}

void MainWindow::verifyInput()
{
    bool inputOk =
            inputIsDouble(ui->n->text()) &&
            inputIsDouble(ui->dt->text()) &&
            inputIsDouble(ui->omega->text()) &&
            inputIsDouble(ui->ymin->text()) &&
            inputIsDouble(ui->ymax->text());

    ui->simulateButton->setDisabled(!inputOk);
}


