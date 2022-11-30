# my-look

A typical usage if you would like to find a list of words that start with "gn" would be:

prompt> ./my-look -f /usr/share/dict/words gn

my-look has one required command-line argument: the string to search for.  However, my-look has a number of optional command-line arguments that must appear before the required string.

-V : prints information about this utility; the message should be exactly "my-look from CS537 Spring 2022" followed by a newline.  The utility should then exit with status code 0 without processing any more options.  (Note this an upper-case V, not lower-case.  Lower-case v is often used to signify verbose output.)
-h: prints help information about this utility; you can display this information in the way you think is best.  The utility should then exit with status code 0 without processing any more options.
-f <filename>: uses <filename> as the input dictionary.  For example, "my-look -f ./mywords" will read the file "./mywords" for input.  If this option is not specified, then  my-look will read from standard input (i.e., stdin); it will not open a file called stdin!!!  
If my-look encounters any other arguments or has any error parsing the command line arguments, you should exit with status code 1 and print the exact error message "my-look: invalid command line"  (followed by a newline).
