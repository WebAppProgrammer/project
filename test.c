#include<stdio.h>
#include<string.h>
#include<unistd.h>


int main(int argc, char *argv[]){
    char p2[20];
    char p1[20];
      
     
    
    if( access( argv[1], F_OK ) != -1  && access( argv[2], F_OK ) != -1 && argc==3  ) {
        // file exists
        printf("EXISTS");
    } else {
        // file doesn't exist
         printf("FILE DOES NOT EXIST");
	 return 0; 
    }
    return 0;
}
# Project
