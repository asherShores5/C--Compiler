myFunc:
addi $s0, $zero, 10
addi $t0, $t0, 4
sw   $s0, foo($t0)
main:
la $a0, x #get address
li $a1, 5 #new value
sw $a1 0($a0) #save new value

