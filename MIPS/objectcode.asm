
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
test:
	li $t1,1
	move $t2,$t1
test2:
	li $t1,1
	move $t3,$t1
main:
	li $t1,1
	move $t3,$t1
	li $t1,2
	move $t4,$t1
	li $t1,3
	move $t5,$t1
	li $t1,1
	mul $t6,$t3,$t4
	div $t6,$t7
	mflo $t6
	add $t6,$t1,$t6
	add $t1,$t4,$t5
	mul $t1,$t3,$t1
	add $t1,$t6,$t1
