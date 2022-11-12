.data
newLine: .asciiz "\n"
myChar  .byte   'a'

.text
main:
# -----------------------
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
.end main

.end main
