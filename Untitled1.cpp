#include <iostream>
using namespace std;
typedef struct Book {
    string title;
    string author;
    int isbn;
    bool Availability;
} Book;
void input(Book* lib[], int n) {
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "\nEnter Title of Book " << i + 1 << ": ";
        getline(cin, lib[i]->title);
        cout << "Enter Author Name: ";
        getline(cin, lib[i]->author);
        cout << "Book ISBN Code: ";
        cin >> lib[i]->isbn;
        lib[i]->Availability = 0;
        cin.ignore();
    }
}
void display(Book* lib[], int n) {
    cout << "\n========= Library Books =========\n";
    for (int i = 0; i < n; i++) {
        cout << "Title: " << lib[i]->title << endl;
        cout << "Author: " << lib[i]->author << endl;
        cout << "ISBN: " << lib[i]->isbn << endl;
        cout << "Status: "
             << (lib[i]->Availability ? "Borrowed" : "Available") << endl;
        cout << "--------------------------------\n";
    }
}
void manage(Book* lib[], int n) {
    char ans;
    int code;
    bool found = false;
    cout << "Enter y to return, n to borrow: ";
    cin >> ans;
    if (ans == 'n' || ans == 'N') {
        cout << "Enter ISBN to borrow: ";
        cin >> code;
        for (int i = 0; i < n; i++) {
            if (lib[i]->isbn == code) {
                found = true;
                if (lib[i]->Availability == 0) {
                    lib[i]->Availability = 1;
                    cout << "Book borrowed successfully.\n";
                } else {
                    cout << "Book already borrowed.\n";
                }
                break;
            }
        }
    }
    else if (ans == 'y' || ans == 'Y') {
        cout << "Enter ISBN to return: ";
        cin >> code;
        for (int i = 0; i < n; i++) {
            if (lib[i]->isbn == code) {
                found = true;
                if (lib[i]->Availability == 1) {
                    lib[i]->Availability = 0;
                    cout << "Book returned successfully.\n";
                } else {
                    cout << "Book was not borrowed.\n";
                }
                break;
            }
        }
    }
    else {
        cout << "Invalid choice.\n";
        return;
    }
    if (!found) {
        cout << "Invalid ISBN.\n";
    }
}
int main() {
    int n, opt;
    cout << "Enter number of books: ";
    cin >> n;
    Book* lib[n];
    for (int i = 0; i < n; i++)
        lib[i] = new Book;
    do {
        cout << "\n===== Book Management System =====\n";
        cout << "1. Data Entry\n";
        cout << "2. Display Data\n";
        cout << "3. Borrow / Return Book\n";
        cout << "4. Exit\n";
        cout << "Choose option: ";
        cin >> opt;
        switch (opt) {
        case 1:
            input(lib, n);
            break;
        case 2:
            display(lib, n);
            break;
        case 3:
            manage(lib, n);
            display(lib, n);
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid Option Selected\n";
        }
    } while (opt != 4);
    for (int i = 0; i < n; i++)
        delete lib[i];
    return 0;
}