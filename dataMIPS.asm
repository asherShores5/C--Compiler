.data
newLine: .asciiz "\n"
x:   .word  2
help:   .word  3

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
la $a0, x #get address
li $a1, 10 #new value
sw $a1 0($a0) #save new value
# Printing -----------
li $v0, 1
lw $a0, help
syscall
