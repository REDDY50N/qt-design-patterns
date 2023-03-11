#ifndef SMARTFACTORY_H
#define SMARTFACTORY_H

#include <memory>
#include <QDebug>

class ISmartProduct {
public:
    virtual ~ISmartProduct() {
    qDebug() << "Houston I am out! My smart base is destroyed ..." << Qt::endl;
}
    virtual void doSomething() = 0;
};

class SmartProductA : public ISmartProduct {
public:
    void doSomething() override {
        /* Implementierung für ProductA */
        qDebug() << "Do something smart..." << Qt::endl;
    }
};

class SmartProductB : public ISmartProduct {
public:
    virtual void doSomething() override { /* implementation for ProductB */ }
};

class SmartProductFactory {
public:
    static std::unique_ptr<ISmartProduct> createProduct(int type) {
        if (type == 1) {
            return std::make_unique<SmartProductA>();
        }
        else if (type == 2) {
            return std::make_unique<SmartProductB>();
        }
        else {
            return nullptr;
        }
    }
};


#endif // SMARTFACTORY_H
