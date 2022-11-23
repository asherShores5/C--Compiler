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

