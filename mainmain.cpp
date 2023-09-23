#include <iostream>


using namespace std;

class Apartment{
public:
    int residents = 2;
    int squares = 100;

    void maarita(){
        cout << "Asunto maaritetty. Asukkaita: " << residents << " Nelioita: " << squares << endl;
    }
    double laskeKulutus(double hinta){
        double kulutus = residents * squares * hinta;
        return kulutus;
    }
    Apartment(){
        cout << "Asunto luotu" << endl;
    }
};

class Kerros : virtual public Apartment{
public:
    Apartment as1;
    Apartment as2;
    Apartment as3;
    Apartment as4;

    void maaritaAsunnot(){
        cout << "Maaritetaan 4 kpl kerroksen asuntoja" << endl;
        for(int i = 0; i < 4; i++){
            maarita();
        }
    }
    double laskeKulutus(double hinta){
        double kulutus = residents * squares * hinta * 4;
        return kulutus;
    }
    Kerros(){
        cout << "The floor has been created" << endl;
    }
};

class Katutaso : virtual public Kerros, virtual public Apartment{
public:
    Apartment as1;
    Apartment as2;

    void maaritaAsunnot(){
        cout << "Defining 2 katutaso apartments" << endl;
        maarita();
        maarita();
        cout << "defining 4 katutaso siding apartments" << endl;
        for(int i = 0; i < 4; i++){
            maarita();
        }
    }
    double laskeKulutus(double hinta){


        double kulutus = residents * squares * hinta * 6;
        return kulutus;
    }
    Katutaso(){
        cout << "Katutaso luotu" << endl;
    }
};

class Kerrostalo : virtual public Kerros, public Katutaso{
private:
    Katutaso eka;
    Kerros toinen;
    Kerros kolmas;
public:
    double laskeKulutus(double hinta){
        double kulutus = residents * squares * hinta * 14;
        return kulutus;
    }
    Kerrostalo(){
        cout << "Kerrostalo luotu" << endl;
        eka.maaritaAsunnot();
        toinen.maaritaAsunnot();
        kolmas.maaritaAsunnot();
    }
};
