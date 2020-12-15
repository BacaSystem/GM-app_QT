#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startdialog.h"
#include "damagedialog.h"
#include "creatordialog.h"
#include "model.h"

#include <QItemSelection>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new Model();

    ui->tableView->setModel(model);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableView->verticalHeader()->hide();
    ui->tableView->setColumnHidden(2, true);
    ui->tableView->setColumnHidden(3, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->setColumnHidden(5, true);
    ui->tableView->setColumnHidden(6, true);
    ui->tableView->setColumnHidden(7, true);
    ui->tableView->setColumnHidden(8, true);
    ui->tableView->setColumnHidden(9, true);
    ui->tableView->setColumnHidden(10, true);

    ui->tableView->update();

    QItemSelectionModel* select = ui->tableView->selectionModel();
    connect(select, &QItemSelectionModel::currentRowChanged, this, &MainWindow::updateView);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}

void MainWindow::updateView(const QModelIndex &current, const QModelIndex &previuos)
{
    Q_UNUSED(previuos);

    auto unit = model->getUnits().value(current.row());

    ui->headLabel->setText(QString::number (unit.getArmor().at(1)));
    ui->handRLabel->setText(QString::number(unit.getArmor().at(20)));
    ui->legRLabel->setText(QString::number (unit.getArmor().at(85)));

    ui->bodyLabel->setText(QString::number (unit.getArmor().at(60)));
    ui->handLLabel->setText(QString::number(unit.getArmor().at(40)));
    ui->legLLabel->setText(QString::number (unit.getArmor().at(95)));
}

void MainWindow::addUnit(const Unit &unit)
{
    QVector<Unit> collection = model->getUnits();

    auto i = std::lower_bound(collection.begin(), collection.end(), unit);

    model->insertRows(i - collection.begin(), 1);

    QModelIndex index = model->index(i - collection.begin(),0);
    model->setData(index, unit.getName(), Qt::EditRole);

    index = model->index(i - collection.begin(),1);
    model->setData(index, unit.getHp(), Qt::EditRole);
    index = model->index(i - collection.begin(),2);
    model->setData(index, unit.getInitiative(), Qt::EditRole);
    index = model->index(i - collection.begin(),3);
    model->setData(index, unit.getWt(), Qt::EditRole);
    index = model->index(i - collection.begin(),4);
    model->setData(index, unit.getZr(), Qt::EditRole);

    index = model->index(i - collection.begin(),5);
    model->setData(index, unit.getArmor().at(1), Qt::EditRole);
    index = model->index(i - collection.begin(),6);
    model->setData(index, unit.getArmor().at(20), Qt::EditRole);
    index = model->index(i - collection.begin(),7);
    model->setData(index, unit.getArmor().at(85), Qt::EditRole);
    index = model->index(i - collection.begin(),8);
    model->setData(index, unit.getArmor().at(60), Qt::EditRole);
    index = model->index(i - collection.begin(),9);
    model->setData(index, unit.getArmor().at(40), Qt::EditRole);
    index = model->index(i - collection.begin(),10);
    model->setData(index, unit.getArmor().at(95), Qt::EditRole);
}

void MainWindow::damageUnit(const int target, const int dmg, const int loc)
{
    Unit taker = model->getUnits().at(target);
    taker.TakeDmg(dmg, loc);
    model->setData(model->index(target,1), taker.getHp());
}

void MainWindow::on_startButton_clicked()
{
    if(!isStarted)
    {
        StartDialog start;
        start.setModal(true);
        if(start.exec() == QDialog::Accepted)
        {
            addUnit(Unit("Valahujr", 15, start.getVInit()));
            addUnit(Unit("Eldrill", 15, start.getEInit()));
            addUnit(Unit("Waldemar", 15, start.getWInit()));
            addUnit(Unit("Beatrix", 15, start.getBInit()));
            addUnit(Unit("Magnus", 15, start.getMInit()));

            isStarted = true;
            ui->startButton->setText(tr("Add Unit"));
        }
    }
    else {

        CreatorDialog creator;
        creator.setModal(true);
        if(creator.exec() == QDialog::Accepted)
        {
            for(int i = 0; i < creator.getCount(); i++)
            {
                addUnit(Unit(creator.getName(),
                             creator.getK10(),
                             creator.getHp(),
                             creator.getWt(),
                             creator.getZr(),
                             creator.getArmorH(),
                             creator.getArmorRH(),
                             creator.getArmorRL(),
                             creator.getArmorB(),
                             creator.getArmorLH(),
                             creator.getArmorLL()));
            }
        }
    }
}

void MainWindow::on_resetButton_clicked()
{
    model->resetModel();
    isStarted = false;
    ui->startButton->setText(tr("Start"));
}

void MainWindow::on_dmgButton_clicked()
{
    if(isStarted)
    {
        DamageDialog dmgDialog(model->getUnits());
        dmgDialog.setModal(true);
        if(dmgDialog.exec() == QDialog::Accepted)
            damageUnit(dmgDialog.getTarget(), dmgDialog.getDmg(), dmgDialog.getLoc());
    }
}
