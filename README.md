<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/35/The_C_Programming_Language_logo.svg/2000px-The_C_Programming_Language_logo.svg.png" alt="C" width="64px" height="64px"> <img src="https://upload.wikimedia.org/wikipedia/en/thumb/9/97/Santa_Monica_College_seal.svg/1200px-Santa_Monica_College_seal.svg.png" alt="SMC" width="64px" height="64px">

<h1>C Programming</h1>

This repo contains all of the projects I submitted as part of my C Programming
course at Santa Monica College in the Spring 2018 semester.

<h2>Testing</h2>

You can run the scripts yourself by cloning the repo to your local machine. In order to clone, type the following into your terminal:

```
git clone git@github.com:dalibran/C-Projects.git
```

Once you navigate to the repo directory, you'll have to compile the source code. In order to do this, you'll need Xcode's Command Line Tools installed. Assuming that is installed, run the following command to compile an individual project file. Here is the command for compiling the first project:

```
gcc -o Printing 01Printing.c
```

Run the object code within your terminal by executing the following command:

```
./Printing
```

<h2>Project Descriptions</h2>

<h3>Project 6</h3>

This project was an exercise in generating multidimensial arrays. I created a multidimensional array of fixed size and filled it with a random assortment of 1's and 0's. After that, I iterated through each row, summed up the contents, and assigned a parity bit based on whether the sum was odd or even.

<img src="https://www.dropbox.com/s/ter6l2sks90boz0/Screenshot%202018-07-13%2016.05.07.png?raw=1" alt="Project4" width="350px" height="400px">

<h3>Project 5</h3>

After generating an array and filling it with random integers, I wrote a quicksort and binary search algorithm to demonstrate the different ways of sorting an array. For the binary search, I printed each step of the search to the console as a way of visualizing how the algorithm worked.

<img src="https://www.dropbox.com/s/0ku65c3tbh4sadm/Screenshot%202018-07-13%2016.00.32.png?raw=1" alt="Project4" width="350px" height="600px">

<h3>Project 4</h3>

The goal of this project was to develop a software version of Craps, the popular casino game. After randomly generating a dice roll, I used a switch statement, coupled with recursion, to account for the various outcomes of a dice roll and continue rolling if necessary.

<img src="https://www.dropbox.com/s/u2bx5ejyl0fyalx/Screenshot%202018-07-13%2015.54.23.png?raw=1" alt="Project4" width="350px" height="500px">

<h3>Project 3</h3>

I was tasked with generating an array of variable size full of random integers
ranging from 10 to 90. Once generated, I created several functions to perform
various actions upon the array. These functions allow me to print the array,
find the maximum and minimum values, calculate the average of all values,
perform a bubble sort, and find the median.

<img src="https://www.dropbox.com/s/20s7vcl4kbmw84s/Screenshot%202018-04-11%2013.41.17.png?raw=1" alt="Project3" width="350px" height="500px">

<h3>Project 2</h3>

This project focused on looping. Specifically, I was asked to print a diamond
composed of my initials, where the number of the diamond's lines was determined randomly. I achieved this using several nested for-loops.

<img src="https://www.dropbox.com/s/pwnqcuqljcyubb0/Screenshot%202018-04-11%2013.40.57.png?raw=1" alt="Project2" width="350px" height="500px">

<h3>Project 1</h3>

An introduction project where we printed our initials to the console. The goal
was to become familiar with the basic construction of main(), as well as printf().
