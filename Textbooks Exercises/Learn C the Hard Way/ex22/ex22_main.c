#include "ex22.h"
#include "dbg.h"

const char *MY_NAME = "Not Zed Shaw";

void scope_demo(int count)
{
	log_info("count is: %d", count);
	
	if (count > 10)
	{
		// BAD practice!! Called 'shadowing' a variable
		int count = 100;
		log_info("count in this scope is: %d", count);
	}

	log_info("count is at exit: %d", count);

	// BAD practice!! Don't reuse function parameters, lest you get confused about which variable's value you're changing
	count = 3000;

	log_info("count after assign: %d", count);
}

int main(int argc, char *argv[])
{
	// test THE_AGE accessor
	log_info("Name: %s; Age: %d", MY_NAME, get_age());

	set_age(100);

	log_info("Now Age = %d", get_age());

	// test THE_SIZE extern
	log_info("THE_SIZE: %d", THE_SIZE);
	print_size();

	THE_SIZE = 9;

	log_info("THE_SIZE is now: %d", THE_SIZE);
	print_size();

	// test ratio function
	log_info("Ratio at first: %f", update_ratio(2.0));
	log_info("Ratio again: %f", update_ratio(10.0));
	log_info("Ratio one last time: %f", update_ratio(200.0));

	// test scope
	int count = 4;
	scope_demo(count);
	scope_demo(count * 20);
	log_info("count after calling scope demo: %d", count);
	

	return 0;
}
