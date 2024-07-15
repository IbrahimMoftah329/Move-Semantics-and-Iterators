Project 1 consists of 5 files: Main.cpp, Book.cpp, Book.hpp, MoveAll.cpp, MoveAll.hpp. All those files, as well as a sample input file, can be downloaded by clicking on "Project 1 template and input files" right above this.
You will implement the Book class in Book.cpp and write the moveAll function in MoveAll.cpp. Those are the only files you'll be graded on.
The rest of the files have already been written for you.
Main.cpp has space at the end for you to write test cases. Books read in from the file will be stored in vector<Book> catalog at that point, while vector<Book> cart will be empty, so that you can move Books into it.
The project will be due by end of day Friday, March 1, and will be submitted on Gradescope. The autograder will be up over the weekend.
Clarifications / FAQs:
In moveAll, "moving" a Book implies that you delete it from the source. So yes, you must delete moved Books from the source.
In moveAll, you must count the number of Books moved using the provided variable int books_moved, so that it may be printed at the end of the function.
Book's print() method should print in the exact same format as the original file. At the end, you should return to the next line, but not skip a line. So one endl after printing the last line, not two.
std::swap should only be used if you actually need to swap objects. Using it to move or copy is needlessly inefficient.
The entirety of project 1 (once you've completed Book.cpp and MoveAll.cpp) reads Book objects in from a file, stores them in a vector of Books called "catalog", and allows you to move Books from "catalog" to another vector of Books called "cart". It does this using the moveAll function, which moves all Books containing a specified keyword.
Books have 7 data members:
        std::string title_;
        std::string author_;
        long long int ISBN_;
        int* icon_;
        float price_;
        std::vector<std::string> keywords_;
        std::string blurb_;
Title, author, and ISBN should be self-explanatory.
Icon is meant to represent a small bitmap, so it consists of 80 integers between 0 and 255.
Price is stored as a float, but when printed out must have exactly 2 digits after the decimal point.
Keywords is a list of categories or tags (usually 3), such as "Spanish Literature", "Food", "Amish Fiction" (yes that's one of the categories my TA found), etc.
Blurb is a short description of the book.
Some of the data was scraped from various places while some parts were randomly generated, so don't expect the data to make sense all the time. Also, some blurbs had special characters that cause problems, and may look odd. Despite that, everything reads in and works fine, and our TA Daniel made the descriptions much more convincing than I expected - it's not that easy to generate random book descriptions that look legit even at a glance.
