*This project has been created as part of the 42 curriculum by ebin-ahm.*

# get_next_line

---

## Description

Text stored in files is a continuous stream of bytes, and low-level system calls such as read() retrieve this data without any notion of human-readable lines.

get_next_line  provides a higher-level abstraction by grouping these bytes into logical lines, using the newline character (\n) as a delimiter. This allows programs to process file contents line by line, in the way the text was originally intended to be read.


### Purpose

- To read and return a single line of text from a file descriptor without prior knowledge of the line's length.

### Concept

Static Variable - a variable that maintains its value and state (data persistence)throughout the entire execution of a program.

get_next_line() uses one static pointer (commonly named stash) that persists between calls.

- It stores any bytes that were read but not yet returned as part of a line.

- This prevents losing partial lines when a newline does not appear within a single read() call.
 

### Structure of get_next_line

**get_next_line.h** – Declares all public function prototypes, macros (such as BUFFER_SIZE), and includes the required standard library headers used throughout the project.

**get_next_line.c** – Contains the core implementation of get_next_line().

**get_next_line_utils.c** – Includes utility functions used by the main algorithm, such as:
- string and memory manipulation helpers,
- buffer concatenation and trimming,
- newline detection and safe memory handling.

---

## Instructions

### Compilation
To compile the code with buffer size of 42, run:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```

## Algorithm

get_next_line() returns one line per call by storing unread bytes in a persistent stash.

1. Validate fd and BUFFER_SIZE.

2. While the stash does not contain '\n' and read() returns bytes:
	- read up to BUFFER_SIZE bytes into a temporary buffer,
	- append those bytes to the stash.

3. Extract the next line from the stash:

	- if a newline exists, return up to and including '\n',
	- otherwise, if EOF and stash has data, return the remaining data.

4. Update the stash by removing the returned part.

5. Return the allocated line (caller frees it).

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