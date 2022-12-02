.data
newLine: .asciiz "\n"
x:   .word  5
y:   .word  3

.text
main:
# -----------------------
jal  main
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main

main:
# Printing -----------
li $v0, 1
lw $a0, x
syscall
