#ifndef task11structs_H
#define task11structs_H
typedef struct Book {
    char* BookTitle;
    char* Author;
    unsigned long accession_number;
    int Issued;
}Book;
typedef struct Library {
    Book** books;
    int NumberOfDifferentBooks;
}Library;
#endif