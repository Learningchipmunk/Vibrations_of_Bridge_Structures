/********************************************************************************
** Form generated from reading UI file 'simplelinechart.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLELINECHART_H
#define UI_SIMPLELINECHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_SimpleLineChart
{
public:
    QCustomPlot *customPlot;

    void setupUi(QDialog *SimpleLineChart)
    {
        if (SimpleLineChart->objectName().isEmpty())
            SimpleLineChart->setObjectName(QStringLiteral("SimpleLineChart"));
        SimpleLineChart->resize(400, 300);
        customPlot = new QCustomPlot(SimpleLineChart);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(10, 10, 371, 271));

        retranslateUi(SimpleLineChart);

        QMetaObject::connectSlotsByName(SimpleLineChart);
    } // setupUi

    void retranslateUi(QDialog *SimpleLineChart)
    {
        SimpleLineChart->setWindowTitle(QApplication::translate("SimpleLineChart", "Oscillations Plot", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SimpleLineChart: public Ui_SimpleLineChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLELINECHART_H
