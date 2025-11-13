<h1 align="center">📜 Get Next Line</h1>

<p align="center">
  <b>File reading, one line at a time — memory-safe, efficient, and reusable</b><br>
  <i>By <a href="https://github.com/CristianBitca">Cristian Bitca</a> · 42 London</i>
</p>

<p align="center">
  <img src="assets/banner.png" alt="Get Next Line Banner" width="800">
</p>


<p align="center">
  <img src="https://img.shields.io/badge/language-C-blue.svg?style=for-the-badge" />
  <img src="https://img.shields.io/badge/build-passing-brightgreen.svg?style=for-the-badge" />
  <img src="https://img.shields.io/badge/norminette-passed-success.svg?style=for-the-badge" />
  <img src="https://img.shields.io/github/license/CristianBitca/get_next_line.svg?style=for-the-badge" />
</p>

---

## 🧩 Overview

**Get Next Line (GNL)** is a project from **42 School** designed to strengthen your understanding of file descriptors, static variables, and dynamic memory management in C.  
Its purpose is simple but essential: **read a file or standard input, one line at a time, without losing data between calls.**

---

## 🧠 Concept

Unlike `fgets()` or `getline()`, `get_next_line()` does not rely on standard buffered I/O.  
It manually manages reading, buffering, and concatenation to handle any file descriptor, whether it’s a text file, standard input, or even a network socket.

This project is a perfect exercise in:
- Efficient memory allocation and freeing  
- Handling multiple file descriptors simultaneously  
- Managing edge cases like EOF and newlines correctly  

---

## 🗂️ Project Structure

```
get_next_line/
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
└── Makefile
```

---

## ⚙️ Compilation

The provided **Makefile** compiles your project into an object or executable format depending on the test setup.

| Command | Description |
|----------|-------------|
| `make` | Compiles all source files |
| `make clean` | Removes object files |
| `make fclean` | Cleans everything including executables |
| `make re` | Rebuilds from scratch |

---

## 🧩 Function Breakdown

### 🔹 Main Function
`char *get_next_line(int fd);`  
Reads from file descriptor `fd` and returns the next line (including `\n` if present).  
Returns `NULL` at EOF or on error.

### 🔸 Helper Functions
- `ft_gnl_strjoin` – Concatenates two strings and frees the first one  
- `ft_gnl_strchr` – Locates a character in a string  
- `ft_gnl_strdup` – Duplicates a string into newly allocated memory  
- `ft_gnl_substr` – Extracts a substring from a given string  
- `ft_gnl_strlen` – Returns string length  
- `ft_gnl_calloc` – Allocates zero-initialized memory  

---

## 🧪 Example Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

Compile and run:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c && ./a.out
```

Output example:
```
Hello World!
This is the first line.
And here comes the second one.
```

---

## 🧠 Key Features

✅ Handles **any file descriptor**  
✅ Supports **multiple simultaneous descriptors** (bonus)  
✅ Returns **exactly one line per call**  
✅ **Memory-safe** — no leaks, no overreads  
✅ Fully **Norminette compliant**  

---

## 🧰 Typical Workflow

```bash
make         # Compile the project
./a.out      # Run your test program
make clean   # Clean object files
make fclean  # Clean everything
make re      # Rebuild from scratch
```

---

## 📎 Bonus Part (optional)

If you’re implementing the **bonus version**, your program should:
- Handle multiple file descriptors at once  
- Maintain independent buffers for each file descriptor  
- Still return only one line per call  

---

## 👤 Author

**Cristian Bitca**  
📍 42 London  
💻 GitHub: [@CristianBitca](https://github.com/CristianBitca)

---

<p align="center">
  <i>“A line at a time — precision, patience, and pointer mastery.”</i><br>
  🧠 Built with discipline, crafted for clarity.
</p>
