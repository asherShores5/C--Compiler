.data
newLine: .asciiz "\n"
x:   .word  10
num1:   .word  5
num2:   .word  20
result:   .word  25
msg0: .asciiz "hello"

.text
# -----------------------

main:
jal while0
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

lw $t0, x
li $t1, 0
# --- IF STMT --- #

while0:
lw $t0, x
li $t1, 10
# --- IF STMT --- #
bne $t0, $t1, false0
# PRINTING NEW LINE ---->
li $v0, 4
la $a0, newLine
syscall
# Printing -----------
li $v0, 1
lw $a0, x
syscall
# --- JUMP PAST ELSE --- #
beq $0, $0, jumpElse0

# --- ELSE STMT --- #
false0:
# ---PAST ELSE--->
jumpElse0:
lw $t0, x
li $t1, 5
sub $s1, $t0, $t1
la $t0, x #get address
move $t1, $s1 #new value
sw $t1 0($t0) #save new value
# PRINTING NEW LINE ---->
li $v0, 4
la $a0, newLine
syscall
li $v0, 4
la $a0, msg0
syscall
lw $t0, x
li $t1, 0
blt $t1, $t0, while0
