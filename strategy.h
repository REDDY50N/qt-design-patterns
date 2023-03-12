#ifndef STRATEGY_H
#define STRATEGY_H

/**
 * @brief Legacy Code
 *
 * Alle
 *
 */
class Calculator {
public:
    double calculate(int calculationType, double x, double y) {
        if (calculationType == 1) {
            return x + y;
        } else if (calculationType == 2) {
            return x - y;
        } else if (calculationType == 3) {
            return x * y;
        } else if (calculationType == 4) {
            return x / y;
        }
        // ...
    }
};

/**
 * @brief Strategy Interface
 *
 * implementiert verschiedene Versionen des Algorithmus
 * der durch die Strategy-Schnittstelle definiert ist.
 */
class CalculationStrategy {
public:
    virtual double calculate(double x, double y) = 0;
};

/**
 * @brief Konkrete Strategien werden hier implementiert:
 */
class AdditionStrategy : public CalculationStrategy {
public:
    double calculate(double x, double y) override {
        return x + y;
    }
};

class SubtractionStrategy : public CalculationStrategy {
public:
    double calculate(double x, double y) override {
        return x - y;
    }
};

class MultiplicationStrategy : public CalculationStrategy {
public:
    double calculate(double x, double y) override {
        return x * y;
    }
};

class DivisionStrategy : public CalculationStrategy {
public:
    double calculate(double x, double y) override {
        return x / y;
    }
};




#endif // STRATEGY_H
