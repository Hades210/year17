.section .data
data_items:
	.long 3,67,34,200,45,75,54,34,44,33,22,11,66,0
output:
	.asciz "The max num in the array is: '%d'"

.section .bss
	.lcomm buffer,4

.section .text
.globl _start
_start:
	movl $0, %edi
	movl data_items(,%edi,4), %eax
	movl $buffer, %esi
	movl %eax, (%esi)

start_loop:
	cmpl $0, %eax
	je loop_exit
	incl %edi
	movl data_items(,%edi,4), %eax
	cmpl %eax, (%esi)
	jge start_loop

	movl %eax, (%esi)
	jmp start_loop

loop_exit:

	pushl $buffer
	pushl $output
	call printf
	addl $8, %esp
	push $0
	call exit