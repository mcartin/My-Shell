
Name: Cara Martin
Student ID: 22390791
I acknowldege the DCU Academic Integrity Policy

Operations & Commands:
-cd:
    cd <the directory you want to change to>
    **WILL CHANGE CURRENT DIRECTORY TO THE DESIRED DIRETORY**

	typing this command into the terminal followed by your desired 
	directory will change your current working directory to the
	directory requested if it already exist

-clear:
    clear
    **CLEARS THE SYSTEM INTERFACE OF ALL PREVIOUS TEXT ON THE SCREEN**

	typing this command into the terminal removes all text either
	generated or manually typed from the screen leaving just your
	"Type Command ==>" at the top of the terminal

-dir:
    dir <the name of the directory whos files you want to see>
    **LIST ALL THE FILES IN THE DIRECTORY REQUESTED**

	typing this command into the terminal followed by the directory
	to which files you wish to see will be listed in the format of
	(file type and permissions) (number of hard links) (owner and group)
	(file size) (modification date and time) (file or directory name)

-environ:
    environ
    **LISTS THE ENVIRONMENT VARIABLES AND VALUES**

	typing this command into the terminal will display a list of
	environment variblas combined with their values belong to the
	current shell session in the form of variable=value

-echo:
    echo <any input>
    **REPRINTS THE GIVEN INPUT AFTER ECHO TO THE COMMAND LINE**

	typing this command into the terminal followed by any input will
	print everything after the word 'echo' on a newline command line

-help:
    help
    **OPENS THIS MANUAL TO THE INTERFACE**

	typing this command into the terminal will produce the manual i.e
	this document which contains all the necessary information a user
	would need to work the interface.

-pause:
    pause <'enter' key pressed>
    ***PAUSES ANY OPERATIONS UNTIL THE ENTER KEY IS PRESSED**

	typing this command into the terminal will pause all operations of
	the shell until you the user press the enter buttom to cancel the
	running of this operation and continue running the previous
	operation

-quit:
    quit
    **END THE CURRENT RUNNING PROGRAM**

	typing this command into the terminal will end the program that
	is currently running in the shell



Environment Concepts:
-Environmental Variables:
	present in the get_curr_dir() with getcwd() function retrieveing and
	storing it in the cwd variable.
-Environmental Interaction:
	l_env()(list environment variables) function prints the variables demonstrating
	the program interact and display information about environment.
-File Operations:
	fopen(), fclose(), freopen(), fprint() used in i/o operations demonstrates
	interaction with file system i.e. part of border environment.
-System Calls:
	chdir()(change current working directory), execvp(), examples of system calls
	used to execute other programs interacting ewith underlying system environment. 


I/O Redirection:
	Detection of redirection symbols by tokenising the input line and checking for 
	'<', '>', '>>', done in the loop that iterates over the command line args[].

	Input Redirection (<) when detected the stdin (standard input) is redirected
	to read from this file by using the freopen() function opening the specified
	filw in read mode.

	Output Redirection (>, >>) when detected the stdout (standard output) is written
	to the file which is created or truncated if it exists also by useing freopen().

	After redirection the command is dealt with i.e. cd, clear, echo.

	Finally there is the closing of redirection files using fclose() function.

Process concept:
	For this program each process i.e. each time a user enters a command such as cd or
	or echo my shell creates a new process to execute with its own memory space, file 
	descriptors and execution environment.
Background v Foreground Execution:
	Background = process running independently of the shell, user can continue to enter
	command (ls &) can be acccess with this shell by using '&' symbol.
	Foreground =  process which receives input from user and interacts directly with the
	terminal, waits to complete before accepting further information i.e. the evrion command
	has to complete before further interaction can take place.
	-This shell primarily focuses on foreground execution as most commands involve user 
	interaction.

Overall layout and display of understanding:
	
	This is a simple shell program written in C that allows users to execute commands
	interactively or from a batch file. It provides functionalities such as changing directories
	(cd), clearing the screen (clear), listing directory contents (dir), displaying environment
	variables (environ), echoing input (echo), and showing a help manual (help). Additionally,
	it supports I/O redirection for both input and output streams, enabling users to redirect
	stdin and stdout to/from files.

	The program reads user input from the command line or from a batch file, tokenises the input
	into individual arguments, and executes the corresponding commands. It handles input/output
	redirection by detecting <, >, and >> symbols in the input arguments and appropriately
	redirects stdin and/or stdout using freopen().

	This shell also implements basic error handling and provides a simple interface for users
	to interact with. While it lacks more advanced features found in full-fledged shells.


References:
	1. How Linux Works, 3rd Edition: What Every Superuser Should Know, Brian Ward, 21 April 2021

	2. Linux System Programming: Talking Directly to the Kerne; and C Library, Robert Love, 31 May 2013, O'Reilly 

	3. Linux/UNIX System Programming Fundamentals, man7org, Michael Kerrisk Course Introduction, 2020
	pdf link = https://www.man7.org/training/download/Linux_System_Programming-man7.org-mkerrisk-NDC-TechTown-2020.pdf

	4. Write Your Own Shell, Jess Inspired, 6 June 2022 
	
