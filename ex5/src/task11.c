#include "../include/task11.h"
//Create a Library Management System. Create a structure containing book information like accession number, 
//name of author, book title and flag to know whether book is issued or not. Create a menu in which the following can be done. 
//1-Display book information 2 - Add a new book 3 - Display all the books in the library of a particular author 
// 4 - Display the total number of 
//books in the library 5 - Issue a book (If we issue a book, then its number gets decreased by 1 and if we add a book, its number gets increased by 1)
void mission11Menu(Library** lib){
    int option  = 0;
    char title[50] = {'\0'}, author[50] = {'\0'};
    unsigned long accession_num = bigrandom();
    do{
        printf("choose from following options:\n"
        "1- display book information\n"
        "2- add a new book\n"
        "3- display all books\n"
        "4- display total number of books in the library\n"
        "5- issue a book\n");
        scanf("%d", &option);
        switch(option) {
            case 1 :
                DisplayInforamtionAboutBook(*lib);
                break;
            case 2 :
                printf("enter book's title:\n");
                getchar();
                fgets(title, sizeof(title), stdin);
                int k = strlen(title);
                title[k - 1] = '\0';
                printf("enter the book's author:\n");
                fgets(author, sizeof(author), stdin);
                int j = strlen(author);
                author[j -1] = '\0';
                Book* book = CreateBook(title,author,&accession_num);
                AddBook(*lib, &book);
                break;
            case 3 :
                DisplayAllBooks(*lib);
                break;
            case 4 :
                TotalNumOfBooks(*lib);
                break;
            case 5 :
                printf("enter book's title:\n");
                getchar();
                fgets(title, sizeof(title), stdin);
                int f = strlen(title);
                title[f -1] = '\0';
                IssueBook(*lib, title);
                break;
            default :
                break;
        }
    } while (option < 1 || option > 6);
}
Book* CreateBook(char* BookTitle, char* Author, unsigned long* accession_number) {
    Book* book = NULL;
    book = (Book*)malloc(sizeof(Book));
    if(book == NULL) {
        printf("allocation of booktitle failed\n");
        exit(0);
    }
    char* Title = setStringInHeap(BookTitle);
    char* author = setStringInHeap(Author);
    book->Author = author;
    book->BookTitle = Title;
    (*accession_number) += 1;
    book->accession_number = (*accession_number);
    book->Issued = 0;

    return book;
}
void DisplayAllBooks(Library* lib) {
    if(lib->NumberOfDifferentBooks == 0) {
        printf("no books registered in library. add books\n");
    } else {
        for(int i = 0; i < lib->NumberOfDifferentBooks; i++) {
            printf("book title is : %s, author name is : %s, accession number is : %ld,is the book issued?",(lib->books)[i]->BookTitle, (lib->books)[i]->Author, (lib->books)[i]->accession_number);
            if((lib->books)[i]->Issued == 1) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
}
void initializeBooksArray(Book*** books_arr, int* arr_size) {
    (*arr_size) += 1;
    Book** tmp = (Book**)realloc(*books_arr, (*arr_size)*sizeof(Book*));
    if(tmp == NULL) {
        printf("allocation of books arr failed\n");
        exit(0);
    }

    *books_arr = tmp;
}
char* setStringInHeap(char* str) {
    int i = strlen(str);
    char *HeapStr = (char*)malloc((i+1) * sizeof(char));
    if(HeapStr == NULL) {
        printf("allocation of string failed\n");
        exit(0);
    }
    strcpy(HeapStr,str);
    HeapStr[i] = '\0';
    return HeapStr;
}
Library* AddBook(Library* library, Book** book) {
    Book* book_tmp = BookSearch(library, (*book)->BookTitle);
    if(book_tmp == NULL) {
        initializeBooksArray(&(library->books), &(library->NumberOfDifferentBooks));
        (library->books)[library->NumberOfDifferentBooks - 1] = (*book);
    } else {
        if(book_tmp ->Issued == 1 ) {
            (book_tmp ->Issued) = ((book_tmp ->Issued) + 1) % 2;
            printf("thank you for returning the book back\n");
        } else {
            printf("book already exist in library\n");
        }
        free((*book)->Author);
        (*book)->Author = NULL;
        free((*book)->BookTitle);
        (*book)->BookTitle = NULL;
        free(*book);
        *book = NULL;
        book = NULL;
    }
    return library;
}
Library* InitializeLibrary() {
    Library* tmp_lib = NULL;
    if(tmp_lib == NULL) {
        tmp_lib = (Library*)malloc(sizeof(Library));
        if(tmp_lib == NULL) {
            printf("allocation of library failed\n");
            exit(0);
        }
        tmp_lib->books = NULL;
        tmp_lib->NumberOfDifferentBooks = 0;
    }
    return tmp_lib;
}
Book* BookSearch(Library* library, char *title) {
    for(int i =0; i < library->NumberOfDifferentBooks; i++) {
        if(strcmp((library->books)[i]->BookTitle, title) == 0) {
            return (library->books)[i];
        }
    }
    return NULL;
}
void clearLibrary(Library** lib) {
    if(*lib != NULL) {
        ClearBooksArray(&((*lib)->books), &((*lib)->NumberOfDifferentBooks));
        free((*lib)->books);
        (*lib)->books = NULL;
        free(*lib);
        *lib = NULL;
    }
}
void ClearBooksArray(Book*** books_arr, int* arr_size) {
    for(int i = 0; i < *arr_size; i++) {
        if((*books_arr)[i] != NULL) {
            free(((*books_arr)[i])->Author);
            ((*books_arr)[i])->Author = NULL;
            free(((*books_arr)[i])->BookTitle);
            ((*books_arr)[i])->BookTitle = NULL;
            free(((*books_arr)[i]));
            ((*books_arr)[i]) = NULL;
        }
    }
}
void DisplayAllBooksFromSameAuthor(Library* library, char *author) {
    int amount = 0;
    for(int i =0; i < library->NumberOfDifferentBooks; i++) {
        if(strcmp((library->books)[i]->Author, author) == 0) {
            amount += 1;
        }
    }
    printf("num of books with given author is: %d\n", amount);
}
void DisplayInforamtionAboutBook(Library* library) {
    int option = 0;
    char str[50] = {'\0'};
    printf("if you want to search by author press 1, by title press 2\n");
    scanf("%d", &option);
    getchar();
    if(option == 1) {
        printf("enter name of author:");
        fgets(str, sizeof(str), stdin);
        int i = strlen(str);
        str[i-1] = '\0';
        DisplayAllBooksFromSameAuthor(library,str);
    } else if(option == 2) {
        printf("enter name of title:");
        fgets(str, sizeof(str), stdin);
        int i = strlen(str);
        str[i-1] = '\0';
        Book* book = BookSearch(library,str);
        if(book == NULL) {
            printf("book not found in library\n");
        } else {
            printf("book title is : %s, author name is : %s, accession number is : %ld,is the book issued?",book->BookTitle, book->Author, book->accession_number);
            if(book->Issued == 1) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
}
void TotalNumOfBooks(Library* library) {
    printf("the total number of books in library is : %d\n", library->NumberOfDifferentBooks);
}
unsigned long bigrandom()
{
    int i = 0;
     unsigned long n = 0;
     // First digit must be non-zero:
     do
     {
         n = rand() % 10;
     } while(n == 0);
     for(i = 1; i < 10; i++)
     {
         n *= 10; 
         n += rand() % 10;
     }
     return n;
}
Library* IssueBook(Library* library, char* title) {
    Book* book = BookSearch(library,title);
    if(book == NULL) {
        printf("we dont have record of this book in the library\n");
    } else {
        if(book->Issued == 0) {
            (book->Issued) = ((book->Issued) + 1)  % 2;
            printf("book issued\n");
        } else {
            printf("book is taken. wait until the book will be returned\n");
        }
    }
    return library;
}
