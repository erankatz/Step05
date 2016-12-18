main:

jal Label_0_main

Label_0_main:

	addi $fp,$sp,40

	li $t0,-4

	add $t1,$fp,$t0

	sw $v0,0($t1)

	li $t0,-4

	add $t1,$fp,$t0

	lw $t2,0($t1)

	li $t0,4

	add $t1,$t2,$t0

	sw $v0,0($t1)

	li $t0,-4

	add $t1,$fp,$t0

	lw $t2,0($t1)

	li $t0,8

	add $t1,$t2,$t0

	sw $v0,0($t1)

	li $v0,10

	syscall
Label_1_AllocateRecord:

Label_2_AllocateArray:

Label_3_PrintInt:

	lw $a0,0($sp)

	li $v0,1

	syscall

	li $a0,32

	li $v0,11

	syscall

	jr $ra

Label_4_Access_Violation:

	li $a0,65

	li $v0,11

	syscall

	li $a0,99

	li $v0,11

	syscall

	li $a0,99

	li $v0,11

	syscall

	li $a0,101

	li $v0,11

	syscall

	li $a0,115

	li $v0,11

	syscall

	li $a0,115

	li $v0,11

	syscall

	li $a0,32

	li $v0,11

	syscall

	li $a0,86

	li $v0,11

	syscall

	li $a0,105

	li $v0,11

	syscall

	li $a0,111

	li $v0,11

	syscall

	li $a0,108

	li $v0,11

	syscall

	li $a0,97

	li $v0,11

	syscall

	li $a0,116

	li $v0,11

	syscall

	li $a0,105

	li $v0,11

	syscall

	li $a0,111

	li $v0,11

	syscall

	li $a0,110

	li $v0,11

	syscall

	li $v0,10

	syscall

