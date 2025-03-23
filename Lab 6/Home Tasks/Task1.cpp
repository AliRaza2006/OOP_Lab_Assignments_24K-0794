#include <iostream>
#include <string>
using namespace std;

class Books
{
    protected:
    string genre;
    public:
    Books(string genre)
    {
        this->genre=genre;
    }
    void virtual display()
    {
        cout<<"Genre: "<<genre<<endl;
    }
};
class Mystery:public Books
{
    private:
    string title;
    string author;
    public:
    Mystery(string t,string a):Books("Mystery"),title(t),author(a){}
    void display()override
    {
        Books::display();
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
    }
};
class Novel:public Books
{
    private:
    string title;
    string author;
    public:
    Novel(string t,string a):Books("Novel"),title(t),author(a){}
    void display()override
    {
        Books::display();
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
    }
};
int main()
{
    Novel n("Wuthering Heights","Emily Bronte");
    Mystery m("The Woman in White","Wilkie Collins");
    n.display();
    cout<<endl;
    m.display();
}