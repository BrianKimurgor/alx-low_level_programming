# Hash Tables in C

This project implements a hash table data structure in C as part of the 0x1A C - Hash tables curriculum. Hash tables are essential data structures in computer science used for efficient key-value storage and retrieval. The project focuses on various aspects of hash tables, including their implementation, usage, and collision handling.

## Table of Contents

- [Resources](#resources)
- [Learning Objectives](#learning-objectives)
- [Requirements](#requirements)
- [Data Structures](#data-structures)
- [Tasks](#tasks)
- [Advanced Task](#advanced-task)

## Resources

To successfully complete this project, you can refer to the following resources:

- [What is a HashTable Data Structure - Introduction to Hash Tables, Part 0](https://www.youtube.com/watch?v=MfhjkfocRR0)
- [Hash function](https://en.wikipedia.org/wiki/Hash_function)
- [Hash table](https://en.wikipedia.org/wiki/Hash_table)
- [All about hash tables](https://www.cs.cmu.edu/~adamchik/15-121/lectures/Hashing/hashing.html)
- [Why hash tables and not arrays](https://stackoverflow.com/questions/730620/how-does-a-hash-table-work)
- [PHP Internals Book: HashTable](https://www.phpinternalsbook.com/hashtable/basics.html)

## Learning Objectives

By the end of this project, you should be able to explain the following concepts without using external resources:

**General**
- What is a hash function
- What makes a good hash function
- What is a hash table, how do they work, and how to use them
- What is a collision and what are the main ways of dealing with collisions in the context of a hash table
- What are the advantages and drawbacks of using hash tables
- What are the most common use cases of hash tables

**Copyright - Plagiarism**
- You should understand that plagiarism is strictly forbidden and will result in removal from the program. You must come up with solutions to the tasks yourself.

## Requirements

**General**
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project, is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You are not allowed to use global variables
- No more than 5 functions per file
- You are allowed to use the C standard library
- The prototypes of all your functions should be included in your header file called hash_tables.h
- Don't forget to push your header file
- All your header files should be include guarded

## Data Structures

Please use these data structures for this project:

```c
/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
     char *key;
     char *value;
     struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
     unsigned long int size;
     hash_node_t **array;
} hash_table_t;
Tasks
0. Create a Hash Table
Write a function that creates a hash table.

Prototype:

c
Copy code
hash_table_t *hash_table_create(unsigned long int size);
Parameters:

size: The size of the array
Returns:

A pointer to the newly created hash table
If something went wrong, your function should return NULL
1. Implement a Hash Function - djb2
Write a hash function implementing the djb2 algorithm.

Prototype:

c
Copy code
unsigned long int hash_djb2(const unsigned char *str);
Parameters:

str: The key, a string
Returns:

The hash value calculated using the djb2 algorithm
2. Get the Index of a Key
Write a function that gives you the index of a key.

Prototype:

c
Copy code
unsigned long int key_index(const unsigned char *key, unsigned long int size);
Parameters:

key: The key
size: The size of the array of the hash table
Returns:

The index at which the key/value pair should be stored in the array of the hash table
3. Add an Element to the Hash Table
Write a function that adds an element to the hash table.

Prototype:

c
Copy code
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
Parameters:

ht: The hash table you want to add or update the key/value to
key: The key (cannot be an empty string)
value: The value associated with the key (can be an empty string)
Returns:

1 if it succeeded, 0 otherwise
In case of collision, add the new node at the beginning of the list
4. Retrieve a Value Associated with a Key
Write a function that retrieves a value associated with a key.

Prototype:

c
Copy code
char *hash_table_get(const hash_table_t *ht, const char *key);
Parameters:

ht: The hash table you want to look into
key: The key you are looking for
Returns:

The value associated with the element, or NULL if the key couldn't be found
5. Print a Hash Table
Write a function that prints a hash table.

Prototype:

c
Copy code
void hash_table_print(const hash_table_t *ht);
Parameters:

ht: The hash table
Format:

Print the key/value pairs in the order that they appear in the array of the hash table
Order: array, list
Format: see example
If ht is NULL, don't print anything
6. Delete a Hash Table
Write a function that deletes a hash table.

Prototype:

c
Copy code
void hash_table_delete(hash_table_t *ht);
Parameters:

ht: The hash table
7. Implement a Sorted Hash Table (Advanced Task)
In this advanced task, you will implement a sorted hash table similar to the ordered hash tables used in PHP. The sorted hash table is ordered based on the ASCII values of the keys.

Data Structures:

c
Copy code
/**
 * struct shash_node_s - Node of a sorted hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 * @sprev: A pointer to the previous element of the sorted linked list
 * @snext: A pointer to the next element of the sorted linked list
 */
typedef struct shash_node_s
{
     char *key;
     char *value;
     struct shash_node_s *next;
     struct shash_node_s *sprev;
     struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 * @shead: A pointer to the first element of the sorted linked list
 * @stail: A pointer to the last element of the sorted linked list
 */
typedef struct shash_table_s
{
     unsigned long int size;
     shash_node_t **array;
     shash_node_t *shead;
     shash_node_t *stail;
} shash_table_t;
You will also need to implement the following functions:

Create a Sorted Hash Table:

c
Copy code
shash_table_t *shash_table_create(unsigned long int size);
Set a Key/Value Pair in the Sorted Hash Table:

c
Copy code
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
Get the Value Associated with a Key in the Sorted Hash Table:

c
Copy code
char *shash_table_get(const shash_table_t *ht, const char *key);
Print the Sorted Hash Table:

c
Copy code
void shash_table_print(const shash_table_t *ht);
Print the Sorted Hash Table in Reverse Order:

c
Copy code
void shash_table_print_rev(const shash_table_t *ht);
Delete the Sorted Hash Table:

c
Copy code
void shash_table_delete(shash_table_t *ht);
You are allowed to have more than 5 functions in your file.

Advanced Task (Task 7)
Implementing a Sorted Hash Table
In this advanced task, you will implement a sorted hash table similar to the ordered hash tables used in PHP. The sorted hash table is ordered based on the ASCII values of the keys.

To implement the sorted hash table, you will need to create new data structures (shash_node_t and shash_table_t) and modify the existing functions to work with the new data structures. Please see the task description above for details on the data structures and function prototypes.

You can run the provided test program 100-main.c to verify the functionality of your sorted hash table implementation.

bash
Copy code
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 100-main.c 100-sorted_hash_table.c 1-djb2.c 2-key_index.c -o sht
./sht
Please make sure to thoroughly test your implementation to ensure correctness and memory leak prevention.

Remember that this is an advanced task, and it may require significant modifications to your code. Take your time to understand the new data structures and how they should work together to implement the sorted hash table.
