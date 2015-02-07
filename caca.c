#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <termios.h>
#define BUFFERSIZE 100

int main(int argc, char *argv[]){
    int fd1, fd2;
    struct stat sb;
    struct stat sb2;
    char *line = NULL;  /* forces getline to allocate with malloc */
    size_t len = 0;
    ssize_t read;
    fd_set rfds;
    int n;
    int fd[2];
    char buf[1025];
    const char* data;
    struct timeval tv;
    int retval;
    unsigned char     buffer[BUFFERSIZE];
    FILE                         *instream;
    int                            bytes_read=0;
    int                            buffer_size=0;
    /* Initialize the timeout data structure. */
    stat(argv[1], &sb);
    stat(argv[2], &sb2);
    
    if( access( argv[1], F_OK ) != -1  && access( argv[2], F_OK ) != -1 && argc==3 && S_ISFIFO(sb.st_mode) && S_ISFIFO(sb2.st_mode)&& argc==3){
        // file exists
        
        fcntl (fd1, F_SETFD);
        open (argv[1],  O_NONBLOCK, O_RDONLY);
        printf("1n");
        printf("PIPE 1 ASYNCHRNOUS+ READ ONLY!n");
        printf("2n");
        fcntl (fd2, F_SETFD);
        printf("3n");
        open (argv[2],  O_NONBLOCK, O_WRONLY);
        printf("4n");
        printf("PIPE 2 ASYNCHRNOUS+ WRITE ONLY!n");
        printf("5n");
        
        /* Watch stdin (fd 0) to see when it has input. */
        printf("6n");
        /* Don’t rely on the value of tv now! */
        /* Watch stdin (fd 0) to see when it has input. */
        FD_ZERO(&rfds);
        printf("7n");
        FD_SET(0, &rfds);
        printf("8n");
        /* Wait up to five seconds. */
        tv.tv_sec = 5;
        printf("9n");
        tv.tv_usec = 0;
        printf("10n");
        retval = select(1,&rfds, NULL, NULL, &tv);
        /* Don't rely on the value of tv now! */
        printf("11n");
        while(1){
            instream=fopen("/dev/stdin","r");
            
            /* did it open? */
            if(instream!=NULL){
                /* read from stdin until it's end */
                //        while((bytes_read=fread(&buffer, buffer_size, 100, instream))==buffer_size){
                
                while(1){
                    //fprintf(stdout, "%c", buffer[0]);
                    //      bytes_read=fread(&buffer, buffer_size, 100, instream);
                    fread(&buffer, buffer_size, 100, instream);
                    
                    write(2,buf,strlen(buf));
                }
            }
            /* if any error occured, exit with an error message */
            else{
                fprintf(stderr, "ERROR opening stdin. aborting.n");
                exit(1);
            }
            
            
            
            
            //read(0, &buf, 1);
            
        }
        
        
        
        
        
        if (retval == -1)
            perror("gghh select()");
        else if (retval)
            printf("Data is available now.n");
        /* FD_ISSET(0, &rfds) will be true. */
        else
            printf("No data within five seconds.n %d       %d", FD_ISSET(0,&rfds), retval);
        
        return 0;
        
        
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

