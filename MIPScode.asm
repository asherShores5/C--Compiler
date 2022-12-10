.text
# -----------------------

main:
# Printing -----------
li $v0, 1
lw $a0, x
syscall
# --- JUMP PAST ELSE --- #
beq $0, $0, jumpElse1

# --- ELSE STMT --- #
false1:
la $a0, x #get address
li $a1, 5 #new value
sw $a1 0($a0) #save new value
