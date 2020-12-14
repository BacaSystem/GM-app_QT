#include "model.h"

int Model::rowCount(const QModelIndex &parent) const
{
    return collection.count();
}

int Model::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    if(index.row() >= collection.size())
        return QVariant();
    if(role == Qt::DisplayRole){
        if(index.column() == 0)
            return collection.at(index.row()).getName();
                    //stringList.at(index.row());
        else
            return collection.at(index.row()).getHp();
                    //QString("HP %1").arg(index.row()+1);
    }
    else
        return QVariant();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();
    if(orientation == Qt::Horizontal){
        switch (section) {
            case 0:
                return QString("Name");
            case 1:
                return QString("Health");
        }
        return QVariant();
    }
    else
        return QString("%1").arg(50 - section + 1);
}

bool Model::insertRows(int position, int rows, const QModelIndex &index)
{
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for(int row = 0; row < rows; ++row)
    {
        //stringList.insert(position, "");
        //collection.insert(position, Unit("test", 40));
    }
    endInsertRows();

    return true;
}

bool Model::removeRows(int position, int rows, const QModelIndex &parent)
 {
     beginRemoveRows(QModelIndex(), position, position+rows-1);

     for (int row = 0; row < rows; ++row) {
         collection.removeAt(position);
     }

     endRemoveRows();
     return true;
}


