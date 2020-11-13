#########################################################################
#   Description:
#     Calculate prime numbers  
#
#   Modification history:
#   Date        Name        Modification
#   2020-10-18  Elkin Rozo
#########################################################################

	
#########################################################################
#   Main program
#########################################################################
	.data   #data section
	
number: .byte 0x02
	
str: .ascii "Start program"
message: .ascii "amount of prime number: \n"
constant_two: .byte  0x02
constant_tree: .byte  0x03
Lk: .byte 0x00
aux: .byte 0x00
breakpoint: .ascii " \n"
number_v: .word 30
	.text 

lb  $s7,constant_tree               # start en tree to count 
lb  $t4, Lk                         # Load var in memory
lb  $s6,aux                         #count in memory   

main:
		
	#Start program
	li $v0,4
 	la $a0, str
 	syscall
 	
 	lw  $t1, number_v
 	j   start
 	 	 	
 	li $v0, 10
	syscall
	
	jr $ra
		
isPrime:
	
	lb  $t0, constant_two   # Load $t0 to value constant_two
	beq $t1,$t0,Lu        # if input equals two then end true
	slt $t2,$t1,$t0	       # if input less two then end false
	beq $t2,1,end	       # apply line before
	
	jal isOdd              # if is odd return 1 or true continue
	move $s1,$t2
	# li $s0,3               # start en tree to count 
	beq $s1,1,test         # if $s1 different from pair continue
	beq $s1,0, end        # end if number is pair
	
 	j  end

test:
	j  forIsPrime	 	
forIsPrime:
	
	 
	la $s1,($t1)        # load $si to value number_V
	div $t0,$s1,3          # div $s1 to tree
	
	ble $s7,$t0,ok         # if $s0 <= $t0 evaluate if it has divisors
	bge $s7,$t0,Lu       # end process,  
	j forIsPrime

ok:
	div $s1,$s7            # div n / i to get mod 
	mfhi $s3               # save to residue
	add $s7,$s7,2          # increase by two
	beq $s3,0,end          # if residue equals 0 to end
	# la $s4,0               # 			  			  	
 	
isOdd:
	
	lb $t0, constant_two   # Load $t1 with value 2
	div $t1,$t0            # div input to 2 
	mfhi $t2               # save residue in $t2
	bne $t2, 0, forIsPrime         # if residue different 0 return 1 o true 
	jr $ra




Lu:
	la $t4,1
	li $v0,4
 	la $a0, breakpoint
 	syscall
	li $v0, 1
 	lb $a0, aux
 	syscall
 	li $t4,0
 	
 	add $s6,$s6,1
 	
	j start

endEnd:
	li $v0,4
 	la $a0, breakpoint
 	syscall
 	
 	li $v0,4
 	la $a0, message
 	syscall
 	
	li $v0, 1
 	la $a0, ($s6)
 	
 	syscall 
 	
	li $v0,10
	syscall 

 	

start:
	lb  $t0,aux
	lw  $t1, number_v
	blt $t0,$t1,L2
	beq $t0,$t1,endEnd
	

L2:		
	
	add $t0,$t0,1
	sb  $t0,aux
	
	
	#li $v0, 1
 	#la $a0, ($t0)
 	#syscall 
 	
	#la $t1,($t0)         # load value i in to $t1
	la $t1,($t0)
	lb  $s7,constant_tree               # start en tree to count
	j isPrime
		
	j start              # call function
	
end:	
	#li $v0, 1
 	#lb $a0, aux
 	#syscall
 	li $t4,0
	j start
	
	
		

			
	
	
	
	
	
	
 	
 	