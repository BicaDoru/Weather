#include "Weather.h"

Weather::Weather(Service& service, QWidget* parent)
    : service(service), QMainWindow(parent)
{
    ui.setupUi(this);
    this->populate();
    this->connectButtonFilter();
    this->connectButtonComputeTotal();
}

void Weather::populate()
{

    this->service.sortDays();

    for (auto& day : this->service.getDays())
    {

        this->ui.listWidget->addItem(QString::fromStdString(day.toString()));
    }

}


Weather::~Weather()
{}

void Weather::connectButtonFilter()
{

    QObject::connect(this->ui.filterButton, &QPushButton::clicked, this, &Weather::handleFilter);
}

void Weather::handleFilter()
{
    string filteredIntervals;
    int prob = this->ui.inputLine->text().toInt();

    for (auto& day : this->service.filterByProb(prob))
    {
        filteredIntervals += day.toString() + "\n";
    }

    QString message = QString::fromStdString(filteredIntervals);

    QMessageBox::information(this, "Filtered intervals:", message);
}

void Weather::connectButtonComputeTotal()
{

    QObject::connect(this->ui.computeTotalButton, &QPushButton::clicked, this, &Weather::handleNrHours);

}

void Weather::handleNrHours()
{
    int start = this->ui.startHourLineEdit->text().toInt();
    string descrption = this->ui.descriptionLineEdit->text().toStdString();

    int nrHours = this->service.nrHours(start, descrption);

    if (nrHours == 0)
    {
        QString error = QString::fromStdString("Error, no intervals were found");
        QMessageBox::warning(this, "Error", error);
        return;
    }

    QString message = QString::fromStdString(to_string(nrHours));
    QMessageBox::information(this, "Nr of hours", message);

}
