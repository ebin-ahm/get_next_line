*This project has been created as part of the 42 curriculum by ebin-ahm.*

# get_next_line

---

## Description

Text files are stored as a continuous stream of bytes. Low-level system calls such as read() return raw bytes without any built-in notion of lines or text structure.

get_next_line() provides a higher-level abstraction by grouping this stream into logical lines using the newline character (\n) as a delimiter.
This allows a program to read and process file contents line by line, in the same way the text is intended to be consumed by a user.


### Purpose

- Read and return exactly one line from a file descriptor per call.

- Handle lines of unknown and arbitrary length.

- Preserve unread data between calls without losing partial lines.

### Concept

A static variable is a variable that preserves its value across multiple function calls during the lifetime of the program.

In get_next_line(), a single static pointer (commonly named stash) is used to store leftover bytes between calls.

This persistent buffer is required because:

- a single call to read() may stop in the middle of a line, and

- a line may span across multiple read() calls.

The stash:

- accumulates newly read data,

- keeps incomplete lines for the next call, and

- ensures no bytes are lost between successive invocations of get_next_line().
 

### Structure of get_next_line

* get_next_line.h
Declares the public function prototype, defines macros (such as BUFFER_SIZE), and includes the required standard headers.

* get_next_line.c
Contains the main implementation of get_next_line() and the core reading and extraction logic.

* get_next_line_utils.c
Provides helper functions used by the main algorithm, including:

- string and memory manipulation,
- dynamic buffer concatenation,
- newline detection,
- safe allocation and cleanup routines.

---

## Instructions

### Compilation
To compile the code with buffer size of 42, run:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```

## Algorithm

get_next_line() returns one line per call by storing unread bytes in a persistent stash.

1. Validate inputs

- Check that the file descriptor is valid.

- Ensure BUFFER_SIZE is greater than 0.

2. Read until a full line is available

- While the stash does not contain a newline character ('\n') and read() returns data:

- read up to BUFFER_SIZE bytes into a temporary buffer,

- append the buffer to the stash.

3. Extract the next line

- If a newline exists in the stash, extract and return the substring up to and including '\n'.

- Otherwise, if end-of-file is reached and the stash still contains data, return the remaining bytes as the last line.

4. Update the stash

- Remove the returned portion from the stash.

- Keep only the leftover bytes for the next call.

5. Return

- Return the newly allocated line.

- The caller is responsible for freeing the returned memory.

## Resources

### Classic References
- man pages for utility functions
- 42 Norminette rules
- Get Next Line pdf version: 14.2

### AI-Assisted Learning
AI (ChatGPT) was used for:
1. Clarifying concepts such as pointers, memory operations, and linked list operations  
2. Explaining algorithms, edge cases, and debugging  

All code was manually written and verified by ebin-ahm.
