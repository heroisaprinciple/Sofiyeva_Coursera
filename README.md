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
