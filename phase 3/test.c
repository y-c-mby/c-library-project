#include "local_library.h"
BookCopy * test_create()
{
	unsigned short  num;
	BookCopy * ptr;
	printf("enter internal num \n");
	scanf("%hu",&num);
	ptr=create_copy(num);
	return ptr;
}
void test_is_librarian_required()
{
	BookCopy * book=test_create();
	printf("is_librarian_required %s \n",get_boolen(is_librarian_required(book)));
}
void test_is_bookbinder_required()
{
	BookCopy * book=test_create();
	printf("is_bookbinder_required %s \n",get_boolen(is_bookbinder_required(book)));
}
void test_is_ok()
{
	BookCopy * book=test_create();
	printf("is_ok %s \n",get_boolen(is_ok(book)));
}
void test_is_unless()
{
	BookCopy * book=test_create();
	printf("is_unless %s \n",get_boolen(is_unless(book)));
}
void test_are_in_same_condition()
{
	BookCopy * book=test_create();
	printf("are_in_same_condition %s \n",get_boolen(are_in_same_condition(book,book)));
}

