.section .rodata
.align 2
.str:
	.string "%d "
	.text
	.align 2
	.global main
.next:
	.string "\n"
	.text
	.align 2
	.global main

main:

movi $r8,#1
movi $r9,#0

.L1:

	addi $r8,$r8,#1
	slti $r6,$r8,#100
	beqz $r6, .end

	movi $r7, #2
.L2:

	slt $r6,$r7,$r8
	beqz $r6, .print

	divsr $r2,$r1,$r8,$r7
	beqz $r1 ,.L1

	addi $r7,$r7,#1

	j .L2

.print:

	la $r0, .str
	move $r1,$r8
	bal printf

	addi $r9,$r9,1
	movi $r5,#10
	divsr $r2, $r1,$r9,$r5
	beqz $r1, .enter

	j .L1

.enter:

	la $r0,.next
	bal printf
	j .L1

.end:
	ret
