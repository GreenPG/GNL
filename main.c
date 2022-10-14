#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int	fd;
	char	*line;
		
	line = "";
	fd	= open("files/41_no_nl", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	return (0);		
}
