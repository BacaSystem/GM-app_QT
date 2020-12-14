#ifndef MODEL_H
#define MODEL_H

#include <QAbstractItemModel>
#include "unit.h"

#include <QDebug>

class Model : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit Model(QVector<Unit>& units, QObject *parent = nullptr) : QAbstractTableModel(parent), collection(units){}

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;


    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    bool insertRows(int position, int rows, const QModelIndex& index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex& index = QModelIndex()) override;

    //bool insertColums(int position, int rows, const QModelIndex& index = QModelIndex()) override;
    //bool removeColums(int position, int rows, const QModelIndex& index = QModelIndex()) override;

private:
    QVector<Unit> collection;
    QStringList stringList;
};

#endif // MODEL_H
