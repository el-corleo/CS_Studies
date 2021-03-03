How to add the stdlib.jar to your classpath when compiling java code

OS X / Linux / Git Bash
-----------------------
% javac -classpath .:stdlib.jar MyProgram.java
% java  -classpath .:stdlib.jar MyProgram

Windows Commmand Prompt
-----------------------
% javac -classpath .;stdlib.jar MyProgram.java
% java  -classpath .;stdlib.jar MyProgram