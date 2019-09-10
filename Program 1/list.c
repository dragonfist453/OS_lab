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
	if(argc == 1)
		d = opendir("./");
	else if(argc > 2)
	{
		printf("Too many arguments\n");
		exit(0);
	}
	else
		d = opendir(argv[1]);
	struct stat stats;
	while(d!=NULL)
	{
		struct dirent *d1 = readdir(d);
		stat(buf,&stats);
		PrintFileProps(stats,d1);
		printf("\'%s\'\n",d1->d_name);
	}
	closedir(d);
	return 0;
}
void PrintFileProps(struct stat stats,struct dirent *file)
{
	struct tm dt;
	mode_t ez = stats.st_mode;
	switch(ez & S_IFMT)
	{
		case S_IFBLK: printf("b ");;break;
		case S_IFCHR: printf("c ");break;
		case S_IFDIR: printf("d ");break;
		case S_IFIFO: printf("p ");break;
		case S_IFLNK: printf("l ");break;
		case S_IFSOCK: printf("s ");break;
		default: printf("- ");break;
	}
	printf( (ez & S_IRUSR) ? "r":"-");
	printf( (ez & S_IWUSR) ? "w":"-");
	printf( (ez & S_IXUSR) ? "x ":"- ");
	printf( (ez & S_IRGRP) ? "r":"-");
	printf( (ez & S_IWGRP) ? "w":"-");
	printf( (ez & S_IXGRP) ? "x ":"- ");
	printf( (ez & S_IROTH) ? "r":"-");
	printf( (ez & S_IWOTH) ? "w":"-");
	printf( (ez & S_IXOTH) ? "x ":"- ");

	printf("%ld ",stats.st_nlink);

	tf = getpwuid(stats.st_uid);
	printf("%s ",tf->pw_name);

	gf = getgrgid(stats.st_gid);
	printf("%s ",gf->gr_name);

	printf("%zu ",stats.st_size);
	printf("%s ",file->d_name);
	printf("%s ",ctime(&stats.st_mtime));
}
