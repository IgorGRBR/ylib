# ylib
ylib is an alternative to libft.

Libft is a library that is used in 42 School and developed by its students. ylib aims to be a simple alternative that provides a variety of useful types and functions to simplify the development of 42 School projects. ylib is compatible with 42 School Norm v3*.

*My definition of compatible is that the norminette doesn't complain about the code :).

# Modules
ylib is split into several modules (.h files), each one of them can be used on its own, but may depend on other modules (i.e. almost every module depends on ytypes.h). To include every module, use:
`#import <ylib.h>`.
To avoid potential name clashes, it is recomended to only include ytypes.h in other header files.

## ylib.h
This header includes everything from the library.

## ydefines.h
This header currently only contains an alternative definition for NULL.

## ytypes.h
This header contains all types declarations of ylib.

## ychar.h
This header contains various character related functions.

## ycmem.h
This header contains functions for performing raw memory operations.

## ycstr.h
This header contains functions for manipulating character arrays (cstrings).

## yio.h
This header contains functions for reading/writing cstrings to file descriptors.

## ylist.h
This header contains various functions for managing untyped, dynamically-sized lists of pointers.

## ymath.h
This header contains various math functions that I've found to be useful in situations where the use of math.h was prohibited/wasn't enough.

## yprint.h
This header contains yprintf - an alternative to printf for cases when printf is not allowed.

## yprint_format.h
This header is for internal use only. Do not include it in your projects. It contains helper functions for yprintf formatting.

## ystring.h
This header contains functions for manipulating strings. Strings are an alternative to cstrings that contain both cstring itself and its length. They were developed for a scenario where the support of various UTF encodings was necessary, however I haven't encountered such projects yet.

## yvec2.h
This header contains operations for 2D vectors of ints and doubles.
