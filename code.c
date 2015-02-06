/*
 OS.c
 project
 
 Created by Mouna Hammoudi on 2/4/15.
 Copyright (c) 2015 Mouna Hammoudi. All rights reserved.
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main() {
    
    char *str ;
    char *saveptr;
    char *p1, *p2;
    fgets(str, 100, stdin);
    p1 = strtok_r(str, " ", &saveptr);
    p2 = strtok_r(NULL, " ", &saveptr);
    printf("FILE1:%s", p1);
    printf("FILE2:%s", p2);
    
    
    if( access( p1, F_OK ) != -1 && access( p2, F_OK ) != -1) {
        // file exists
        printf("FILE EXISTS!");
    } else {
        // file doesn't exist
        printf("FILE DOES NOT EXIST!");
        
    }
    
    return 0;
}


