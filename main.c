#include "func.h"

int main()
{
	//testDB();
	if (connectDB() < 0) {
		return -1;
	}

	select_1();

	closeDB();

	return 0;
}