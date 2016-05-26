#include "func.h"

void main()
{
	FILE* fp;

	fp = fopen("membership.txt", "w");
	fclose(fp);

	select();
}
