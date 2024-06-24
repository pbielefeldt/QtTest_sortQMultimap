# QtTest_sortQMultimap #
How does Qt sort Multimaps?

Someone else already asked for it:
https://www.qtcentre.org/threads/71890-How-to-reverse-the-order-of-the-same-keys-when-inserted-using-QMultiMap

I tested it out.

## Build ##

```sh
qmake -project
qmake

make
```

Run with
```sh
./QtTest_sortQMultimap
```

## Result ##

As I added
```C++
    myMultiMap.insert("Key1", "Value1");
    myMultiMap.insert("Key1", "Value2");
```

my expectation was to get
```sh
"Value1"
"Value2"
```

as a result.
That is what I understand should happen if the QMultiMap, like other associative containers in Qt, maintains the elements in a sorted order.
However, I see that the result is just reversed
```sh
"Value1"
"Value2"
```
