.data
newLine: .asciiz "\n"
x:   .word  20
y:  .byte   'n'
result:   .word  4
msg0: .asciiz "Success"

.text
# -----------------------

main:
lw $t0, x
li $t1, 0
# --- IF STMT --- #
blt $t0, $t1, false0
# Printing -----------
li $v0, 1
lw $a0, result
syscall
# --- JUMP PAST ELSE --- #
beq $0, $0, jumpElse0

# --- ELSE STMT --- #
false0:
# Printing -----------
li $v0, 11
lb $a0, y
syscall
# ---PAST ELSE--->
jumpElse0:
li $v0, 4
la $a0, msg0
syscall
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main


