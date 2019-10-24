#include "simplelinechart.h"
#include "ui_simplelinechart.h"
#include <QVector>
#include <cmath>

using namespace std;

double f(double x,double v)
{
    return v;
}

double g(double x,double O,double u)
{
    return u;
}

double Omega(333.45);

double h(double t,double y,double u)
{
    return -111189.5*y-9.8-u-392*cos(Omega*t);//100 personnes
}


SimpleLineChart::SimpleLineChart(QWidget *parent,int n, double dt, double omega,double ymin, double ymax)
    :QDialog(parent),ui(new Ui::SimpleLineChart)
{
    ui->setupUi(this);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(ui->customPlot);
    setLayout(layout);

    QVector<double> x, y;
    Omega=omega;
    int xmin=0;
    double xmax=n*dt;

    double  *v=new double[n];//temps total c'est dt*n = 4 sec ici
    double  *u=new double[n];

    SimpleLineChart::RungKutta2(g,h,0,0,0,dt,n,v,u) ;

    for (int i=0; i<n; ++i)
    {
        x.append(i*dt);
        y.append(v[i]);
    }
    delete [] v;
    delete [] u;
    // cree un graphe
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // donne des noms aux axes
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // donne les intervalles des axes
    ui->customPlot->xAxis->setRange(xmin, xmax);
    ui->customPlot->yAxis->setRange(ymin, ymax);
    ui->customPlot->replot();
}

SimpleLineChart::~SimpleLineChart()
{
    delete ui;
}


void SimpleLineChart::RungKutta2(double (*f)(double,double,double),double (*g)(double,double,double), double x0, double o0,double u0, double dx, int n, double *O,double *U)
{
    O[0]=o0;
    U[0]=u0;
    double k1f,k2f,k3f,k1g,k2g,k3g;
    for(int i(1);i<n;++i)
    {
        k1f=f(x0+dx*(i-1),O[i-1],U[i-1]);
        k1g=g(x0+dx*(i-1),O[i-1],U[i-1]);
        k2f=f(x0+dx*(i-1)+dx/2,O[i-1]+k1f*dx/2,U[i-1]+k1g*dx/2);
        k2g=g(x0+dx*(i-1)+dx/2,O[i-1]+k1f*dx/2,U[i-1]+k1g*dx/2);
        k3f=f(x0+dx*i,O[i-1]+k2f*dx,U[i-1]+k2g*dx);
        k3g=g(x0+dx*i,O[i-1]+k2f*dx,U[i-1]+k2g*dx);
        O[i]=O[i-1]+dx*(k1f+4*k2f+k3f)/6;
        U[i]=U[i-1]+dx*(k1g+4*k2g+k3g)/6;
    }
}

