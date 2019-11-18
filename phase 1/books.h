#include <stdbool.h>
#include "stdio.h"
struct b1
{
	size_t internal_num;
	size_t serial_num;
	bool is_borrowed;
	
};
typedef struct b1 BookCopy;
/*typedef enum { FALSE, TRUE } Bool;*/
typedef enum Z
{
	KIDS,
	HIGHSCHOOL,
	ADULT,
	COMICS,
	DOCUMENTARY
}Zone;
typedef enum e1
{
	E_OK,
	E_ISBORROWED,
	E_ALREADY_IN_LIBRARY
}ErrorCode;
struct book
{
	size_t internal_num;
	char name[50];
	int promotion;
	Zone z;
	
};
typedef struct book Book;
void print_copy(BookCopy *b1);
char * get_error_name(ErrorCode z);
void print_Book(Book * b1);
char * get_zone_name(Zone z);
ErrorCode borrow_copy(BookCopy *b1,bool is_borrowing);
void init_copy(BookCopy *b1,size_t internal);
