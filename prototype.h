#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <QtCore/QDebug>
#include <QtCore/QObject>
#include <QtCore/QSharedPointer>

/*!
 *  @brief Prototype - Beispielhaft Implementierung des Prototype-Patterns (Creational)
 *
 *  Anwendung:
 *  Vorhandene Objekte klonen/kopieren ohne unseren Code von deren Klassen abhängig zu machen
 *
 *  @example example.cpp
 *  Folgendes Code-Beispiel verdeutlicht das klonen eines Objekts:
 *
 *  @code{.cpp}
 *  // Star Wars Stormtrooper Clone Mnemonics:
 *   QSharedPointer<FighterPrototype> StromtrooperBoss(new FighterPrototype);
 *   StromtrooperBoss->setEnergyVal(150);
 *
 *   QSharedPointer<FighterPrototype> StromtrooperClone1(StromtrooperBoss->clone());
 *   QSharedPointer<FighterPrototype> StromtrooperClone2(StromtrooperBoss->clone());
 *   StromtrooperClone2->setEnergyVal(180);
 *
 *   qDebug() << "Energy of StromtrooperBoss: " << StromtrooperBoss->energy();
 *   qDebug() << "Energy of StromtrooperBoss: " << StromtrooperClone1->energy();
 *   qDebug() << "Energy of StromtrooperBoss: " << StromtrooperClone2->energy();
 *  @endcode
 */
class FighterPrototype : public QObject {
    Q_OBJECT

public:
    /**
     * @brief Konstruktor
     * @param parent Der übergeordnete QObject-Pointer, falls vorhanden
     */
    FighterPrototype(QObject *parent = nullptr) : QObject(parent), m_energy(0) {}

    /**
     * @brief Copy-Konstruktor
     * @param other Das zu kopierende Objekt (ein Klon-Krieger)
     */
    FighterPrototype(const FighterPrototype &other) : QObject(other.parent()), m_energy(other.m_energy) {}

    /**
     * @brief Getter-Funktion für das Attribut m_energy
     * @return Der aktuelle Wert von m_energy (Energielevel des Kämpfers)
     */
    int energy() const { return m_energy; }

    /**
     * @brief Setter-Funktion für das Attribut m_energy
     * @param energy Der neue Wert für m_energy (Energielevel des Kämpfers)
     */
    void setEnergyVal(int energy) { m_energy = energy; }

    /**
     * @brief Virtuelle Methode zur Erstellung eines Klon-Kämpfers (Kopie des aktuellen Objekts)
     *
     * Diese Methode gibt einen Zeiger auf eine neue Instanz von <FighterPrototype> zurück,
     * die eine exakte Kopie des aktuellen Objekts ist. Der Rückgabewert muss von dem Anrufer freigegeben werden.
     *
     * @return Ein Zeiger auf eine neue Instanz von <FighterPrototype>
     */
    virtual FighterPrototype *clone() const { return new FighterPrototype(*this); }

private:
    int m_energy; /*! Energielevel des Klon-Kämpfers */
};


#endif // PROTOTYPE_H
