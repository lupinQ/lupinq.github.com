    关系表达式作为条件时，应写为constant==variable，这样如果将==写成=时计算机可以报错。
    #include <sdio.h>先搜索库，再搜索当前目录
    返回值类型，函数声明：因为需要调用，所以需要声明，函数实现，函数声明一般放在头文件中，将函数声明全部包含进去。求绝对值的函数第一步是要考虑返回值类型，代码正确性跟写法很重要，每写一个函数都要去调试，此为增量式开发。
    int main()
    main函数的返回值的作用，看这个程序是否正常运行。显示声明，不能隐式声明，否则后患无穷！！
    通过函数指针，通过函数地址，直接调用为三种调用方式。
gcc只是一个外壳，不是编译器，它能够调用编译工具。gcc自动生成名为a.out的文件。 
-o 为output输出，gcc -o myabs myabs.c意为将文件编译输出为名为myabs的文件 源文件名为myabs.c
-o要与文件名myabs连在一起，此外可以任意调换顺序。
格式可以为gcc -o myabs myabs.c
          gcc myabs.c -o myabs
学习要主动！
gcc --help命令
运行myabs程序，输入./myabs
switch的用法，其中条件表达式中只能加‘整型’和‘字符型’,case后只能加常数，default用于将所有情况包括进去。break与case配合，可构建分支。
用{}括起来的语句叫做块语句，block
和if语句的区别：和case之后数值匹配（equal）时才执行，而if语句不如是。
while循环两种形式：while 和 do while
while格式
while(){
}
（）后接一条语句，或是一条块语句。

do-while格式
do 
{
}while()；
do-while至少执行一次

for循环
for(;;){}
for(;;);为无限循环。
for(初始化语句；条件控制表达式；主要用于累加){}
写法灵活，for和while能够100%等价。
break控制语句，跳出本层循环，跳出switch语句。
continue控制语句，提前结束本次循环，进行下次循环。
递归的定义，程序设计的技巧，函数调用自己本身。
使用递归的好处：使程序逻辑变得非常简洁，清晰。
递归和循环是等价的，用递归能实现的，用循环也能实现。
如何转换：不断改变实参的数值。
转换不是很关键，汇编等底层会碰到。
递归和循环在效率上的比较。
递归不断地开辟栈空间，栈空间有限。
当递归次数多时，将递归转换为循环。
标号，随心所欲写
标号代表标签后这个函数在存放中的开始地址。goto语句后加标签。
goto无条件跳转，只有在错误处理时才会用到goto.尽量不用goto.
流程图，用于分析程序结构。在同外行人交流时有用。
流程图的画法：
            开始，结束=>圆角矩形
            程序流=>箭头
            顺序结构=>矩形
            分支结构=>菱形
            循环结构=>菱形
有一类人是专门写代码的，有一类人是专门画流程图的。
练习：1.判断润年，打印出结果。包括参数的检查，函数签名的检查。能够被4，不能被100整除，能被400整除的年份。
      2.奇数求和，从1到99.
      3.for循环，100！有多少个零。
【题目】今天在网上看到一道题目：100！结果数值中末尾有几个0？

【分析】计算100！会溢出，所以使用将10分拆为10 =
2X5，在1~100中，寻找2的个数N(比如，4有两个2)，以及5的个数M，结果 X = M > N ? N
: M;

【图表分析】   现在只分析5，

                         1，2，3，4，5，6，...，25， ...，100

                         除以5后为：
                         0，0，0，0，1，0，...，5，...，20，此时有20个5

                         再对                 1，2，3，...，20进行同样计算：

                         除以5后为：    0，0，0，0，1，...，4，此时有4个

                         因为4 < 5，所以最终结果20 + 4 = 24；

                         同样验证1000!为：

                         1000/5 = 200

                         200/5 = 40

                         40/5 = 8

                         8/5 = 1

                         共计：200 + 40 + 8 + 1 = 249个0

                         同样考虑2，要远多于5的存在，

                         至此，完结
                        
    可以设想：先求出100!的值，然后数一下末尾有多少个零。事实上，与上题一样，由于计算机所能表示的整数范围有限，这是不可能的。
    为了解决这个问题，必须首先从数学上分析在100!结果值的末尾产生零的条件。不难看出：一个整数若含有一个因子5，则必然会在求100!时产生一个零。因此问题转化为求1到100这100个整数中包含了多少个因子5。若整数N能被25整除，则N包含2个因子5；若整数N能被5整除，则N包含1个因子5。
                         *程序说明与注释
                         #include<stdio.h>
                         int main()
                         {
                         int a,count =0;
                         for(a=5;a<=100;a+=5)
                         //循环从5开始，以5的倍数为步长，考察整数
                         {
                         ++count; //若为5的倍数，计数器加1
                         if(!(a%25)) ++count; //若为25的倍数，计数器再加1
                         }
                         printf("The number of 0 in the end of 100! is:
                         %d.\n",count); //打印结果
                         return 0;
                         }

                         *运行结果
                         The number of 0 in the end of 100! is: 24.
     *问题进一步讨论

    本题的求解程序是正确的，但是存在明显的缺点。程序中判断整数N包含多少个因子5的方法是与程序中的100有关的，若题目中的100改为1000，则就要修改程序中求因子5的数目的算法了。

     *思考题

    修改程序中求因子5的数目的算法，使程序可以求出任意N!的末尾有多少个零。


    单行注释//多行注释/**/
    编程时应注意添加可调用函数。
    scanf用法，注意取址运算符&，scanf的返回值是变量的地址值，若是格式控制符和变量的类型不符，则将变量类型强制转换成格式控制符所属类型。
    gdb调试工具，gcc c文件 -g -o 指定文件名，-g意为把调试信息输出到可执行文件中。
    输入help即输出gdb的帮助信息。
    运行程序如下：
    (gdb) help
    List of classes of commands:

    aliases -- Aliases of other commands
    breakpoints -- Making program stop at certain points
    data -- Examining data
    files -- Specifying and examining files
    internals -- Maintenance commands
    obscure -- Obscure features
    running -- Running the program
    stack -- Examining the stack
    status -- Status inquiries
    support -- Support facilities
    tracepoints -- Tracing of program execution without stopping the program
    user-defined -- User-defined commands

    Type "help" followed by a class name for a list of commands in that class.
    Type "help all" for the list of all commands.
    Type "help" followed by command name for full documentation.
    Type "apropos word" to search for commands related to "word".
    Command name abbreviations are allowed if unambiguous.
    (gdb) 
    help+子命令，查询各自类别的帮助。
    list
    列出源代码的命令，输出10行，再次输入list,再次输出10行。亦可回车，在gdb环境下输入回车意为再次执行前次操作。
    list 的缩写是l,输入l亦可执行list命令。
    l+行号，表示列出此行上下的10行内容，上下各5行。
    l+函数名，表示列出main上下共10行。
    输入q退出gdb.   
    start 将程序加载到内存中令其运行，启动程序后，停在第一个语句。
    next 缩写为n，单步执行，遇到函数时执行到底。跳出函数时，继续单步执行。
    run 执行到底，中间不停。缩写为r.
    step 单步执行，遇到函数时跳入函数内部单步执行。 
    finish 当进入调用函数单步执行，即执行step跳入函数中时，输入finish即可瞬间将调用函数执行完毕，停到调用函数后的第一条语句。
    i+locals 打印出当前函数的所有局部变量的值。缩写为i+loc
    backtrace 缩写为bt，用于显示嵌套函数的层数，即栈的层数，最里层函数位于栈顶，main永远位于栈底，内外层函数依次排列下去，开始显示为 #+序号，函数括号内部的赋值表达式表征参数的传递。main序号后的十六进制参数为main函数首地址。 
    frame+序号
    缩写为f，用于查看输入序号所代表的函数的层数和传递参数，貌似还有跳转到相应函数第一条语句的功能。
    备注：另外，如果用户处于main主函数中，尚未进入调用函数，那么输入bt后只显示main函数，序号为#0,此时如果输入f 1命令，则显示“#0  0x00000000 in ?? ()”类似提示。
    print+表达式 缩写为p+表达式，p不仅能打印表达式，变量还能打印数组。可以给当前运行程序的变量赋值。可以在调试程序时动态改变相应变量的值，不必再改动程序源代码或再次运行程序。
    set+var+表达式 专门改变变量值的指令。与print类似，只不过不打印。
    display+变量 用于观察执行过程中某个变量的值，单步执行时每次都显示此变量的值。单独检测某个变量的值。此变量在其生存期中会一直处于被检测状态。
    运行结果如下：
         (gdb) display n
         3: n = 134514011
    undisplay+序号 取消对于变量的检测。其上结果n：前对应的数字3即为变量序号。
    breakpoints 缩写为b,便于调试。单步执行的原理即为每条语句设置断点。b+行数
    设置断点位置。断点的第一种设置方法,b+行号；断点的第二种设置方法，b+子函数名称，停留在进入调用函数的第一条语句；第三种设置方法，断点+if 意为满足if条件后断点方能起作用。第四种设置方法，b+文件名:行号(查询断点的十种设置方法)   
    continue 缩写为c，即为一直执行程序。
    info b 缩写为i b，显示当前已经设置的断点。
    运行结果如下：
    (gdb) i b
    Num     Type           Disp Enb Address    What
    4       breakpoint     keep y   0x08048454 in main at 润年第一次修改.c:8
        breakpoint already hit 1 time
    
    disable+断点序号，缩写为dis+序号，使其断点停止活动，即将断点enable属性设为n.
    enable+断点序号，缩写为ena+序号，使其断点恢复活动，即将断点enable属性设为y.
    delete+断点序号，缩写为del+序号,删除断点。
    clear+行号，删除断点。
    clear+函数名，删除函数下第一个断点。
    continue 缩写为c,用n或是遇到断点时,执行c将会执行程序直到遇到下一个断点。
    最好用的调试方法是看代码，注释代码，执行printout.
    
    编码规范：
    标识符的命名，各公司均有各自不同的命名规范。
    空格 变量所在的表达式中各变量应有空格。
    声明和执行语句之间应该空一行，函数和函数之间空一行。
    main()   
    {
    }一般为黑客的写法，
   
    main(){   
    }一般为商业公司的写法。
   
    indent 格式化源文件的工具。indent --help 浏览indent用法
    indent -kr c文件 为编写indent作者的编码格式。
    indent -kr -i8 c文件 为老师的编码格式。
        
作业：
    1、1到200间不能被3整除的数输出，每行输出8个。
    2、有1、2、3、4，4个数字，请问能组成多少个互不相同且无重复数字的三位数，都是多少？格式化输出。
    3、打印1到100之间的所有素数。
    4、统计一下某字符串中某指定字符出现的次数。
    5、打印出半菱形。

数组
    
    数组的基本概念，数组属于向量类型。
    数组是一种特殊的复合类型，其内容在物理内存上是连续排列的。
    标量：单个数据
    向量：同类型数据的集合，也可以理解为标量的集合。
    
    如何定义一个数组。
    int a[];这种定义不合法，但不会报错。因为定义的目的是程序运行之前为数组分配存储空间。数组元素个数必为常量。有可能覆盖其他存储空间的内容。
    int foo(int n){
             int a[n];
    }
    这种写法是可以的，当程序运行至此，系统将为传递过来的实参开辟存储空间，传递过来即为常量。
    在n值很小时，允许，但当n值很大时，栈空间有限，容易发生错误。不推荐此种写法。    数组下标范围从0到n-1.
      
    在内存中的存放，连续存放，每个元素分配相应类型的存储空间。
    全局变量是在DS中分配存储空间的，函数内部的局部变量是在栈中分配存储空间的。
    最小的在高地址，最大的在低地址。
    
    初始化，当对数组不进行初始化时，默认全部清零。部分初始化时，未被赋值的全部清零，不可以跳转赋值。例如，a[10]={1,2,,4,};不合法
    int a[10]={[8]=1,[9]=9，};此为跳转赋值的合法方式，最后一个逗号可有可无。

    a[10]中a代表数组在内存空间中的首地址。a默认为不可更改的地址变量。
    a[10]中只有首地址能够作为实参进行函数间的传递，传进函数的是一个地址值。
    
    int sort(int a[10]){
        a++;
      }
      此种写法是正确的，此处函数的a非原函数的a.
      不能把数组当作返回值来返回。地址能够作为返回值来返回。
     int sort(int a[10]){
        a++;
        return a;
     }
      
     sizeof();括号内部的表达式可以是变量，也可以是字符串，还可以是数组地址值。
     sizeof("hello")值为6，sizeof算上\0.
     sizeof(函数名)值为1，sizeof(&函数名)值为 返回值类型所占字节*1
     sizeof(数组首地址)值为整个数组大小。
     sizeof(常量)值为常量所属类型所占字节数。
     sizeof(类型名)值为类型所占字节数。

多维数组，a[][]
     多维数组的初始化，a[10][2]={
                                 {1,2}
                                 {3,4}
                                 {5,6}
                                 {7,8}
                                 ……
                                 }
                       a[10][2]={1,2,3,4,5,6,7……}把多维空间看成扁平空间。
                       a[10][2]={ [1][2]=1,[2][4]=2,}跳转赋值的合法方式。
冒泡排序法
        下标最小的放在低地址，小标最大的放在高地址。
        随机函数rand(),rand()%10,得到0到9的随机数。

字符串
        实际上是将字符存入数组中，以‘\0’（表示数学上的0）结尾，null占0位，tab占11位，大写字母排列靠前，低八位存放ASCII码。A对应ASCII码为65，a对应ASCII码为97.
        a="hello"中a的值为"hello"的首地址,所以可以说表达式"hello"的值为字符串"hello"的首地址，"hello"[1]='e',字符串为常量，保存在代码段，只能读不能写，可以执行，data段能读能写，因此，"hello"[1]='a';是非法的。
       "hello"中有六个元素，不要忘记'\0'.a[6]="hello";
       a[5]="hello";printf("%s\n",a);输出结果为hello��，在存储时，只有找到'\0'，这个字符串才会停止输出，因此，会一直输出连续栈的内容。
       printf("%s\0\n",a);只输出hello.没有换行。
       \t制表符，缩进八个空格，
       \n\r表示在Windows下的换行，\n为在Linux下的换行，写出与平台无关的编码。
       \f换页，当成换行就可以了。
       \v垂直制表，竖着缩进。
       \'单引号，\"双引号，printf("\"hello\"");输出为"hello"
       %%百分号，\数字，查询的ASCII码值。
       
       字符串本来便是字符型数组，因此，可以如是初始化，char
       a[10]={'a','b',[5]='c','\0'};显式赋值，隐式赋值char a[10]={'a','b',};不提倡。
       char a[6]="hello";
       char b[6]={'h','e','l','l','o','\0'};
       以上两段字符串均可读可写，只不过a[]比b[]大，a是先在栈存储，然后复制到a[]的存储空间，而b是直接赋值到存储空间。
       printf("%s","hello");"hello"可以用变量替换，否则不如一下方式简便。
       printf("hello");
       strlen(a);用于测量a字符串中字符的个数，不包括'\0'.
       编写strlen()函数代码，
       const是constant常量的缩写，可用来修饰许多东西，保证传进来的实参不能改变。       main(const argc,char * argv[]),argc的含义，代表传进main函数的参数个数。
       ./test 321 435 12 234 命令中argc==5,代表传进5个参数。
       argv[]为保存传递进函数main中的参数内容的指针的数组,编程看结果。argv是指针数组的首地址。指针为一个指向内存空间的地址，32位机器总线有32根，指针保存内存地址，总是占有4个字节的空间。
       argv[]中存放的是指向传递进main函数的字符串参数的首地址的指针。
       代码如下：
       int main(int argc,char * argv[])
       {
        int i;
        for(i=0;i<argc;i++)
        printf()
       }
       atoi()函数，作为将字符串转换成整数的函数。
       约瑟夫环问题
       第一，保证开始计数的人i是活的。
       第二，次数m从1开始累加,直加到规定m次数，在此期间，人的序号应设置前向累加i++.
       第三，累加到m次，将数到m的第i个人标记，输出。
       第四，回到循环，继续累加。
       第五，设置k参数，记被标记人的个数。当k=n时，停止计数，退出循环。
     
     strcombine函数中对数组赋了两次'\0',导致段错误。

结构体
    复合类型，不是标量类型，概念。
    初始化,标准定义方法：
    struct complex{
        double x;
        double y;
    }
    在函数以外定义的变量为全局变量，在函数内部定义的变量为局部变量。
    struct complex{
        double x;
        double y;
    }z1,z2;
    int main(){}
    初始化
    struct complex{
            double x;
            double y;
            int a[4];
    }z1={0.1,3.2,1,2,3,4},z2;
    也可以如是初始化
     struct complex{
         double x;
         double y;
         int a[4];
      }z1={0.1,3.2,{1,2,3,4}},z2;
     合法初始化：
     struct complex{
       double x;
       double y;
       int a[4];
     }z1={0.1,3.2,{1,2,3,4}},z2={.y=2.0,.a[3]=5}; .意为属于结构体。

     定义结构体类型变量： struct complex z3;

     结构体的嵌套
     初始化方法一：
     struct complex{
        struct real{
           int b1;
           float b2;
        }m;
        double x;
        double y;
        int a[4];
     }
     初始化方法二：
       struct real{
          int b1;
          float b2;
          }
      struct complex{
              struct real m;
                double x;
                double y;
                int a[4];
            }
        初始化方法三：
        struct complex{
           struct real{
                int b1;
                float b2;
           };
           struct real bbb;
        
        };
        初始化方法四：
        struct complex{
           struct real *ccc
           struct real{
            int a;
            int b;
           };
        };当编译器能够确定其类型的分配空间时，便能够定义。指针所占空间大小一定，为完全类型complete type，因此可以被分配空间。
        不合法初始化：
        struct complex{
           struct real ccc
           struct real{
            int a;
            int b;
            };
         }z1;
       不合法初始化中因为ccc为不完全类型incomplete type，编译器找不到分配空间大小，因此不合法。
       嵌套定义最大定义三层，超过三层很少用到。人能够理解能力的上限，数据结构越复杂，就越不容易理解。

       访问成员
       z1.成员名
       z1.ccc(为指针变量，要求此指针变量先初始化，即有确定指向)->b1=0；
       结构体中不完全初始化时没有被初始化的变量全为0，而完全未初始化的结构体变量数据随机。指针在不进行初始化时值随机。
       结构体之间能否相互赋值？
       能，将内存空间对应字节进行赋值，有弊端：当结构体中存在指针，如果动态分配的内存在z1中被free掉，z2将失去对原空间的合法访问权，z2将成为野指针，因此应对z2重新赋值。z2也有自己的一块动态空间，与z1不重叠。只不过内容进行拷贝。
       动态内存分配，在内存中分配一块指定大小的内存空间。malloc()
       结构体进行赋值操作是为了存储公共信息。
       typedef用现有类型定义新类型的关键字，为现有类型起一别名。
       typedef int INT32;
       INT32 a;
       INT32为和int一样的类型名。
        第一种用法：
       struct complex{
        double x,y;
        };
        typedef struct complex complex_t(别名)；为结构体起别名。
        第二种用法：
        typedef struct complex{
            double x,y;
        }complex_t(别名);
        在complex_t后加_t是表明此为typedef定义出来的。
        标准用法：
        typedef struct{double x,y;}complex_t;
        以放情不自禁地如下定义：complex z1;
        struct{double x,y;}z1;匿名结构体.
        struct complex{struct{double x,y;}z1;};
        匿名结构体通常嵌套在其他结构体，只能引用，不能用它定义其他变量，内部结构不公开，使用匿名结构体是一种常用的封装方法。
        
        定义结构体数组，struct complex{int b[3];}a[4];引用时，a[1].b[1]
        内存布局，结构体的内存布局是连续的。
        32位计算机cpu访问内存时以4字节进行对齐，取数据时保证每次都能取到。布局如下：
        struct complex{
           int a;
           char b;
           int c;
        };
        内存布局为，a(占4字节)b(占1个字节)$$$c(占4个字节)
        struct complex{
           int a;
           char b;
           char c;
        };
        内存布局为，a(占4个字节)b(1)c(1)$$
        struct complex{
            int a;
            char b;
            short c;
        };
        内存布局为，a(4)b(1)c(2)$
        struct complex{
           int a;
           char b;
           int c;
           short d;
        };
       内存布局为，a(4)b(1)$$$c(4)d(2)$$ 
        共用体union
        union AA{
          int a;
          char b[4];
        }x1;
        访问方式同结构体相同x1.a，所有变量共享储存空间，大小为变量中占字节最多者大小。
       小端表示法，大端表示法，针对于整型数，x1.a=4,
       若为大端表示，低二进制位放在高地址，高二进制位放在低地址。
       x1.b[4]=4,
       若为小端表示（通常），低二进制位放在低地址，高二进制位放在高地址。
       x1.b[0]=4
       数组的小标小的放在低地址，小标大的放在高地址。
       
       共用体嵌套
      结构体作为函数的参数，如何传递？
      传递形式一：
      typedef AA{
      int a,b;
      }AA_t;
      AA_t add(AA_t c,AA_t d){}
      结构体知识点：两结构体各元素求和，只有一下一种形式。
      AA_t add(AA_t c,AA_t d){
        AA_t e;
        e.a=c.a+d.a;
        e.b=c.b+d.b;
        return c;
     }

        使用指针进行冒泡排序法更节省时间，空间。
        typedef struct{}student_t;
        student_t student[10];
        student_t *psstudent[10];

        交换psstudent[i]和psstudent[j]的值。
    枚举 
    在一个集合里，分别把每一个集合成员访问一次。类似于遍历。
    enum Week{
      SUN=0,
      MON,
      TUE,
      WEN,
      THUR,
      FRI,
      SAT
    };
MON==1，TUE==2，在没被赋值的元素后面每个元素自动加1.直到遇到被赋值的元素。
    枚举元素能够被赋负值，表征状态，替换switch,case语句。
     
    位域
    union aa{
    struct bit{
      unsigned int one:1;
      unsigned int two:5;/*表示规定变量two占几个二进制位*/
      unsigned int three:2;
    }x1;}x2;
    int main(){
      x2.x1.one=1;
      x2.x1.two=3;
      x2.x1.three=1;
    return 0;
    }
    规定位域主要用于寄存器控制。（硬件设备）位域连续储存。
    one低位，two中间位，three高位，总共占用2字节，有一个字节空闲，int排布，高24位不用，全为00000000，低八位为01000111.总32位排布为00000000000000000000000001000111.
   文件操作函数fopen(),返回值为文件句柄，FILE *fp=fopen(文件名,r)
    fclose()的返回值为整型，正常关闭返回值为null，否则返回非空.
    fgets(char *s,int size,FILE *s stream) 
    缓冲区为数组，EOF是文件结束的标志。EOF=1,表示是否达到文件末尾。
    判断是否达到文件末尾，feof(file),返回值为非零。
    strchr(str,'@');做一个for循环，找一个特定的字符。
    连续出现多次跳过，第一个出现跳过，不跳过的记录位置，往前找，如果不超过32，则合法，输出；往后找，不超过64，则合法，输出。
    数制转换
    除2倒序取余法 
    补码，正数的补码是它本身，负数的补码是除符号位按位取反加1.
    浮点数在机器中怎么编码？
    第一位代表符号位，后面连着的5位为指数位，以16为基准，大于16的为正数，小于16的为负数，（以偏移指数为基准）后面的几位为精度部分，省出来小数点一位作为精度。
    表达式
    +-*/%中，只有%要求两个操作数均为整型，i++和++i的区别。i均自增1，表达式的值不同。逻辑运算符&&||!,？：问号表达式的嵌套，位运算
    逻辑右移，右移时低位补0，数学右移，右移时低位根据所移位判断补0，整数为0，负数为1.计算机的右移是逻辑右移。指定某一位为1，让这一位和1相或，指定某一位为0，让这一位和0相与，取某一位的值是让这一位同1相与，取反是与1异或。异或交换两个变量的值，a^=b;b^=a;a^=b;简单加密。只能对整型进行异或，乘除其实是移位和按位操作的模拟。    
    empty_cache();清空缓冲区，常与scanf()同用。用getchar()将缓冲区数据全部读出并清空。

    除法操作是用移位和加法，会消耗大量的CPU时间。嵌入式CPU功耗很低，运算速度很慢，所有运算皆为定点运算即整型运算，所有浮点运算都可以用整型运算来代替。将所有浮点数同时放大一定数量级，即可将其化为整型。
    数据类型  ILP32(位数)，IP64(位数) 
    char         8             8
    short        16            16
    int          32            32
    long int     32            64
    long long    64            64
    指针         32            32

    使用C99标准，gcc c文件名 -std=c99.
    int范围为-2^31到2^31-1,unsigned int的范围0到2^32-1,unsigned
    short的范围为0到2^16-1.
    
    类型转换，函数的参数和返回值，返回一个整数，会自动转换为整型，printf("%c",'a');传进去整数的时候会默认传进去的为整型，将对char型作类型转换，然后将整型转换为char型，隐式类型转换。
    整型与短整型运算，首先将短整型转换为整型，隐式类型转换。
    短整型转换为长整型的时候会进行位扩展，长整型转换为短整型会进行位截断。
    类型转换由编译器完成。
    
    类型转换
    （类型名）参数；(int)a;
    指针类型转换(int *)a;
    计算机整数运算速度高于浮点数，写出浮点数默认为double,float型浮点数后面加f,float占32位，double占64位。long double占12字节。
    字符型char里面存的是整型，0到127.读文本文件不可能读到-1，结束传-1.

    函数栈帧
    函数栈帧是函数运行的环境，它里面包含四类信息，一、函数的参数，保存函数传进去的参数，二、局部变量的值，即函数内部定义的变量的值，三、函数返回时下一条可执行指令的地址，四、上一个函数栈帧栈底的地址。
    代码段（倒数第二段）保存指令和常数，数据段（最下面的一段）保存已经初始化的全局数据，没有初始化的全局数据。
    函数的临时变量存在栈里，动态内存分配在堆上分配。栈只有1～2M，中间的堆进行动态内存分配。
    每一段均可以重定位。
    虚拟地址映射，每一个进程逻辑上占用4G的内存，逻辑寻址范围为4G，物理上不足4G，CPU做虚拟地址映射，映射到内存上，最上面的栈顶，从上往下增，每调用一个函数均增加一个函数栈帧。什么情况下会用到动态内存分配。虚拟机的映像为2.7G.
    加载到内存空间的程序成为进程，函数栈帧存四类信息。栈底保存函数栈帧。
    栈底数高。

    最上层函数main,第二层调用函数foo,第三层调用函数bar.
    参数在压栈时是从右往左压。
    foo(2,4)先压4再压2.
    存在main函数的栈帧中，
    b:4
    a:2
    dd                                    foo的地址压到eIP中
    函数调用后下一条return语句的地址        栈底存在ebp中,
   
    上一个栈的基址指针（上一个函数的栈底地址）
    d:b
    c:a
    return语句的地址

    上一个栈帧的栈底地址
    e
    return语句的地址

    如果数组，先从高地址向低地址压。
    局部数组下标越界，会覆盖上一个函数下一条指令的返回值。程序返回时指令的地址
    
    gcc怎么把一个c语言程序变成汇编程序.
    gcc c文件名 -S
    return返回值存在eax寄存器中，ebp总是指向当前函数的栈底,eax,ebx,ecx,edx
    i register 查看所有寄存器值。
    
    eax是编译器规定的，
    递归不能层次太大。
    
    物理地址为0的空间不能访问，分配物理地址若返回值为null，则分配失败。
    变量的布局
    代码段只读，代码段加载到内存受保护，只能读不能写。
    数据段保存初始化的全局数据，可读可写，空间大小不变，数据可以改变。
    先定义的全局变量保存在低地址，后定义的保存在高地址，顺序储存。
    常量保存在rodata段,字符串保存在rodata段，可以共享。
    rodata section和text section在链接时会合并成一个segment.加载到内存后值都是不可修改的，只读受保护。
    bss段保存未初始化的全局数据，链接之后bss段在程序文件中不占空间,在加载到内存之后全部清零。bss section和text section在链接时合并成一个segment，访问权限可读可写。
    全局变量不初始化默认值为零，初始化不赋值默认值为零。
    局部变量不初始化值为随机值，初始化不赋值默认值为零。
    局部变量在程序运行时分配储存空间，其空间分配在程序栈帧上。
    局部变量的初始化在程序运行时，全局变量的初始化在编译时运行。程序未运行时，全局变量已经在外存（磁盘）上分配储存空间。
    全局变量和局部变量的区别，实质是储存位置上的区别。
    编译器在解析符号时使用离引用处最近的符号定义，内层定义会覆盖外层定义。
    变量的修饰符有四种，static,auto,register,extern.
    
    auto默认
    register经常访问，不会分配在栈帧上，会分配在寄存器上，如果寄存器不足，将会分配在栈帧上。
    extern修饰全局变量时代表引用，引用前先声明，可以写在任何地方。
    变量的生存期和作用域
    生存期：静态生存期
            自动生存期
            动态分配生存期
    作用域：在文件内部定义的，加了static,则只在文件内部起作用。在函数内部定义的，加了static,则只在函数内部起作用。
    作业：位操作，email,解析myshell
    链接详解和多文件程序的设计。
    
    多文件模块的程序设计，C是以文件为模块进行划分的，模块是以文件为单位的。
    声明是对要引用的对象进行说明。
    定义和声明的实质区别：定义分配储存空间，声明不必分配储存空间。是否在代码段数据段分配存储空间。
    变量可以不定义，当声明变量时，声明会自动升级为定义，函数必须定义。
    函数不声明也可以用，不过相当危险。声明的函数必须是定义过的。
    函数不声明直接使用，叫做函数隐式声明，是非常危险的操作。编译器通过自己推导得出返回值类型，推导结果往往错误。
    变量的声明类型必须和变量的定义类型相符。如果不相符，即为重名。编译不通过。
    static应用于变量和函数的区别，应用于变量，只能在它的作用域内使用，不能被调用。应用于函数，这个函数只能在当前文件中调用，不能在其他文件中调用。
    封装思想static,供其他人使用不对外公开的使用static,对外公开的不必封装。
    接口函数，没有用static标识，对外公开的函数称为接口函数。
    可执行文件，对象文件，共享动态库文件，采用elf格式。均为二进制格式。均为已经编译成机器代码的文件。
    readelf -a 文件名>文本文件名，重定位到文本文件

    各种Unix系统的可执行文件均采用elf格式。
   
    链接
    #ifndef 判断该宏是否存在，若不存在则执行下面语句。 文件首位，加快编译器预处理的速度，避免死循环。多次引用，重复编译浪费时间。
    empty_cache()清空缓冲区，源代码：
    char ch;
    ch=getchar();
    while(getchar()!=EOF && getchar()!='\n') ch=getchar();
    没有加static是为接口函数，对外公开。
    
gcc main.c ./mybit/common.c ./mybit/d2b.c ./mybit/encryption.c ./mybit/exchange.c ./mybit/multi.c -I./mybit -o main
    I为include的缩写，意为它所引用的头文件要在其后紧跟的目录下去找。
    gcc -Wall 不能放过的警告。
    #include "路径名" 不推荐，
    
    C语言诞生的过程：预处理（#include 宏定义#define），编译(翻译成汇编代码)，汇编（将汇编代码翻译成二进制的机器指令），链接（将二进制的机器代码link成可执行文件）
    中间文件，预处理之后生成.i文件，经过编译后生成.s文件，汇编生成的.o文件。
    gcc -E c文件名，生成.i文件，gcc -S c文件名，生成.s文件，gcc -c
    c文件名，生成.o文件，为elf文件格式,用readelf -a c文件名>文件名 重定向
    链接是将外部函数与自己写的函数结合在一起，代码段和代码段合并，数据段和数据段合并。合并成可执行文件，合并同类项。
    函数库，包含供其他程序调用的二进制文件。
    应用函数库的目的是以二进制的形式发布代码。
    汇编之后.o文件的地址称为重新定位的逻辑地址。
    地址回填，链接之前，.o文件调用函数的地址为0，链接之后将函数真正的地址填进去。
    启动历程将main函数当作子函数调用，退出负责清理程序。
    未链接则启动历程不会调用main函数。
    系统调用，操作系统提供的基本功能，open,close,read,write.

    静态库，在程序链接之后会将函数的二进制的目标代码插入到程序的可执行文件当中。合并成最终的目标文件。
    在链接之后就已经确定了。
    动态库，在程序运行时，把动态库加载到内存空间，确定函数的入口地址，动态地链接调用该函数。(发展方向)
    静态库的优缺点：需要的函数插入，不需要的函数不插入，函数地址确定，程序执行很快。库里的东西改变，需重新编译。
    前期绑定。
    动态库的优缺点：发布一个库，就可以更新了。加载到内存空间之后可供多个客户端使用。程序第一次运行时比较慢，回填之后会变快。
    接口不变，后期绑定。
    静态库的制作方法
    1.gcc -c c文件名 编译
    2.ar rs .a库文件名 .o文件名（需要添加的.o文件），打包静态库
    ar rs libbit.a *.o
    gcc -l（.a文件会默认将lib去掉） l代表使用某个库
    3.gcc main.c -L. -lbit -o bitop 使用静态库
    main.c为包含main函数主程序的c文件名。
    L指定在那个目录下找库
    lib为静态库的前缀，r代表将.o文件添加到静态库，s代表库建立后重新建立索引
    lupin@ubuntu:~/test/mylesson/mybit$ ls
    common.c  d2b.c  encryption.c  exchange.c  main.c   multi.h
    common.h  d2b.h  encryption.h  exchange.h  multi.c
    lupin@ubuntu:~/test/mylesson/mybit$ gcc -c common.c d2b.c encryption.c
    exchange.c multi.c
    lupin@ubuntu:~/test/mylesson/mybit$ ls
    common.c  d2b.c  encryption.c  exchange.c  main.c   multi.o
    common.h  d2b.h  encryption.h  exchange.h  multi.c
    common.o  d2b.o  encryption.o  exchange.o  multi.h
    lupin@ubuntu:~/test/mylesson/mybit$ ar rs libbit.a *.o
    ar: creating libbit.a
    lupin@ubuntu:~/test/mylesson/mybit$ gcc main.c -L. -lbit -o bitop
    lupin@ubuntu:~/test/mylesson/mybit$ ls
    bitop     common.o  d2b.o         encryption.o  exchange.o  multi.c
    common.c  d2b.c     encryption.c  exchange.c    libbit.a    multi.h
    common.h  d2b.h     encryption.h  exchange.h    main.c      multi.o
    lupin@ubuntu:~/test/mylesson/mybit$ ./bitop
   
    非当前目录下生成库。
    1.gcc -c ./mybit/*.c 在当前目录下生成*.o
    2.ar rs libbit.a *.o
    3.gcc main.c -L. -lbit -I./mybit -o bitop
    -I代表头文件所在路径。
    gcc main.c -L. -lbit -I./mybit static -o bitop
    显式指定使用静态库

    动态库的制作方法：
    1.编译 gcc -c -fPIC *.c PIC位置无关
    2.gcc *.o -shared -o libbit.so 动态库名称为libbit.so
    3.gcc main.c -L. -lbit -I./mybit -o bitop
    
    ldd bitop
    寻找动态共享库
    方法一，LD_LIBRARY_PATH（不允许使用）
    方法二，执行lupin@ubuntu:~/test/mylesson$ sudo vim /etc/ld.so.conf
            将动态库所在的目录加到文件末行。
            lupin@ubuntu:~/test/mylesson$ sudo ldconfig -v
            建立索引，将索引放在/etc/ld.so.cache文件中。
    方法三，将动态库拷贝到/usr或是/lib. sudo cp bit /usr 
    方法四，硬编码方法（不推荐使用）
    
    系统库目录
    .so.a.b.c a为主版本号，不同的动态库，若主版本号相同，则动态库的接口函数相同。若函数接口做了更新，则必须增加主版本号，b为次版本号，不影响接口。
    
    符号链接 soname，只包含主版本号的文件名
    真实文件名real name,包含主版本号，次版本号的文件名
    linkername 链接时加的linkername
lupin@ubuntu:~/test/mylesson$ gcc -shared -o libbit.so.1.0
-Wl,-soname,libbit.so.1
lupin@ubuntu:~/test/mylesson$ sudo ldconfig
lupin@ubuntu:~/test/mylesson$ ls -s libbit.so.1.0 libbit.so
lupin@ubuntu:~/test/mylesson$ gcc bitop.c -L. -lbit -I./mybit -o bitop

PIC位置无关代码，加载到内存空间时，位置不是固定的，可以任意指定空间。可以动态寻找函数入口地址。

  plt section 存放动态库函数的入口地址
  plt表的概念
 
头文件包含接口函数的函数声明
发布库时要尽量保持函数的签名不变，便于维护。

更改时只需要进行打包即可。ar rs libbit.a common.o
common.o为改变的文件

生成makefile的规则 
蓝色的bitop:目标 编译之后生成的结果，
目标后可跟许多条件，条件为一系列的文件名，表示要生成目标所需要的条件。
红色的称为命令必须以tab键开头，打法与在terminal中相同。

第一个目标一般规定为最后生成的文件名
制作好Makefile之后，只需打make命令，即可生成文件bitop.

第二个目标common.o往往为第一个目标的条件，第二个目标又依赖于其本身c文件和它的c文件所引用的.h文件。

执行过程
首先检查（第一个目标文件名）是否存在，并且为最新版本，如果生成条件的时间比生成目标的时间还要晚，则视为不是最新版本，生成bitop文件。检查条件是否生成，若是没有生成，则先生成条件，再生成最新版本文件。若是条件被修改，则用最新版本的条件生成最新版本的文件。

自己写的头文件要写引用时要加""

最后的目标clean:执行清理工作，@后面的命令并不显示执行命令的名称，只显示执行命令的结果。

-后面的命令即使出错了，依然忽略错误继续往下执行。
格式十分严格，tab键开头。
.PHONY:伪目标，如果其条件文件不存在，则不需要生成文件，直接执行其后的命令。

make clean执行清理工作。make 第一个目标名，执行生成文件命令。

all代表第一个目标的名字，代表编译整个工程。
install代表把编译好的工程安装到系统当中去，配置相应参数。
clean代表清理生成的目标文件。
distclean执行clean动作，同时清理临时文档，配置文档。

echo显示注释作用，用于一些批命令中需要注释给用户看的地方，比如前一条命令执行会花很长时间，常规来会用echo显示一条信息让用户知道这个时候比较慢，稍微等待一会。之类的信息。

隐含规则：
#default
OUTPUT——OPTION=-o $@自动添加到程序开头
相当于添加了一个include
$@代表在此规则中目标名字
#default
CC=cc
cc是gcc的真是名字
#default
COMPILE.c=$(CC)$(CFLAGS)$(CPPFLAGS)$(TARGET_ARCH) -c
-c为一个字符串，ABC=-c gcc $(ABC)替换之后即为gcc -c
(CFLAGS)(CPPFLAGS) (TARGET_ARCH)三个字符串的值默认为空。
$(变量名)代表对这个变量取内容
(CFLAGS)编译参数(CPPFLAGS)预处理器选项(TARGET_ARCH)目标平台

若CFLAGS=-I.则只在当前目录下寻找头文件

%.o:%.c
#   commands to execute(built-in)
        $(COMPILE.c)$(OUTPUT_OPTION)$<
        cc $@ $<   替换之后
    举例为cc common.o common.c 
    $<表示目标后第一个条件名字。

模式规则
%为通配符，相当于所有的.o文件为目标，所有的.c文件为条件


系统默认模式规则，当前目录下的所有.o的文件的条件为所有的.c文件。
因此Makefile中只需写第一个目标
bitop:*.o
    gcc main.c *.o -c main

clean: ……

第一种写法存在Makefile中，第二种写法存在Makefile1中，第三种写在Makefile2中，若需要在.o文件中添加.h文件，则需要写成Makefile3.

第四种写法，运用替换，存在Makefile4中。

$^表示这条规则中所有条件，-o表示output输出，$@表示当前模式规则下目标名字，$?表示规则中所有比目标新的条件，$< 表示规则中第一个条件。

当在Makefile中，格式不正确时字符不变色。

第五种写法，
不必每次都去人工分析每个文件所需的头文件。
gcc -MM main.c不包含系统的头文件。
gcc -M main.c包含系统的头文件。

变量替换语法 $(sources:.c=.d)
将sources中所有.c均替换成.d
include $(sources:.c=.d)将.d文件包含进去。
当系统找不到.d时会将.d当成目标文件更新.
set -e当后面运行的命令一条出错即结束程序。
在Makefile中$$代表一个$.
.$$代表当前进程的进程ID.
$@.$$$$为临时文件，
\代表续行符，sed将文件内容取出，拼凑成需要的内容。
.d文件包含.c文件对于头文件的依赖关系。
%.d:%.c
    set -e;rm -f $@;\
    $(CC) -MM $(CPPFLAGS) $< >$@.$$$$;\
    sed 's,\($*\)\o[ :]*,\1.0 $@ : ,g' <$@.$$$$>$@;\
    rm -f $@.$$$$
命令解析：
set -e当后面运行的命令一条出错即结束程序。
rm -f $@;删除更新之前的.d文件。
$(CC) -MM $(CPPFLAGS) $< >$@.$$$$;\将不包含系统的头文件导入到相应$@.$$$$临时文件中。在Makefile中$$代表一个$. .$$代表当前进程的进程ID.
sed 's,\($*\)\o[ :]*,\1.0 $@ : ,g' <$@.$$$$>$@;\将临时文件$@.$$$$中的内容导入到.d文件中。
rm -f $@.$$$$删除临时文件。
命令最后一句没有分号。
第五种写法存在Makefile5中。

总目录下Makefile会调用子目录中的makefile.
将命令写在makefile的命令行中 make -C 目录名，则会调用子目录下的makefile

在命令行中加入CFLAGS=-g,则会




