#include <iostream>
using namespace std;

struct BookDetails 
{
    string title;
    string author;
    int publicationYear;
};

struct LoanDate 
{
    int day;
    int month;
    int year;
};

struct LoanDetails 
{
    BookDetails book;
    LoanDate loanDate;
    char borrowerName[100];
} loanedBooks[100];

int main() 
{
    BookDetails books[10][10];  // Array for storing book details
    int numberOfBooks, numberOfLoans, repeat;

    do 
	{
        system("cls");  // Clear screen (Windows-specific)
        cout << "=====BOOK LOAN PROGRAM=====\n";
        cout << "Enter the number of books to input: "; 
        cin >> numberOfBooks;

        // Input details for each book
        for (int row = 1; row <= numberOfBooks; row++) 
		{
            cout << "Book " << row << endl;
            for (int col = 1; col <= numberOfBooks; col++) 
			{
                cin.ignore();  // Clear the input buffer before reading strings
                cout << "________________________________________________________________________________________________________\n";
                cout << "Book Title\t\t\t\t: "; 
                getline(cin, books[row][col].title);
                cout << "Author Name\t\t\t\t: "; 
                getline(cin, books[row][col].author);
                cout << "Publication Year\t\t\t: "; 
                cin >> books[row][col].publicationYear;
                cout << "________________________________________________________________________________________________________\n";
            }
        }

        cin.ignore();  // Clear any leftover newline character

        cout << "=========================================\n";
        cout << "Borrower's Name\t\t\t\t: "; 
        cin.getline(loanedBooks[100].borrowerName, 100);  // Input borrower's name
        cout << "Loan Date (e.g., 19 02 1998)\t\t: "; 
        cin >> loanedBooks[100].loanDate.day >> loanedBooks[100].loanDate.month >> loanedBooks[100].loanDate.year;
        cout << "Number of Books Borrowed\t\t: "; 
        cin >> numberOfLoans;

        // Input details for each borrowed book
        for (int row = 1; row <= numberOfLoans; row++) 
		{
            cin.ignore();  // To clear the input buffer
            cout << "-----------------------------------------\n";
            cout << "Book Title\t\t: "; 
            getline(cin, loanedBooks[row].book.title);
            cout << "Author Name\t\t: "; 
            getline(cin, loanedBooks[row].book.author);
            cout << "Publication Year\t\t: "; 
            cin >> loanedBooks[row].book.publicationYear;
            cout << "-----------------------------------------\n";
        }

        cout << "=========================================\n"; 
        cout << endl;
        
        // Ask if the user wants to repeat the program
        cout << "Repeat Program (Press 1 to continue)\t: "; 
        cin >> repeat;
    } 
	while (repeat == 1);

    system("cls");
    cout << "==========PROGRAM ENDED==========\n";
    
    return 0;
}
