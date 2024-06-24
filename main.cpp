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

    QStringList values = myMultiMap.values("Key1");
    foreach (const QString &value, values) {
        qDebug() << value;
    }

    // this actually fixes it
	//const QString key("Key1");
    //QMultiMap<QString, QString>::iterator i = myMultiMap.upperBound(key);
    //QMultiMap<QString, QString>::iterator end = myMultiMap.lowerBound(key);

    //while (i != end) {
    //    --i;
    //    qDebug() << i.value();
    //}

    return a.exec();
}
