# CS50 Week 4 : MEMORY

* Memory counts in __hexadecimal__ 0-9 a-f, where "f" is 15. In hexadecimal, we use powers of 16. So in hexadecimal, 255 if FF. OF is 10. 10 id 16. 
  * RGB uses hexadecimal digits
  * When using hexadecimal, everything is prefixed with OX. 
* When we assign a variable, it exists at a certain address in computer's memory. This address is called a __pointer__.
  * &n retrieves a pointer
  * *&n retrieves value at specific pointer
  * int *p = &n;  <- syntax to store pointer to int. 
* A string s is a pointer to the first char and is synonomous to char *. The computer knows to find the end of the string by the Null terminating character, byte of 0's. 
  * char *s = "Emma";
  * Still use %s in printf because it prints until terminating character.
* If you copy a string to another variable, you are copying the address. So if you make changes to that string, you'll change both variables. 
  * t = s <- same address
  * copy character to different addresses to prevent this. 
* char *t = malloc(strlen(s) + 1); <- memory allocation which uses string length + 1 for null termination. 

```
for (int i = 0, n = strlen(s); i <= n + 1; i++)
{
  //will only change t to upper because we've allocated a separate space in memory
  t[i] = s[i];
}

t[0] = toupper(t[0]) 
```
* Can also use strcpy(t, s)
* malloc will return the pointer of the first memory address.
* Free is a function that hands back memory. Programs can run out of memory so it's important to free the memory. 
* valgrind ./copy is a debugger that goes over memory. Put help50 in front to decode. 
* Buffer overflow -> you've gone beyond the byes of memory you allocated. 
* Memory leak means you're not freeing memory that you used. 
* When you pass variables as arguments, they are copied to the other functions, so you won't be able to impact the actual varialbes. 
* "Garbage collection" notices unused memory in your program and frees it. 
* Memory conceptually works in levels. Up top is (1) machine code which are all the compiled 0's and 1's. Next level is (2)globals (variables, other data), next is (3) heap, which expands downwards and includes memory allocation (malloc). Next is (4) stack, which expands upwards each time you call a function. 
* If you want to affect a local variable, you can pass pointers as arguments to affect the actual variables.

```
void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

//This swaps by the address rather than the value
swap(&x, &y);
```

## Get int without training wheels

```
  int x;
  printf("x: ");
  //pass to scanf the address of your variable
  //to put value in for you. 
  scanf("%i", &x);
  printf("X: %i", x);
```
## Get string without training wheels

```
//No memory allocated, so we get null
char *s = NULL;
printf("s: ");
scanf("%s", s);
printf("s: %s\n", s);

//hard code memory allocated
char s[5];
printf("s: ");
scanf("%s", s);
printf("s: %s\n", s);
```

## Work with Files
FILE * file = fopen("phonebook.csv", "a");
char *name = get_string("Name: ");
char *number = get_string("Numbers: ");

//Put data in the file in csv format
fprintf(file, "%s, %s\n", name, number);

```
int main(int argc, char *argv[])
{
if(argc != 2)
{
  return 1;
}

FILE * file = file(argv[1], "r");
if (file == NULL)
{
  return 1;
}

char bytes[3]
fread(byes, 3, 1, file)

//check if bytes are 0xff 0xd8 0xff (jpeg bytes)

if(bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
{
  printf("maybe");
} else
{
  printf("no");
}
}
```