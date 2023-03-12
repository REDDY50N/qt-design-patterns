#ifndef SINGLETON_H
#define SINGLETON_H

#include <QDebug>

/*!
 *  @brief SimpleSingleton - Einfache Implementierung des Singleton-Patterns
 *
 *  Singleton stellt sicher, dass eine Klasse nur eine Instanz hat,
 *  und gleichzeitig einen globalen Zugriffspunkt auf diese Instanz bereitstellt.
 *
 *  Beispiel einer Singleton Implementierung mit privaten Datenmembern und
 *  öffentlichen Methoden.
 *
 *  @example example.cpp
 *  Folgendes Code-Beispiel verdeutlicht den Methodenaufruf:
 *
 *  @code{.cpp}
 *  SimpleSingleton::instance().foo();
 *  SimpleSingleton::instance().bar();
 *  @endcode
 */
class SimpleSingleton {
public:
    /**
     *  @brief Singleton Instanz
     *
     *  Der Zugriff auf die öffentlichen Methoden erfolgt ausschließlich
     *  über diese statische instance() Methode erfolgen.
     *
     *  @return gibt die Singleton-Instanz zurück
     */
    static SimpleSingleton& instance() {
        static SimpleSingleton instance;
        return instance;
    }

    /**
     *  @brief Öffentliche Methoden
     *
     *  Der Aufruf muss mit MySingleton::instance() erfolgen,
     *  damit auf die einzige Instanz der Klasse zuzugreifen wird.
     */
    void foo() { qDebug() << "Houston please create some singleton foo..."; }
    void bar() { qDebug() << "Houston please create some singleton bar..."; }

private:
    /**
     *  @brief Beschreibung des Konstruktors
     *
     *  Kopierkonstruktor und Zuweisungsoperator müssen private sein,
     *  um zu verhindern, dass der Benutzer eine neue Instanz der Klasse erstellt.
     */
    SimpleSingleton() { /* ... */ }
    SimpleSingleton(const SimpleSingleton&) = delete;
    SimpleSingleton& operator=(const SimpleSingleton&) = delete;

    // Instanzvariablen:
    int myVariable; /**< Beschreibung der Instanzvariable */
};



#endif // SINGLETON_H
