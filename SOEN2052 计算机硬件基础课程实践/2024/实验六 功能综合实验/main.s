/*=====================================================================
// 文件名称：main.s
// 功能概要：汇编语言编程，调用构件GPIO，实现红绿交替闪烁
// 版权所有：苏大嵌入式(sumcu.suda.edu.cn)
// 版本更新：20220102-20240301
//=====================================================================*/

.include "includes.inc"    /* 包含汇编总头文件 */
#define MAINLOOP_COUNT 1000

/* 定义数据段 ==================== */
.section .data       /* 定义数据段 */
hello_information:
    .ascii "\n"
    .ascii "-----------------------------------------------------------------\n"
    .ascii "★金葫芦提示★                                                   \n"
    .ascii "【中文名称】RISC-V汇编工程框架（GPIO、UART构件测试样例）          \n"
    .ascii "【程序功能】实现红绿交替闪烁的功能                              \n"
    .ascii "----------------------------------------------------------------\n\0"
printf_format1:
    .ascii "当前闪烁次数：%d\n\0"
printf_format2:
    .ascii "当前灯状态：%s\n\0"
state_red:     .ascii "RED\n\0"
state_green:   .ascii "GREEN\n\0"

.align 4
mMainLoopCount: .word 0   /* 主循环次数变量 */
mLigtCount:     .word 0   /* 闪烁次数 */
mLightState:    .word 0   /* 当前灯状态：0=红，1=绿 */

/* 定义代码段 ==================== */
.section .text
.type main function
.global main

main:
    /* 初始化部分 */
    addi sp, sp, -48              /* 申请栈空间 */
    la a0, hello_information      /* 串口输出初始化信息 */
    call printf
    /* 初始化GPIO灯引脚 */
    li a0, LIGHT_RED
    li a1, GPIO_OUTPUT
    li a2, LIGHT_OFF
    call gpio_init
    li a0, LIGHT_GREEN
    call gpio_init
    /* 初始化串口 */
    li a0, UART_User
    li a1, 115200
    call uart_init
    li a0, UART_User
    call uart_enable_re_int

main_loop:
    /* 主循环计数逻辑 */
    la a5, mMainLoopCount
    lw t1, 0(a5)
    addi t1, t1, 1
    sw t1, 0(a5)
    li t2, MAINLOOP_COUNT
    bltu t1, t2, main_loop        /* 未达到循环计数要求，继续循环 */
    li t1, 0
    sw t1, 0(a5)                  /* 重置主循环计数 */

    /* 切换灯状态逻辑 */
    la a5, mLightState
    lw t1, 0(a5)
    li t2, 0                      /* 红灯状态 */
    beq t1, t2, light_red
    li t2, 1                      /* 绿灯状态 */
    beq t1, t2, light_green

light_red:
    li a0, LIGHT_GREEN           /* 关闭绿灯 */
    li a1, LIGHT_OFF
    call gpio_set
    li a0, LIGHT_RED             /* 点亮红灯 */
    li a1, LIGHT_ON
    call gpio_set
    la a0, printf_format2        /* 输出状态信息 */
    la a1, state_red
    call printf
    j update_state

light_green:
    li a0, LIGHT_RED             /* 关闭红灯 */
    li a1, LIGHT_OFF
    call gpio_set
    li a0, LIGHT_GREEN           /* 点亮绿灯 */
    li a1, LIGHT_ON
    call gpio_set
    la a0, printf_format2        /* 输出状态信息 */
    la a1, state_green
    call printf
    j update_state

update_state:
    /* 更新灯状态 */
    la a5, mLightState
    lw t1, 0(a5)
    li t2, 0                      /* 红灯状态 */
    beq t1, t2, set_green_state   /* 如果当前是红灯，切换为绿灯 */
    li t2, 1                      /* 绿灯状态 */
    beq t1, t2, set_red_state     /* 如果当前是绿灯，切换为红灯 */

set_green_state:
    li t1, 1                      /* 设置为绿灯状态 */
    sw t1, 0(a5)
    j update_finish

set_red_state:
    li t1, 0                      /* 设置为红灯状态 */
    sw t1, 0(a5)

update_finish:
    /* 更新闪烁次数 */
    la a5, mLigtCount
    lw t1, 0(a5)
    addi t1, t1, 1
    sw t1, 0(a5)
    la a0, printf_format1
    lw a1, 0(a5)
    call printf

    j main_loop                 /* 返回主循环 */

    /* 释放栈并退出 */
    addi sp, sp, 48
    ret