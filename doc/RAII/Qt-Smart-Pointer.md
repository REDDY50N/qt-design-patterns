# RAII-Prinzip

Das RAII-Prinzip (Resource Acquisition Is Initialization) ist ein wichtiger Aspekt des Memory Managements in C++. Es sorgt dafür, dass Ressourcen automatisch freigegeben werden, wenn sie nicht mehr benötigt werden. In Qt wird das RAII-Prinzip oft mit smarten Zeigern (Smart Pointers) umgesetzt, die automatisch Speicher freigeben, wenn sie außerhalb ihres Gültigkeitsbereichs sind.

Hier sind ein paar Beispiele, wie das RAII-Prinzip in der Praxis mit smarten Zeigern in Qt funktioniert:

### Beispiel 1: QSharedPointer

`QSharedPointer` ist eine Implementierung eines Smart Pointers in Qt, der die gemeinsame Nutzung von Objekten ermöglicht. Wenn mehrere Smart Pointer ein Objekt gemeinsam nutzen, wird das Objekt automatisch freigegeben, wenn der letzte Smart Pointer seinen Gültigkeitsbereich verlässt.

```cpp
#include <QSharedPointer>

class MyClass {
public:
    MyClass() { qDebug() << "MyClass created"; }
    ~MyClass() { qDebug() << "MyClass destroyed"; }
};

int main() {
    QSharedPointer<MyClass> ptr1(new MyClass());
    {
        QSharedPointer<MyClass> ptr2 = ptr1;
        QSharedPointer<MyClass> ptr3 = ptr1;
    }
    qDebug() << "All smart pointers destroyed";
}
```

In diesem Beispiel wird `MyClass` von mehreren Smart Pointern (`ptr1`, `ptr2`, `ptr3`) gemeinsam genutzt. Das Objekt wird automatisch freigegeben, wenn der letzte Smart Pointer seinen Gültigkeitsbereich verlässt. In diesem Fall werden alle Smart Pointer am Ende des Blocks zerstört und das Objekt wird freigegeben.

### Beispiel 2: QScopedPointer

`QScopedPointer` ist ein weiterer Smart Pointer in Qt, der dazu dient, Objekte automatisch zu löschen, wenn sie nicht mehr benötigt werden. Im Gegensatz zu `QSharedPointer` ist `QScopedPointer` jedoch nur für die exklusive Nutzung eines Objekts durch einen Smart Pointer gedacht.

```cpp
#include <QScopedPointer>

class MyClass {
public:
    MyClass() { qDebug() << "MyClass created"; }
    ~MyClass() { qDebug() << "MyClass destroyed"; }
};

int main() {
    QScopedPointer<MyClass> ptr(new MyClass());
    qDebug() << "Smart pointer created";
    ptr.reset(); // Das Objekt wird sofort freigegeben
    qDebug() << "Smart pointer destroyed";
}
```

In diesem Beispiel wird `MyClass` von einem `QScopedPointer` (`ptr`) exklusiv genutzt. Wenn `ptr` seinen Gültigkeitsbereich verlässt oder `reset()` aufgerufen wird, wird das Objekt sofort freigegeben. In diesem Fall wird das Objekt freigegeben, wenn `reset()` aufgerufen wird.

### Beispiel 3: QObject und Parenting

QObject-Klassen in Qt verwalten ihre Kindobjekte mithilfe des Parenting-Systems. Wenn ein Objekt als Kind eines anderen Objekts erstellt wird, setzt Qt das Parent-Objekt automatisch als Besitzer des Kind-Objekts. Wenn das Parent-Objekt gelöscht wird, werden auch alle Kind-Objekte automatisch gelöscht.

```c++
#include <QObject>

class MyObject : public QObject {
    Q_OBJECT
public:
    MyObject(QObject* parent = nullptr) : QObject(parent) { qDebug()
```

 
