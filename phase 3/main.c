
#include "local_library.h"
#include "stdlib.h"
#include "test.h"
#define NUMCOPIES 2
extern Book books[];
ErrorCode error;
void print_books()
{
	unsigned short i;
	unsigned short j=num_books();
	for(i=0;i<j;i++)
	{
		print_Book(&(books[i]));
	}
}
void print_copies(size_t numofcopies,BookCopy **book_copies)
{
	size_t i;
	for(i=0;i<numofcopies;i++)
	{
		print_copy(book_copies[i]);
	}
}
void borrow_book(size_t numofcopies,BookCopy **book_copies)
{
	int n;
	unsigned short internal;
	size_t i;
	bool flag=false;
	printf("menu:\nfor borrow a book-copy press 1\n for return a book-copy press 2\n for exit prees 9\n");
	scanf("%d",&n);
	if(n==9)
	{
		printf("goodby");
		return;
	}
	if(n!=1&&n!=2)
	{
		printf("%s \n",get_error_name(E_BAD_INDEX));
	}
	else
	{
		printf("enter internal number \n");
		scanf("%hu",&internal);
		for(i=0;i<numofcopies;i++)
		{
			if(book_copies[i]->internal_num==internal)
			{
				if(n==1)
				{
					printf("%s \n",get_error_name(borrow_copy(book_copies[i],true)));
				}
				else
				{
					printf("%s \n",get_error_name(borrow_copy(book_copies[i],false)));
				}
				flag=true;	
			}
		}
		if(!flag)
		{
			printf("%s \n",get_error_name(E_THIS_BOOK_DIDNT_FOUND));
		}
	}
}
void free_array(size_t numofcopies,BookCopy **book_copies)
{
	size_t i;
	for(i=0;i<numofcopies;i++)
	{
		free(book_copies[i]);
	}
	free(book_copies);
	book_copies=NULL;
}

int main()
{
	
	
	/*initilaziation*/
	size_t i;
	unsigned short internal;
	size_t numofcopies;
	BookCopy **book_copies;
	/* test functions */
	test_is_librarian_required();
	test_is_bookbinder_required();
	test_are_in_same_condition();
	test_is_ok();
	test_is_unless();
	/*print the name of the books of the library*/
	print_books();
	/*put copies in the array of the book-copies;*/
	printf("enter number of copies:");
	scanf("%lu \n",&numofcopies);
	book_copies=malloc(sizeof(BookCopy*)*numofcopies);
	for(i=0;i<numofcopies;i++)
	{
		scanf("%hu",&internal);
		*(book_copies+i)=create_copy(internal);
	}
	print_copies(numofcopies,book_copies);
	/*borrowing books in the library*/
	borrow_book(numofcopies,book_copies);
	/*print_copies(numofcopies,book_copies);*/
	/*free the allocation memory*/
	free_array(numofcopies,book_copies);
	return 1;
	
}

