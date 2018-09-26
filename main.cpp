/*#######################################################
 * Einsendeaufgabe 5
######################################################*/
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <stdexcept>
#include <typeinfo>
using namespace std;

class insekt{
protected:
    int laenge, gewicht;
public:
   insekt(int,int);
   insekt();
   virtual void essen();
   virtual void ausgabe();
   ~insekt();
};
class libelle: public insekt{
    int geschwindigkeit;
public:
    libelle(int,int,int);
    libelle(int);
    virtual void ausgabe();
    virtual void essen();
    ~libelle();
};
insekt::insekt(int l,int g){
    laenge=l;
    gewicht=g;
}
insekt::insekt(){
    laenge=50;
    gewicht=30;
}
insekt::~insekt(){
    cout << "Insektendestruktor" << endl;
}
void insekt::essen(){
    laenge++;
    gewicht++;
}
void libelle::essen(){
    laenge++;
    gewicht++;
    geschwindigkeit--;
}
void insekt::ausgabe(){
    cout << "Das Insekt ist " << laenge << " cm lang und wiegt " << gewicht << " Gramm." << endl;
}
void libelle::ausgabe(){
    cout << "Die Libelle ist " << laenge << " cm lang, wiegt " << gewicht << " Gramm und fliegt so schnell: " << geschwindigkeit << endl;
}
libelle::libelle(int l, int g, int s):insekt(l,g){
    geschwindigkeit=s;
}
libelle::libelle(int s){
    geschwindigkeit=s;
}
libelle::~libelle(){
    cout << "Libellendestruktor" << endl;
}
int main()
{

    insekt* linsekt = new insekt();
    libelle* llibelle = new libelle(99);
    libelle* llibelle2 = new libelle(1,2,3);
    libelle* llibelle3 = new libelle(33,33,34);
    linsekt->ausgabe();
    linsekt->essen();
    linsekt->ausgabe();
    llibelle->ausgabe();
    llibelle->essen();
    llibelle->ausgabe();
    llibelle2->ausgabe();
    llibelle2->essen();
    llibelle2->ausgabe();
    llibelle3->ausgabe();
    llibelle3->essen();
    llibelle3->ausgabe();
    delete linsekt;
    delete llibelle;
    delete llibelle2;
    delete llibelle3;
    return 0;
}
