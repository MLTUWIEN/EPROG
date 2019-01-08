#include "kunde.hpp"

using namespace std;

string Kunde::getName() {
    return name;
}
double Kunde::getKontostand() {
    return kontostand;
}
int Kunde::getPin() {
    return pin;
}
void Kunde::setName(string n) {
    name = n;
}
void Kunde::setKontostand(double k) {
    kontostand = k;
}
void Kunde::setPin(int p) {
    pin = p;
}

void Kunde::printBalance() {
    cout << "Aktueller Kontostand: " << kontostand << endl;
}
bool Kunde::checkPIN() {
    int p;
    cout << "PIN eingeben: ";
    cin >> p;
    return (pin == p);
}
void Kunde::drawMoney() {
    double x;
    if (checkPIN()) {
        cout << "Betrag eingeben: ";
        cin >> x;
        if (x <= kontostand) {
            kontostand -= x;
            cout << x << " Euro abgehoben" << endl;
        } else {
            cout << "Nicht genug Geld am Konto" << endl;
        }
    } else {
        cout << "Falsche PIN" << endl;
    }
    printBalance();
}

int main() {
    string name;
    int pin;
    Kunde kunde = Kunde();
    kunde.setKontostand(100);

    cout << "Name: ";
    cin >> name;
    kunde.setName(name);

    cout << "PIN: ";
    cin >> pin;
    kunde.setPin(pin);

    kunde.printBalance();
    kunde.drawMoney();
    return 0;
}