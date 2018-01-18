#include <dirent.h>
#include <errno.h>
#include "./get_next_line/repoGit/libft/libft.h"

int main(int argc, char **argv)
{
	DIR *dir;
	struct dirent *dirstream;
	
	ft_putstr("argv = ");
	ft_putstr(argv[1]);
	ft_putstr("\n");
	if (!(dir = opendir(argv[1])))
	{
		ft_putstr("errno = ");
		ft_putnbr(errno);
		ft_putstr("\n strerror(errno) = ");
		ft_putstr(strerror(errno));
		ft_putstr("\n");
		perror("c moch");
		return (0);
	}
	while (dirstream = readdir(dir))
	{
		ft_putstr(dirstream->d_name);
		ft_putnbr(dirstream->d_type);
		ft_putstr("\n");
	}
	if (errno)
	{
		ft_putstr("errno = ");
		ft_putnbr(errno);
		ft_putstr("\n strerror(errno) = ");
		ft_putstr(strerror(errno));
		ft_putstr("\n");
		perror("c moch");
	}
	closedir(dir);
	return(0);
}
