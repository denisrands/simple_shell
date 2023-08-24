#include "shell.h"

/**
* _myhistory – code that displays list history, one command by line, followed
*     with line numbers, starting at 0.
* @info: Struct contains potential arguments. Used to maintain
*        constant function prototype.
*  Return: Always 0
*/
int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}

/**
* unset_alias - sets alias to string
* @info: parameter struct
* @str: the string alias
*
* Return: Always 0 on success, 1 on error
*/
int unset_alias(info_t *info, char *str)
{
char *i, j;
int ret;

i = _strchr(str, '=');
if (!i)
return (1);
j = *i;
*i = 0;
ret = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*i = j;
return (ret);
}

/**
* set_alias - sets alias to string
* @info: parameter struct
* @str: the string alias
*
* Return: Always 0 on success, 1 on error
*/
int set_alias(info_t *info, char *str)
{
char *i;

i = _strchr(str, '=');
if (!i)
return (1);
if (!*++i)
return (unset_alias(info, str));

unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
* print_alias - prints an alias string
* @node: the alias node
*
* Return: Always 0 on success, 1 on error
*/
int print_alias(list_t *node)
{
char *i = NULL, *a = NULL;

if (node)
{
i = _strchr(node->str, '=');
for (a = node->str; a <= i; a++)
_putchar(*a);
_putchar('\'');
_puts(i + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
* _myalias - mimics the alias builtin (man alias)
* @info: Structure containing potential arguments. Used to maintain
*          constant function prototype.
*  Return: Always 0
*/
int _myalias(info_t *info)
{
int a = 0;
char *i = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (a = 1; info->argv[a]; a++)
{
i = _strchr(info->argv[a], '=');
if (i)
set_alias(info, info->argv[a]);
else
print_alias(node_starts_with(info->alias, info->argv[a], '='));
}

return (0);
}
