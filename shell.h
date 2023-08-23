#ifndef SHELL_H
#define SHELL_H

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>

#define LOAD 1024
#define PAR_LOAD 128
#define PAR_SHORT " \a\n\t\r"

extern char **environ;

/**
 * struct inp - input on runtime
 * @avec: argument vector
 * @argt: tokens of the command line
 * @intk: ...
 * @presnt: last status of the shell
 * @sheep: counter of lines
 * @_vicinity: environment variable
 * @pid: process ID of the shell
 */
typedef struct inp
{
	char **avec;
	char *intk;
	char **argt;
	int presnt;
	int sheep;
	char **_vicinity;
	char *pid;
} inp_shell;

/**
 * struct signal_list - single linked list
 * @signal: ; | &
 * @fward: next node
 * Description: single linked list to staore separators
 */

typedef struct signal_list
{
	char signal;
	struct signal_list *fward;
} sig_list;

/**
 * struct strline_list - single linked list
 * @seam: command line
 * @fward: next node
 * Description: single linked list to store command lines
 */
typedef struct strline_list
{
	char *seam;
	struct strline_list *fward;
} strlin_list;

/**
 * struct variant_list - single linked list
 * @dim_var: length of the variable
 * @wght: value fo the variable
 * @dim_wght: length of the value
 * @fward: next node
 * Description: single linked list to store variables
 */
typedef struct variant_list
{
	int dim_var;
	char *wght;
	int dim_wght;
	struct variant_list *fward;
} d_var;

/**
 * struct inher_s - Builtin struct for command args
 * @nick: The name of the command builtin i.e. cd, exit, env
 * @pf: data type pointer function
 */
typedef struct inher_s
{
	char *nick;
	int (*pf)(inp_shell *inpsh);
} inher_u;

/* acc_registry.c */
sig_list *add_sig_tail(sig_list **head, char sig);
void free_sig_list(sig_list **head);
strlin_list *add_dim_tail(strlin_list **head, char *seam);
void free_strlin_list(strlin_list **head);

/* acc_registry1.c */
d_var *add_dvar_n(d_var **head, int dvar, char *wght, int dwght);
void free_dvar_list(d_var **head);

/* acc_str.c functions */
char *_strcat(char *des, const char *sr);
char *_strcpy(char *des, char *sr);
int _strcmp(char *t1, char *t2);
char *_strchr(char *t, char c1);
int _strspn(char *t, char *take);

/* acc_mem.c */
void _memcpy(void *n_ptr, const void *ptr, unsigned int sz);
void *_realloc_(void *ptr, unsigned int o_sz, unsigned int n_sz);
char **_realloc_p(char **ptr, unsigned int o_sz, unsigned int nw_sz);

/* acc_str2.c */
char *_strdup(const char *t);
int _strlen(const char *t);
int cp_chars(char str[], const char *dlim);
char *_strtok(char str[], const char *dlim);
int _isdigit(const char *t);

/* acc.str3.c */
void rv_string(char *t);

/* chk_syntx_err.c */
int rep_char(char *intk, int x);
int err_sig_op(char *intk, int x, char last);
int fir_char(char *intk, int *x);
void pr_syntx_err(inp_shell *inpsh, char *intk, int  x, int bool);
int chk_syntx_err(inp_shell *inpsh, char *intk);

/* shell_circle.c */
char *wout_comm(char *in);
void sh_circle(inp_shell *inpsh);

/* rd_seam.c */
char *rd_seam(int *x_eof);

/* split.c */
char *chng_char(char *intk, int bool);
void add_nodes(sig_list **head_s, strlin_list **head_l, char *intk);
void go_next(sig_list **list_s, strlin_list **list_l, inp_shell *inpsh);
int split_cmds(inp_shell *inpsh, char *intk);
char **split_seam(char *intk);

/* rep_var.c */
void chk_env(d_var **h, char *in, inp_shell *inp);
int chk_vars(d_var **h, char *in, char *st, inp_shell *inp);
char *repl_intk(d_var **head, char *intk, char *n_intk, int n_len);
char *rep_var(char *intk, inp_shell *inpsh);

/* g_seam */
void br_seam(char **seamptr, size_t *m, char *buff, size_t y);
ssize_t get_seam(char **seamptr, size_t *m, FILE *strm);

/* exec_seam */
int exec_line(inp_shell *inpsh);

/* cmd_exec.c */
int _cdir(char *road, int *x);
char *_which_(char *cmd, char **_vicinity);
int _exe_(inp_shell *inpsh);
int chk_err_cmd(char *dir, inp_shell *inpsh);
int cmd_execut(inp_shell *inpsh);

/* g_env1.c */
int cmp_env_nick(const char *nenv, const char *nick);
char *_getenv(const char *nick, char **_vicinity);
int _env(inp_shell *inpsh);

/* g_env2.c */
char *cp_info(char *nick, char *value);
void set_env(char *nick, char *value, inp_shell *inpsh);
int _setenv(inp_shell *inpsh);
int _unsetenv(inp_shell *inpsh);

/* g_cd.c */
void cd_dt(inp_shell *inpsh);
void cd_to(inp_shell *inpsh);
void cd_previous(inp_shell *inpsh);
void cd_to_home(inp_shell *inpsh);

/* cd_shell.c */
int cd_shell(inp_shell *inpsh);

/* g_builtin.c */
int (*get_builtin(char *cmd))(inp_shell *);

/* _exit.c */
int exit_sh(inp_shell *inpsh);

/* acc_stdlib.c */
int g_len(int m);
char *acc_itoa(int m);
int _atoi(char *t);

/* acc_error1.c */
char *err_g_cd(inp_shell *inpsh);
char *err_nfound(inp_shell *inpsh);
char *strcat_cd(inp_shell *inpsh, char *note, char *err, char *v_str);
char *err_exit_shell(inp_shell *inpsh);

/* acc_error2.c */
char *err_path_126(inp_shell *inpsh);
char *err_env(inp_shell *inpsh);
char *err_g_alias(char **argt);
char *err_syntx(char **argt);
char *err_permit(char **argt);

/* g_error.c */
int g_err(inp_shell *inpsh, int eval);

/* g_signint.c */
void g_signint(int sym);

/* r_shell */
int r_shell(void);

/* acc_help.c */
void acc_help_setenv(void);
void acc_help_env(void);
void acc_help_unsetenv(void);
void acc_help_exit(void);
void acc_help_general(void);

/* acc_help2.c */
void acc_help(void);
void acc_help_alias(void);
void acc_help_cd(void);

/* g_help.c */
int g_help(inp_shell *inpsh);

#endif
