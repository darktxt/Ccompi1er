
.data
_hint: .asciiz "Input:"
_ret: .asciiz "\n"
.globl main
.text
read:
    li $v0,4
    la $a0,_hint
    syscall
    li $v0,5
    syscall
    jr $ra
print:
    li $v0,1
    syscall
    li $v0,4
    la $a0,_ret
    syscall
    move $v0,$0
    jr $ra
s:
	addi $sp,$sp,-20
	sw $t0,12($sp)
	sw $t1,16($sp)
	lw $t7,8($sp)
	move $t7,$a0
	li $t0,1
	add $t1,$t7,$t0
	lw $t8,4($sp)
	move $t8,$t1
	li $t0,1
	sub $t1,$t7,$t0
	lw $t9,0($sp)
	move $t9,$t1
	mul $t0,$t8,$t9
	move $v0,$t0
	jr $ra
	lw $t0,12($sp)
	lw $t1,16($sp)
	addi $sp,$sp,20
main:
	addi $sp,$sp,-12
	sw $t0,4($sp)
	sw $t1,8($sp)
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal read
	lw $ra,0($sp)
	move $t0,$v0
	addi $sp,$sp,4
	move $t1,$t0
	move $a0,$t1
	addi $sp,$sp,-24
	sw $t0,0($sp)
	sw $ra,4($sp)
	sw $t1,8($sp)
	sw $t2,12($sp)
	sw $t3,16($sp)
	sw $t4,20($sp)
	jal s
	lw $a0,0($sp)
	lw $ra,4($sp)
	lw $t1,8($sp)
	lw $t2,12($sp)
	lw $t3,16($sp)
	lw $t4,20($sp)
	addi $sp,$sp,24
	move $t0 $v0
	lw $t7,0($sp)
	move $t7,$t0
	move $a0,$t7
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal print
	lw $ra,0($sp)
	addi $sp,$sp,4
	lw $t0,4($sp)
	lw $t1,8($sp)
	addi $sp,$sp,12
