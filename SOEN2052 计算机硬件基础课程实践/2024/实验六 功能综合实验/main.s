/*=====================================================================
// �ļ����ƣ�main.s
// ���ܸ�Ҫ��������Ա�̣����ù���GPIO��ʵ�ֺ��̽�����˸
// ��Ȩ���У��մ�Ƕ��ʽ(sumcu.suda.edu.cn)
// �汾���£�20220102-20240301
//=====================================================================*/

.include "includes.inc"    /* ���������ͷ�ļ� */
#define MAINLOOP_COUNT 1000

/* �������ݶ� ==================== */
.section .data       /* �������ݶ� */
hello_information:
    .ascii "\n"
    .ascii "-----------------------------------------------------------------\n"
    .ascii "����«��ʾ��                                                   \n"
    .ascii "���������ơ�RISC-V��๤�̿�ܣ�GPIO��UART��������������          \n"
    .ascii "�������ܡ�ʵ�ֺ��̽�����˸�Ĺ���                              \n"
    .ascii "----------------------------------------------------------------\n\0"
printf_format1:
    .ascii "��ǰ��˸������%d\n\0"
printf_format2:
    .ascii "��ǰ��״̬��%s\n\0"
state_red:     .ascii "RED\n\0"
state_green:   .ascii "GREEN\n\0"

.align 4
mMainLoopCount: .word 0   /* ��ѭ���������� */
mLigtCount:     .word 0   /* ��˸���� */
mLightState:    .word 0   /* ��ǰ��״̬��0=�죬1=�� */

/* �������� ==================== */
.section .text
.type main function
.global main

main:
    /* ��ʼ������ */
    addi sp, sp, -48              /* ����ջ�ռ� */
    la a0, hello_information      /* ���������ʼ����Ϣ */
    call printf
    /* ��ʼ��GPIO������ */
    li a0, LIGHT_RED
    li a1, GPIO_OUTPUT
    li a2, LIGHT_OFF
    call gpio_init
    li a0, LIGHT_GREEN
    call gpio_init
    /* ��ʼ������ */
    li a0, UART_User
    li a1, 115200
    call uart_init
    li a0, UART_User
    call uart_enable_re_int

main_loop:
    /* ��ѭ�������߼� */
    la a5, mMainLoopCount
    lw t1, 0(a5)
    addi t1, t1, 1
    sw t1, 0(a5)
    li t2, MAINLOOP_COUNT
    bltu t1, t2, main_loop        /* δ�ﵽѭ������Ҫ�󣬼���ѭ�� */
    li t1, 0
    sw t1, 0(a5)                  /* ������ѭ������ */

    /* �л���״̬�߼� */
    la a5, mLightState
    lw t1, 0(a5)
    li t2, 0                      /* ���״̬ */
    beq t1, t2, light_red
    li t2, 1                      /* �̵�״̬ */
    beq t1, t2, light_green

light_red:
    li a0, LIGHT_GREEN           /* �ر��̵� */
    li a1, LIGHT_OFF
    call gpio_set
    li a0, LIGHT_RED             /* ������� */
    li a1, LIGHT_ON
    call gpio_set
    la a0, printf_format2        /* ���״̬��Ϣ */
    la a1, state_red
    call printf
    j update_state

light_green:
    li a0, LIGHT_RED             /* �رպ�� */
    li a1, LIGHT_OFF
    call gpio_set
    li a0, LIGHT_GREEN           /* �����̵� */
    li a1, LIGHT_ON
    call gpio_set
    la a0, printf_format2        /* ���״̬��Ϣ */
    la a1, state_green
    call printf
    j update_state

update_state:
    /* ���µ�״̬ */
    la a5, mLightState
    lw t1, 0(a5)
    li t2, 0                      /* ���״̬ */
    beq t1, t2, set_green_state   /* �����ǰ�Ǻ�ƣ��л�Ϊ�̵� */
    li t2, 1                      /* �̵�״̬ */
    beq t1, t2, set_red_state     /* �����ǰ���̵ƣ��л�Ϊ��� */

set_green_state:
    li t1, 1                      /* ����Ϊ�̵�״̬ */
    sw t1, 0(a5)
    j update_finish

set_red_state:
    li t1, 0                      /* ����Ϊ���״̬ */
    sw t1, 0(a5)

update_finish:
    /* ������˸���� */
    la a5, mLigtCount
    lw t1, 0(a5)
    addi t1, t1, 1
    sw t1, 0(a5)
    la a0, printf_format1
    lw a1, 0(a5)
    call printf

    j main_loop                 /* ������ѭ�� */

    /* �ͷ�ջ���˳� */
    addi sp, sp, 48
    ret