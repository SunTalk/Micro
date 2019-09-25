.equ num ,100

.section .rodata
.align 2

prime:
    .space num*4                    ! int prime[100]

.str1:
    .string "%d "
    .text
.str2:
    .string "\n"
    .text
    .global main

main:
    movi   $r9, 1                   ! r9 = i = 1
    la     $r8, prime               ! r8 = prime address
    movi  $r10, 1

.set_prime:

    sw    $r10, [$r8+($r9<<2)]      ! prime[i] = 1
    addi   $r9, $r9, 1              ! i++
    move   $r7, $r9
    sltsi  $r7, $r7, num            ! i < 100
    bnez   $r7, .set_prime

    ! end set_prime

    movi   $r9, 2                   ! r9 = i = 2
    movi   $r4, 1                   ! r4 = 1
    movi   $r6, 0                   ! int k = 0

.Loop1:
    move   $r7, $r9
    sltsi  $r7, $r7, num            ! i < 100
    beqz   $r7, .finish             
    lw    $r10, [$r8+($r9<<2)]      ! r10 = prime[i]
    movi   $r4, 1
    beq   $r10, $r4, .Loop2         ! if( prime[i] )
    addi   $r9, $r9, 1              ! i++
    b         .Loop1

.Loop2:
    move   $r3, $r9                 ! int j = i
    add    $r3, $r3, $r9            ! j = j + i
    movi   $r5, 0

.sieve:
    move   $r7, $r3
    sltsi  $r7, $r7, num            ! j < 100
    beqz   $r7, .print_prime           
    sw     $r5, [$r8+($r3<<2)]      ! prime[j] = 0
    add    $r3, $r3, $r9            ! j = j + i
    b   .sieve

.print_prime:
    move   $r1, $r9
    la     $r0, .str1
    bal printf                      ! printf("%d ",i)
    addi   $r9, $r9, 1              ! i++
    addi   $r6, $r6, 1              ! k++
    movi   $r4, 10
    divsr  $r1, $r2, $r6, $r4       ! if( k%10 == 0 )
    beqz   $r2, .print_enter
    b   .Loop1

.print_enter:
    la     $r0, .str2
    bal printf                      ! printf("\n")
    b   .Loop1

.finish:
    ret
    .end