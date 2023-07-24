


# 先讲指针的算术运算，有利用理解`&a+1`

>
> https://www.runoob.com/cplusplus/cpp-pointer-arithmetic.html
>
> 
>




# 数组名 a 和 &a 的区别



>
> https://blog.csdn.net/wanwenweifly4/article/details/6424058
>
> `a`和`&a`
>
> > `a`并不是普通变量名，而是数组名，所以`&a`并不表示取`a`的存储地址
> > 
> > `a`和`&a`只是在数值上相同
> > 
> > `a+1`表示的是数组第一个元素地址, 即`a + i = &a[i]`
> > 
> > `&a+1`表示的是跨过a数组的下一个地址`&a + i = &a[0] + sizeof(a[0]) * a_len * i `
>
> 
> `a` 和 `&a[0]` 一样
>
> 
> `a` 和 `&a[0]` 和 `&a` 只是数值相同，
> 
> > 但是 `a` 和 `&a[0]` 本质上相同，是指向数组的第一个元素的指针， `a = &a[0]`
> > 
> > `&a` 本质上是指向整个数组
> 
> 













# *a 和 *&a区别（c++传值）

>
> https://blog.csdn.net/weixin_42889479/article/details/81437659
>




















