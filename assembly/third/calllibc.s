.section .data
output:
	.asciz "The processor vendor id is '%s'\n"
.section .bss
	.lcomm buffer,12

.text
.globl _start
_start:
	movl $0, %eax
	cpuid
	movl $buffer, %edi
	movl %ebx, (%edi)
	movl %edx, 4(%edi)
	movl %ecx, 8(%edi)
	push $buffer
	push $output
	call printf
	addl $8, %esp
	push $0
	call exit