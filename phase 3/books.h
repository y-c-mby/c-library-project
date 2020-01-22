#include <stdbool.h>
#include "stdio.h"

struct b1
{
	unsigned short internal_num;
	unsigned int serial_num;
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
typedef enum
{
	E_DRAMA,
	E_THILLER,
	E_HOMUR,
	E_NON_FICTION
}genre;
typedef enum e1
{
	E_OK,
	E_IS_BORROWED,
	E_ALREADY_IN_LIBRARY,
	E_BAD_INDEX,
	E_THIS_BOOK_DIDNT_FOUND,
	E_NULL_PTR,
	E_ALLOCATION_ERROR,
	E_OVER_MEMBER
	
}ErrorCode;
typedef enum 
{
	E_CHEM,
	E_HIST,
	E_MUSC
}describe;
typedef union gen
{
	struct d
	{
		char text_quality;
		char plot_quality;
	}drama;
	int thrilling_factor;
	struct c
	{
		short int homur_quality;
		char homur_type;
	}homur;
	describe non_fiction;
}genre_prop;
 
struct book
{
	unsigned short internal_num;
	char name[50];
	
	signed char promotion;
	Zone z;
	
	genre g;
	genre_prop gp;
	
};
typedef struct book Book;
void print_copy(BookCopy *b1);
const char * get_error_name(ErrorCode z);
void print_Book(Book * b1);
const char * get_zone_name(Zone z);
ErrorCode borrow_copy(BookCopy *b1,bool is_borrowing);
ErrorCode init_copy(BookCopy *b1,unsigned short internal);
bool are_in_same_condition(BookCopy *b1,BookCopy *b2);
bool is_unless(BookCopy *b1);
bool is_ok(BookCopy *b1);
bool is_bookbinder_required(BookCopy *b1);
bool is_librarian_required(BookCopy *b1);
BookCopy *create_copy(unsigned short internal);
const char * get_boolen(bool r);
