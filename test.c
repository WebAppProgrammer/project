#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <sys/stat.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
    int fd1, fd2; 
    struct stat sb; 
    struct stat sb2;
    fd_set set;
    struct timeval timeout;
  /* Initialize the file descriptor set. */
  FD_ZERO (&set);
  FD_SET (fd1, &set);

  /* Initialize the timeout data structure. */
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;  
    stat(argv[1], &sb);
    stat(argv[2], &sb2); 
    if( access( argv[1], F_OK ) != -1  && access( argv[2], F_OK ) != -1 && argc==3 && S_ISFIFO(sb.st_mode) && S_ISFIFO(sb2.st_mode)&& argc==3) {
        // file exists
        
	fcntl (fd1, F_SETFD); 	
	open (argv[1],  O_NONBLOCK, O_RDONLY);
	printf("PIPE 1 ASYNCHRNOUS+ READ ONLY!\n");  
	fcntl (fd2, F_SETFD);   
        open (argv[0],  O_NONBLOCK, O_WRONLY);
        printf("PIPE 2 ASYNCHRNOUS+ WRITE ONLY!\n");
	select (FD_SETSIZE,&set, NULL, NULL, &timeout); 
	printf("TIMEOUT!\n"); 
} 
else if(argc<=2){
	printf("ERROR: You need to specify 2 pipes\n"); 
}


else {
        // file doesn't exist
         printf("ERROR: INVALID PIPE\n");
	 return 0; 
    }
    return 0;
}
