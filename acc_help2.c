#include "shell.h"

/**
 * acc_help_cd - displays help info for the 'cd' cmd
 * Return: ...
 */
void acc_help_cd(void)
{
	char *boa = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, boa, _strlen(boa));
	boa = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, boa, _strlen(boa));
}

/**
 * acc_help_alias - displays help info for the 'alias' cmd
 * Return: ...
 */
void acc_help_alias(void)
{
	char *boa = "alias: alias [-p] [nick[=value]...]\n";

	write(STDOUT_FILENO, boa, _strlen(boa));
	boa = "\tDefine or display aliases.\n";
	write(STDOUT_FILENO, boa, _strlen(boa));
}

/**
 * acc_help - displays help info for the 'help' cmd
 * Return: ...
 */
void acc_help(void)
{
	char *boa = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, boa, _strlen(boa));
	boa = "\tDisplay information about builtin  commands.\n ";
	write(STDOUT_FILENO, boa, _strlen(boa));
	boa = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, boa, _strlen(boa));
}
