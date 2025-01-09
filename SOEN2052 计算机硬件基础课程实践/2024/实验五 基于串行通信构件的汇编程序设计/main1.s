/*=====================================================================
//�ļ����ƣ�main.s
//���ܸ�Ҫ��������Ա�̣����ù���GPIO��ʵ�ֺ졢�̡�����ɫ�Ƶ���Ͽ���
//��Ȩ���У��մ�Ƕ��ʽ(sumcu.suda.edu.cn)
//�汾���£�20220102-20240301
//=====================================================================*/

.include "includes.inc"    /* ���������ͷ�ļ� */

/* �������ݶΣ���data�Σ�RAM���򣬱���ʹ�õ�����=================== */
.section .data       
hello_information:   
    .ascii "\n"
    .ascii "-----------------------------------------------------------------\n"
    .ascii "����«��ʾ��                                                   \n"
    .ascii "���������ơ�RISC-V��๤�̿�ܣ�GPIO��UART��������������          \n"
    .ascii "�������ܡ������������GPIO�����������������Ӵ����ж�             \n"
    .ascii "��Ӳ�����ӡ���������05_UserBoard�ļ�����user.inc�ļ�              \n"
    .ascii "������˵����ͨ����IDE�˵��������ߡ��������ڹ��ߡ���                \n"
    .ascii "                   ���û����� ������MCU�������ֽ�               \n"
    .ascii "----------------------------------------------------------------\n\0"

printf_format1:           
    .ascii "���յ�������: %c\n\0" /* ��ʽ���Ʒ�������ʾ���յ����ַ� */
    
/* �������Σ���Flash���򣬴�Ŵ��롢����=========================== */
.section  .text           
.type main function       
.global main              
.align 2                  

/* ������ */
main:
    /*��1���������� */
    addi sp, sp, -48              /* ����ջ�ռ� */
    la a0, hello_information     /* ���������Ϣ */
    call printf                 /* ���ú��� */

    /* ��ʼ��GPIO����ơ��̵ơ����ƣ� */
    li a0, LIGHT_RED             
    li a1, GPIO_OUTPUT           
    li a2, LIGHT_OFF             
    call gpio_init              /* ��ʼ����� */

    li a0, LIGHT_GREEN          
    li a1, GPIO_OUTPUT           
    li a2, LIGHT_OFF             
    call gpio_init              /* ��ʼ���̵� */

    li a0, LIGHT_BLUE           
    li a1, GPIO_OUTPUT           
    li a2, LIGHT_OFF             
    call gpio_init              /* ��ʼ������ */

    /* ��ʼ������UART */
    li a0, UART_User             
    li a1, 115200                
    call uart_init              

    li a0, UART_User             
    call uart_enable_re_int      /* ���ô��ڽ����ж� */

main_loop: 
    /* ��ȡ�������� */
    li a0, UART_User             
    li a1, 0                     
    call uart_re1               /* ��ȡһ���ֽ� */
    
    /* �жϽ����Ƿ�ɹ� */
    bnez a1, main_loop           /* �������ʧ�ܣ�����ѭ�� */
    
    move t0, a0                 /* �����յ����ַ����� t0 */
    
    /* �жϽ��յ����ַ��������ƵƵ�״̬ */
    li t1, 'R'                  /* ����ַ��� 'R' */
    beq t0, t1, turn_on_red_light
    
    li t1, 'r'                  /* ����ַ��� 'r' */
    beq t0, t1, turn_off_red_light

    li t1, 'G'                  /* ����ַ��� 'G' */
    beq t0, t1, turn_on_green_light

    li t1, 'g'                  /* ����ַ��� 'g' */
    beq t0, t1, turn_off_green_light

    li t1, 'B'                  /* ����ַ��� 'B' */
    beq t0, t1, turn_on_blue_light

    li t1, 'b'                  /* ����ַ��� 'b' */
    beq t0, t1, turn_off_blue_light

    li t1, 'Y'                  /* ����ַ��� 'Y' */
    beq t0, t1, turn_on_yellow_light  /* �Ƶƣ���+�̣� */

    li t1, 'y'                  /* ����ַ��� 'y' */
    beq t0, t1, turn_off_yellow_light

    li t1, 'M'                  /* ����ַ��� 'M' */
    beq t0, t1, turn_on_magenta_light  /* ��ɫ����+���� */

    li t1, 'm'                  /* ����ַ��� 'm' */
    beq t0, t1, turn_off_magenta_light

    li t1, 'C'                  /* ����ַ��� 'C' */
    beq t0, t1, turn_on_cyan_light    /* ��ɫ����+���� */

    li t1, 'c'                  /* ����ַ��� 'c' */
    beq t0, t1, turn_off_cyan_light

    li t1, 'W'                  /* ����ַ��� 'W' */
    beq t0, t1, turn_on_white_light  /* ��ɫ����+��+���� */

    li t1, 'w'                  /* ����ַ��� 'w' */
    beq t0, t1, turn_off_white_light

    j main_loop                 /* ������ѭ�� */
    
turn_on_red_light:
    li a0, LIGHT_RED            /* ������� */
    li a1, LIGHT_ON             /* �Ƶ�״̬ */
    call gpio_set               /* ���ƺ���� */
    la a0, printf_format1       
    call printf                 /* ������յ����ַ� */
    j main_loop                 /* ������ѭ�� */
    
turn_off_red_light:
    li a0, LIGHT_RED            /* ������� */
    li a1, LIGHT_OFF            /* �Ƶ�״̬ */
    call gpio_set               /* ���ƺ���� */
    la a0, printf_format1       
    call printf                 /* ������յ����ַ� */
    j main_loop                 /* ������ѭ�� */
    
turn_on_green_light:
    li a0, LIGHT_GREEN          /* �̵����� */
    li a1, LIGHT_ON             /* �Ƶ�״̬ */
    call gpio_set               /* �����̵��� */
    la a0, printf_format1       
    call printf                 /* ������յ����ַ� */
    j main_loop                 /* ������ѭ�� */

turn_off_green_light:
    li a0, LIGHT_GREEN          /* �̵����� */
    li a1, LIGHT_OFF            /* �Ƶ�״̬ */
    call gpio_set               /* �����̵��� */
    la a0, printf_format1       
    call printf                 /* ������յ����ַ� */
    j main_loop                 /* ������ѭ�� */
    
turn_on_blue_light:
    li a0, LIGHT_BLUE           /* �������� */
    li a1, LIGHT_ON             /* �Ƶ�״̬ */
    call gpio_set               /* ���������� */
    la a0, printf_format1       
    call printf                 /* ������յ����ַ� */
    j main_loop                 /* ������ѭ�� */

turn_off_blue_light:
    li a0, LIGHT_BLUE           /* �������� */
    li a1, LIGHT_OFF            /* �Ƶ�״̬ */
    call gpio_set               /* ���������� */
    la a0, printf_format1       
    call printf                 /* ������յ����ַ� */
    j main_loop                 /* ������ѭ�� */

turn_on_yellow_light:          /* �Ƶƣ��� + �̣� */
    li a0, LIGHT_RED            /* ������� */
    li a1, LIGHT_ON             /* �Ƶ�״̬ */
    call gpio_set               /* ���ƺ���� */
    li a0, LIGHT_GREEN          /* �̵����� */
    li a1, LIGHT_ON             /* �Ƶ�״̬ */
    call gpio_set               /* �����̵��� */
    la a0, printf_format1       
    call printf                 /* ������յ����ַ� */
    j main_loop                 /* ������ѭ�� */

turn_off_yellow_light:
    li a0, LIGHT_RED            /* ������� */
    li a1, LIGHT_OFF            /* �Ƶ�״̬ */
    call gpio_set               /* ���ƺ���� */
    li a0, LIGHT_GREEN          /* �̵����� */
    li a1, LIGHT_OFF            /* �Ƶ�״̬ */
    call gpio_set               /* �����̵��� */
    la a0, printf_format1       
    call printf                 /* ������յ����ַ� */
    j main_loop                 /* ������ѭ�� */

turn_on_magenta_light:         /* ��ɫ���� + ���� */
    li a0, LIGHT_RED            /* ������� */
    li a1, LIGHT_ON             /* �Ƶ�״̬ */
    call gpio_set               /* ���ƺ���� */
    li a0, LIGHT_BLUE           /* �������� */
    li a1, LIGHT_ON             /* �Ƶ�״̬ */
    call gpio_set               /* ���������� */
    la a0, printf_format1       
    call printf                 /* ������յ����ַ� */
    j main_loop                 /* ������ѭ�� */

turn_off_magenta_light:
    li a0, LIGHT_RED            /* ������� */
    li a1, LIGHT_OFF            /* �Ƶ�״̬ */
    call gpio_set               /* ���ƺ���� */
    li a0, LIGHT_BLUE           /* �������� */
    li a1, LIGHT_OFF            /* �Ƶ�״̬ */
    call gpio_set               /* ���������� */
    la a0, printf_format1       
    call printf                 /* ������յ����ַ� */
    j main_loop                 /* ������ѭ�� */

turn_on_cyan_light:            /* ��ɫ���� + ���� */
    li a0, LIGHT_GREEN          /* �̵����� */
    li a1, LIGHT_ON             /* �Ƶ�״̬ */
    call gpio_set               /* �����̵��� */
    li a0, LIGHT_BLUE           /* �������� */
    li a1, LIGHT_ON             /* �Ƶ�״̬ */
    call gpio_set               /* ���������� */
    la a0, printf_format1       
    call printf                 /* ������յ����ַ� */
    j main_loop                 /* ������ѭ�� */

turn_off_cyan_light:
    li a0, LIGHT_GREEN          /* �̵����� */
    li a1, LIGHT_OFF            /* �Ƶ�״̬ */
    call gpio_set               /* �����̵��� */
    li a0, LIGHT_BLUE           /* �������� */
    li a1, LIGHT_OFF            /* �Ƶ�״̬ */
    call gpio_set               /* ���������� */
    la a0, printf_format1       
    call printf                 /* ������յ����ַ� */
    j main_loop                 /* ������ѭ�� */

turn_on_white_light:           /* ��ɫ���� + �� + ���� */
    li a0, LIGHT_RED            /* ������� */
    li a1, LIGHT_ON             /* �Ƶ�״̬ */
    call gpio_set               /* ���ƺ���� */
    li a0, LIGHT_GREEN          /* �̵����� */
    li a1, LIGHT_ON             /* �Ƶ�״̬ */
    call gpio_set               /* �����̵��� */
    li a0, LIGHT_BLUE           /* �������� */
    li a1, LIGHT_ON             /* �Ƶ�״̬ */
    call gpio_set               /* ���������� */
    la a0, printf_format1       
    call printf                 /* ������յ����ַ� */
    j main_loop                 /* ������ѭ�� */

turn_off_white_light:
    li a0, LIGHT_RED            /* ������� */
    li a1, LIGHT_OFF            /* �Ƶ�״̬ */
    call gpio_set               /* ���ƺ���� */
    li a0, LIGHT_GREEN          /* �̵����� */
    li a1, LIGHT_OFF            /* �Ƶ�״̬ */
    call gpio_set               /* �����̵��� */
    li a0, LIGHT_BLUE           /* �������� */
    li a1, LIGHT_OFF            /* �Ƶ�״̬ */
    call gpio_set               /* ���������� */
    la a0, printf_format1       
    call printf                 /* ������յ����ַ� */
    j main_loop                 /* ������ѭ�� */

/* ��ջ�ָ��ֳ� */
    addi sp, sp, 48                   /* �ͷ�ջ֡ */
    ret                               /* ���� */
