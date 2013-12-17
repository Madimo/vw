#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "init.h"
#include "global.h"

void avg_init(int argc, char *argv[])
{
	if (argc < 2) {
		printf("vw version %s\n", _version);
        exit(0);
	} else if (argc < 3) {
        // todo: read from file
        
	} else if (strcmp(argv[argc - 2], "~~")) {
		printf("No output file\n");
		exit(-1);
	} else {
        opt = argv[argc - 1];
        iptn = argc - 3;
        ipt = (char **) malloc(sizeof(char *) * (argc - 3));
        memcpy(ipt, &argv[1], sizeof(char *) * (argc - 3));
    }
}
