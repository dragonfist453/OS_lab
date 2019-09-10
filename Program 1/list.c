#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>

void PrintFileProps(struct stat stats,struct dirent *file);
struct passwd *tf;
struct group *gf;
char buf[512];
int main(int argc, char* argv[])
{
	DIR *d;
	char str[30];
	if(argc == 1)
	{
		d = opendir("./");
		sprintf(str,"./");
	}
	else if(argc > 2)
	{
		printf("Too many arguments\n");
		exit(0);
	}
	else
	{
		d = opendir(argv[1]);
		sprintf(str,"%s",argv[1]);
	}
	struct stat stats;
	struct dirent *file;
	while( (file = readdir(d)) != NULL)
	{
		sprintf(buf,"%s%s",str,file->d_name);
		stat(buf,&stats);
		PrintFileProps(stats,file);
	}
	closedir(d);
	return 0;
}
void PrintFileProps(struct stat stats,struct dirent *file)
{
	struct tm dt;
	//mode_t ez = stats.st_mode;
	switch(stats.st_mode & S_IFMT)
	{
		case S_IFBLK: printf("b");;break;
		case S_IFCHR: printf("c");break;
		case S_IFDIR: printf("d");break;
		case S_IFIFO: printf("p");break;
		case S_IFLNK: printf("l");break;
		case S_IFSOCK: printf("s");break;
		default: printf("-");break;
	}
	printf( (stats.st_mode & S_IRUSR) ? "r":"-");
	printf( (stats.st_mode & S_IWUSR) ? "w":"-");
	printf( (stats.st_mode & S_IXUSR) ? "x":"-");
	printf( (stats.st_mode & S_IRGRP) ? "r":"-");
	printf( (stats.st_mode & S_IWGRP) ? "w":"-");
	printf( (stats.st_mode & S_IXGRP) ? "x":"-");
	printf( (stats.st_mode & S_IROTH) ? "r":"-");
	printf( (stats.st_mode & S_IWOTH) ? "w":"-");
	printf( (stats.st_mode & S_IXOTH) ? "x":"-");

	printf(" %3ld",stats.st_nlink);

	tf = getpwuid(stats.st_uid);
	printf(" %9s",tf->pw_name);

	gf = getgrgid(stats.st_gid);
	printf(" %9s",gf->gr_name);

	printf(" %10zu",stats.st_size);

	printf(" %20s",ctime(&stats.st_mtime));

	printf(" \'%s\'\n",file->d_name);
}
