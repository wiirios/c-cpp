// #include <stdio.h>

// int main() {
//
//     int r = 0;    
//     int bar = do_thing(r, 20);
//     if (err()) goto error;
//     ...
//     error:
//         printf(some shit);  
//         free(bar);
//         return 0;
//
//     return 0;
// }

/*
Albeit deprecated by some people, the equivalent of the goto statement is
used frequently by compilers in form of the unconditional jump instruction.

The goto statement comes in handy when a function exits from multiple
locations and some common work such as cleanup has to be done.  If there is no
cleanup needed then just return directly.

Choose label names which say what the goto does or why the goto exists.  An
example of a good name could be ``out_free_buffer:`` if the goto frees ``buffer``.
Avoid using GW-BASIC names like ``err1:`` and ``err2:``, as you would have to
renumber them if you ever add or remove exit paths, and they make correctness
difficult to verify anyway.

The rationale for using gotos is:

- unconditional statements are easier to understand and follow
- nesting is reduced
- errors by not updating individual exit points when making
  modifications are prevented
- saves the compiler work to optimize redundant code away ;)

.. code-block:: c

	int fun(int a)
	{
		int result = 0;
		char *buffer;

		buffer = kmalloc(SIZE, GFP_KERNEL);
		if (!buffer)
			return -ENOMEM;

		if (condition1) {
			while (loop1) {
				...
			}
			result = 1;
			goto out_free_buffer;
		}
		...
	out_free_buffer:
		kfree(buffer);
		return result;
	}

A common type of bug to be aware of is ``one err bugs`` which look like this:

.. code-block:: c

	err:
		kfree(foo->bar);
		kfree(foo);
		return ret;

The bug in this code is that on some exit paths ``foo`` is NULL.  Normally the
fix for this is to split it up into two error labels ``err_free_bar:`` and
``err_free_foo:``:

.. code-block:: c

	err_free_bar:
		kfree(foo->bar);
	err_free_foo:
		kfree(foo);
		return ret;

Ideally you should simulate errors to test all exit paths.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int main() {
	char username[MAX];
	char password[MAX];

    printf("your username");
	scanf("19%s", username);

	printf("your password");
	scanf("19%s". password);

	if (strcmp(username, "teste") != 0) goto err_username;

	if (strcmp(password, "teste") != 0) goto err_password;

	printf("teste login");

	err_username:
		printf("wrong username");
		return 1;

	err_password:
		printf("wrong password");
		return 1;

    return 0;
}
