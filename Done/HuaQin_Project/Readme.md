# <center>**名称华清远见嵌入式项目实习**</center>

# 项目介绍
&emsp;大三期末华清远见的嵌入式实训项目, 本身项目的最终目的是做一个 **嵌入式语音识别+开关检测+uart+beep+led** 裸机编程项目, 但是最终由于语音识别确实太拉跨了(不是说我人拉跨, 是语音识别的技术太拉跨了, 我觉得本质上就是一个应用层的东西). 因此, 我只做了其他内容.

# 源码属性
include文件夹 -> 作为.h头文件包含, 所有自定义的函数&结构体<br>
src文件夹 -> 作为自己编写的所有函数的实体文件. 具体的函数都定义在src文件夹中<br>
start文件夹 -> 存放必要的.s .o文件

/*.c => 与裸机变成无关, 属于应用层面的编程, 即使没有这个文件, main文件夹里面的内容也能make

# 项目问题

使用最新版本的arm-linux-gcc无法编译. 必须使用arm-linux-gcc 4.3.2 才有编译成功的可能