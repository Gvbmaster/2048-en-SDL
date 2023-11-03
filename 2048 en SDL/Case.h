#pragma once
class Case {

private:
    int value; // Valeur de la case (0 pour une case vide, sinon une puissance de 2)

public:
    Case();
    int getValue() const;
    void setValue(int newValue);
    bool isEmpty() const;

};

