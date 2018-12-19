#include <iostream>
#include <cassert>

using namespace std;

class SparKonto {

private:

    unsigned int numnummer;
    double guthaben;
    double zinssatz;

public:

    double getZinssatz();
    void setZinssatz(double x);
    int getKontonummer();
    void setKontonummer(unsigned int k);
    void abheben(double x);
    void einzahlen(double x);
    double berechneGuthaben(int i);
};

int main(){

    int num, jahre;
    double zinssatz;
    double geld;

    SparKonto Konto ;

    cout << "Geben Sie ihre Kontonummer ein!" << endl;
    cin >> num;
    cout << "Geben Sie ihren Zinssatz ein!" << endl;
    cin >> zinssatz;

    Konto.setKontonummer(num);
    Konto.setZinssatz(zinssatz);

    for(int i = 0; i < 2; i++){

        cout << endl;
        cout << "Wieviel Geld moechten Sie einzahlen?" << endl;
        cin >> geld;

        Konto.einzahlen(geld);
    }

    for(int i = 0; i < 2; i++){

        cout << endl;
        cout << "Wieviel Geld moechten Sie abheben?" << endl;
        cin >> geld;

        Konto.abheben(geld);
    }

    cout << endl;
    cout << "Wie viele Jahre berechnen?" << endl;
    cin >> jahre;

    cout << endl;
    cout << "Mit dem Zinssatz " << Konto.getZinssatz() << " auf dem Konto " << Konto.getKontonummer();
    cout << " werden Sie in " << jahre << " Jahren " << Konto.berechneGuthaben(jahre) << " Euro haben." << endl;

    return 0;
}

double SparKonto::getZinssatz(){

    return zinssatz;
}

void SparKonto::setZinssatz(double x){

    assert(x > 0);
    zinssatz = x;
}

int SparKonto::getKontonummer(){

    return numnummer;
}

void SparKonto::setKontonummer(unsigned int k){

    assert(k > 0);
    numnummer = k;
}

void SparKonto::abheben(double x){

    if(x <= guthaben){

        guthaben -= x;

        cout << "Sie haben noch " << guthaben << " Euro auf Ihrem Konto" << endl;
    }
    else{

        cout << "ERROR: Sie haben nur " << guthaben << "Euro auf ihrem Konto" << endl;
    }
}

void SparKonto::einzahlen(double x){

    assert(x >= 0);

    guthaben += x;

    cout << "Sie haben " << guthaben << " Euro auf ihrem Konto" << endl;

}

double SparKonto::berechneGuthaben(int i){

    assert(i >= 0);

    for (int j = 0; j < i; j++){

        guthaben *= (1. + zinssatz);
    }

    return guthaben;
}



