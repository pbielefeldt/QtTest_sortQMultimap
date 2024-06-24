# QtTest_sortQMultimap #
How does Qt sort Multimaps?

Someone else already asked for it:
https://www.qtcentre.org/threads/71890-How-to-reverse-the-order-of-the-same-keys-when-inserted-using-QMultiMap

I tested it out.

## Build ##

```sh
mkdir build
cd build
qmake ..

make
```

Run with
```sh
./QtTest_sortQMultimap
```

## Result ##

As I added
```C++
    myMultiMap.insert("Key1", "f Value5");
    myMultiMap.insert("Key1", "d Value4");
    myMultiMap.insert("Key1", "b Value3");
    myMultiMap.insert("Key1", "a Value2");
    myMultiMap.insert("Key1", "c Value1");
    myMultiMap.insert("Key1", "e Value7");
```

my expectation was to get
```sh
"f Value5"
"d Value4"
```

and so forth as a result.
That is what I understand should happen if the QMultiMap, like other associative containers in Qt, maintains the elements in a sorted order.
However, I see that the result is just reversed when iterating it and printing:
```sh
"e Value7"
"c Value1"
"a Value2"
"b Value3"
"d Value4"
"f Value5"
```

Note that I addded some letters to the front, just to make sure it isn't ordered alphabetically.


## Workaround ##

It seems possible to avoid this be manually creating a reverse iterator.
```C++
    QMultiMap<QString, QString>::iterator rit = myMultiMap.upperBound(key);
    QMultiMap<QString, QString>::iterator end = myMultiMap.lowerBound(key);

    while (rit != end) {
        --rit;
        qDebug() << rit.value();
    }
```

However, it is unclear what unwanted effects this might have tbh.
