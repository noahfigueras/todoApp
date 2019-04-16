# todoApp

This is a command line todo app, created using C language. I created this program for myself because I spend a lot of time working in the command line and it comes very handy a command line program where I can keep track of my todos for the day. It is very easy to customize for your own needs, so feel free to make any changes you want for yourself in the code and I will accept changes for improving the program.

**Instalation**

First of all, the complete program is made for UNIX systems. If you are using Windows or Mac the only concern is to adapt the system("clear") on line 134 to your current system. 

In order to install the todo app in your system you will have to download the output file in the **bin** directory called **todos**. Once you download it to your computer in order to run the program locally in the command line as:

user@Nuts:~$ todos

1. move the **todos** output file to your current ./bin directory in the system.

**OUTPUT**

![alt text](https://raw.githubusercontent.com/noahfigueras/todoApp/master/todoApp.png)

**USAGE**

You have 3 options:
1. Add todo (Press number **1**)
2. Delete todo(Press number **2** and after press the number of the desire todo you want to delete)
3. Exit (Press number **3** to exit from the program).

**File Structure**

todoApp.c **->** Contains all the program, main function, function definitions and implementations...

todoApp.png **->** It is a picture of the basic output of the program.

//Bin folder

todos **->** This is the compiled output file for installation in your computer.

todoList.txt **->** This is the .txt file generated to store the todos once you exit the program. You don't have to install that file. When the main program is executed if it doesn't find a file it is going to create one in the same directory as installed.

# Author
Noah Figueras **->** www.noahfigueras.com 

contact me: noahfigueras@gmail.com
