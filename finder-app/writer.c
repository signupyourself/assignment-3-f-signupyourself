#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<syslog.h>
#include<errno.h>

int main(int argc, char** argv){
    
    openlog(NULL,0,LOG_USER);

    if(argc < 3){
        syslog(LOG_ERR, "Not all arguments provided\n");
        return 1;
    }

    int fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0644);
    
    if(fd == -1){

        syslog(LOG_ERR, "Error creating file\n");
        return 1;
    }

    syslog(LOG_DEBUG, "Writing %s to file %s\n",argv[2], argv[1]);

    int status = write(fd, argv[2], strlen(argv[2]));
    
    if(status == -1){
        syslog(LOG_ERR, "Error writing to the file\n");
        return 1;
    }

    return 0;
}