#include "model.h"

int Model::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : collection.size();
}

int Model::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 11;
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
        else if (index.column() == 1)
            return collection.at(index.row()).getHp();
        else if (index.column() == 2)
            return collection.at(index.row()).getInitiative();
        else if(index.column() == 3)
            return collection.at(index.row()).getWt();
        else if(index.column() == 4)
            return collection.at(index.row()).getZr();

        else if(index.column() == 5)
            return collection.at(index.row()).getArmor().at(1);
        else if(index.column() == 6)
            return collection.at(index.row()).getArmor().at(20);
        else if(index.column() == 7)
            return collection.at(index.row()).getArmor().at(85);
        else if(index.column() == 8)
            return collection.at(index.row()).getArmor().at(60);
        else if(index.column() == 9)
            return collection.at(index.row()).getArmor().at(40);
        else if(index.column() == 10)
            return collection.at(index.row()).getArmor().at(95);
        return QVariant();
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
            default:
                break;
        }
        return QVariant();
    }
    else
        return QString("");
}

bool Model::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);

    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for(int row = 0; row < rows; ++row)
    {
        collection.insert(position, Unit());
    }
    endInsertRows();

    return true;
}

bool Model::removeRows(int position, int rows, const QModelIndex &index)
 {
    Q_UNUSED(index);

    beginRemoveRows(QModelIndex(), position, position+rows-1);

    for (int row = 0; row < rows; ++row)
        collection.removeAt(position);

    endRemoveRows();
    return true;
}

bool Model::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole)
    {
        const int row = index.row();
        auto unit = collection.value(row);

        switch (index.column()) {
        case 0:
            unit.setName(value.toString());
            break;
        case 1:
            unit.setHp(value.toInt());
            break;
        case 2:
            unit.setInitiative(value.toInt());
            break;
        case 3:
            unit.setWt(value.toInt());
            break;
        case 4:
            unit.setZr(value.toInt());
            break;
        case 5:
            unit.setHArmor(value.toInt());
            break;
        case 6:
            unit.setRHArmor(value.toInt());
            break;
        case 7:
            unit.setRLArmor(value.toInt());
            break;
        case 8:
            unit.setBArmor(value.toInt());
            break;
        case 9:
            unit.setLHArmor(value.toInt());
            break;
        case 10:
            unit.setLLArmor(value.toInt());
            break;
        }

        collection.replace(row, unit);
        //std::sort(collection.begin(), collection.end());
        //std::sort(collection.begin(), collection.end(), [](const Unit& a, const Unit& b) {return a.getInitiative() < b.getInitiative();});
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});

        return true;
    }
    return false;
}

Qt::ItemFlags Model::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index);
}

bool Model::resetModel()
{
    beginResetModel();

    removeRows(0, collection.count());

    endResetModel();

    return true;
}

const QVector<Unit>& Model::getUnits() const
{
    return collection;
}


