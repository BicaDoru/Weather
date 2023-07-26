#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Weather.h"
#include "Service.h"
#include <QPushButton>
#include <QMessageBox>

class Weather : public QMainWindow
{
    Q_OBJECT

public:
    Weather(Service&, QWidget* parent = nullptr);

    void populate();

    ~Weather();

private:
    Ui::WeatherClass ui;

    Service service;

    void connectButtonFilter();

    void handleFilter();

    void handleNrHours();

    void connectButtonComputeTotal();
};
