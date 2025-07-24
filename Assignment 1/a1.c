/* Outline:
    Find a way to implement structures representing the players info (name,
   salary, season) Implement a function to read sixers.csv and make a linked
   list of the players Q1: Most seasons Q2: Highest cumulative salary Q3:
   Highest salary in season Main function prints all of the questions
*/
/* stdlib.h
1	double atof(const char *str)
Converts the string pointed to, by the argument str to a floating-point number
(type double).

2	int atoi(const char *str)
Converts the string pointed to, by the argument str to an integer (type int).

3	long int atol(const char *str)
Converts the string pointed to, by the argument str to a long integer (type long
int).

4	double strtod(const char *str, char **endptr)
Converts the string pointed to, by the argument str to a floating-point number
(type double).

5	long int strtol(const char *str, char **endptr, int base)
Converts the string pointed to, by the argument str to a long integer (type long
int).

6	unsigned long int strtoul(const char *str, char **endptr, int base)
Converts the string pointed to, by the argument str to an unsigned long integer
(type unsigned long int).

7	void *calloc(size_t nitems, size_t size)
Allocates the requested memory and returns a pointer to it.

8	void free(void *ptr
Deallocates the memory previously allocated by a call to calloc, malloc, or
realloc.

9	void *malloc(size_t size)
Allocates the requested memory and returns a pointer to it.

10	void *realloc(void *ptr, size_t size)
Attempts to resize the memory block pointed to by ptr that was previously
allocated with a call to malloc or calloc.

11	void abort(void)
Causes an abnormal program termination.

12	int atexit(void (*func)(void))
Causes the specified function func to be called when the program terminates
normally.

13	void exit(int status)
Causes the program to terminate normally.

14	char *getenv(const char *name)
Searches for the environment string pointed to by name and returns the
associated value to the string.

15	int system(const char *string)
The command specified by string is passed to the host environment to be executed
by the command processor.

16	void *bsearch(const void *key, const void *base, size_t nitems, size_t
size, int (*compar)(const void *, const void *)) Performs a binary search.

17	void qsort(void *base, size_t nitems, size_t size, int (*compar)(const
void *, const void*)) Sorts an array.

18	int abs(int x)
Returns the absolute value of x.

19	div_t div(int numer, int denom)
Divides numer (numerator) by denom (denominator).

20	long int labs(long int x)
Returns the absolute value of x.

21	ldiv_t ldiv(long int numer, long int denom)
Divides numer (numerator) by denom (denominator).

22	int rand(void)
Returns a pseudo-random number in the range of 0 to RAND_MAX.

23	void srand(unsigned int seed)
This function seeds the random number generator used by the function rand.

24	int mblen(const char *str, size_t n)
Returns the length of a multibyte character pointed to by the argument str.

25	size_t mbstowcs(schar_t *pwcs, const char *str, size_t n)
Converts the string of multibyte characters pointed to by the argument str to
the array pointed to by pwcs.

26	int mbtowc(whcar_t *pwc, const char *str, size_t n)
Examines the multibyte character pointed to by the argument str.

27	size_t wcstombs(char *str, const wchar_t *pwcs, size_t n)
Converts the codes stored in the array pwcs to multibyte characters and stores
them in the string str.

28	int wctomb(char *str, wchar_t wchar)
Examines the code which corresponds to a multibyte character given by the
argument wchar.
*/

/* string.h
1	void *memchr(const void *str, int c, size_t n)
Searches for the first occurrence of the character c (an unsigned char) in the
first n bytes of the string pointed to, by the argument str.

2	int memcmp(const void *str1, const void *str2, size_t n)
Compares the first n bytes of str1 and str2.

3	void *memcpy(void *dest, const void *src, size_t n)
Copies n characters from src to dest.

4	void *memmove(void *dest, const void *src, size_t n)
Another function to copy n characters from str2 to str1.

5	void *memset(void *str, int c, size_t n)
Copies the character c (an unsigned char) to the first n characters of the
string pointed to, by the argument str.

6	char *strcat(char *dest, const char *src)
Appends the string pointed to, by src to the end of the string pointed to by
dest.

7	char *strncat(char *dest, const char *src, size_t n)
Appends the string pointed to, by src to the end of the string pointed to, by
dest up to n characters long.

8	char *strchr(const char *str, int c)
Searches for the first occurrence of the character c (an unsigned char) in the
string pointed to, by the argument str.

9	int strcmp(const char *str1, const char *str2)
Compares the string pointed to, by str1 to the string pointed to by str2.

10	int strncmp(const char *str1, const char *str2, size_t n)
Compares at most the first n bytes of str1 and str2.

11	int strcoll(const char *str1, const char *str2)
Compares string str1 to str2. The result is dependent on the LC_COLLATE setting
of the location.

12	char *strcpy(char *dest, const char *src)
Copies the string pointed to, by src to dest.

13	char *strncpy(char *dest, const char *src, size_t n)
Copies up to n characters from the string pointed to, by src to dest.

14	size_t strcspn(const char *str1, const char *str2)
Calculates the length of the initial segment of str1 which consists entirely of
characters not in str2.

15	char *strerror(int errnum)
Searches an internal array for the error number errnum and returns a pointer to
an error message string.

16	size_t strlen(const char *str)
Computes the length of the string str up to but not including the terminating
null character.

17	char *strpbrk(const char *str1, const char *str2)
Finds the first character in the string str1 that matches any character
specified in str2.

18	char *strrchr(const char *str, int c)
Searches for the last occurrence of the character c (an unsigned char) in the
string pointed to by the argument str.

19	size_t strspn(const char *str1, const char *str2)
Calculates the length of the initial segment of str1 which consists entirely of
characters in str2.

20	char *strstr(const char *haystack, const char *needle)
Finds the first occurrence of the entire string needle (not including the
terminating null character) which appears in the string haystack.

21	char *strtok(char *str, const char *delim)
Breaks string str into a series of tokens separated by delim.

22	size_t strxfrm(char *dest, const char *src, size_t n)
Transforms the first n characters of the string src into current locale and
places them in the string dest.
*/

/* strtok() function
char* getfield(char* line, int num) {
    char * token;
    int token_count = 1;

    get the first token from the line

    token = strtok(line, ",");

    walk through other tokens

    while (token != NULL) {
        if (num == token_count)
            return(token);
        token = strtok (NULL, ",");
        token_count ++;
    }
    return NULL;
} */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLAYER_NAME 100
#define LINE_LENGTH 256

/* Gives us a structure we can use for the player name, the salary, and the
 * season. */
typedef struct player {
  char name[PLAYER_NAME];
  int salary;
  int season;
} Player;

/* Gives us a structure with info and a pointer to use */
typedef struct info {
  Player info;
  struct info *n;
} Info;

void q1(Info *y);
void q2(Info *y);
void q3(Info *y);

Info *readfile(const char *filename);

Info *readfile(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Cannot open the file.\n");
    exit(1);
  }

  Info *head = NULL;
  char line_array[LINE_LENGTH];

  while (fgets(line_array, LINE_LENGTH, fp) != NULL) {
    line_array[strcspn(line_array, "\n")] = '\0';
    char *n = strtok(line_array, ",");

    Player p;
    strcpy(p.name, n);
    sscanf(strtok(NULL, ","), "%d", &p.season);
    sscanf(strtok(NULL, ","), "%d", &p.salary);

    Info *new_info = malloc(sizeof(Info));
    if (new_info == NULL) {
      exit(1);
    }
    new_info->info = p;
    new_info->n = NULL;

    if (head == NULL) {
      head = new_info;
    } else {
      Info *last_info = head;
      while (last_info->n != NULL) {
        last_info = last_info->n;
      }
      last_info->n = new_info;
    }
  }

  fclose(fp);
  return head;
}

void q1(Info *y) {
  int season_count;
  season_count = 0;
  char player_name[PLAYER_NAME] = "";

  Info *st = y;
  while (st != NULL) {
    int current_season_count = 1;
    Info *x = st->n;
    while (x != NULL) {
      if (strcmp(st->info.name, x->info.name) == 0) {
        current_season_count++;
      }
      x = x->n;
    }

    if (current_season_count > season_count) {
      season_count = current_season_count;
      strcpy(player_name, st->info.name);
    }

    st = st->n;
  }

  printf("Here is the player with the most seasons played: %s, %d\n",
         player_name, season_count);
}

void q2(Info *y) {
  int max_salary;
  max_salary = 0;
  char player_name[PLAYER_NAME] = "";

  Info *st = y;
  while (st != NULL) {
    if (st->info.salary > max_salary) {
      max_salary = st->info.salary;
      strcpy(player_name, st->info.name);
    }
    st = st->n;
  }

  printf("Here is the player with the highest salry %s, $%d\n", player_name,
         max_salary);
}

void q3(Info *y) {
  int highest_playerseasonsalary;
  highest_playerseasonsalary = 0;
  char player_name[PLAYER_NAME] = "";

  Info *st = y;
  while (st != NULL) {
    int seasonal_salary = st->info.salary;
    if (seasonal_salary > highest_playerseasonsalary) {
      highest_playerseasonsalary = seasonal_salary;
      strcpy(player_name, st->info.name);
    }
    st = st->n;
  }

  printf("Here is the player with the highest seasonal salary: %s, $%d\n",
         player_name, highest_playerseasonsalary);
}

int main() {
  char filename[] = "sixers.csv";

  Info *y = readfile(filename);
  q1(y);
  q2(y);
  q3(y);
}
