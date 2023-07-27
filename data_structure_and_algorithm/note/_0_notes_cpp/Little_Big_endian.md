# 大端模式、小端模式


>
> 小端字节序（Little-endian）：高字节数据存放在高地址，低字节数据存放在低地址。
> 
> 大端字节序（Big-endian）：低字节数据存放在高地址，高字节数据存放在低地址。 
>
> <font color="gree">人类读写数据习惯是大端字节序，大数据先读，小数据后读。所以小端是反人类的方式</font>
> 
> <font color="yellow">小端是反人类的方式, 但是更适合机器</font>
>
> 常见的处理器大小端架构：
> > STM32、ARM、Intel-X86都采用小端模式， IBM采用大端模式
> 
> 网络通讯协议采用的是Big-Endian
>
> 
>

>
> <font color="yellow">谁更好？</font>
> 
> 小端模式：强制类型转换数据不需要调整字节内容。
> 
> 大端模式：符号位判断固定为第一个字节，容易判断正负，便于人类阅读。
> 
> 总结：`大小端没有谁更优更劣，各种优点就是对方劣势`。
>
> 



> 
> <font color="yellow">如何代码判断大小端</font>
> 
> https://blog.csdn.net/kingforyang/article/details/116271717
> 








