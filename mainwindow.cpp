#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startdialog.h"

#include <QDebug>

#include "model.h"
#include "QStandardItemModel"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



     units.append(*new Unit("Valahujr", 50));
     units.append(*new Unit("Eldrill", 50));
     units.append(*new Unit("Waldemar", 50));
     units.append(*new Unit("Beatrix", 50));
     units.append(*new Unit("Magnus", 50));

    //QStandardItemModel* model = new QStandardItemModel();
    //QStringList headers;
    //headers << "Valahujr" << "Waldemar" << "Beatrix" << "Eldrill";
    //model->setHorizontalHeaderLabels(headers);


    //QStandardItem item("A (0,0)");
    //model->appendRow(&item);
    //model->setItem(0,1, new QStandardItem("B (0,1)"));


    Model* model = new Model(units);

    ui->tableView->setModel(model);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->update();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}


void MainWindow::on_startButton_clicked()
{
    StartDialog start;
    start.setModal(true);
    if(start.exec() == QDialog::Accepted)
        return;
}
