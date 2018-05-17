# CompilerCpp
## About
A simplified grammar pascal compiler.It includes a lexical analyzer, a parser and a code generator.The generated code is SIC/XE assembly
code.
## Building source code
First, clone the  repository by
```
git clone https://github.com/oswidan97/CompilerCpp.git
```    
### For UNIX based systems
If CMake is not installed on your system, follow the following instructions
#### Installing CMake
    sudo apt-get install cmake
#### Building
    cmake ~/PATH_of_source_code's_parent_directory/cmake-build-debug
    make
### For windows based systems
#### Installing CMake
Install the latest version of CMake from the [CMake download page](https://cmake.org/download/)
#### Building
Follow the instructions [here](https://cmake.org/runningcmake/)

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
 ## Supported Grammar in BNF
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
