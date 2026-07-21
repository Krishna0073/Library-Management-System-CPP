#include<iostream>
using namespace std;

// Arrays to store book details
string bookID[20], bookName[20], author[20], category[20], status[20];
int total = 0;

// Function Prototypes
void addBook()
{
    int n;

    cout<<"\nHow many books do you want to add? ";
    cin>>n;

    if(total+n>20)
    {
        cout<<"\nLibrary is Full!\n";
        return;
    }

    for(int i=0;i<n;i++)
    {
        cout<<"\nBook "<<i+1<<endl;

        cout<<"Book ID: ";
        cin>>bookID[total];

        cin.ignore();

        cout<<"Book Name: ";
        getline(cin,bookName[total]);

        cout<<"Author Name: ";
        getline(cin,author[total]);

        cout<<"Category: ";
        getline(cin,category[total]);

        status[total]="Available";

        total++;
    }

    cout<<"\nBook Added Successfully!\n";
}
void showBooks()
{
    if(total == 0)
    {
        cout << "\nNo books available in the library!" << endl;
        return;
    }

    cout << "\n========== Library Books ==========\n";

    for(int i = 0; i < total; i++)
    {
        cout << "\nBook " << i + 1 << endl;
        cout << "Book ID   : " << bookID[i] << endl;
        cout << "Book Name : " << bookName[i] << endl;
        cout << "Author    : " << author[i] << endl;
        cout << "Category  : " << category[i] << endl;
        cout << "Status    : " << status[i] << endl;
        cout << "-----------------------------------" << endl;
    }
}
void searchBook()
{
    if(total == 0)
    {
        cout << "\nNo books available in the library!" << endl;
        return;
    }

    string id;
    bool found = false;

    cout << "\nEnter Book ID to Search: ";
    cin >> id;

    for(int i = 0; i < total; i++)
    {
        if(bookID[i] == id)
        {
            found = true;

            cout << "\n========== Book Found ==========\n";
            cout << "Book ID   : " << bookID[i] << endl;
            cout << "Book Name : " << bookName[i] << endl;
            cout << "Author    : " << author[i] << endl;
            cout << "Category  : " << category[i] << endl;
            cout << "Status    : " << status[i] << endl;

            break;
        }
    }

    if(found == false)
    {
        cout << "\nBook not found!" << endl;
    }
}
void issueBook()
{
    if(total == 0)
    {
        cout << "\nNo books available in the library!" << endl;
        return;
    }

    string id;
    bool found = false;

    cout << "\nEnter Book ID to Issue: ";
    cin >> id;

    for(int i = 0; i < total; i++)
    {
        if(bookID[i] == id)
        {
            found = true;

            if(status[i] == "Available")
            {
                status[i] = "Issued";
                cout << "\nBook Issued Successfully!" << endl;
            }
            else
            {
                cout << "\nBook is already issued!" << endl;
            }

            break;
        }
    }

    if(found == false)
    {
        cout << "\nBook not found!" << endl;
    }
}
void returnBook()
{
    if(total == 0)
    {
        cout << "\nNo books available in the library!" << endl;
        return;
    }

    string id;
    bool found = false;

    cout << "\nEnter Book ID to Return: ";
    cin >> id;

    for(int i = 0; i < total; i++)
    {
        if(bookID[i] == id)
        {
            found = true;

            if(status[i] == "Issued")
            {
                status[i] = "Available";
                cout << "\nBook Returned Successfully!" << endl;
            }
            else
            {
                cout << "\nThis book is already available!" << endl;
            }

            break;
        }
    }

    if(found == false)
    {
        cout << "\nBook not found!" << endl;
    }
}
void updateBook()
{
    if(total == 0)
    {
        cout << "\nNo books available!" << endl;
        return;
    }

    string id;
    bool found = false;

    cout << "\nEnter Book ID to Update: ";
    cin >> id;

    for(int i = 0; i < total; i++)
    {
        if(bookID[i] == id)
        {
            found = true;

            cout << "\nEnter New Book ID: ";
            cin >> bookID[i];

            cin.ignore();

            cout << "Enter New Book Name: ";
            getline(cin, bookName[i]);

            cout << "Enter New Author Name: ";
            getline(cin, author[i]);

            cout << "Enter New Category: ";
            getline(cin, category[i]);

            cout << "\nBook Updated Successfully!" << endl;
            break;
        }
    }

    if(found == false)
    {
        cout << "\nBook not found!" << endl;
    }
}
void deleteBook()
{
    if(total == 0)
    {
        cout << "\nNo books available!" << endl;
        return;
    }

    string id;
    bool found = false;

    cout << "\nEnter Book ID to Delete: ";
    cin >> id;

    for(int i = 0; i < total; i++)
    {
        if(bookID[i] == id)
        {
            found = true;

            for(int j = i; j < total - 1; j++)
            {
                bookID[j] = bookID[j + 1];
                bookName[j] = bookName[j + 1];
                author[j] = author[j + 1];
                category[j] = category[j + 1];
                status[j] = status[j + 1];
            }

            total--;

            cout << "\nBook Deleted Successfully!" << endl;
            break;
        }
    }

    if(found == false)
    {
        cout << "\nBook not found!" << endl;
    }
}
int main()
{
    int choice;

    while(true)
    {
        cout<<"\n=====================================\n";
        cout<<"      LIBRARY MANAGEMENT SYSTEM\n";
        cout<<"=====================================\n";
        cout<<"1. Add Book\n";
        cout<<"2. Show All Books\n";
        cout<<"3. Search Book\n";
        cout<<"4. Issue Book\n";
        cout<<"5. Return Book\n";
        cout<<"6. Update Book\n";
        cout<<"7. Delete Book\n";
        cout<<"8. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                showBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                updateBook();
                break;

            case 7:
                deleteBook();
                break;

            case 8:
                cout<<"\nThank You!\n";
                return 0;

            default:
                cout<<"\nInvalid Choice!\n";
        }
    }
}
