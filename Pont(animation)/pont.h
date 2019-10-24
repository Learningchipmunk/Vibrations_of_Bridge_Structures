#ifndef PONT_H
#define PONT_H

#include <QWidget>
#include <QTimer>

#include <vector>

namespace Ui {
class Pont;
}

class Pont : public QWidget
{
    Q_OBJECT

private:
    int m;
    double dx;
    double L;
    double dt;
    double k;
    double v0;
    std::vector<double> l;
    std::vector<std::vector<double>> Y;
    QTimer timer;

public:
    explicit Pont(QWidget *parent = 0);
    ~Pont();

private slots:
    void updatePosition();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Pont *ui;
};

#endif
