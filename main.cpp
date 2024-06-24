#include <QCoreApplication>
#include <QDebug>
#include <QMultiMap>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMultiMap<QString, QString> myMultiMap;
    myMultiMap.insert("Key1", "f Value5");
    myMultiMap.insert("Key1", "d Value4");
    myMultiMap.insert("Key1", "b Value3");
    myMultiMap.insert("Key1", "a Value2");
    myMultiMap.insert("Key1", "c Value1");
    myMultiMap.insert("Key1", "e Value7");
	
    myMultiMap.insert("Key2", "3 ValueA");
    myMultiMap.insert("Key2", "1 ValueB");
    myMultiMap.insert("Key2", "2 ValueC");
    myMultiMap.insert("Key2", "4 ValueD");

    const QString key("Key1");

    qDebug("Iterate in \"forward\" direction:\n");
    QStringList values = myMultiMap.values("Key1");
    foreach (const QString &value, values) {
        qDebug() << value;
    }

    // this actually fixes it
	qDebug("\n\nIterate in again, using \"--it\" direction:\n");
    QMultiMap<QString, QString>::iterator rit = myMultiMap.upperBound(key);
    QMultiMap<QString, QString>::iterator end = myMultiMap.lowerBound(key);

    while (rit != end) {
        --rit;
        qDebug() << rit.value();
    }

    return a.exec();
}
