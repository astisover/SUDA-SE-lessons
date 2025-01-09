/*=====================================================================
//文件名称：main.s
//功能概要：汇编语言编程，调用构件GPIO，实现红、绿、蓝三色灯的组合控制
//版权所有：苏大嵌入式(sumcu.suda.edu.cn)
//版本更新：20220102-20240301
//=====================================================================*/

.include "includes.inc"    /* 包含汇编总头文件 */

/* 定义数据段，即data段（RAM区域，变量使用的区域）=================== */
.section .data       
hello_information:   
    .ascii "\n"
    .ascii "-----------------------------------------------------------------\n"
    .ascii "★金葫芦提示★                                                   \n"
    .ascii "【中文名称】RISC-V汇编工程框架（GPIO、UART构件测试样例）          \n"
    .ascii "【程序功能】这个样例是在GPIO构件样例基础上增加串口中断             \n"
    .ascii "【硬件连接】见本工程05_UserBoard文件夹下user.inc文件              \n"
    .ascii "【操作说明】通过本IDE菜单栏“工具”→“串口工具”，                \n"
    .ascii "                   打开用户串口 ，接收MCU发来的字节               \n"
    .ascii "----------------------------------------------------------------\n\0"

printf_format1:           
    .ascii "接收到的命令: %c\n\0" /* 格式控制符用于显示接收到的字符 */
    
/* 定义代码段，即Flash区域，存放代码、常数=========================== */
.section  .text           
.type main function       
.global main              
.align 2                  

/* 主函数 */
main:
    /*【1】启动部分 */
    addi sp, sp, -48              /* 申请栈空间 */
    la a0, hello_information     /* 输出启动信息 */
    call printf                 /* 调用函数 */

    /* 初始化GPIO（红灯、绿灯、蓝灯） */
    li a0, LIGHT_RED             
    li a1, GPIO_OUTPUT           
    li a2, LIGHT_OFF             
    call gpio_init              /* 初始化红灯 */

    li a0, LIGHT_GREEN          
    li a1, GPIO_OUTPUT           
    li a2, LIGHT_OFF             
    call gpio_init              /* 初始化绿灯 */

    li a0, LIGHT_BLUE           
    li a1, GPIO_OUTPUT           
    li a2, LIGHT_OFF             
    call gpio_init              /* 初始化蓝灯 */

    /* 初始化串口UART */
    li a0, UART_User             
    li a1, 115200                
    call uart_init              

    li a0, UART_User             
    call uart_enable_re_int      /* 启用串口接收中断 */

main_loop: 
    /* 读取串口数据 */
    li a0, UART_User             
    li a1, 0                     
    call uart_re1               /* 读取一个字节 */
    
    /* 判断接收是否成功 */
    bnez a1, main_loop           /* 如果接收失败，继续循环 */
    
    move t0, a0                 /* 将接收到的字符存入 t0 */
    
    /* 判断接收到的字符，并控制灯的状态 */
    li t1, 'R'                  /* 如果字符是 'R' */
    beq t0, t1, turn_on_red_light
    
    li t1, 'r'                  /* 如果字符是 'r' */
    beq t0, t1, turn_off_red_light

    li t1, 'G'                  /* 如果字符是 'G' */
    beq t0, t1, turn_on_green_light

    li t1, 'g'                  /* 如果字符是 'g' */
    beq t0, t1, turn_off_green_light

    li t1, 'B'                  /* 如果字符是 'B' */
    beq t0, t1, turn_on_blue_light

    li t1, 'b'                  /* 如果字符是 'b' */
    beq t0, t1, turn_off_blue_light

    li t1, 'Y'                  /* 如果字符是 'Y' */
    beq t0, t1, turn_on_yellow_light  /* 黄灯（红+绿） */

    li t1, 'y'                  /* 如果字符是 'y' */
    beq t0, t1, turn_off_yellow_light

    li t1, 'M'                  /* 如果字符是 'M' */
    beq t0, t1, turn_on_magenta_light  /* 紫色（红+蓝） */

    li t1, 'm'                  /* 如果字符是 'm' */
    beq t0, t1, turn_off_magenta_light

    li t1, 'C'                  /* 如果字符是 'C' */
    beq t0, t1, turn_on_cyan_light    /* 青色（绿+蓝） */

    li t1, 'c'                  /* 如果字符是 'c' */
    beq t0, t1, turn_off_cyan_light

    li t1, 'W'                  /* 如果字符是 'W' */
    beq t0, t1, turn_on_white_light  /* 白色（红+绿+蓝） */

    li t1, 'w'                  /* 如果字符是 'w' */
    beq t0, t1, turn_off_white_light

    j main_loop                 /* 返回主循环 */
    
turn_on_red_light:
    li a0, LIGHT_RED            /* 红灯引脚 */
    li a1, LIGHT_ON             /* 灯的状态 */
    call gpio_set               /* 控制红灯亮 */
    la a0, printf_format1       
    call printf                 /* 输出接收到的字符 */
    j main_loop                 /* 返回主循环 */
    
turn_off_red_light:
    li a0, LIGHT_RED            /* 红灯引脚 */
    li a1, LIGHT_OFF            /* 灯的状态 */
    call gpio_set               /* 控制红灯灭 */
    la a0, printf_format1       
    call printf                 /* 输出接收到的字符 */
    j main_loop                 /* 返回主循环 */
    
turn_on_green_light:
    li a0, LIGHT_GREEN          /* 绿灯引脚 */
    li a1, LIGHT_ON             /* 灯的状态 */
    call gpio_set               /* 控制绿灯亮 */
    la a0, printf_format1       
    call printf                 /* 输出接收到的字符 */
    j main_loop                 /* 返回主循环 */

turn_off_green_light:
    li a0, LIGHT_GREEN          /* 绿灯引脚 */
    li a1, LIGHT_OFF            /* 灯的状态 */
    call gpio_set               /* 控制绿灯灭 */
    la a0, printf_format1       
    call printf                 /* 输出接收到的字符 */
    j main_loop                 /* 返回主循环 */
    
turn_on_blue_light:
    li a0, LIGHT_BLUE           /* 蓝灯引脚 */
    li a1, LIGHT_ON             /* 灯的状态 */
    call gpio_set               /* 控制蓝灯亮 */
    la a0, printf_format1       
    call printf                 /* 输出接收到的字符 */
    j main_loop                 /* 返回主循环 */

turn_off_blue_light:
    li a0, LIGHT_BLUE           /* 蓝灯引脚 */
    li a1, LIGHT_OFF            /* 灯的状态 */
    call gpio_set               /* 控制蓝灯灭 */
    la a0, printf_format1       
    call printf                 /* 输出接收到的字符 */
    j main_loop                 /* 返回主循环 */

turn_on_yellow_light:          /* 黄灯（红 + 绿） */
    li a0, LIGHT_RED            /* 红灯引脚 */
    li a1, LIGHT_ON             /* 灯的状态 */
    call gpio_set               /* 控制红灯亮 */
    li a0, LIGHT_GREEN          /* 绿灯引脚 */
    li a1, LIGHT_ON             /* 灯的状态 */
    call gpio_set               /* 控制绿灯亮 */
    la a0, printf_format1       
    call printf                 /* 输出接收到的字符 */
    j main_loop                 /* 返回主循环 */

turn_off_yellow_light:
    li a0, LIGHT_RED            /* 红灯引脚 */
    li a1, LIGHT_OFF            /* 灯的状态 */
    call gpio_set               /* 控制红灯灭 */
    li a0, LIGHT_GREEN          /* 绿灯引脚 */
    li a1, LIGHT_OFF            /* 灯的状态 */
    call gpio_set               /* 控制绿灯灭 */
    la a0, printf_format1       
    call printf                 /* 输出接收到的字符 */
    j main_loop                 /* 返回主循环 */

turn_on_magenta_light:         /* 紫色（红 + 蓝） */
    li a0, LIGHT_RED            /* 红灯引脚 */
    li a1, LIGHT_ON             /* 灯的状态 */
    call gpio_set               /* 控制红灯亮 */
    li a0, LIGHT_BLUE           /* 蓝灯引脚 */
    li a1, LIGHT_ON             /* 灯的状态 */
    call gpio_set               /* 控制蓝灯亮 */
    la a0, printf_format1       
    call printf                 /* 输出接收到的字符 */
    j main_loop                 /* 返回主循环 */

turn_off_magenta_light:
    li a0, LIGHT_RED            /* 红灯引脚 */
    li a1, LIGHT_OFF            /* 灯的状态 */
    call gpio_set               /* 控制红灯灭 */
    li a0, LIGHT_BLUE           /* 蓝灯引脚 */
    li a1, LIGHT_OFF            /* 灯的状态 */
    call gpio_set               /* 控制蓝灯灭 */
    la a0, printf_format1       
    call printf                 /* 输出接收到的字符 */
    j main_loop                 /* 返回主循环 */

turn_on_cyan_light:            /* 青色（绿 + 蓝） */
    li a0, LIGHT_GREEN          /* 绿灯引脚 */
    li a1, LIGHT_ON             /* 灯的状态 */
    call gpio_set               /* 控制绿灯亮 */
    li a0, LIGHT_BLUE           /* 蓝灯引脚 */
    li a1, LIGHT_ON             /* 灯的状态 */
    call gpio_set               /* 控制蓝灯亮 */
    la a0, printf_format1       
    call printf                 /* 输出接收到的字符 */
    j main_loop                 /* 返回主循环 */

turn_off_cyan_light:
    li a0, LIGHT_GREEN          /* 绿灯引脚 */
    li a1, LIGHT_OFF            /* 灯的状态 */
    call gpio_set               /* 控制绿灯灭 */
    li a0, LIGHT_BLUE           /* 蓝灯引脚 */
    li a1, LIGHT_OFF            /* 灯的状态 */
    call gpio_set               /* 控制蓝灯灭 */
    la a0, printf_format1       
    call printf                 /* 输出接收到的字符 */
    j main_loop                 /* 返回主循环 */

turn_on_white_light:           /* 白色（红 + 绿 + 蓝） */
    li a0, LIGHT_RED            /* 红灯引脚 */
    li a1, LIGHT_ON             /* 灯的状态 */
    call gpio_set               /* 控制红灯亮 */
    li a0, LIGHT_GREEN          /* 绿灯引脚 */
    li a1, LIGHT_ON             /* 灯的状态 */
    call gpio_set               /* 控制绿灯亮 */
    li a0, LIGHT_BLUE           /* 蓝灯引脚 */
    li a1, LIGHT_ON             /* 灯的状态 */
    call gpio_set               /* 控制蓝灯亮 */
    la a0, printf_format1       
    call printf                 /* 输出接收到的字符 */
    j main_loop                 /* 返回主循环 */

turn_off_white_light:
    li a0, LIGHT_RED            /* 红灯引脚 */
    li a1, LIGHT_OFF            /* 灯的状态 */
    call gpio_set               /* 控制红灯灭 */
    li a0, LIGHT_GREEN          /* 绿灯引脚 */
    li a1, LIGHT_OFF            /* 灯的状态 */
    call gpio_set               /* 控制绿灯灭 */
    li a0, LIGHT_BLUE           /* 蓝灯引脚 */
    li a1, LIGHT_OFF            /* 灯的状态 */
    call gpio_set               /* 控制蓝灯灭 */
    la a0, printf_format1       
    call printf                 /* 输出接收到的字符 */
    j main_loop                 /* 返回主循环 */

/* 从栈恢复现场 */
    addi sp, sp, 48                   /* 释放栈帧 */
    ret                               /* 返回 */
