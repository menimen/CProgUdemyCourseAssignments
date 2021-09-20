#ifndef task11_H
#define task11_H
#include "task11Structs.h"
#include "ex5.h"
void mission11Menu(Library **lib);
Library* InitializeLibrary();
Book* CreateBook(char* BookTitle, char* Author, unsigned long* accession_numbert);
char* setStringInHeap(char* str);
unsigned long bigrandom();
Library* AddBook(Library* library, Book** book);
void DisplayAllBooksFromSameAuthor(Library* library, char *author);
void TotalNumOfBooks(Library* library);
Library* IssueBook(Library* library, char* title);
Book* BookSearch(Library* library, char *title);
void clearLibrary(Library** lib);
void initializeBooksArray(Book*** books_arr, int* arr_size);
void ClearBooksArray(Book*** books_arr, int* arr_size);
void DisplayAllBooks(Library* lib);
void DisplayInforamtionAboutBook(Library* library);
#endif