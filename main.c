#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char ** argv){
    if (argc == 1){
        printf("error: must pass in a file\n");
        return 1;
    }

    // get file name
    char * filename = argv[1];

    // compile C file
    char compile_command_buffer[strlen(filename)]; 
    sprintf(compile_command_buffer, "gcc %s -o ./runner.exe", filename);
    system(compile_command_buffer);

    // not all files have command line args
    if (argc == 2){
        system("./runner.exe");
        system("rm runner.exe");
        return 0;
    }

    // get command line arguments
     
    int args_len = 0;
    for (int i = 2; i<argc; i++){
        args_len += sizeof(argv[i]);
        args_len += sizeof(" ");
    }

    // argv for CRUN looks like :
    // ./CRUN ./test.c argument1 argument2
    char  * cl_args_buffer = malloc(args_len);
    strcpy(cl_args_buffer, " "); 

    for (int i = 2; i < argc; i++){
        strcat(cl_args_buffer, argv[i]);
        strcat(cl_args_buffer, " ");
    }

    char runner_command_buffer[strlen("./runner.exe ") + strlen(cl_args_buffer)];
    sprintf(runner_command_buffer, "./runner.exe %s", cl_args_buffer);
    free(cl_args_buffer);
    system(runner_command_buffer);
    system("rm runner.exe");
    return 0;
}
