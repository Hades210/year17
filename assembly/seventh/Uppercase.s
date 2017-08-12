####### toupper.s #######
#system call numbers
.equ SYS_OPEN, 5
.equ SYS_WRITE, 4
.equ SYS_READ, 3
.equ SYS_CLOSE, 6
.equ SYS_EXIT, 1

#options for open
.equ O_RDONLY, 0
.equ O_CREAT_WRONLY_TRUNC, 03101
.equ O_PERMISSION, 0666

#starnard file descriptors
.equ STDIN, 0
.equ STDOUT, 1
.equ STDERR, 2

#system call interrupt
.equ LINUX_SYSCALL, 0x80
.equ END_OF_FILE, 0 

.section .bss
#Buffer - this is where the data is loaded into from the data
#file and written from into the output file.

.equ BUFFER_SIZE, 500
.lcomm BUFFER_DATA, BUFFER_SIZE

.section .text
#STACK POSITION
.equ ST_SIZE_RESERVE, 8
.equ ST_FD_IN, -4
.equ ST_FD_OUT, -8
.equ ST_ARGC, 0		#Number of arguments
.equ ST_ARGV_0, 4	#Name of program
.equ ST_ARGV_1, 8	#Input file name
.equ ST_ARGV_2, 12	#Output file name

.globl _start
_start:
	movl %esp, %ebp
	subl $ST_SIZE_RESERVE, %esp	#Allocate space for our file
open_files:
open_fd_in:
	movl $SYS_OPEN, %eax	#open syscall
	movl ST_ARGV_1(%ebp), %ebx #input filename into %ebx
	movl $O_RDONLY, %ecx
	movl $O_PERMISSION, %edx
	int $LINUX_SYSCALL
store_fd_in:
	movl %eax, ST_FD_IN(%ebp)
open_fd_out:
	movl $SYS_OPEN, %eax	#open the file
	movl ST_ARGV_2(%ebp),%ebx
	movl $O_CREAT_WRONLY_TRUNC, %ecx #flags for writing to the file mode for new file
	movl $O_PERMISSION, %edx
	int $LINUX_SYSCALL
store_fd_out:
	#store the file descriptor here
	movl %eax, ST_FD_OUT(%ebp)

### BEGIN MAIN LOOP ###
read_loop_begin:
	movl $SYS_READ, %eax
	movl ST_FD_IN(%ebp), %ebx	#get the input file descriptor
	movl $BUFFER_DATA, %ecx 	#the location to read into
	movl $BUFFER_SIZE, %edx 	#the size of the buffer
	int $LINUX_SYSCALL			#size of buffer read is returned in %eax

	### EXIT IF WE' REACHED THE END ###
	cmpl $END_OF_FILE, %eax		#check for end of file marker
	jle end_loop				#if found or on error, go the end
continue_read_loop:
	### CONVERT_THE_BLOCK_TO_UPPER_CASE ###
	pushl $BUFFER_DATA			#location of buffer
	pushl %eax					#size of the buffer
	call convert_to_upper
	popl %eax					#get the size back
	addl $4, %esp				# restore %esp

	###WRITE THE BLOCK OUT TO THE OUTPUT FILE ###
	movl %eax, %edx				#size of the buffer
	movl $SYS_WRITE, %eax
	movl ST_FD_OUT(%ebp), %ebx	#the output file descriptor
	movl $BUFFER_DATA, %ecx 	#location of the buffer
	int $LINUX_SYSCALL

	### CONTINUE THE LOOP ###
	jmp read_loop_begin

end_loop:
	### CLOSE THE FILES ###
	movl $SYS_CLOSE, %eax
	movl ST_FD_OUT(%ebp), %ebx
	int $LINUX_SYSCALL
	movl $SYS_CLOSE, %eax
	movl ST_FD_IN(%ebp), %ebx
	int $LINUX_SYSCALL

	### EXIT ###
	movl $SYS_EXIT, %eax
	movl $0, %ebx
	int $LINUX_SYSCALL

#convert_to_upper function
#INPUT: The first parameter is the location of the block of memory to convert
#The second parameter is the length of that buffer
#OUTPUT: This function overwrites the current buffer with the new version

### CONSTANTS ###
.equ LOWERCASE_A, 'a'
.equ LOWERCASE_Z, 'z'
.equ UPPER_CONVERSION, 'A' - 'a'

### STACK STUFF ###
.equ ST_BUFFER_LEN, 8
.equ ST_BUFFER,12

convert_to_upper:
	pushl %ebp
	movl %esp, %ebp

### SET UP VARIABLES ###
	movl ST_BUFFER(%ebp), %eax
	movl ST_BUFFER_LEN(%ebp), %ebx
	movl $0, %edi		#loop variable

# if a buffer with zero length was given to us, just leave
	cmpl $0, %ebx
	je end_convert_loop

convert_loop:
	movb (%eax, %edi,1), %cl 	# get the current byte
	cmpb $LOWERCASE_A, %cl 		#go the the next byte unless it is between 'a' and 'z'
	jl 	next_byte
	cmpb $LOWERCASE_Z, %cl
	jg	next_byte

#otherwise convert the byte to uppercase, and store it back
	addb $UPPER_CONVERSION, %cl
	movb %cl, (%eax,%edi,1)

next_byte:
	incl %edi				#next byte
	cmpl %edi, %ebx 		#continue unless we've reached the end
	jne convert_loop 
end_convert_loop:
	movl %ebp, %esp
	popl %ebp
	ret