//
// Created by david_stocek on 4/8/22.
//

#ifndef CPP_ISBN_KNIHA_HPP
#define CPP_ISBN_KNIHA_HPP


#include <string>


using namespace std;


class Kniha {
public:
    Kniha();
    Kniha(const string& title, const string& author, const string& isbn);
    Kniha(const Kniha &other);
    ~Kniha();
    [[nodiscard]] string getTitle() const;
    [[nodiscard]] string getAuthor() const;
    [[nodiscard]] string getIsbn() const;
    [[nodiscard]] string getIsbnClean(string new_isbn) const;
    [[nodiscard]] int getIsbnLength(string new_isbn) const;
    [[nodiscard]] string getAll() const;
    [[nodiscard]] string getParsed() const;
    void setTitle(const string& new_title);
    void setAuthor(const string& new_author);
    void setIsbn(const string& new_isbn);
    void setAll(const string& new_title, const string& new_author, const string& new_isbn);
    bool operator==(const Kniha &other) const;
    Kniha& operator=(const Kniha &other);

private:
    std::string title;
    std::string author;
    std::string isbn;
    void setDefault();
    bool validData(const string& new_title, const string& new_author, string new_isbn);
    bool validIsbn(string new_isbn);
};

std::ostream & operator <<(std::ostream & , const Kniha &);
#endif //CPP_ISBN_KNIHA_HPP
