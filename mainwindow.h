#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addUnit(const Unit& unit);

    void damageUnit(const int target, const int dmg, const int loc);

    void updateView(const QModelIndex& current, const QModelIndex& previuos);

private slots:
    void on_startButton_clicked();

    void on_resetButton_clicked();

    void on_dmgButton_clicked();

private:
    Ui::MainWindow *ui;
    Model* model;
    bool isStarted = false;
};
#endif // MAINWINDOW_H
