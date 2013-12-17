#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "writer.h"
#include "global.h"

void write_to_vhd()
{
	FILE *fopt = NULL;
	fopt = fopen(opt, "rb+");
	if (fopt == NULL) {
		printf("%s: %s\n", opt, strerror(errno));
		exit(-1);
	}
	
    int i;
	for (i = 0; i < iptn; ++i) {
		FILE *fipt = NULL;
		fipt = fopen(ipt[i], "rb");
		fseek(fipt, 0, SEEK_SET);
		if (NULL == fipt) {
			printf("%s: %s\n", ipt[i], strerror(errno));
			printf("Write stoped\n");
			fclose(fopt);
			exit(-1);
		}
		fseek(fipt, 0, SEEK_END);
		size_t fsiz = ftell(fipt);
		fseek(fipt, 0, SEEK_SET);
		size_t cur = 0;
		char buf[bufsiz];
		while (1) {
			memset(buf, 0, sizeof(buf));
			size_t s = fread(buf, bufsiz, 1, fipt);
			fwrite(buf, bufsiz, 1, fopt);
			cur += 512;
			if (cur >= fsiz)
				break;
		}
		fclose(fipt);
	}
	fclose(fopt);
}
