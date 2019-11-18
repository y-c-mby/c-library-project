#include <stdbool.h>
#include "stdio.h"

struct b1
{
	size_t internal_num;
	size_t serial_num;
	bool is_borrowed;
	size_t borrowing_times;
	char problem;
	
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
	E_IS_BORROWED,
	E_ALREADY_IN_LIBRARY,
	E_BAD_INDEX,
	E_THIS_BOOK_DIDNT_FOUND
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
bool are_in_same_condition(BookCopy *b1,BookCopy *b2);
bool is_unless(BookCopy *b1);
bool is_ok(BookCopy *b1);
bool is_bookbinder_required(BookCopy *b1);
bool is_librarian_required(BookCopy *b1);
BookCopy *create_copy(size_t internal);
char * get_boolen(bool r);
