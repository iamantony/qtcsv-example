#include <algorithm>

#include <QVariant>
#include <QList>
#include <QStringList>
#include <QDir>
#include <QDebug>

#include "qtcsv/variantdata.h"
#include "qtcsv/reader.h"
#include "qtcsv/writer.h"

void WriteToFile(const QString& filePath);
void ReadAndPrint(const QString& filePath);
void ReadAndProcess(const QString& filePath);

int main()
{
    QString filePath = QDir::currentPath() + "/info.csv";
    WriteToFile(filePath);
    ReadAndPrint(filePath);
    ReadAndProcess(filePath);

    return 0;
}

void WriteToFile(const QString& filePath)
{
    qDebug() << "=== Write to csv-file ==";

    QVariant first(2);

    QList<QVariant> second;
    second << QVariant("pi") << 3.14159265359;

    QStringList fourth;
    fourth << "one" << "two";

    QtCSV::VariantData varData;
    varData << first << second;
    varData.addEmptyRow();
    varData.addRow(fourth);

    if ( false == QtCSV::Writer::write(filePath, varData) )
    {
        qDebug() << "Failed to write to a file";
    }

    qDebug() << "... Write is OK";
}

void ReadAndPrint(const QString& filePath)
{
    qDebug() << "=== Read csv-file and print it content to terminal ==";

    QList<QStringList> readData = QtCSV::Reader::readToList(filePath);
    for ( int i = 0; i < readData.size(); ++i )
    {
        qDebug() << readData.at(i).join(",");
    }
}

void ReadAndProcess(const QString& filePath)
{
    qDebug() << "=== Read csv-file and process it content ==";

    // Create processor that:
    // - replate empty lines by some data
    // - revert elements in a row and save them into internal container
    class RevertProcessor : public QtCSV::Reader::AbstractProcessor
    {
    public:
        QList< QStringList > data;

        virtual void preProcessRawLine(QString& line)
        {
            if (line.isEmpty())
            {
                line = "Say 'No' to empty lines!";
            }
        }

        virtual bool processRowElements(const QStringList& elements)
        {
            QList<QString> revertedElements(elements);
            std::reverse(revertedElements.begin(), revertedElements.end());

            data.push_back(QStringList(revertedElements));
            return true;
        }
    };

    RevertProcessor processor;
    if (false == QtCSV::Reader::readToProcessor(filePath, processor))
    {
        qDebug() << "Failed to read file";
        return;
    }

    // Print rows with reverted elements
    for ( int i = 0; i < processor.data.size(); ++i )
    {
        qDebug() << processor.data.at(i).join(",");
    }
}
