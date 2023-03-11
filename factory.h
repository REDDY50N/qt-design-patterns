#ifndef FACTORY_H
#define FACTORY_H

/*!
 * Factory Pattern Implemetation
 *
 * Anwendung:
 * - Flexibilität und Wartbarkeit
 * - Komplexität der Objekterstellung zu reduzieren
 *
 * Funktionsweise:
 * - Erstellung von Objekten an eine separate Factory-Klasse delegiert
 *
 * Beschreibung:
 * Das Factory Pattern sinnvoll, wenn ...
 *  - mehrere Klassen mit unterschiedlicher Funktionalität, aber gemeinsamer Schnittstelle
 *
 *  - das Factory Pattern kann auch hilfreich sein, wenn sich die Implementierung der Klassen im Laufe der Zeit ändern kann,
 *    und die Anwendung flexibel bleiben muss, um Änderungen zu ermöglichen
 *
 *  - bspw. um unterschiedliche Objekte je nach Benutzer- oder Systemeinstellungen zu erstellen
 *
 */

#include <QString>
#include <QDebug>

// Interface-Klasse
class IProduct
{
public:
    virtual ~IProduct() {
        qDebug() << "Houston I am out! My base is destroyed ..." << Qt::endl;
    }

    //! pure virtual function (=0)
    //! die erbende Klasse MUSS für jede virtuelle Methode eine Implementierung bereistellen
    virtual void doSomething() = 0;
    //virtual void doSomethingElse() = 0;
};

// Konkrete Implementierungsklassen
class ProductA : public IProduct
{
public:
    void doSomething() override {
        /* Implementierung für ProductA */
        qDebug() << "Do something ..." << Qt::endl;
    }
};

class ProductB : public IProduct
{
public:
    void doSomething() override {
        /* Implementierung für ProductB */
        qDebug() << "Do something ..." << Qt::endl; }
};

// Factory-Klasse
class ProductFactory
{
public:
    static IProduct* createProduct(const QString& productType)
    {
        if (productType == "A")
            return new ProductA;
        else if (productType == "B")
            return new ProductB;
        else
            return nullptr;
    }
};


#endif // FACTORY_H
