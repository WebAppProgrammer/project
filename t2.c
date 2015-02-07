#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <sys/stat.h>
#include<stdio.h>
#include<string.h>
#include <errno.h>
 #include <sys/select.h>
    #include <sys/time.h>
  #include <stdlib.h>
    #include <stdio.h>
    #include <fcntl.h>
 #include <sys/time.h>
 #include <sys/select.h>
 #include <fcntl.h>
 #include <signal.h>

  int readPipe(int fd)
    {
        ssize_t bytes;
        size_t total_bytes = 0;
        char buffer[100*1024];

        printf("\nReading pipe descriptor # %d\n",fd);
        for(;;) {
            bytes = read(fd, buffer, sizeof(buffer));
            if (bytes > 0) {
                total_bytes += (size_t)bytes;
                printf("%s", buffer);
            } else {
                if (errno == EWOULDBLOCK) {
                    break;
                } else {
                    perror("read error");
                    return EXIT_FAILURE;
                }
            }
        }
        return EXIT_SUCCESS;
    }





int main(int argc, char argv[]){
    int fd_a, fd_b;
    int nfd; 
    fd_set read_fds; 
    struct stat sb; 
    struct stat sb2;
    fd_set set;
    struct timeval tv;
    const char pfd[2]; 
  /* Initialize the timeout data structure. */
    tv.tv_sec = 10;
    tv.tv_usec = 0;  
    stat(argv[1], &sb);
    stat(argv[2], &sb2); 
    if( access( argv[1], F_OK ) != -1  && access( argv[2], F_OK ) != -1 && argc==3 && S_ISFIFO(sb.st_mode) && S_ISFIFO(sb2.st_mode)&& argc==3) {
        // file exists
       
	// open file descriptors of named pipes to watch
    fd_a = fcntl(argv[0], F_SETFL , 0);
 







         open(fd_a, O_RDONLY , O_NONBLOCK);
        if (open(fd_a, O_RDONLY , O_NONBLOCK) == -1) {
            perror("open error");
            return EXIT_FAILURE;
        }
        open(fd_b, O_WRONLY , O_NONBLOCK);
        if (   open(fd_b, O_WRONLY , O_NONBLOCK)==-1) {
          perror("open error");
            return EXIT_FAILURE;

	}

        for(;;)
        {
            // clear fds read flags
            FD_ZERO(&read_fds);

            // check if there is new data in any of the pipes
            // PIPE_A
            FD_SET(fd_a, &read_fds);
            nfd = select(fd_a+1, &read_fds, NULL, NULL, &tv);
            if (nfd != 0) {
                if (nfd == -1) {
                  perror("open error");
            return EXIT_FAILURE;
		}
                if (FD_ISSET(fd_a, &read_fds)) {
                    readPipe(fd_a);
                }
            }

            // PIPE_B
            FD_SET(fd_b, &read_fds);
            nfd = select(fd_b+1, &read_fds, NULL, NULL, &tv);
            if (nfd != 0) {
                if (nfd == -1) {
                    perror("select error");
                    return EXIT_FAILURE;
                }
                if (FD_ISSET(fd_b, &read_fds)){
                    readPipe(fd_b);
                }
            }

  usleep(100000);
        }
        return EXIT_SUCCESS;
    }
}
/*
 
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
}*/
