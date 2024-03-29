I am Arina Sofiyeva. 
This is a group of assignments for "Introduction to Embedded Systems Software and Development Environments"
by University of Colorado Boulder.

<h2>The first week:</h2>
This is a simple programming assignment that prints statistics to the command line using a variety of c-programming operators and features.

To compile and run the project, use ``gcc -o stats.out stats.c -lm`` and ``./stats.out``.
Compile always with ``-lm`` flag to link the math library.

--------------------------------------------------------------------------
<h2>The second week:</h2>
Here I will create a build system using the GNU tools, GCC and GNU Make. 
This assignment will require me to compile multiple files, link them together and create a final output executable. 
Platforms to support: the host environment and the target embedded system MSP432. 
The host system will allow to simulate software on a host platform.
The host embedded system will use the native compiler, gcc. 
The target embedded system will use the cross compiler, arm-none-eabi-gcc.

Preprocessor, assembly, object, dependency, executable, and map output files are already generated.
Go to `assignment2/m2/src` and run `./c1m2.out`. There you'll see an output:
````
aXy72_L+R
````

In ``src`` directory run ``make build PLATFORM=HOST`` to see info about the system:
````
gcc  -DHOST  -I../include/common -o c1m2.out main.c memory.c
size c1m2.out
   text    data     bss     dec     hex filename
   2137     600      24    2761     ac9 c1m2.out
````
--------------------------------------------------------
<h2>The third week is not included here as it was an ordinary test.</h2>

----------------------------------------------------------
<h2>The fourth week:</h2>
I will reuse my earlier assignments and add some new functions that manipulate memory. 
I will test it on the host machine, but my code should compile for both the target platform and host platform.

Run ``make PLATFORM=HOST build`` and you'll see such output:
```
gcc  -DHOST -MMD -MF src/course1.d -MP -MT"src/course1.d src/course1.o" -c src/course1.c
gcc  -DHOST -MMD -MF src/data.d -MP -MT"src/data.d src/data.o" -c src/data.c
gcc  -DHOST -MMD -MF src/memory.d -MP -MT"src/memory.d src/memory.o" -c src/memory.c
gcc  -DHOST -MMD -MF src/main.d -MP -MT"src/main.d src/main.o" -c src/main.c
gcc  -DHOST  -Iinclude/common -Iinclude/msp432 -Iinclude/CMSIS -o assignment4.out src/main.c src/memory.c src/data.c src/course1.c src/stats.c

size assignment4.out
   text    data     bss     dec     hex filename
   8030     640       8    8678    21e6 assignment4.out

```
In addition, object files will be generated.
You can also run ``make VERBOSE=1 PLATFORM=HOST build``.

or: ``make PLATFORM=MSP432 build``, but you won't see the resulting binary on the host machine.
Moreover, you'll encounter several warnings about I/O system.
