.data
newLine: .asciiz "\n"
x:   .word  1
y:   .word  3
help:   .word  1

.text
main:
# -----------------------
jal  test
jal  main
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main


test:
li $t0, 1
li $t1, 3
bgt $t0, $t1, false0
la $a0, x #get address
li $a1, 0 #new value
sw $a1 0($a0) #save new value

false0:
la $a0, x #get address
li $a1, 5 #new value
sw $a1 0($a0) #save new value
li $v1, x
jr  $ra
# Printing -----------
li $v0, 1
lw $a0, help
syscall
li $v1, 0
jr  $ra
.end test

main:
# Printing -----------
li $v0, 1
lw $a0, rv
syscall
.end main
