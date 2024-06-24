#include <QCoreApplication>
#include <QDebug>
#include <QMultiMap>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMultiMap<QString, QString> myMultiMap;
    myMultiMap.insert(myMultiMap.upperBound("Key1"), "Key1", "e Value5");
    myMultiMap.insert(myMultiMap.upperBound("Key1"), "Key1", "c Value4");
    myMultiMap.insert(myMultiMap.upperBound("Key1"), "Key1", "a Value3");
    myMultiMap.insert(myMultiMap.upperBound("Key1"), "Key1", "b Value2");
    myMultiMap.insert(myMultiMap.upperBound("Key1"), "Key1", "d Value1");

    myMultiMap.insert("Key2", "3 ValueA");
    myMultiMap.insert("Key2", "1 ValueB");
    myMultiMap.insert("Key2", "2 ValueC");
    myMultiMap.insert("Key2", "4 ValueD");

    QString key("Key1");
    qDebug("Iterate in Key1 \"forward\" direction:\n");
    foreach (const QString &value, myMultiMap.values(key)) {
        qDebug() << value;
    }

    /*
    // this actually "fixes" it
    qDebug("\n\nIterate in again, using \"--it\" direction:\n");
    QMultiMap<QString, QString>::iterator rit = myMultiMap.upperBound(key);
    QMultiMap<QString, QString>::iterator end = myMultiMap.lowerBound(key)-1;

    --rit;
    while (rit != end) {
        qDebug() << rit.value();
        --rit;
    }
    */

    return a.exec();
}
