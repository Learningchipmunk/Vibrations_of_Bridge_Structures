#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_simulateButton_clicked();

    void verifyInput();
private:
    Ui::MainWindow *ui;

    bool connectToVerifyInput(const QLineEdit *lineEdit);
};

#endif // MAINWINDOW_H
