.globl Factorial
	        .type   Factorial, @function
factorial:
		pushl   %ebp
	        movl    %esp, %ebp
	        subl    $16, %esp
	        movl    $1, -8(%ebp) #stores 1 into local variable i.
	        movl    $1, -4(%ebp) #stores 1 into local variable result.
	        jmp     .L4
	.L5:
	        movl    -4(%ebp), %eax
	        imull   -8(%ebp), %eax #multiplying to 
		jo	.L6 #checks to see if overflow has occurred 
	        movl    %eax, -4(%ebp) #result = result*i
	        addl    $1, -8(%ebp) #i++ 
	.L4:
	        movl    -8(%ebp), %eax
	        cmpl    8(%ebp), %eax #compares i and n
	        jle     .L5
	        movl    -4(%ebp), %eax #returns variable result
		jmp	.L7
	.L6:	movl	$0, %eax #returns 0 if overflow has occurred 
	.L7:	        
		leave
	        ret
	        .size   factorial, .-factorial
	.LC0:
	        .string "nCr: %d\n"
	        .text
	          # Your code for Factorial should go here
	

.globl nCr
	.type	nCr, @function
nCr:
		pushl   %ebp
	        movl    %esp, %ebp
	        pushl   %esi
	        pushl   %ebx
	        subl    $32, %esp
	        movl    8(%ebp), %eax #8(%ebp) = n
	        movl    %eax, (%esp)
	        call    factorial
		movl    %eax, %ebx #ebx = n!
		cmp	$0, %eax
		je	.L8 #if factorial returns 0 = overflow     	        
		movl    12(%ebp), %eax #12(%ebp) = r
	        movl    %eax, (%esp)
	        call    factorial
	        movl    %eax, %esi  #esi = r!
		cmp	$0, %eax
		je	.L8 #if factorial returns 0 = overflow     
		movl    12(%ebp), %eax
	        movl    8(%ebp), %ecx
	        subl    %eax, %ecx #ecx = n-r
	        movl    %ecx, %eax
	        movl    %eax, (%esp)
	        call    factorial
	        movl    %esi, %edx #edx = (n-r)!
		cmp     $0, %edx
	        je      .L8 #if factorial returns 0 = overflow
	        imull   %eax, %edx #edx = r!*(n-r)!
		jo	.L8	#check if mulitplication reuslts in overflow
		movl    %edx, -12(%ebp)
	        movl    %ebx, %edx
	        movl    %edx, %eax
	        sarl    $31, %edx
	        idivl   -12(%ebp)
	        addl    $32, %esp
	        popl    %ebx
	        popl    %esi
	        popl    %ebp
	        ret
	.L8:
		movl	$0, %eax #returns 0 if overflow has occurred
		leave	
		ret		
	        .size   nCr, .-nCr

	# Your code for nCr should go here

