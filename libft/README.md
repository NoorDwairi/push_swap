*This activity has been created as part of the 42 curriculum by dlababne.*

# Libft

## Description

This is a C library created as part of the 42 Libft project.

The goal of this project is to recreate several functions from the C standard library and to build additional utility functions for working with strings, memory, file descriptors, and linked lists.

The project is divided into three parts:

- **Part 1:** Recreation of standard C library functions.
- **Part 2:** Additional utility functions for strings, memory, conversions, and file descriptors.
- **Part 3:** Functions for creating and manipulating linked lists.

The project also includes a Makefile used to compile the source files into a static library called `libft.a`.

---

## Instructions

The project includes a Makefile that automates the compilation of the library and simplifies the build process.

### Compile the library

```bash
make
```

This compiles the source files into object files and creates `libft.a`.

### Remove object files

```bash
make clean
```

Removes the `.o` object files while keeping the library.

### Remove object files and the library

```bash
make fclean
```

Removes both the object files and `libft.a`.

### Rebuild the library

```bash
make re
```

Equivalent to performing a full clean followed by a new compilation.

---

# Resources

The following resources were used during the project:

- 42 Libft subject PDF
- `man` pages
- GeeksforGeeks
- W3Schools
- YouTube videos about C programming, linked lists, pointers, memory management, and Makefiles
- Tripouille's `libftTester`
- Norminette
- Google AI
- ChatGPT
- Gemini

---

# AI Usage

AI tools were used as **learning, debugging, and explanation assistants** throughout the project.

They were mainly used to:

- Understand C concepts such as pointers, pointer-to-pointer variables, casting, `size_t`, `void *`, and function pointers.
- Understand memory allocation, `malloc`, `free`, `calloc`, and memory-related edge cases.
- Understand how linked lists work and how nodes are connected.
- Understand the difference between modifying an existing list and creating a new list.
- Explain compiler and linker errors encountered during development.
- Help analyze failing tester cases and understand why a function produced an incorrect result.
- Check possible edge cases and compare the implementation with the requirements of the 42 subject.
- Understand Makefile rules such as `all`, `clean`, `fclean`, and `re`.
- Understand Norminette requirements and reorganize functions when necessary.
- Help explain code line by line and trace what happens in memory.
- Help create small test `main` functions for testing individual functions.
- Review code and point out possible problems or missing cases.

AI was **not used as a substitute for understanding the project**. The code was studied, tested, modified, and debugged manually. AI explanations were used to help understand the reasoning behind the implementation and to investigate problems encountered during testing.

---

# Library

## Part 1 - Libc Functions

Part 1 recreates functions from the C standard library for working with characters, strings, and memory.

### Character Functions

#### `ft_isalpha`

Checks whether a character is an alphabetic character (`A-Z` or `a-z`).

#### `ft_isdigit`

Checks whether a character is a decimal digit (`0-9`).

#### `ft_isalnum`

Checks whether a character is either alphabetic or a digit.

#### `ft_isascii`

Checks whether a value belongs to the ASCII character range (`0-127`).

#### `ft_isprint`

Checks whether a character is printable, including space.

#### `ft_toupper`

Converts a lowercase alphabetic character to uppercase.

#### `ft_tolower`

Converts an uppercase alphabetic character to lowercase.

---

### String Functions

#### `ft_strlen`

Calculates the length of a null-terminated string, without counting the terminating `'\0'`.

#### `ft_strchr`

Searches for the first occurrence of a character in a string and returns a pointer to it.

#### `ft_strrchr`

Searches for the last occurrence of a character in a string and returns a pointer to it.

#### `ft_strncmp`

Compares up to `n` characters of two strings.

#### `ft_strnstr`

Searches for a smaller string inside another string, limited to a specified length.

---

### Memory Functions

#### `ft_memset`

Fills a block of memory with a specified byte value.

#### `ft_bzero`

Sets a specified number of bytes in memory to zero.

#### `ft_memcpy`

Copies a specified number of bytes from one memory area to another.

#### `ft_memmove`

Copies bytes between memory areas while correctly handling overlapping memory regions.

#### `ft_memchr`

Searches a block of memory for the first occurrence of a byte.

#### `ft_memcmp`

Compares two blocks of memory byte by byte.

---

### String Copy and Concatenation

#### `ft_strlcpy`

Copies a string into a destination buffer while respecting the destination buffer size and ensuring null termination when possible.

#### `ft_strlcat`

Appends one string to another while respecting the destination buffer size.

---

### Conversion and Allocation

#### `ft_atoi`

Converts the beginning of a string representing an integer into an `int`.

#### `ft_calloc`

Allocates memory for multiple elements and initializes all allocated bytes to zero.

#### `ft_strdup`

Allocates memory and creates a duplicate of an existing string.

---

# Part 2 - Additional Functions

Part 2 contains additional functions for string manipulation, memory allocation, integer conversion, function pointers, and writing data to file descriptors.

## String Manipulation

### `ft_substr`

Creates and returns a new substring starting at a specified position with a maximum length.

### `ft_strjoin`

Allocates a new string containing two strings joined together.

### `ft_strtrim`

Creates a new string with specified characters removed from the beginning and end.

### `ft_split`

Splits a string into an array of strings using a specified delimiter character.

---

## Conversion

### `ft_itoa`

Converts an integer into a newly allocated null-terminated string.

---

## Function Pointer Functions

### `ft_strmapi`

Applies a function to every character of a string and returns a new string containing the transformed characters.

### `ft_striteri`

Applies a function to every character of a string while allowing the function to modify the original string.

---

## File Descriptor Functions

### `ft_putchar_fd`

Writes a single character to a specified file descriptor.

### `ft_putstr_fd`

Writes a string to a specified file descriptor.

### `ft_putendl_fd`

Writes a string followed by a newline to a specified file descriptor.

### `ft_putnbr_fd`

Writes an integer to a specified file descriptor.

---

# Part 3 - Linked Lists

Part 3 introduces linked lists and provides functions for creating, traversing, modifying, and deleting linked-list nodes.

A linked list is made of nodes. Each node contains:

- `content` — the data stored in the node.
- `next` — a pointer to the next node.

The list ends when `next` is `NULL`.

---

### `ft_lstnew`

Creates and returns a new linked-list node containing the given content.

The new node initially has `next` set to `NULL`.

### `ft_lstadd_front`

Adds a new node to the beginning of a linked list.

The new node becomes the first node of the list.

### `ft_lstsize`

Counts and returns the number of nodes in a linked list.

### `ft_lstlast`

Finds and returns the last node of a linked list.

### `ft_lstadd_back`

Adds a new node to the end of a linked list.

### `ft_lstdelone`

Deletes one node by calling the provided deletion function on its content and then freeing the node itself.

### `ft_lstclear`

Deletes every node in a linked list, using the provided deletion function for each node's content.

### `ft_lstiter`

Iterates through a linked list and applies a function to the content of every node.

### `ft_lstmap`

Creates a new linked list by applying a function to every element of an existing list.

The original list is not modified.

If allocation fails while creating the new list, the already-created nodes are cleaned up.

---

# Compilation

The library can be compiled with:

```bash
make
```

After compilation, the static library will be:

```text
libft.a
```

It can then be linked with another C program, for example:

```bash
cc main.c -L. -lft
```

---

# Testing

The functions were tested individually using custom `main` programs and external testing tools.

Testing included:

- Normal inputs
- Empty strings
- Boundary values
- `NULL` cases where applicable
- Different buffer sizes
- Memory allocation failures where relevant
- Integer edge cases
- Linked-list edge cases
- Pointer and memory behavior
- Function-pointer behavior
- Compilation and linking
- Norminette checks

Tripouille's `libftTester` was also used to identify incorrect behavior and edge cases.

---

# Project Structure

The project contains:

```text
libft/
├── Makefile
├── libft.h
├── ft_isalpha.c
├── ft_isdigit.c
├── ft_isalnum.c
├── ...
├── ft_lstnew.c
├── ft_lstadd_front.c
├── ft_lstsize.c
├── ft_lstlast.c
├── ft_lstadd_back.c
├── ft_lstdelone.c
├── ft_lstclear.c
├── ft_lstiter.c
├── ft_lstmap.c
└── README.md
```

The source files are compiled into object files and then archived into:

```text
libft.a
```

---

# Learning Objectives

This project helped develop a better understanding of:

- C syntax and standard library functions
- Pointers and pointer arithmetic
- Pointer-to-pointer variables
- Dynamic memory allocation
- `malloc`, `calloc`, and `free`
- Strings and null termination
- Memory manipulation
- Type casting
- `void *`
- Function pointers
- Linked lists
- Memory ownership and cleanup
- Makefiles and static libraries
- Compilation and linking
- Debugging
- Testing and edge cases
- Norminette and 42 coding standards
