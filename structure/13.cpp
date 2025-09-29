#include <iostream>
#include <vector>
using namespace std;

struct Book {
    int accession_no;
    string author;
    string title;
    bool is_issued;
};

void displayBook(const Book& b) {
    cout << "\nAccession No: " << b.accession_no
         << "\nAuthor: " << b.author
         << "\nTitle: " << b.title
         << "\nIssued: " << (b.is_issued ? "Yes" : "No") << endl;
}

void addBook(vector<Book>& library) {
    Book b;
    cout << "\nEnter accession number: ";
    cin >> b.accession_no;
    cout << "Enter author name: ";
    cin.ignore();
    getline(cin, b.author);
    cout << "Enter book title: ";
    getline(cin, b.title);
    b.is_issued = false;
    library.push_back(b);
    cout << "Book added successfully.\n";
}

void booksByAuthor(const vector<Book>& library, const string& author) {
    cout << "\nBooks by " << author << ":\n";
    for (const auto& b : library) {
        if (b.author == author) {
            displayBook(b);
        }
    }
}

void countByTitle(const vector<Book>& library, const string& title) {
    int count = 0;
    for (const auto& b : library) {
        if (b.title == title && !b.is_issued) {
            count++;
        }
    }
    cout << "\nNumber of available copies of \"" << title << "\": " << count << endl;
}

void totalBooks(const vector<Book>& library) {
    cout << "\nTotal number of books in library: " << library.size() << endl;
}

void issueBook(vector<Book>& library, int accession_no) {
    for (auto& b : library) {
        if (b.accession_no == accession_no && !b.is_issued) {
            b.is_issued = true;
            cout << "Book issued successfully.\n";
            return;
        }
    }
    cout << "Book not found or already issued.\n";
}

int main() {
    vector<Book> library;
    int choice;

    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Display book information\n";
        cout << "2. Add a new book\n";
        cout << "3. Display all books by a particular author\n";
        cout << "4. Display number of books of a particular title\n";
        cout << "5. Display total number of books\n";
        cout << "6. Issue a book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int acc;
                cout << "Enter accession number: ";
                cin >> acc;
                bool found = false;
                for (const auto& b : library) {
                    if (b.accession_no == acc) {
                        displayBook(b);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Book not found.\n";
                break;
            }
            case 2:
                addBook(library);
                break;
            case 3: {
                string author;
                cout << "Enter author name: ";
                cin.ignore();
                getline(cin, author);
                booksByAuthor(library, author);
                break;
            }
            case 4: {
                string title;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                countByTitle(library, title);
                break;
            }
            case 5:
                totalBooks(library);
                break;
            case 6: {
                int acc;
                cout << "Enter accession number to issue: ";
                cin >> acc;
                issueBook(library, acc);
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
