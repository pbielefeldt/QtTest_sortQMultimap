#include <QCoreApplication>
#include <QDebug>
#include <QMultiMap>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMultiMap<QString, QString> myMultiMap;
    myMultiMap.insert("Key1", "Value1");
    myMultiMap.insert("Key1", "Value2");
    myMultiMap.insert("Key2", "Value3");

    QStringList values = myMultiMap.values("Key1");
    foreach (const QString &value, values) {
        qDebug() << value;
    }

    return a.exec();
}
