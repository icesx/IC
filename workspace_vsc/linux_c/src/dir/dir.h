void file_cwd(char *cwd,int length);
int file_mkdir(char* dir);
int file_rmdir(char* dir);
struct dirent * dir_list(char* file);
int file_link(char *oldpath, char *newpath);
int file_unlink(char *newpath);
struct stat * file_stat(char *file)
int file_mkdir(char *dir)
int file_rmdir(char *dir)