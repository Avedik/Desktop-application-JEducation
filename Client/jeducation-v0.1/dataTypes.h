#ifndef DATATYPES_H
#define DATATYPES_H

#include <QDataStream>
#include <QMetaType>

enum class DataTypes : qint32 {
    JSON, IMAGE
};
Q_DECLARE_METATYPE(DataTypes);

QDataStream& operator<<(QDataStream & ds, DataTypes t) {
    return ds << (qint32)t;
}

QDataStream& operator>>(QDataStream & ds, DataTypes& t) {
    qint32 val;
    ds >> val;
    if (ds.status() == QDataStream::Ok)
        t = DataTypes(val);
    return ds;
}

#endif // DATATYPES_H