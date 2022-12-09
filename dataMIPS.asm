.data
newLine: .asciiz "\n"
x:   .word  1
y:   .word  3
help:   .word  3
rv:   .word  0

.text
main:
# -----------------------
jal  test
jal  mainFunc
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main


test:
li $t0, 1
li $t1, 3
# --- IF STMT --- #
bne $t0, $t1, false0
la $a0, x #get address
li $a1, 0 #new value
sw $a1 0($a0) #save new value
# Printing -----------
li $v0, 1
lw $a0, x
syscall
li $v0, 4
la $a0, newLine
syscall
# --- JUMP PAST ELSE --- #
beq $0, $0, jumpElse0

# --- ELSE STMT --- #
false0:
la $a0, x #get address
li $a1, 5 #new value
sw $a1 0($a0) #save new value
# Printing -----------
li $v0, 1
lw $a0, y
syscall
li $v0, 4
la $a0, newLine
syscall
# ---PAST ELSE--->
jumpElse0:
li $v1, 0
jr  $ra
.end test

mainFunc:
# Printing -----------
li $v0, 1
lw $a0, x
syscall
.end mainFunc
