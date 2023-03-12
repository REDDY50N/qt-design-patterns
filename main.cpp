// ==============================================
// DESIGN PATTERN
// ==============================================
// Date:    02/2023
// Purpose: Playground for C++ Design Patterns
// ==============================================

// Hint:
// choose which pattern to test by uncomment the define
//#define SINGLETON
//#define FACTORY
#define PROTOTYPE

#ifdef SINGLETON
#include "singleton.h"
#endif

#ifdef FACTORY
#include "factory.h"
#include "smartfactory.h"
#endif

#ifdef PROTOTYPE
#include "prototype.h"
#endif

#include <QCoreApplication>
#include <iostream>


// ==============================================
// MAIN
// ==============================================
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /// SINGLETON:
#ifdef SINGLETON
    SimpleSingleton::instance().bar();
#endif

    /// PROTOTYPE:
#ifdef SINGLETON
    SimpleSingleton::instance().bar();
#endif

    /// FACTORY:
#ifdef FACTORY
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
#endif

    return a.exec();
}
