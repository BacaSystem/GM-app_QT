#ifndef MODEL_H
#define MODEL_H

#include <QAbstractItemModel>
#include "unit.h"

class Model : public QAbstractTableModel
{
Q_OBJECT

public:
    explicit Model(QObject *parent = nullptr) : QAbstractTableModel(parent){}
    explicit Model(const QVector<Unit>& units, QObject *parent = nullptr) : QAbstractTableModel(parent), collection(units){}

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;


    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    bool insertRows(int position, int rows, const QModelIndex& index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex& index = QModelIndex()) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    bool resetModel();

    const QVector<Unit>& getUnits() const;


private:
    QVector<Unit> collection;
};

#endif // MODEL_H
