Project: Book Management and Moving Function

Overview
Project involves implementing a Book class and a moveAll function, both of which will be evaluated. The project consists of five files: Main.cpp, Book.cpp, Book.hpp, MoveAll.cpp, and MoveAll.hpp. You will be working specifically on Book.cpp and MoveAll.cpp. The other files have been provided to you, and Main.cpp includes space for writing test cases.

Objective
The goal is to read book data from a file, store it in a vector called catalog, and move selected books to another vector called cart based on a specified keyword. This operation will be performed using the moveAll function.

Clarifications and Requirements

Book Class Implementation:
Data Members: std::string title_, std::string author_, long long int ISBN_, int* icon_, float price_, std::vector<std::string> keywords_, std::string blurb_.
Printing: The print() method of the Book class should output data in the exact format as the original file, followed by a single newline (not double).

moveAll Function:
Functionality: The function should move all books containing a specified keyword from the catalog vector to the cart vector.
Books Moved Counter: Use the provided int books_moved variable to count the number of books moved.
Deletion: "Moving" a book implies deleting it from the source vector (catalog).
Efficiency: Avoid using std::swap unnecessarily, as it is inefficient for moving or copying objects.

Main.cpp
Test Cases: Add your test cases at the end of Main.cpp.
Data Storage: Books read from the file will be stored in the catalog vector, while the cart vector will initially be empty.

Book Data
Attributes: Title, author, ISBN, icon, price, keywords, and blurb.
Icon: A small bitmap represented by 80 integers between 0 and 255.
Price: Stored as a float and printed with exactly two decimal places.
Keywords: A list of categories or tags, typically three.
Blurb: A short description of the book.
