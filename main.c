#include <stdio.h>
#include "stdlib.h"
#include "string.h"

typedef struct Person
{
    char *name;
    int age;
} person;

typedef enum
{
    RED, GREEN, BLUE
}color;


int main ()
{
  //TODO Strings:
  char *msg = "Hello World";
//  msg[0] = 'M'; // run-time error, string literal is saved in read-only data
  // segment - Can't change (notice: msg is in stack)
  const char *safe_msg = "Hello World"; // preferred
  safe_msg = "Hello Again"; // possible

  char msg_array[] = "Hello World";
  printf ("%lu\n", sizeof (msg_array)); // 12- including the null char
  msg_array[0] = 'M'; // possible- string literal is saved in read-only data
  // segment, but msg is stored in stack

  printf ("The length of msg is: %lu\n", strlen (msg));
  char *copy_str = malloc (strlen (msg) + 1); // include null char
  if (copy_str == NULL)
  {
    return EXIT_FAILURE;
  }
  strcpy (copy_str, msg); // Works well
  printf ("%s\n", copy_str);

  strcpy (copy_str, msg_array); // Works well
  printf ("%s\n", copy_str);
  free (copy_str);


  //TODO Arrays:
  int columns = 8;
  int *arr[4]; // arr is an array of 4 pointers to int
  for (int i = 0; i < 4; i++)
  {
    arr[i] = malloc (columns * sizeof (int)); // pointer to int
    if (arr[i] == NULL)
    {
      for (int j = 0; j < i; j++)
      {
        free (arr[j]);
      }
      return EXIT_FAILURE;
    }
  }
  for (int i = 0; i < 4; i++)
  {
    free (arr[i]);
  }

  int (*arr1)[columns] = malloc (4 * 8 * sizeof (int)); // arr1 is a pointer to
  // an array of 8 ints
  if (arr1 == NULL)
  {
    return EXIT_FAILURE;
  }
  free (arr1);


  //TODO Structs
  person p1 = {"Bar", 19};
  person p2 = p1;
  p1.age = 20;
  p1.name = "Or";
  printf ("The name of p1 is: %s\n", p1.name); // changed
  printf ("The age of p1 is: %d\n", p1.age); // changed
  printf ("The name of p2 is: %s\n", p2.name); // not changed
  printf ("The age of p2 is: %d\n", p2.age); // not changed

  person *p_arr = malloc (2 * sizeof (person));
  if (p_arr == NULL)
  {
    return EXIT_FAILURE;
  }
  p_arr[0] = p1;
  p_arr[1] = p2;
  for (int i = 0; i < 2; i++)
  {
    printf ("The name of the person %d is: %s\n", i, p_arr[i].name);
  }
  free (p_arr);


  //TODO GenericProgramming
  int *int_ptr = malloc(sizeof (int));
  if (int_ptr == NULL)
  {
    return EXIT_FAILURE;
  }
  double *double_ptr = malloc(sizeof(double));
  if (double_ptr == NULL)
  {
    free(int_ptr);
    return EXIT_FAILURE;
  }
  char *char_ptr = malloc (sizeof (char));
  if (char_ptr == NULL)
  {
    free(int_ptr);
    free(double_ptr);
    return EXIT_FAILURE;
  }
  printf ("The size of int_ptr is %lu\n", sizeof (int_ptr));
  printf ("The size of double_ptr is %lu\n", sizeof (double_ptr));
  printf ("The size of char_ptr is %lu\n", sizeof (char_ptr));

  int num = 5;
  *int_ptr = num;
  char *converted_int = (char*) int_ptr;
  printf("Content of converted_int (format is %%d) is: %d\n",
         *converted_int); // prints 5
  printf("Content of converted_int (format is %%c) is: %c \n", *converted_int);
  int x = 4;
  void *void_ptr = &x;
  char *tmp = void_ptr;
  printf ("%d\n", *tmp); // 4


  //TODO Enum
  color c1 = GREEN;
  printf ("The num of the color is: %d\n", c1); // prints 1

  enum week{Sun, Mon, Tue} day; // possible to define that way, day is like c1
  day = Tue;
  printf ("Printing day... %d\n", day); // prints 2
  enum week d = Mon;
  printf ("Printing d... %d\n", d); // prints 1
  switch (d)
  {
    case Sun:
      printf("Not working\n");
      break;

    case Mon:
      printf ("Working\n");
      break;

    case Tue:
      printf("Not working\n");
      break;

    default:
      printf ("Default\n");
      break;
  }

  //TODO ASCII stuff:
  int d1 = 'a';
  printf ("The ASCII of %c is %d\n", d1, d1); // The ASCII of a is 97
  char c_a = 'a';
  printf("The ASCII of %c is %d\n", c_a, c_a); // The ASCII of a is 97
  int d2 = 97;
  printf ("The ASCII of %c is %d\n", d2, d2); // The ASCII of a is 97
  char c_a_1 = 97;
  printf ("The ASCII of %c is %d\n", c_a_1, c_a_1); // The ASCII of a is 97


  return 0;
}