# Simple C Shell Project

<p>This is a Simple Implementation of a C Shell written in C. It allows Users to enter commands and execute them as separete processes</p>

## Features
- Displays a prompt and waits for the user to type a command.
- The prompt is displayed again each time a command has been executed.
- Command lines are simple, consisting of only one word or a command with arguments.
- Handles errors and displays an error message if an executable cannot be found.
- Handles the "end of file" condition (Ctrl+D).
- Handles the PATH environment variable to locate executables.
- fork is not called if the command doesn't exist.
- Implements the built-in exit command to exit the shell.

## Usage
To compile and run the shell use the following command:
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
`$ ./hsh`
## Contributors
1. Griffin Mulei
2. Catherine Kimani

## Example
<p>Here's is an example of how our shell works:</p>

`./hsh`
`#cisfun$ ls -l /tmp`
`total 51`
`-rw------- 1 user user 0 Apr 22 20:05` `gdm3-config-err-RgfRb9`
`drwx------ 2 user user 2 Apr 22 23:11` `pyright-22007-hpwHZ9MO97Gt`
`drwx------ 2 user user 2 Apr 22 23:11` `pyright-22007-Vu9A4aTSmqbo`
`drwxrwxr-x 3 user user 3 Apr 22 23:10` `python-languageserver-cancellation`
`drwxrwxr-x 3 user user 3 Apr 22 23:08` `remote-file-71752ccfe2464e99`
`drwx------ 4 root root 4 Apr 22 20:05 snap-private-tmp`