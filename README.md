# CompilerCpp
## About
A simplified grammar pascal compiler.It includes a lexical analyzer, a parser and a code generator.The generated code is SIC/XE assembly
code.

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
