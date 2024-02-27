#include "Book.hpp"

    // Default constructor for the Book class
    Book::Book() : title_(""), author_(""), ISBN_(0), icon_(nullptr), price_(0.0), keywords_{}, blurb_("")
    {

    }

    // Destructor for the Book class
    Book::~Book()
    {
        // Deallocate memory for icon_
        delete[] icon_;
    }

    // Copy constructor for the Book class
    Book::Book(const Book& rhs)
    {
        // Copy constructor copies values of member variables from the source object (rhs).
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        price_ = rhs.price_;
        blurb_ = rhs.blurb_;
        
        // Deep copy for icon_
        if (rhs.icon_) {
            icon_ = new int(*rhs.icon_);
        } else {
            icon_ = nullptr;
        }

        // Deep copy for keywords_
        keywords_ = rhs.keywords_;
    }

    // Copy assignment operator for the Book class
    Book& Book::operator=(const Book& rhs)
    {
        // Check for self-assignment
        if (this != &rhs) {
            // Release resources held by the current object

            delete icon_;

            // Copy values of member variables from the source object (rhs).

            // Deep copy for icon_
            if (rhs.icon_) {
                icon_ = new int(*rhs.icon_);
            } else {
                icon_ = nullptr;
            }

            // Deep copy for keywords_
            keywords_ = rhs.keywords_;

            // Copy the rest of the member variables
            title_ = rhs.title_;
            author_ = rhs.author_;
            ISBN_ = rhs.ISBN_;
            price_ = rhs.price_;
            blurb_ = rhs.blurb_;
        }
        return *this;
    }

    // Move constructor for the Book class
    Book::Book(Book&& rhs) 
    {
        // Move constructor "steals" the resources (e.g., memory) from the source object (rhs).
        title_ = std::move(rhs.title_);
        author_ = std::move(rhs.author_);
        ISBN_ = std::move(rhs.ISBN_);
        price_ = std::move(rhs.price_);
        blurb_ = std::move(rhs.blurb_);

        // Move ownership of keywords_ from rhs to the current object
        keywords_ = std::move(rhs.keywords_);

        // Move ownership of icon_ from rhs to the current object
        icon_ = rhs.icon_;

        // Set source object's icon_ to nullptr to avoid deleting it in its destructor
        rhs.icon_ = nullptr;
    }

    // Move assignment operator for the Book class
    Book& Book::operator=(Book&& rhs)
    {
        // Check for self-assignment
        if (this != &rhs) {
            // Release resources held by the current object

            delete icon_;

            // Move values of member variables from the source object (rhs).

            // Move ownership of icon_ from rhs to the current object
            icon_ = rhs.icon_;

            // Set source object's icon_ to nullptr to avoid deleting it in its destructor
            rhs.icon_ = nullptr;

            // Move ownership of keywords_ from rhs to the current object
            keywords_ = std::move(rhs.keywords_);

            // Move the rest of the member variables
            title_ = std::move(rhs.title_);
            author_ = std::move(rhs.author_);
            ISBN_ = std::move(rhs.ISBN_);
            price_ = std::move(rhs.price_);
            blurb_ = std::move(rhs.blurb_);
        }
        return *this;
    }

    // Getter for the title of the book
    const std::string& Book::getTitle() const
    {
        return title_;
    }

    // Setter for the title of the book
    void Book::setTitle(const std::string& title)
    {
        title_ = title;
    }

    // Getter for the author of the book
    const std::string& Book::getAuthor() const
    {
        return author_;
    }

    // Setter for the author of the book
    void Book::setAuthor(const std::string& author)
    {
        author_ = author;
    }

    // Getter for the ISBN of the book
    long long int Book::getISBN() const
    {
        return ISBN_;
    }

    // Setter for the ISBN of the book
    void Book::setISBN(long long int ISBN)
    {
        ISBN_ = ISBN;
    }


    // Getter for the icon of the book
    const int* Book::getIcon() const
    {
        return icon_;
    }

    // Setter for the icon of the book
    void Book::setIcon(int* icon)
    {
        delete icon_; // Release the existing icon memory if any
        
        // Allocate new memory and copy the elements
        icon_ = new int[80];
        for (int i = 0; i < 80; ++i) {
            icon_[i] = icon[i];
        }
    }

    // Getter for the price of the book
    float Book::getPrice() const
    {
        return price_;
    }

    // Setter for the price of the book
    void Book::setPrice(float price)
    {
        price_ = price;
    }

    // Getter for the keywords associated with the book
    const std::vector<std::string>& Book::getKeywords() const
    {
        return keywords_;
    }

    // Setter for the keywords associated with the book
    void Book::setKeywords(const std::vector<std::string>& keywords)
    {
        keywords_ = keywords;
    }

    // Getter for the blurb (short description) of the book
    const std::string& Book::getBlurb() const
    {
        return blurb_;
    }

    // Setter for the blurb (short description) of the book
    void Book::setBlurb(const std::string& blurb)
    {
        blurb_ = blurb;
    }

    // Method to print details of the book
    void Book::print() const
    {
        std::cout << "Title: " << title_ << std::endl;
        std::cout << "Author: " << author_ << std::endl;
        std::cout << "ISBN: " << ISBN_ << std::endl;

        std::cout << "Icon: ";
        if (icon_) {
            for (int i = 0; i < 80; ++i) {
                std::cout << icon_[i] << " ";
            }
        } else {
            std::cout << "Icon: nullptr" << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Price: $" << std::fixed << std::setprecision(2) << price_ << std::endl;

        std::cout << "Keywords: ";
        for (size_t i = 0; i < keywords_.size(); ++i) {
            std::cout << keywords_[i];
            
            // Print comma if it's not the last keyword
            if (i < keywords_.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;

        std::cout << "Blurb: " << blurb_ << std::endl;
    }
