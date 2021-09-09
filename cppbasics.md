<!-- Output copied to clipboard! -->

<!-----
NEW: Check the "Suppress top comment" option to remove this info from the output.

Conversion time: 0.992 seconds.


Using this Markdown file:

1. Paste this output into your source file.
2. See the notes and action items below regarding this conversion run.
3. Check the rendered output (headings, lists, code blocks, tables) for proper
   formatting and use a linkchecker before you publish this page.

Conversion notes:

* Docs to Markdown version 1.0β29
* Tue Jun 29 2021 11:29:33 GMT-0700 (PDT)
* Source doc: CPP memory management
* Tables are currently converted to HTML tables.
----->



```
C++ programmers have control of the memory and lifecycle of every variable
```




1. Stack Space
*   Every variable has 
1. Type
2. Name 
3. Value
4. Memory address (through & operator)	
*   By default variables live in stack memory and contain an undefined value(unless initialized with a specific value (int val = 0;)
*   Stack memory is associated with the current function; thus the memory’s lifecycle is tied to that function
*   Stack memory starts from high addresses and grows down.

### Block Scope

*   Blocks of code, signified by { }, create an inner stack on top of the preexisting stack
*   Lifetime of stack variables inside the block is called scope of the variable
*   When the block ends, the inner stack si removed and the variables are deleted from memory
*   After the block ends, the outer variables who continue to have their scope exist outside this block


### Scope of variables in Loops

For/While loop



*   The variables declared inside the for loop declaration will have the scope only within the body of the for loop.
*   However if the variable is previously declared and is not redeclared inside the declaration of for loop, the scope of the outer variable extends even within the for loop

```
#include <iostream>
int main() {
  int x = -1;
  std::cout << "[Outside the loop] x is now (should be -1): " << x << std::endl;
 for (int x = 0; x <= 2; x++) {
   std::cout << "[Inside the loop] x is now: " << x << std::endl;
 }
  // The outer scope x is still -1

 std::cout << "[Outside the loop] x is now (should be -1): " << x << std::endl;
  
  // This version doesn't redeclare x, so it just inherits access to the
  // same x variable from the outer scope. This modifies the outer x directly!
 
 for (x = 0; x <= 2; x++) {
   std::cout << "[Inside the loop] x is now: " << x << std::endl;
 }
  // In the last iteration where the condition x<=2 was true, x had the value 2.
 // After that iteration, x was incremented one more time and became 3.
 // Then the condition was false and the loop body did not execute.
 // Afterwards, the outer scope x is still 3 because the loop modified it.
 
 std::cout << "[Outside the loop] x is now (should be 3): " << x << std::endl;
  return 0;
}
```
### Pointer:



*   Points to another variable of the same type
*   Hold the address of the specified variable.
*   Through dereferencing(*), a new value can be assigned to the variable to which the pointer is pointing.

e.g. 


```
Int num = 7;
Int *p = &num;
*p = 40;
std::cout<<num; 
//returns 40 instead of 7, since the value is reassigned using its pointer 
```




*   The pointer lifecycle is linked to the current function as well since the pointer is also stored in stack memory
USE REFERENCES WHEN YOU CAN AND POINTERS WHEN YOU HAVE TO





## HEAP MEMORY



*   Allows to allocate memory independent of Function’s Lifecycle.(Usually longer than the Function’s lifecycle
*   Heap memory starts with lower addresses and grows up(usually the starting addresses are smaller than Stack memory)
*   Cpp uses new operator to create heap memory
*   The new operator
1. Allocate memory for the data structure in the heap memory
2. Initialize the data structure
3. Return pointer to the start of data structure

```
int *num = new int;
int *num = new int[]
```


*   Here num is an integer pointer stored in the stack memory.
*   This pointer points to an address in the heap memory allocated via the new operator 
*   The memory allocated in the heap for a data structure is reclaimed using the delete operator.

```
delete num;
delete[] num;
```




### NULL POINTER:



*   When the delete operator is used the heap space is freed.
*   **However the pointer in stack memory pointing to the deallocated heap space still exists. **These pointers are called dangling pointers
*   Null-pointer is a pointer that points to memory  address 0x00 (represents a pointer to nowhere)
*   Address 0x00 is reserved and is never used by the system; will generate a segmentation fault  when accessed
*   Null pointer cannot be deleted.

```
delete num;
num = nullptr
```



### References

*   Alias to a memory location (reference)  
*   Declared as &&lt;variable_name>
*   Value stored is same as variable value

    		


```
int &y = num;
int &y = *x;
```



	


## Constructor



*   Cpp automatically provides an automatic default constructor with every class declaration; this initializes the member variables with their default value
*   Custom default constructor:

    Specifies the state of the object when it is instantiated

1. Is a member function with the same name as the class
2. Takes Zero parameters
3. Does not have a return type

	


```
Cube::Cube()
```




*   Custom Constructors:

    Custom default constructors with specific arguments


```
Cube::Cube(double length)
```


*   Copy constructor:

    Cpp automatically provides an automatic copy constructor with every class declaration; It copies the contents of all member variables

1. Is a custom constructor with exactly one argument
2. Argument is a constant reference of type class

```
Cube::Cube(const Cube &obj)
```

**Automatic copy constructor**:

Invoked in 3 cases



1. Passing an object as an argument (by value)

<table>
  <tr>
   <td>
<code>void <strong>foo</strong>(Cube obj) 
{ 
      
}</code>
   </td>
  </tr>
  <tr>
   <td><strong><code>int main() 
{  
   Cube c; 
   foo(c); // copy constructor is invoked 
} </code></strong>
   </td>
  </tr>
</table>




2. Returning an object from a function (by value)

<table>
  <tr>
   <td>
<code>Cube <strong>foo</strong>() 
{ 
    Cube c1; 
    <strong>return</strong> c1; // copy constructor is invoked 
}</code>
   </td>
  </tr>
  <tr>
   <td><strong><code>int main()
{  
   Cube c2; 
   c2 = foo(); // copy constructor is invoked again 
} </code></strong>
   </td>
  </tr>
  <tr>
   <td>
   </td>
  </tr>
</table>




3. Initializing a new object

<table>
  <tr>
   <td>
   </td>
  </tr>
  <tr>
   <td>
<strong><code>int main() 
{  
   Cube c1; 
   c2 = c1; // copy constructor is invoked</code></strong>
<code> 
} </code>
   </td>
  </tr>
</table>



#### NOTE:


Copy constructor is only invoked when the object is being constructed. In the following case** it is not invoked**


<table>
  <tr>
   <td>
   </td>
  </tr>
  <tr>
   <td><strong><code>int main() 
{  
   Cube c1,c2;   
// note  c2 is already constructed using default constructor 
   c2 = c1;  // copy constructor is not invoked 
} </code></strong>
   </td>
  </tr>
</table>



#### Assignment operator:


Cpp compiler provides an automatic assignment operator for every class; it copies the contents of all member variables


CUSTOM ASSIGNMENT operator:



*   Public member of the class
*   Has function name “**operator=”**
*   Has return value as the reference of the Class
*   Has only one argument which is the constant reference to the class’ type.
*   Always returns the **dereferenced value of the object pointer this**

```
Cube & Cube::operator=(const Cube &obj)
{
   return *this;
}
```

