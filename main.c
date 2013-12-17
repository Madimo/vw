#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "lib/init.h"
#include "lib/writer.h"

int main(int argc, char *argv[])
{
	avg_init(argc, argv);
    write_to_vhd();
    
	return 0;
}
