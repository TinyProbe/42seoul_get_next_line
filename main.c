#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void) {
	char *str;

	str = get_next_line(0);
	while (str) {
		printf("%s", str);
		free(str);
		str = get_next_line(0);
	}
}

//int main(void) {
//	int fd[2];
//	char *str[2];
//	int i;
//
//	fd[0] = open("get_next_line_utils.c", O_RDONLY);
//	fd[1] = open("get_next_line.c", O_RDONLY);
//	while (1) {
//		i = 0;
//		str[0] = get_next_line(fd[0]);
//		str[1] = get_next_line(fd[1]);
//		if (str[0]) {
//		   	printf("%s", str[0]);
//			free(str[0]);
//		   	++i;
//	   	}
//		if (str[1]) {
//		   	printf("%s", str[1]);
//			free(str[1]);
//		   	++i;
//	   	}
//		if (!i) { break; }
//	}
//	close(fd[0]);
//	close(fd[1]);
//}
