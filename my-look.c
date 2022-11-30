#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
    FILE *fp;
    char *file_location;
    char search_term[60];
    char str[256];
    int f_flag = 0;
    int str_len = 0;
    int opt;

    if (argc == 1) {  // check that keyword is provided
        printf("my-look: invalid command line\n");
        return 1;
    }

    while((opt = getopt(argc, argv, "Vhf:")) != -1) {  // check for optional flags
        switch (opt) {
            case 'V':
                printf("%s", "my-look\n");
                return 0;
            case 'h':
                printf("%s", "use my-look with the following optional flags\n");
                printf("%s", "-V : prints information about this utility\n");
                printf("%s", "-h: prints help information about this utility\n");
                printf("%s", "-f <filename>: uses <filename> as the input dictionary.\n");
                printf("%s", "ex., \"my-look -f ./mywords\" will read the file \"./mywords\" for input.\n");
                printf("%s", "If this option is not specified, then my-look will read from standard input\n");
                return 0;
            case 'f':
                f_flag = 1;
                file_location = optarg;
                break;
            case '?':
                printf("my-look: invalid command line\n");
                return 1;
        }
    }

    // set search_term as last argument
    strcpy(search_term, argv[argc-1]);
    str_len = strlen(search_term);

    // if f flag is on, open that file, else use stdin
    if (f_flag) {
        fp = fopen(file_location, "r");

        // if file pointer is not openable
        if (fp == NULL) {
            printf("my-look: cannot open file\n");
            return(1);
        }

        // reading new lines in fp
        while ( fgets (str, sizeof(str), fp)!=NULL ) {
            if (strcmp(str, "\n") != 0) {  // if line is a newline, ignore it
                char alp[256];
                
                int i = 0;
                int j = 0;

                while (i < strlen(str)) { // make the string alphanumeric
                    if (isalnum(str[i])) {
                        alp[j] = str[i];
                        ++j;
                    }
                    ++i;
                }
               	alp[j] = '\0';

                if (strncasecmp(alp, search_term, str_len) == 0) {  // if contains the search term (case insensitive)
                    printf("%s", str);
                }
            }
        }

        fclose(fp);
    } else {
        // reading new lines in stdin
        while ( fgets (str, sizeof(str), stdin)!=NULL ) {
            if (strcmp(str, "\n") != 0) {  // if line is a newline, ignore it
                char alp[256];

                int i = 0;
                int j = 0;

                while (i < strlen(str)) { // make the string alphanumeric
                    if (isalnum(str[i])) {
                        alp[j] = str[i];
                        ++j;
                    }
                    ++i;
                }
                alp[j] = '\0';
                
                
                if (strncasecmp(alp, search_term, str_len) == 0) {  // if contains the search term (case insensitive)
                    printf("%s", str);
                }
            }
        }
        fclose(stdin);
    }

    return(0);
}
