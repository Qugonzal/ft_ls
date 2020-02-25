#include <sys/ioctl.h>
#include <stdio.h>
#include <sys/xattr.h>

int main (int ac, char **av)
{
    struct winsize w;
	(void)ac;
	int size;

	size  = listxattr(av[1], 0, 0, 0);
	printf("%d\n", size);
	size  = listxattr(av[1], 0, 0, XATTR_NOFOLLOW);
	printf("%d\n", size);
	size  = listxattr(av[1], 0, 0, XATTR_SHOWCOMPRESSION);
	printf("%d\n", size);
    ioctl(0, TIOCGWINSZ, &w);

    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);
    return 0;
}
