;******************************************************************************
;* Operating-System Construction                                              *
;*----------------------------------------------------------------------------*
;*                                                                            *
;*                               T O C . A S M                                *
;*                                                                            *
;*----------------------------------------------------------------------------*
;*
;******************************************************************************

%include "machine/toc.inc"

; EXPORTED FUNCTIONS

[GLOBAL toc_switch]
[GLOBAL toc_go]

; FUNCTION IMPLEMENTATIONS

[SECTION .text]

; TOC_GO: Starts the very first process.
;
; C prototype: void toc_go(struct toc* regs);

toc_go:
; Add your code here 
mov rbx, [rdi]
mov r12, [rdi+8] 
mov r13, [rdi+16]
mov r14, [rdi+24]
mov r15, [rdi+32]
mov rbp, [rdi+40]
mov rsp, [rdi+48]

ret

; TOC_SWITCH: Context switch. Saves the current register values and replaces
;             them with values of the new "thread of control".
;
; C prototype: void toc_switch (struct toc* regs_now,
;                               struct toc* reg_then);

toc_switch:
; Add your code here 
mov [rdi], rbx
mov [rdi+8], r12
mov [rdi+16], r13
mov [rdi+24], r14
mov [rdi+32], r15
mov [rdi+40], rbp
mov [rdi+48], rsp 

mov rbx, [rsi]
mov r12, [rsi+8] 
mov r13, [rsi+16]
mov r14, [rsi+24]
mov r15, [rsi+32]
mov rbp, [rsi+40]
mov rsp, [rsi+48]

ret
