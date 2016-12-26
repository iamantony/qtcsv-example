#include <QVariant>
#include <QList>
#include <QStringList>
#include <QDir>
#include <QDebug>

#include "qtcsv/variantdata.h"
#include "qtcsv/reader.h"
#include "qtcsv/writer.h"

int main()
{
    QVariant first(2);

    QList<QVariant> second;
    second << QVariant("pi") << 3.14159265359;

    QStringList fourth;
    fourth << "one" << "two";

    QtCSV::VariantData varData;
    varData << first << second;
    varData.addEmptyRow();
    varData.addRow(fourth);

    QString filePath = QDir::currentPath() + "/info.csv";
    if ( false == QtCSV::Writer::write(filePath, varData) )
    {
        qDebug() << "Failed to write to a file";
        return 1;
    }

    QList<QStringList> readData = QtCSV::Reader::readToList(filePath);
    for ( int i = 0; i < readData.size(); ++i )
    {
        qDebug() << readData.at(i).join(",");
    }

    return 0;
}
