.data
newLine: .asciiz "\n"
num1:   .word  20
num2:   .word  49
result:   .word  69
result1:   .word  69
msg0: .asciiz "Good Job"
msg1: .asciiz "n i c e"

.text
# -----------------------

main:
jal  addValue
# Printing -----------
li $v0, 1
lw $a0, result1
syscall
# PRINTING NEW LINE ---->
li $v0, 4
la $a0, newLine
syscall
li $v0, 4
la $a0, msg0
syscall
li $v0, 4
la $a0, msg1
syscall
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main


addValue:
lw $t0, num1
lw $t1, num2
add $s1, $t0, $t1
lw $v1, result
jr  $ra
.end addValue

li $v1, 0

