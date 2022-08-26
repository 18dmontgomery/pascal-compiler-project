# Pascal compiler in C programming lagnugage
## Methodolgy
We were tasked with creating a compiler for the pascal programming langugage from complete scratch, preferably in the C programming language. This monstrous task was broken into four seperate projects explained below. 
## Project 1
I created a lexical analyzer that would break an input text file down into different elements, or lexemes. We used eight separate machines to separate random input text into each lexeme. Each of these lexemes were given a meaning and will be used in the next three projects to develop the compiler.
## Project 2
For this project, I created a syntax analyzer that utilized the code we wrote in project one and the grammar in LL(1) form to get a token, match this token, and output whether or not this token is expected. Every compiler has a form of grammar that the user is required to follow to compile, and pascal is no different. For this project I created a parse function, gettoken function, match function, and individual functions for all 39 terminals listed in the grammar. 
## Project 3 and 4
For project 3, I decorated our grammar to give the language the ability to do type checking and scope checking. This was done by creating a semantic analyzer that used the lex tokens developed in the first project, a decorated parse tree, and multiple error handling functions. We were asked to follow the standard scope checking rules for pascal and complete type checking. For project 4, I was asked to compute memory addresses for local variables in the scope. The memory addresses were dependent on the variable type and size.

## Want more details?
I created a document for each project, explaing what the tasks were and how I went about completing each. These can be found in the documentation folder.
