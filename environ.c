#include "shell.h"

/**
* _myenv –code  prints the current environment
* @info: struct that contains the potential arguments. maintains
*          constant function prototype.
* Return: Always 0
*/
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
* _getenv – code that gets the value of an environ variable
* @info: Struct containing potential arguments. Used to maintain
* @name: env var name
*
* Return: the value
*/
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *j;

while (node)
{
j = starts_with(node->str, name);
if (j && *j)
return (j);
node = node->next;
}
return (NULL);
}

/**
* _mysetenv - Initialize a new environment variable,
*             or modify an existing one
* @info: Structure containing potential arguments. Used to maintain
*        constant function prototype.
*  Return: Always 0
*/
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
* _myunsetenv - Remove an environment variable
* @info: Structure containing potential arguments. Used to maintain
*        constant function prototype.
* Return: Always 0
*/
int _myunsetenv(info_t *info)
{
int p;

if (info->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
for (p = 1; p <= info->argc; p++)
_unsetenv(info, info->argv[p]);

return (0);
}

/**
* populate_env_list - populates env linked list
* @info: Structure containing potential arguments. Used to maintain
*          constant function prototype.
* Return: Always 0
*/
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t p;

for (p = 0; environ[p]; p++)
add_node_end(&node, environ[p], 0);
info->env = node;
return (0);
}
