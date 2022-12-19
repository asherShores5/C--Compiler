.data
newLine: .asciiz "\n"
x:   .word  20
num1: .word     0
num2: .word     0
result:   .word  0
result1:   .word  0
msg0: .asciiz "result:"

.text
# -----------------------

main:
lw $t0, x
li $t1, 0
blt $t1, $t0, while0
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main


addValue:
move $t0, $a0
move $t1, $a1
add $s1, $t0, $t1
la $t0, result #get address
move $t1, $s1 #new value
sw $t1 0($t0) #save new value
lw $v1, result
jr  $ra
.end addValue

# --- CONDITION --- #

while0:
lw $a0, x
li $a1, 5
jal  addValue
la $t0, result1 #get address
move $t1, $v1 #new value
sw $t1 0($t0) #save new value
li $v0, 4
la $a0, msg0
syscall
# Printing -----------
li $v0, 1
lw $a0, result1
syscall
# PRINTING NEW LINE ---->
li $v0, 4
la $a0, newLine
syscall
lw $t0, x
li $t1, 5
sub $s1, $t0, $t1
la $t0, x #get address
move $t1, $s1 #new value
sw $t1 0($t0) #save new value
lw $t0, x
li $t1, 0
blt $t1, $t0, while0
.end while0

