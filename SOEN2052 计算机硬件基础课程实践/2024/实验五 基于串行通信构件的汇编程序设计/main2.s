/*=====================================================================
//文件名称：main.s
//功能概要：汇编语言编程，调用构件GPIO，实现红灯闪烁，且通过串口控制红灯亮灭
//版权所有：苏大嵌入式(sumcu.suda.edu.cn)
//版本更新：20220102-20240301
//=====================================================================*/

.include "includes.inc"    /* 包含汇编总头文件 */

/* 定义数据段，即data段（RAM区域，变量使用的区域）=================== */
.section .data       /* 定义数据段 */
hello_information:   /* 定义字符串，标号即为字符串首地址，\0为结束标志  */
    .ascii "\n"
    .ascii "-----------------------------------------------------------------\n"
    .ascii "★金葫芦提示★                                                   \n"
    .ascii "【中文名称】RISC-V汇编工程框架（GPIO、UART构件测试样例）          \n"
    .ascii "【程序功能】这个样例是在GPIO构件样例基础上增加串口中断             \n"
    .ascii "【硬件连接】见本工程05_UserBoard文件夹下user.inc文件              \n"
    .ascii "【操作说明】通过本IDE菜单栏“工具”→“串口工具”，                \n"
    .ascii "                   打开用户串口 ，接收MCU发来的字节               \n"
    .ascii "----------------------------------------------------------------\n\0"
printf_format1:           /* 定义一个printf使用的数据格式控制符 */
    .ascii "闪烁次数mLightCount =\0"
printf_format2:           /* 定义一个printf使用的数据格式控制符 */
    .ascii "%d\n\0"       /* 一个参数，十进制 */
printf_format3:    
     .ascii "LIGHT_RED:ON--\n\0"
printf_format4:    
     .ascii "LIGHT_RED:OFF--\n\n\0"  
     
.align 4                  /* 对齐 */
mMainLoopCount:           /* 主循环次数变量（主循环临时变量以m为前缀）*/
    .word 0               /* 初值为0 */
.align 2    
mLigtCount:               /* 灯的状态切换次数*/
    .half 0  
.align 1      
mFlag:                    /* 灯的状态标志 */
    .byte 'A'             /* 初值为'A'（暗） */

/* 定义代码段，即Falsh区域，存放代码、常数=========================== */
.section  .text           /* 定义代码段 */
.type main function       /* 声明下面的main标号为函数类型  */
.global main              /* 声明下面的main标号为全局函数，便于初始化调用 */
.align 2                  /* 指令和数据采用2字节对齐，兼容16位指令集 */

/*主函数，一般情况下可以认为程序从此开始运行（实际上有启动过程）------ */
main:
    /*【1】启动部分（开头）========================================== */
    /*（1.1）申请栈空间及串口输出提示 */
    addi sp,sp,-48              /* 申请栈空间 */
                                /* 通过调试串口输出提示 */
    la a0,hello_information     /* 参数a0：串口号 */
    call printf                 /* 调用函数 */ 
    /*（1.2）用户外设模块初始化 */
                                /* 初始化GPIO（红灯），三个参数 */
    li a0,LIGHT_RED             /* 第1参数a0：红灯引脚 */ 
    li a1,GPIO_OUTPUT           /* 第2参数a1：定义为输出 */
    li a2,LIGHT_OFF             /* 第3参数a2：初始状态 */
    call gpio_init              /* 调用函数 */
                                /* 初始化串口UART_User */
    li a0,UART_User             /* 第1参数a0：串口号 */
    li a1,115200                /* 第2参数a1：波特率 */
    call uart_init              /* 调用函数 */
    /*（1.3）使能模块中断 */
                                /* 使能UART_User串口接收中断 */
    li a0,UART_User             /* 只有一个参数a0：串口号 */
    call uart_enable_re_int
    /* 【1】启动部分（结尾）======================================== */
	
/*【2】主循环部分（开头）=========================================== */
main_loop: 
    /*（2.1）读取串口数据 */
    li a0,UART_User             /* 串口号 */
    li a1,0                     /* 成功标志初始化为0 */
    call uart_re1               /* 调用uart_re1读取一个字节 */
    
    /* 判断是否接收成功 */
    bnez a1,main_loop           /* 如果接收失败（a1 != 1），继续循环 */
    
    move t0, a0                 /* 将接收到的字符存入 t0 */
    
    /* 判断接收到的字符，并控制灯的状态 */
    li t1, 'R'                  /* 如果字符是 'R' */
    beq t0, t1, turn_on_red_light
    
    li t1, 'r'                  /* 如果字符是 'r' */
    beq t0, t1, turn_off_red_light
    
    j main_loop                 /* 如果字符不是 'R' 或 'r'，继续循环 */
    
turn_on_red_light:
    /* 红灯亮 */
    li a0, LIGHT_RED            /* 第1参数a0：红灯引脚 */
    li a1, LIGHT_ON             /* 第2参数a1：灯的状态 */
    call gpio_set               /* 控制红灯亮 */
    la a0, printf_format3       /* 输出提示“红灯亮” */
    call printf
    j main_loop                 /* 返回主循环 */
    
turn_off_red_light:
    /* 红灯灭 */
    li a0, LIGHT_RED            /* 第1参数a0：红灯引脚 */
    li a1, LIGHT_OFF            /* 第2参数a1：灯的状态 */
    call gpio_set               /* 控制红灯灭 */
    la a0, printf_format4       /* 输出提示“红灯灭” */
    call printf
    j main_loop                 /* 返回主循环 */

/*【2】主循环部分（结尾）=========================================== */
    /* 从栈恢复现场（即使运行不到这里，每一个函数将栈恢复） */
    addi sp, sp, 48             /* 释放栈帧 */