.text
main:
# -----------------------
jal  test
jal  main
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
