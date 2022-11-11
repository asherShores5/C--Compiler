.text
main:
# -----------------------
# Printing -----------
li $v0, 1
lw $a0, help
syscall
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
