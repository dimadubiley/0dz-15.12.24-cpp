#include <iostream>
#include <string>

using namespace std;

class Book
{
    string Author;
    string Text;
    int pages;
    int year;

public:
    Book(){}

    Book(const string& author, const string& text, int pages, int year)
        : Author(author), Text(text), pages(pages), year(year) {}

    Book(const Book& obj) = delete;
    Book& operator=(const Book& obj) = delete;

    Book(Book&& obj) noexcept
        : Author(move(obj.Author)), Text(move(obj.Text)), pages(obj.pages), year(obj.year)
    {
        obj.pages = 0;
        obj.year = 0;
    }

    Book& operator=(Book&& obj) noexcept
    {
        if (this != &obj)
        {
            Author = move(obj.Author);
            Text = move(obj.Text);
            pages = obj.pages;
            year = obj.year;

            obj.pages = 0;
            obj.year = 0;
        }
        return *this;
    }

    void Enter()
    {
        cout << "Enter author: ";
        getline(cin, Author);
        cout << "Enter text: ";
        getline(cin, Text);
        cout << "Enter number of pages: ";
        cin >> pages;
        cout << "Enter year: ";
        cin >> year;
        cin.ignore();
    }

    void Print() const
    {
        cout << "Author: " << Author << endl;
        cout << "Text: " << Text << endl;
        cout << "Pages: " << pages << endl;
        cout << "Year: " << year << endl;
    }
};

int main()
{
    Book obj;
    obj.Enter();
    obj.Print();

    Book book2("George Orwell", "1984", 328, 1949);
    book2.Print();

    Book book3 = move(book2);
    book3.Print();

    return 0;
}
