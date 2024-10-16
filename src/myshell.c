/*
Name: Cara Martin
Student ID: 22390791
I acknowledge the DCU Academic Integrity Policy
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <errno.h>

#define MAX_BUFFER 1024
#define MAX_ARGS 64
#define SEPARATORS " \t\n"

// Function prototypes
void cd_dir(char *directory);
void clr_scr();
void l_dir(char *directory);
void l_env();
void cmd_echo(char **args);
void help_man();
void pause_program();
char *get_curr_dir();

int main(int argc, char **argv) {
    char buf[MAX_BUFFER];
    char *args[MAX_ARGS];
    char **arg;
    char *prompt = "Ask Command ==>";
    FILE *in_stream;

    // Open batch file if given in cmd line
    if (argc == 2) {
        // Checking if file successfully opened
        in_stream = fopen(argv[1], "r");
        // Error message if file not opened properly
        if (in_stream == NULL) {
            perror("Error opening your file given");
            exit(EXIT_FAILURE);
        }
    } else if (argc != 1) {
        fprintf(stderr, "Correct Input should look like: %s [file]\n", argv[0]);
        exit(EXIT_FAILURE);
    } else {
        in_stream = stdin;
    }

    // Keep reading input until redirected input interrupts or reach 'quit'
    while (!feof(in_stream)) {
        fputs(prompt, stdout);
	if (fgets(buf, MAX_BUFFER, in_stream)) {
	    // Tokenize input line into the array
            arg = args;
            *arg++ = strtok(buf, SEPARATORS);
            while ((*arg++ = strtok(NULL, SEPARATORS)));

            // Check for input/output redirection
            char *in_fl = NULL;
            char *out_fl = NULL;
            FILE *i_file = NULL;
            FILE *o_file = NULL;

            for (int i = 1; args[i] != NULL; i++) {
                if (strcmp(args[i], "<") == 0) {
                    in_fl = args[i + 1];
                    args[i] = NULL;
                } else if (strcmp(args[i], ">") == 0 || strcmp(args[i], ">>") == 0) {
                    out_fl = args[i + 1];
                    args[i] = NULL;
               }
            }

            // Input redirection
            if (in_fl != NULL) {
                i_file = freopen(in_fl, "r", stdin);
                if (i_file == NULL) {
                    perror("Error opening input file");
                    continue;
                }
            }

            // Output redirection
	    if (out_fl != NULL) {
                o_file = freopen(out_fl, "w", stdout);
                if (o_file == NULL) {
                    perror("Error opening output file");
                    continue;
                }
            }
            // cd
            if (strcmp(args[0], "cd") == 0) {
                if (args[1]) {
                    cd_dir(args[1]);
                } else {
                    printf("Correct Input should look like: cd <name of directory>\n");
                }
		continue;
            // clear
            } else if (strcmp(args[0], "clear") == 0) {
                clr_scr();
		continue;
            // dir <directory>
            } else if (strcmp(args[0], "dir") == 0) {
                if (args[1]) {
                    l_dir(args[1]);
                } else {
                    printf("Correct Input should look like: dir <name of directory>\n");
                }
		continue;
            // environ
            } else if (strcmp(args[0], "environ") == 0) {
                l_env();
		continue;
            // echo <input>
            } else if (strcmp(args[0], "echo") == 0) {
                cmd_echo(args);
		continue;
            // quit
            } else if (strcmp(args[0], "quit") == 0) {
                break;
            // help
            } else if (strcmp(args[0], "help") == 0) {
                help_man();
		continue;
            // pause <num>
            } else if (strcmp(args[0], "pause") == 0) {
                pause_program();
		continue;
            // Other commands
            } else {
                execvp(args[0], args);
                printf("Command not found");
            }


            // Close input and output files
            if (i_file != NULL) {
                fclose(i_file);
            }
	    if (o_file != NULL) {
		fclose(o_file);
	    }
        }
    }

    // Close given file if opened
    if (in_stream != stdin) {
        fclose(in_stream);
    }

    return 0;
}

// Function for changing the current directory
void cd_dir(char *directory) {
    if (chdir(directory) == 0) {
        setenv("PWD", directory, 1);
    } else {
        // error message
        perror("cd");
    }
}

// Function for "clear" command
void clr_scr() {
    system("clear");
}

// Function for "dir" command
void l_dir(char *directory) {
    char command[MAX_BUFFER];
    snprintf(command, sizeof(command), "ls -al %s", directory);
    system(command);
}

// Function for "environ" command
void l_env() {
    extern char **environ;
    char **env = environ;
    while (*env) {
        printf("%s\n", *env++);
    }
}
//Function for echo command
void cmd_echo(char **args) {
    for (int i = 1; args[i] != NULL; i++) {
        printf("%s", args[i]);
    }
    printf("\n");
}

// Function to display the manual
void help_man() {
    system("more ../manual/readme.md");
}

//Function to pause the program running
void pause_program() {
    printf("Press Enter to continue...");
    while (getchar() != '\n');
}

// Function for checking current dir
char *get_curr_dir() {
    static char cwd[MAX_BUFFER];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        return cwd;
    } else {
        perror("getcwd");
        return NULL;
    }
}
