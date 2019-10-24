#include "pont.h"
#include "ui_pont.h"
#include <QPainter>
#include <cmath>

using namespace std;

Pont::Pont(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pont)
{
    ui->setupUi(this);
    //conditions initiales
    //m=3320;
    //L=332;//Longueur du pont
    dt=0.000001;//0.000001
    m=1000;//100
    L=100;//10
    k=2438212.96;//IE/(Rho*S)
    v0=3000;//c'est la vitesse initiale du point au milieu du pont (la ou il est le plus vulnerable)
    dx=L/m;
    double dt2=dt*dt;
    double dx2=dx*dx;
    double dx4=dx2*dx2;
    for(int i(0);i<=m;++i)//Y0=0 quelquesoit x a t=0 on suppose que le pont est initialement etendu normalement
    {
        l.push_back(0);
    }
    Y.push_back(l);
    Y.push_back(l);
    Y.push_back(l);
    for(int i(2);i<m-1;++i)//la derivee au point Y[0][m/2]=v sinon le reste est nulle
    {
        if(i==m/2)
        {
            Y[1][i]=Y[0][i]+dt*v0-k*dt2/dx4*(Y[0][i+2]+Y[0][i-2]-4*Y[0][i+1]-4*Y[0][i-1]+6*Y[0][i])/2;
        }
        else
        {
            Y[1][i]=Y[0][i]-k*dt2/dx4*(Y[0][i+2]+Y[0][i-2]-4*Y[0][i+1]-4*Y[0][i-1]+6*Y[0][i])/2;
        }
    }
    //dt*v0;
    connect(&timer,SIGNAL(timeout()),this,SLOT(updatePosition()));//fonctions qui update a chaque 100ms
    timer.setSingleShot(false);//ce n'est pas un single shot!!! C'est un interval
    timer.setInterval(10);//l'interval de temps de l'update
    timer.start();//Le debut du commencement
}

void Pont::paintEvent(QPaintEvent *event){
    // My custom events....
    QPainter painter(this);
    //float Ox=this->frameSize().width()/2;
    float Ox=0;
    float Oy=this->frameSize().height()/2;
    for(int i(0);i<m;++i)
    {
        painter.drawLine(Ox+dx*i*frameSize().width()/L,Oy+Y[0][i]*this->frameSize().height(),Ox+dx*(i+1)*frameSize().width()/L,Oy+Y[0][i+1]*this->frameSize().height());
    }
    QColor white(0,0,0);
    painter.setBrush(white);
}

void Pont::updatePosition(){
    double dt2=dt*dt;
    double dx2=dx*dx;
    double dx4=dx2*dx2;
    Y[2][0]=0;//Conditions de bords, c'est un zero avec une precision de O(dx^3)
    Y[2][1]=0;
    Y[2][m-1]=0;
    Y[2][m]=0;
    for(int i(2);i<m-1;++i)
    {
        Y[2][i]=2*Y[1][i]-Y[0][i]-k*dt2/dx4*(Y[1][i+2]+Y[1][i-2]-4*Y[1][i-1]-4*Y[1][i+1]+6*Y[1][i]);
    }
    for(int i(0);i<=m;++i)//Y0=0 quelquesoit x a t=0 on suppose que le pont est initialement etendu normalement
    {
        Y[0][i]=Y[1][i];
    }
    for(int i(0);i<=m;++i)//Y0=0 quelquesoit x a t=0 on suppose que le pont est initialement etendu normalement
    {
        Y[1][i]=Y[2][i];
    }

    update();
}


Pont::~Pont()
{
    delete ui;
}
