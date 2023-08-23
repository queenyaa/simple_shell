README file for simple_shell project, to create a mini shell.

```
# Custom Shell - README

## Description
This is a custom shell implementation written in C. It provides basic shell functionality, including command execution, environment variable handling, variable expansion, and more.

## Features
- Execution of external commands
- Built-in commands: `env`, `exit`, `setenv`, `unsetenv`, `cd`, `help`
- Environment variable handling
- Variable expansion for `$`, `$$`, and `$?`
- Support for command chaining using `;`, `|`, and `&`
- Ctrl+C signal handling
- Error handling and error messages

## Getting Started
1. Clone the repository: `git clone https://github.com/queenyaa/simple_shell.git`
2. Navigate to the project directory: `cd custom-shell`
3. Compile the code: `gcc -Wall -Werror -Wextra -pedantic *.c -o shell`
4. Run the shell: `./shell`

## Usage
1. Run the shell using the `./shell` command.
2. Enter commands as you would in a standard shell.
3. Use the built-in commands or external commands as needed.
4. Environment variables can be accessed using the `$VAR_NAME` syntax.
5. Use `$?` to refer to the exit status of the last command.
6. Use `$$` to refer to the shell's process ID.

## Built-in Commands
- `env`: Display the environment variables.
- `exit [status]`: Exit the shell with an optional status code (0-255).
- `setenv VAR_NAME VAR_VALUE`: Set an environment variable.
- `unsetenv VAR_NAME`: Unset an environment variable.
- `cd [directory]`: Change the current directory.
- `help [command]`: Display help messages for commands.

## Examples
1. Running external command:
   ```
   $ ls -l
   ```
2. Using environment variables:
   ```
   $ setenv MY_VAR Hello
   $ echo $MY_VAR
   Hello
   ```

3. Variable expansion:
   ```
   $ echo $$
   1234   # Process ID

   $ echo $?
   0      # Exit status of last command
   ```

4. Command chaining:
   ```
   $ ls -l ; pwd
   ```

## Notes
- This shell is a basic implementation and may not cover all edge cases.
- This project is for educational purposes and may not be suitable for production use.

##Auhors
queenyaa (https://github.com/queenyaa)
eoasante98 (https://github.com/eoasante98)

