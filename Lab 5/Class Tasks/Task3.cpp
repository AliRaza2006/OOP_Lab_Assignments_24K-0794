#include <iostream>
#include <vector>

using namespace std;

class Book {
public:
    string title;
    string author;
    string isbn;

    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}
    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << '\n';
    }
};

class Catalog {
private:
    vector<Book*> books;
public:
    void addBook(Book* book) {
        books.push_back(book);
    }
    void removeBook(const string& isbn) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i]->isbn == isbn) {
                books.erase(books.begin() + i);
                break;
            }
        }
    }
    Book* findBook(const string& isbn) {
        for (Book* book : books) {
            if (book->isbn == isbn) {
                return book;
            }
        }
        return nullptr;
    }
};

class Library {
private:
    string name;
    string address;
    Catalog catalog;
    vector<Book*> books;

public:
    Library(string n, string addr) : name(n), address(addr) {}
    void addBook(Book* book) {
        books.push_back(book);
        catalog.addBook(book);
    }
    void removeBook(const string& isbn) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i]->isbn == isbn) {
                books.erase(books.begin() + i);
                break;
            }
        }
        catalog.removeBook(isbn);
    }
    void findBookInCatalog(const string& isbn) {
        Book* book = catalog.findBook(isbn);
        if (book) {
            cout << "Book found in catalog: ";
            book->display();
        } else {
            cout << "Book not found in catalog.\n";
        }
    }
    void displayBooks() {
        cout << "Library: " << name << " (" << address << ")\nBooks:\n";
        for (Book* book : books) book->display();
    }
};

int main() {
    Library lib("Central Library", "123 Library St.");

    Book book1("The C++ Programming Language", "Bjarne Stroustrup", "123456789");
    Book book2("Effective Modern C++", "Scott Meyers", "987654321");

    lib.addBook(&book1);
    lib.addBook(&book2);

    lib.displayBooks();
    lib.findBookInCatalog("123456789");
    lib.findBookInCatalog("000000000");

    lib.removeBook("123456789");
    lib.displayBooks();
    
    return 0;
}