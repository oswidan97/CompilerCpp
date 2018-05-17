# CompilerCpp
## About
A simplified grammar pascal compiler.It includes a lexical analyzer, a parser and a code generator.The generated code is SIC/XE assembly
code.
## Running from the terminal
You can specify the file name of the pascal code to compile or use the default text file code.
The file should be added in the project's parent directory

    cd cmake-build-debug

with specifying the file name

    ./compiler filename


with the default file name

    ./compiler
 ## Output
 The ouput SIC/XE assembly program would be in a file named assembly in the project's parent directory
 ## Supported Grammar
```
<prog>::= PROGRAM <prog-name> VAR <id-list> BEGIN <stmt-list> END.
<prog-name>::= id
<id-list>::= id | <id-list>, id
<stmt-list>::= <stmt> | <stmt-list> ; <stmt>
<stmt>::= <assign> | <read> | <write> | <for>
<assign>::= id := <exp>
<exp>::= <factor> + <factor> | <factor> * factor>
<factor>::= id | ( <exp> )
<read>::= READ ( <id-list> )
<write>::= WRITE ( <id-list> )
<body>::= <stmt> | BEGIN <stmt-list> END
```
