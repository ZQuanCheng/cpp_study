
#### 

>
> https://www.lmlphp.com/user/64615/article/item/1436782/
> 
> <font color="yellow">
> 
> 在使用`函数`或者`仿函数`自定义比较方式时
>
> `std::sort`、`std::set`、`std::map`、`std::priority_queue`这几个是有区别的
>
> </font>
>
> <font color="gree">
>
> `sort`的默认排序为`less`，也就是说从小到大排序； 可以通过`函数`自己写
> 
> `map`默认是`less`，也就说用迭代器迭代的时候默认是小的排在前面；可以通过`仿函数`自己写
> 
> `set`默认是`less`，也就是说用迭代器迭代的时候是从小到大排序的。可以通过`仿函数`自己写
>
> </font>
> 
>
> <font color="pink">
> 
> 唯有`priority_queue`很特殊，
> 
> `priority_queue`默认是`less`，排序结果也是从小到大；可以通过`仿函数`自己写
>
> 但是因为`priority_queue`只能访问`top()`，即`队尾`，所以看起来先出队列的是最大的
>
> `priority_queue`类似于`stack`，而不是`queue`
> 
> </font>
>
> 
>
> 












