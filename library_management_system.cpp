#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

class Book
{
private:
    int id;
    string title;
    string author;
    int quantity;

public:
    Book() {}

    Book(int i, string t, string a, int q)
    {
        id = i;
        title = t;
        author = a;
        quantity = q;
    }

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getQuantity() const { return quantity; }

    void issueBook()
    {
        if(quantity > 0)
            quantity--;
    }

    void returnBook()
    {
        quantity++;
    }

    void display() const
    {
        cout << left
             << setw(8) << id
             << setw(25) << title
             << setw(20) << author
             << quantity << endl;
    }

    string toFile() const
    {
        return to_string(id) + "|" + title + "|" + author + "|" + to_string(quantity);
    }

    void fromFile(string line)
    {
        int p1 = line.find("|");
        int p2 = line.find("|", p1 + 1);
        int p3 = line.find("|", p2 + 1);

        id = stoi(line.substr(0, p1));
        title = line.substr(p1 + 1, p2 - p1 - 1);
        author = line.substr(p2 + 1, p3 - p2 - 1);
        quantity = stoi(line.substr(p3 + 1));
    }
};

class Library
{
private:
    vector<Book> books;

public:
    Library()
    {
        loadBooks();
    }

    ~Library()
    {
        saveBooks();
    }

    void addBook()
    {
        int id, qty;
        string title, author;

        cout << "\nBook ID: ";
        cin >> id;
        cin.ignore();

        cout << "Title: ";
        getline(cin, title);

        cout << "Author: ";
        getline(cin, author);

        cout << "Quantity: ";
        cin >> qty;

        books.push_back(Book(id, title, author, qty));

        cout << "\nBook Added Successfully!\n";
    }

    void viewBooks()
    {
        if(books.empty())
        {
            cout << "\nNo Books Available.\n";
            return;
        }

        cout << "\n-------------------------------------------------------------\n";
        cout << left
             << setw(8) << "ID"
             << setw(25) << "TITLE"
             << setw(20) << "AUTHOR"
             << "QTY\n";
        cout << "-------------------------------------------------------------\n";

        for(Book b : books)
            b.display();
    }

    void searchBook()
    {
        int id;
        cout << "\nEnter Book ID: ";
        cin >> id;

        for(Book b : books)
        {
            if(b.getId() == id)
            {
                cout << "\nBook Found\n";
                b.display();
                return;
            }
        }

        cout << "\nBook Not Found.\n";
    }

    void issueBook()
    {
        int id;
        cout << "\nEnter Book ID: ";
        cin >> id;

        for(Book &b : books)
        {
            if(b.getId() == id)
            {
                if(b.getQuantity() == 0)
                {
                    cout << "\nBook Out of Stock.\n";
                    return;
                }

                b.issueBook();
                cout << "\nBook Issued Successfully.\n";
                return;
            }
        }

        cout << "\nBook Not Found.\n";
    }

    void returnBook()
    {
        int id;
        cout << "\nEnter Book ID: ";
        cin >> id;

        for(Book &b : books)
        {
            if(b.getId() == id)
            {
                b.returnBook();
                cout << "\nBook Returned Successfully.\n";
                return;
            }
        }

        cout << "\nBook Not Found.\n";
    }

    void deleteBook()
    {
        int id;
        cout << "\nEnter Book ID: ";
        cin >> id;

        for(int i = 0; i < books.size(); i++)
        {
            if(books[i].getId() == id)
            {
                books.erase(books.begin() + i);
                cout << "\nBook Deleted Successfully.\n";
                return;
            }
        }

        cout << "\nBook Not Found.\n";
    }

    void saveBooks()
    {
        ofstream file("books.txt");

        for(Book b : books)
            file << b.toFile() << endl;

        file.close();
    }

    void loadBooks()
    {
        ifstream file("books.txt");

        if(!file)
            return;

        string line;

        while(getline(file, line))
        {
            Book b;
            b.fromFile(line);
            books.push_back(b);
        }

        file.close();
    }
};

int main()
{
    Library library;

    int choice;

    do
    {
        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Delete Book\n";
        cout << "7. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                library.addBook();
                break;

            case 2:
                library.viewBooks();
                break;

            case 3:
                library.searchBook();
                break;

            case 4:
                library.issueBook();
                break;

            case 5:
                library.returnBook();
                break;

            case 6:
                library.deleteBook();
                break;

            case 7:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 7);

    return 0;
}
