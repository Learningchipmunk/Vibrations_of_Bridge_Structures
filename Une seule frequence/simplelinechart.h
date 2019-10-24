#ifndef SIMPLELINECHART_H
#define SIMPLELINECHART_H

#include <QDialog>
#include "qcustomplot.h"

double f(double x,double y);
double g(double x,double O,double u);
double h(double t,double O,double u);



namespace Ui {
class SimpleLineChart;
}

class SimpleLineChart : public QDialog
{
    Q_OBJECT

public:
    explicit SimpleLineChart(QWidget *parent,
                             int n, double dt, double omega,
                             double ymin, double ymax);
    ~SimpleLineChart();

private:
    Ui::SimpleLineChart *ui;


    void RungKutta2(double (*f)(double,double,double),
                    double (*g)(double,double,double),
                    double x0, double o0,double u0,
                    double dx, int n, double *O,double *U);
};

#endif
