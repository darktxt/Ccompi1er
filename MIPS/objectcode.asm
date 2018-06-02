
.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text
read:
    li $v0,4
    la $a0,_prompt
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
fact:
	li $t1,2
	mul $t2,$t1,$t3
	li $t1,1
	add $t2,$t2,$t1
	move $t4,$t2
	move $v0,$t4
	jr $ra
main:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal read
	lw $ra,0($sp)
	move $t1,$v0
	addi $sp,$sp,4
	move $t3,$t1
	move $t0,$a0
	move $a0,$t3
	addi $sp,$sp,-24
	sw $t0,0($sp)
	sw $ra,4($sp)
	sw $t1,8($sp)
	sw $t2,12($sp)
	sw $t3,16($sp)
	sw $t4,20($sp)
	jal fact
	lw $a0,0($sp)
	lw $ra,4($sp)
	lw $t1,8($sp)
	lw $t2,12($sp)
	lw $t3,16($sp)
	lw $t4,20($sp)
	addi $sp,$sp,24
	move $t1 $v0
	move $t3,$t1
	move $t0,$a0
	move $a0,$t3
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal print
	lw $ra,0($sp)
	addi $sp,$sp,4
