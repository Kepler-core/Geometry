#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGeometry.h"

class QtGeometry : public QMainWindow
{
    Q_OBJECT

public:
    QtGeometry(QWidget *parent = nullptr);
    ~QtGeometry();

private:
    Ui::QtGeometryClass ui;
};
