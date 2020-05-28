#include "book.h"

book::book(string name, string author, int year, string publish)
{
	set_name(name);
	set_author(author);
	set_year(year);
	set_publish(publish);
	set_deleted(false);
}
