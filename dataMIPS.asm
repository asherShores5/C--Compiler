.data
newLine: .asciiz "\n"
x:   .word  5
help:   .word  3

.text
main:
# -----------------------
# Printing -----------
li $v0, 1
lw $a0, help
syscall
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
.end main

test 
please work