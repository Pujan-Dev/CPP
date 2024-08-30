#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int ISBN_LENGTH = 13;   // Maximum length for ISBN (including null terminator)
const int TITLE_LENGTH = 50;
const int AUTHOR_LENGTH = 50;
const char* FILENAME = "catalog.txt";

class Library {
private:
    char ISBN[ISBN_LENGTH];
    char bookTitle[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int numberOfCopies;

    void writeToFile() {
        ofstream file(FILENAME, ios::app);
        if (!file) {
            cout << "Error opening file for writing" << endl;
            return;
        }
        file << ISBN << "," << bookTitle << "," << author << "," << numberOfCopies << endl;
        file.close();
    }

    bool readFromFile() {
        ifstream file(FILENAME);
        if (!file) {
            cout << "Error opening file for reading" << endl;
            return false;
        }

        bool found = false;
        char buffer[200];
        while (file.getline(buffer, 200)) {
            char fileISBN[ISBN_LENGTH], fileTitle[TITLE_LENGTH], fileAuthor[AUTHOR_LENGTH];
            int fileCopies;

            sscanf(buffer, "%[^,],%[^,],%[^,],%d", fileISBN, fileTitle, fileAuthor, &fileCopies);

            if (strcmp(fileISBN, ISBN) == 0) {
                strcpy(bookTitle, fileTitle);
                strcpy(author, fileAuthor);
                numberOfCopies = fileCopies;
                found = true;
                break;
            }
        }
        file.close();
        return found;
    }

    void displayBook(const char* isbn, const char* title, const char* author, int copies) {
        cout << "ISBN: " << isbn << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Copies: " << copies << endl;
        cout << "------------------------------" << endl;
    }

public:
    Library() : numberOfCopies(0) {
        ISBN[0] = '\0';
        bookTitle[0] = '\0';
        author[0] = '\0';
    }

    void inputBookDetails() {
        cout << "Enter ISBN: ";
        cin.getline(ISBN, ISBN_LENGTH);
        cout << "Enter Book Title: ";
        cin.getline(bookTitle, TITLE_LENGTH);
        cout << "Enter Author: ";
        cin.getline(author, AUTHOR_LENGTH);
        cout << "Enter Number of Copies: ";
        cin >> numberOfCopies;
        cin.ignore();  // Clear newline left in buffer
    }

    void addNewBook() {
        if (readFromFile()) {
            cout << "Book with this ISBN already exists!" << endl;
            return;
        }
        writeToFile();
    }


    void issueBook() {
        if (!readFromFile()) {
            cout << "Book not found!" << endl;
            return;
        }
        if (numberOfCopies > 0) {
            numberOfCopies--;
            writeToFile();
        } else {
            cout << "No copies available to issue!" << endl;
        }
    }

    void returnBook() {
        if (!readFromFile()) {
            cout << "Book not found!" << endl;
            return;
        }
        numberOfCopies++;
        writeToFile();
    }

    void updateBookDetails() {
        // Save current details for comparison
        char oldISBN[ISBN_LENGTH];
        strcpy(oldISBN, ISBN);

        // Clear current details
        ISBN[0] = '\0';
        bookTitle[0] = '\0';
        author[0] = '\0';
        numberOfCopies = 0;

        cout << "Enter new ISBN: ";
        cin.getline(ISBN, ISBN_LENGTH);
        cout << "Enter new Book Title: ";
        cin.getline(bookTitle, TITLE_LENGTH);
        cout << "Enter new Author: ";
        cin.getline(author, AUTHOR_LENGTH);
        cout << "Enter new Number of Copies: ";
        cin >> numberOfCopies;
        cin.ignore();  // Clear newline left in buffer

        if (strcmp(oldISBN, ISBN) != 0 && readFromFile()) {
            cout << "A book with this new ISBN already exists!" << endl;
            return;
        }

        // Overwrite old book details with new details
        ifstream inFile(FILENAME);
        ofstream outFile("temp.txt");

        if (!inFile || !outFile) {
            cout << "Error opening file!" << endl;
            return;
        }

        char buffer[200];
        while (inFile.getline(buffer, 200)) {
            char fileISBN[ISBN_LENGTH];
            sscanf(buffer, "%[^,]", fileISBN);

            if (strcmp(fileISBN, oldISBN) == 0) {
                outFile << ISBN << "," << bookTitle << "," << author << "," << numberOfCopies << endl;
            } else {
                outFile << buffer << endl;
            }
        }

        inFile.close();
        outFile.close();

        remove(FILENAME);
        rename("temp.txt", FILENAME);

        cout << "Book details updated successfully." << endl;
    }


    void deleteBook() {
        if (!readFromFile()) {
            cout << "Book not found!" << endl;
            return;
        }

        if (numberOfCopies != 0) {
            cout << "Cannot delete a book with copies available!" << endl;
            return;
        }

        // Check if the book has been issued
        ifstream inFile(FILENAME);
        if (!inFile) {
            cout << "Error opening file!" << endl;
            return;
        }

        bool bookIssued = false;
        char buffer[200];
        while (inFile.getline(buffer, 200)) {
            char fileISBN[ISBN_LENGTH];
            int fileCopies;

            sscanf(buffer, "%[^,],%*[^,],%*[^,],%d", fileISBN, &fileCopies);

            if (strcmp(fileISBN, ISBN) == 0 && fileCopies < numberOfCopies) {
                bookIssued = true;
                break;
            }
        }
        inFile.close();

        if (bookIssued) {
            cout << "Cannot delete a book that has been issued!" << endl;
            return;
        }

        // Proceed to delete the book
        ifstream inFileToDelete(FILENAME);
        ofstream outFile("temp.txt");

        if (!inFileToDelete || !outFile) {
            cout << "Error opening file!" << endl;
            return;
        }

        while (inFileToDelete.getline(buffer, 200)) {
            char fileISBN[ISBN_LENGTH];
            sscanf(buffer, "%[^,]", fileISBN);

            if (strcmp(fileISBN, ISBN) != 0) {
                outFile << buffer << endl;
            }
        }

        inFileToDelete.close();
        outFile.close();

        remove(FILENAME);
        rename("temp.txt", FILENAME);

        cout << "Book deleted successfully." << endl;
    }

    void displayAllBooks() {
        ifstream file(FILENAME);
        if (!file) {
            cout << "Error opening file for reading" << endl;
            return;
        }

        char buffer[200];
        while (file.getline(buffer, 200)) {
            char fileISBN[ISBN_LENGTH], fileTitle[TITLE_LENGTH], fileAuthor[AUTHOR_LENGTH];
            int fileCopies;

            sscanf(buffer, "%[^,],%[^,],%[^,],%d", fileISBN, fileTitle, fileAuthor, &fileCopies);

            displayBook(fileISBN, fileTitle, fileAuthor, fileCopies);
        }
        file.close();
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "Library Menu:" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Issue Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Update Book Details" << endl;
        cout << "5. Delete Book" << endl;
        cout << "6. Display All Books" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear newline left in buffer

        switch (choice) {
            case 1:
                lib.inputBookDetails();
                lib.addNewBook();
                break;
            case 2:
                lib.inputBookDetails();
                lib.issueBook();
                break;
            case 3:
                lib.inputBookDetails();
                lib.returnBook();
                break;
            case 4:
                lib.inputBookDetails();
                lib.updateBookDetails();
                break;
            case 5:
                lib.inputBookDetails();
                lib.deleteBook();
                break;
            case 6:
                lib.displayAllBooks();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
