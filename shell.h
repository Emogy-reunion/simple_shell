#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAXIMUM_ENTRY_LENGTH 120
#define MAXIMUM_ARGUMENTS 10
#define MAXIMUM_ARGUMENT_LENGTH 20
#define MAXIMUM_BUFFER_SIZE 1024

extern char **environ;
ssize_t custom_getline(char **input, size_t *len, int fd);
char *substitute_vars(char *entry);
char *string_dup(const char *string);
size_t custom_string_length(const char *string);
int my_strcmp(const char *word1, const char *word2);
void my_strcpy(char *location, const char *origin);
int custom_atoi(const char *string);
size_t reject_chars(const char *string, const char *reject);
void custom_env_handling(void);
void custom_cd_handling(char **arguments);
void carry_out_directive(char *directive, char **arguments);
void custom_exit_handling(char **arguments);
void search_run_directive(char **arguments);
void custom_setenv_handling(char **arguments);
void file_input(const char *file_name);
void interactive_mode(void);
void create_buffer(char **entry, size_t *length);
void reallocate_buffer(char **entry, size_t *length);
void builtin(char *arguments[]);
void separate_and_builtin(int num_args, char *args[]);
char *replace_env(char *pointer, char *processed_output);
void custom_unsetenv_handling(char **arguments);

#endif
