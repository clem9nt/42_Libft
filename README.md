<h1 align="center">
	LIBFT 42
</h1>

<h3 align="center">
	<a href="#Summary">Summary</a>
	<span> · </span>
	<a href="#Usage">Usage</a>
</h3>

##  Summary

First project of [42Paris](https://42.fr/) aims to create its own standard
library based on `libc` by creating certain existing and non-existing functions
from scratch.  This library is also intended to be used and enriched with the
functions of our choice throughout the curriculum.  

The code is written in accordance with 42 coding style and ***all the functions are documented with docstrings***.

> *"It will contain a lot of general purpose functions your programs will rely
> upon."* - [Subject](https://cdn.intra.42.fr/pdf/pdf/57361/en.subject.pdf)

I chose not to protect the functions from NULL pointers passed to them as a
parameter, indeed I prefer to let an explicit `SEGV` happen rather than obscure
the problem behind a `return (NULL);` making it more tedious to debug from a
superior layer of abstraction.

This choice is also observable in the `libc`.  For example `STRLEN(3)`
implementation from `<string.h>` will crash a program that tries to pass it a
`NULL` string instead of returning `NULL` as it would if it was protected.

Whole code is documented with docstrings (start from the header file).

##  Usage

Compile the library with a simple `make -j` then add `#include "libft.h"` to
your project and compile it with these additional flags:

    -I <path_to_libft_include_dir>
    -L <path_to_libft_dir>
    -l ft

***Makefile rules***

- `make` -- compiles get_next_line.
- `make clean` -- deletes object files.
- `make fclean` -- deletes object files and get_next_line.
- `make re` -- fclean + make.

- `make update` -- update the repo to its newer version.
- `make norm` -- check 42 coding style.
