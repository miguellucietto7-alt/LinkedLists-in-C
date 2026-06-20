# LinkedLists-in-C
Attempt to create linked lists in C with the objective to improve logic and learn macros in C

you can create your LinkedList with the command 'DEFINE_LIST(type, name)'
with this command you create a typedef of a linked list of the 'type' (int, float, char, ...) and the name##List
Example:
  DEFINE_LIST(int, Int);
  printf("size of the created list type: %zu\n", sizeof(IntList));
  output: size of the created list type: 8

you can use some functions that are created with the DEFINE macro like find, popTail and popHead, new, push and free.

the functions are the name of the list + the function, ex: IntList_new(); // returns a initialized List of the type defined

