.text
main:
# -----------------------
addi $s0, $zero, 2
addi $t0, $t0, 0
sw   $s0, foo(t0)
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
