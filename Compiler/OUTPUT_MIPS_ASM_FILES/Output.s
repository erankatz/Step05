main:

jal Label_0_main

Label_0_main:

	addi $fp,$sp,40

	li $t0,-4

	add $t1,$fp,$t0

	sw $v0,0($t1)

	li $t0,-8

	add $t1,$fp,$t0

	sw $v0,0($t1)

	li $t0,-12

	add $t1,$fp,$t0

	sw $v0,0($t1)

	li $t0,-16

	add $t1,$fp,$t0

	sw $v0,0($t1)

	li $t0,-20

	add $t1,$fp,$t0

	sw $v0,0($t1)

	li $t0,-24

	add $t1,$fp,$t0

	sw $v0,0($t1)

	li $t0,-28

	add $t1,$fp,$t0

	sw $v0,0($t1)

	li $t0,-32

	add $t1,$fp,$t0

	sw $v0,0($t1)

	j Label_7_Skip_This_Function_For_Now

Label_8_Merge:

	li $t0,0

	li $t0,0

	li $t0,-4

	add $t1,$fp,$t0

	li $t0,0

	sw $t0,0($t1)

	li $t0,-8

	add $t1,$fp,$t0

	li $t0,0

	sw $t0,0($t1)

	li $t0,8

	add $t2,$fp,$t0

	lw $t1,0($t2)

	li $t0,0

	beq $t1, $t0, Label_16_T

	bne $t1, $t0, Label_17_F

Label_16_T:

	li $t0,1

	addi $t1,$t0,0

	j Label_18_END

Label_17_F:

	li $t0,0

	addi $t1,$t0,0

	j Label_18_END

Label_18_END:

	li $t0,0

	bne $t1, $t0, Label_9_if_taken

	beq $t1, $t0, Label_10_if_not_taken

Label_9_if_taken:

	li $t0,-4

	add $t1,$fp,$t0

	li $t0,12

	add $t3,$fp,$t0

	lw $t2,0($t3)

	sw $t2,0($t1)

Label_10_if_not_taken:

	li $t0,12

	add $t2,$fp,$t0

	lw $t1,0($t2)

	li $t0,0

	beq $t1, $t0, Label_36_T

	bne $t1, $t0, Label_37_F

Label_36_T:

	li $t0,1

	addi $t1,$t0,0

	j Label_38_END

Label_37_F:

	li $t0,0

	addi $t1,$t0,0

	j Label_38_END

Label_38_END:

	li $t0,0

	bne $t1, $t0, Label_29_if_taken

	beq $t1, $t0, Label_30_if_not_taken

Label_29_if_taken:

	li $t0,-4

	add $t1,$fp,$t0

	li $t0,8

	add $t3,$fp,$t0

	lw $t2,0($t3)

	sw $t2,0($t1)

Label_30_if_not_taken:

	li $t0,8

	add $t2,$fp,$t0

	lw $t1,0($t2)

	li $t0,0

	bne $t1, $t0, Label_56_T

	beq $t1, $t0, Label_57_F

Label_56_T:

	li $t0,1

	addi $t1,$t0,0

	j Label_58_END

Label_57_F:

	li $t0,0

	addi $t1,$t0,0

	j Label_58_END

Label_58_END:

	li $t0,0

	bne $t1, $t0, Label_49_if_taken

	beq $t1, $t0, Label_50_if_not_taken

Label_49_if_taken:

	li $t0,12

	add $t2,$fp,$t0

	lw $t1,0($t2)

	li $t0,0

	bne $t1, $t0, Label_66_T

	beq $t1, $t0, Label_67_F

Label_66_T:

	li $t0,1

	addi $t1,$t0,0

	j Label_68_END

Label_67_F:

	li $t0,0

	addi $t1,$t0,0

	j Label_68_END

Label_68_END:

	li $t0,0

	bne $t1, $t0, Label_59_if_taken

	beq $t1, $t0, Label_60_if_not_taken

Label_59_if_taken:

	li $t0,8

	add $t2,$fp,$t0

	lw $t1,0($t2)

	li $t0,0

	add $t2,$t1,$t0

	lw $t1,0($t2)

	li $t0,12

	add $t3,$fp,$t0

	lw $t2,0($t3)

	li $t0,0

	add $t3,$t2,$t0

	lw $t2,0($t3)

	ble $t1, $t2, Label_91_T

	bgt $t1, $t2, Label_92_F

Label_91_T:

	li $t0,1

	addi $t1,$t0,0

	j Label_93_END

Label_92_F:

	li $t0,0

	addi $t1,$t0,0

	j Label_93_END

Label_93_END:

	li $t0,0

	bne $t1, $t0, Label_69_if_taken

	beq $t1, $t0, Label_70_if_not_taken

Label_69_if_taken:

	li $t0,-8

	add $t1,$fp,$t0

	li $t0,8

	add $t3,$fp,$t0

	lw $t2,0($t3)

	li $t0,0

	add $t3,$t2,$t0

	lw $t2,0($t3)

	sw $t2,0($t1)

	li $t0,-4

	add $t1,$fp,$t0

	sw $v0,0($t1)

Label_70_if_not_taken:

	li $t0,8

	add $t2,$fp,$t0

	lw $t1,0($t2)

	li $t0,0

	add $t2,$t1,$t0

	lw $t1,0($t2)

	li $t0,12

	add $t3,$fp,$t0

	lw $t2,0($t3)

	li $t0,0

	add $t3,$t2,$t0

	lw $t2,0($t3)

	bgt $t1, $t2, Label_156_T

	ble $t1, $t2, Label_157_F

Label_156_T:

	li $t0,1

	addi $t1,$t0,0

	j Label_158_END

Label_157_F:

	li $t0,0

	addi $t1,$t0,0

	j Label_158_END

Label_158_END:

	li $t0,0

	bne $t1, $t0, Label_134_if_taken

	beq $t1, $t0, Label_135_if_not_taken

Label_134_if_taken:

	li $t0,-8

	add $t1,$fp,$t0

	li $t0,12

	add $t3,$fp,$t0

	lw $t2,0($t3)

	li $t0,0

	add $t3,$t2,$t0

	lw $t2,0($t3)

	sw $t2,0($t1)

	li $t0,-4

	add $t1,$fp,$t0

	sw $v0,0($t1)

Label_135_if_not_taken:

Label_60_if_not_taken:

Label_50_if_not_taken:

	li $t0,-4

	add $t2,$fp,$t0

	lw $t1,0($t2)

	addi $v0,$t1,0

	li $t0,0

	li $t0,0

Label_7_Skip_This_Function_For_Now:

	j Label_204_Skip_This_Function_For_Now

Label_205_PrintIntList:

	li $t0,0

	li $t0,0

	li $t0,8

	add $t2,$fp,$t0

	lw $t1,0($t2)

	li $t0,0

	bne $t1, $t0, Label_213_T

	beq $t1, $t0, Label_214_F

Label_213_T:

	li $t0,1

	addi $t1,$t0,0

	j Label_215_END

Label_214_F:

	li $t0,0

	addi $t1,$t0,0

	j Label_215_END

Label_215_END:

	li $t0,0

	bne $t1, $t0, Label_206_if_taken

	beq $t1, $t0, Label_207_if_not_taken

Label_206_if_taken:

Label_207_if_not_taken:

	li $t0,0

	li $t0,0

Label_204_Skip_This_Function_For_Now:

	li $t0,-12

	add $t1,$fp,$t0

	lw $t2,0($t1)

	li $t0,4

	add $t1,$t2,$t0

	li $t0,-16

	add $t3,$fp,$t0

	lw $t2,0($t3)

	sw $t2,0($t1)

	li $t0,-8

	add $t1,$fp,$t0

	lw $t2,0($t1)

	li $t0,4

	add $t1,$t2,$t0

	li $t0,-12

	add $t3,$fp,$t0

	lw $t2,0($t3)

	sw $t2,0($t1)

	li $t0,-4

	add $t1,$fp,$t0

	lw $t2,0($t1)

	li $t0,4

	add $t1,$t2,$t0

	li $t0,-8

	add $t3,$fp,$t0

	lw $t2,0($t3)

	sw $t2,0($t1)

	li $t0,-28

	add $t1,$fp,$t0

	lw $t2,0($t1)

	li $t0,4

	add $t1,$t2,$t0

	li $t0,-32

	add $t3,$fp,$t0

	lw $t2,0($t3)

	sw $t2,0($t1)

	li $t0,-24

	add $t1,$fp,$t0

	lw $t2,0($t1)

	li $t0,4

	add $t1,$t2,$t0

	li $t0,-28

	add $t3,$fp,$t0

	lw $t2,0($t3)

	sw $t2,0($t1)

	li $t0,-20

	add $t1,$fp,$t0

	lw $t2,0($t1)

	li $t0,4

	add $t1,$t2,$t0

	li $t0,-24

	add $t3,$fp,$t0

	lw $t2,0($t3)

	sw $t2,0($t1)

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

