#include "factory.h"
#include "smartfactory.h"

#include <QCoreApplication>
#include <iostream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    /// FACTORY:
    // Objekt der Klasse ProductA mit  Factory erzeugen:
    IProduct* product = ProductFactory::createProduct("A");

    // Produkt verwenden:
    product->doSomething();

    // Produkt freigeben
    delete product;


    /// SMART FACTORY:
    std::unique_ptr<ISmartProduct> smartproduct = SmartProductFactory::createProduct(1);
    if (smartproduct != nullptr) {
        smartproduct->doSomething();
    } // smartproduct wird automatisch gelöscht, wenn der Smart Pointer out of scope geht


    /// TODO:
    /// - QScopedPointer statt std::unique_ptr
    /// - QScopedPointer für Objekte mit begrenztem Gültigkeitsbereich zu verwenden,
    ///   bei denen der Eigentümer des Objekts klar definiert ist

    /*

    #include <QScopedPointer>

    class MyClass {
    public:
        MyClass() {
            // Konstruktor
        }
        ~MyClass() {
            // Destruktor
        }
    };

    int main() {
        QScopedPointer<MyClass> ptr(new MyClass());
        // Benutze ptr hier
        return 0;
    }

     */

    return a.exec();
}
