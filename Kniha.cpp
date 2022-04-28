//
// Created by david_stocek on 4/8/22.
//

#include "Kniha.hpp"


#include <iostream>
#include <string>
#include <utility>


using namespace std;


#define DEFAULT_ISBN "978-0-321-56384-2"
#define DEFAULT_TITLE "The C++ Programming Language"
#define DEFAULT_AUTHOR "Bjarne Stroustrup"
#define MAX_LENGTH 255
#define MIN_LENGTH 2


Kniha::Kniha() {
    this->setDefault();
}

Kniha::Kniha(const string& title, const string& author, const string& isbn) {
    if (!this->validData(title, author, isbn)) {
        cout << "Invalid data, using default ones" << endl;
        this->setDefault();
    } else {
        this->title = title;
        this->author = author;
        this->isbn = isbn;
    }
}

Kniha::Kniha(const Kniha &other) {
    this->title = other.title;
    this->author = other.author;
    this->isbn = other.isbn;
}

Kniha::~Kniha()=default;

void Kniha::setDefault() {
    this->isbn = DEFAULT_ISBN;
    this->title = DEFAULT_TITLE;
    this->author = DEFAULT_AUTHOR;
}

string Kniha::getAuthor() const {
    return this->author;
}

string Kniha::getIsbn() const {
    return this->isbn;
}

string Kniha::getTitle() const {
    return this->title;
}

string Kniha::getIsbnClean(string new_isbn) const {
    new_isbn.erase(remove(new_isbn.begin(), new_isbn.end(), '-'), new_isbn.end());
    return new_isbn;
}

int Kniha::getIsbnLength(string new_isbn) const {
    return getIsbnClean(new_isbn).length();
}

string Kniha::getAll() const {
    return "Title:  " + this->title + "\nAuthor:  " + this->author + "\nISBN:  " + this->isbn + this->getParsed() + "\n";
}

string Kniha::getParsed() const {
    int str[20] = { 0 };
    int j = 0;
    for (int i = 0; this->isbn[i] != '\0'; i++) {
        if (this->isbn[i] == '-') {
            j++;
        } else {
            str[j] = str[j] * 10 + (this->isbn[i] - 48);
        }
    }
    if (this->isbn.length() == 13) {
        return " | Group: " + to_string(str[0]) + "; " + "Publisher: " + to_string(str[1]) + "; " + "Book: " + to_string(str[2]) + "; " + "Control: " + to_string(str[3]) + ";";
    }
    else if (this->isbn.length() == 17){
        return " | Prefix: " + to_string(str[0]) + "; " + "Group: " + to_string(str[1]) + "; " + "Publisher: " + to_string(str[2]) + "; " + "Book: " + to_string(str[3]) + "; " + "Control: " + to_string(str[4]) + ";";
    }
}

void Kniha::setAuthor(const string& new_author) {
    if (!this->validData(this->title, new_author, this->isbn)) {
        cout << "Invalid data, using old ones" << endl;
    } else {
        this->author = new_author;
    }
}

void Kniha::setIsbn(const string& new_isbn) {
    if (!this->validData(this->title, this->author, new_isbn)) {
        cout << "Invalid data, using old ones" << endl;
    } else {
        this->isbn = new_isbn;
    }
}

void Kniha::setTitle(const string& new_title) {
    if (!this->validData(new_title, this->author, this->isbn)) {
        cout << "Invalid data, using old ones" << endl;
    } else {
        this->title = new_title;
    }
}

void Kniha::setAll(const string& new_title, const string& new_author, const string& new_isbn) {
    this->setTitle(new_title);
    this->setAuthor(new_author);
    this->setIsbn(new_isbn);
}

bool Kniha::validData(const string& new_title, const string& new_author, string new_isbn) {
    if (new_title.length() < MIN_LENGTH || new_title.length() > MAX_LENGTH) {
        cout << "Title must be between " << MIN_LENGTH << " and " << MAX_LENGTH << " characters long." << endl;
        return false;
    }
    if (new_author.length() < MIN_LENGTH || new_author.length() > MAX_LENGTH) {
        cout << "Author must be between " << MIN_LENGTH << " and " << MAX_LENGTH << " characters long." << endl;
        return false;
    }
    if (!this->validIsbn(std::move(new_isbn))) {
        cout << "ISBN must be valid." << endl;
        return false;
    }
    return true;
}

bool Kniha::validIsbn(string new_isbn) {
    if (new_isbn.length() != 13 && new_isbn.length() != 17) {
        return false;
    } else if (new_isbn.length() == 13) {
        new_isbn = this->getIsbnClean(new_isbn);
        int sum = 0;
        for (int i = 0; i < 9; i++) {
            int digit = new_isbn[i] - '0';
            if (0 > digit || 9 < digit)
                return false;
            sum += (digit * (10 - i));
        }
        char last = new_isbn[9];
        if (last != 'X' && (last < '0' || last > '9'))
            return false;
        sum += ((last == 'X') ? 10 : (last - '0'));
        if (sum % 11 != 0) {
            return false;
        }
        else {
            return true;
        }
    } else if (new_isbn.length() == 17) {
        new_isbn = this->getIsbnClean(new_isbn);
        int sum = 0;
        for (int i = 1; i <= 13; i++) {
            int digit = new_isbn[i - 1] - '0';
            sum += (digit * (i % 2 ? 1 : 3));
        }
        if (sum % 10 != 0) {
            return false;
        }
        else {
            return true;
        }
    }
    return false;
}

bool Kniha::operator==(const Kniha &other) const {
    if (this->isbn == other.isbn && this->title == other.title && this->author == other.author) {
        return true;
    } else {
        return false;
    }
}

Kniha& Kniha::operator=(const Kniha &other) {
    this->isbn = other.isbn;
    this->title = other.title;
    this->author = other.author;
}

std::ostream & operator<< (std::ostream & os, const Kniha & k){
    os << (k.getAll());
    return os;
}
