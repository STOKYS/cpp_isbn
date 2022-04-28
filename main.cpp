#include <iostream>


#include "Kniha.hpp"


using namespace std;


int main() {

    cout << "Kniha k1 vytvorena vychozim konstruktorem" << endl;
    Kniha k1;
    cout << "Title:  " << k1.getTitle() << endl;
    cout << "Author:  " << k1.getAuthor() << endl;
    cout << "ISBN:  " << k1.getIsbn() << k1.getParsed() << endl << endl;

    cout << "Kniha k2 vytvorena s parametry" << endl;
    Kniha k2("Naucte se C++ za 21 dni", "Jesse Liberty", "978-80-251-1583-1");
    cout << k2.getAll() << endl;

    cout << "Kniha k3 vytvorena kopirovacim konstruktorem" << endl;
    Kniha k3 = k2;
    cout << k3 << endl;

    while (true) {
        string title;
        string author;
        string isbn;
        cout << "Set title:  ";
        getline(cin, title);
        cout << "Set author: ";
        getline(cin, author);
        cout << "Set ISBN:   ";
        getline(cin, isbn);
        cout << "Kniha k1 upravena s parametry" << endl;
        k1.setAll(title, author, isbn);
        cout << k1 << endl;
    }
}
