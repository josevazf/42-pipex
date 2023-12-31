# 42-pipex

This project's goal is to better understand shell redirection and pipes, by handling them in C.

This pipex program takes an input file, performs a command on it, pipes the result to another command which then writes its result to an output file. The result is virtually identical to this kind of shell command:
```
$ < input_file command1 | command2 > output file
```
## Usage
To compile, use ```make```, ```make all``` or ```make bonus```.

### Regular pipex execution
Pipex can handle 2 or more commands. To execute:

```
$ ./pipex input_file command1 command2 ... commandn output_file
```
The output will be written to the specified output file. If the output file exists, it will be overwritten. This replicates the shell command:
```
$ < input_file command1 | command2 | ... | commandn > output_file
```

Each command can be given arguments and options if surrounded by quotation marks. For example:
```
$ ./pipex example.txt "cat" "grep x" "sed s/l/.../g" outfile.txt
```

### Pipex heredoc execution
You can also run pipex with a heredoc, like this:
```
$ ./pipex here_doc LIMITER command1 command2 ... commandn output_file
```
You will then be asked to input text which will be used as input for the commands. In this case, the specified output file will not be overwritten but appended, which replicates the behavior of the shell command:
```
$ << LIMITER command1 | command2 | ... | commandn >> output_file
```

## Norminette
This project was written in accordance with the Norm, which is the coding standard of the 42 school.

The Norm includes:
- Forbidden: for, do...while, switch, case, goto, ternary operators and variable-length arrays 
- Maximum of 25 lines per function
- Maximum line length: 80 columns
- Maximum 4 parameters per function 
- Variable assignments and declarations must be on separate lines
- etc...
