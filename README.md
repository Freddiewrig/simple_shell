0. Betty would be proud
mandatory
Write a beautiful code that passes the Betty checks
1. Simple shell 0.1
mandatory
Write a UNIX command line interpreter.
2. Simple shell 0.2
mandatory
Simple shell 0.1 +

Handle command lines with arguments
3. Simple shell 0.3
mandatory
Simple shell 0.2 +

Handle the PATH
fork must not be called if the command doesn’t exist
4. Simple shell 0.4
mandatory
Simple shell 0.3 +

Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit
5. Simple shell 1.0
mandatory
Simple shell 0.4 +

Implement the env built-in, that prints the current environment
6. Simple shell 0.1.1
#advanced
Simple shell 0.1 +

Write your own getline function
Use a buffer to read many chars at once and call the least possible the read system call
You will need to use static variables
You are not allowed to use getline
7. Simple shell 0.2.1
#advanced
Simple shell 0.2 +

You are not allowed to use strtok
Simple shell 0.4 +

handle arguments for the built-in exit
Usage: exit status, where status is an integer used to exit the shell
9. setenv, unsetenv
#advanced
Simple shell 1.0 +

Implement the setenv and unsetenv builtin commands
10. cd
#advanced
Simple shell 1.0 +

Implement the builtin command cd:
11. ;
#advanced
Simple shell 1.0 +

Handle the commands separator ;
12. && and ||
#advanced
Simple shell 1.0 +

Handle the && and || shell logical operators
13. alias
#advanced
Simple shell 1.0 +

Implement the alias builtin command
Usage: alias [name[='value'] ...]
14. Variables
#advanced
Simple shell 1.0 +

Handle variables replacement
Handle the $? variable
Handle the $$ variable
15. Comments
#advanced
Simple shell 1.0 +

Handle comments (#)
16. File as input
#advanced
Simple shell 1.0 +

Usage: simple_shell [filename]
Your shell can take a file as a command line argument
The file contains all the commands that your shell should run before exiting
The file should contain one command per line
In this mode, the shell should not print a prompt and should not read from stdin
