#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <sys/stat.h>
 #include <sys/stat.h>
 #include <time.h>
 
#define _BSD_SOURCE     /* Get major() and minor() from <sys/types.h> */
 #include <sys/types.h>
int main(int argc, char *argv[]){
    char p2[20];
    char p1[20];
      
     
    
    static void
 displayStatInfo(const struct stat *sb)
 {
     printf("File type:                ");
 
     switch (sb->st_mode & S_IFMT) {
     case S_IFREG:  printf("regular file\n");            break;
     case S_IFDIR:  printf("directory\n");               break;
     case S_IFCHR:  printf("character device\n");        break;
     case S_IFBLK:  printf("block device\n");            break;
     case S_IFLNK:  printf("symbolic (soft) link\n");    break;
     case S_IFIFO:  printf("FIFO or pipe\n");            break;
     case S_IFSOCK: printf("socket\n");                  break;
     default:       printf("unknown file type?\n");      break;
     }
    return 0;
}
