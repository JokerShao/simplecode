# joker's style guide

> update:2019-03-31
当代码是某个算法的实现时，命名规范应优先符合算法公式中的定义，以便理解。  
代码释出版本号，三位数字：`1.2.2`，其中大版本号看产品经理，中位软件更新升级添加功能，末位bug修复。

## C

与C++规范大致相同，只不过函数的命名遵循全部小写字母，下划线分词，如：

```C
int handle_event(int arg0, int arg1)
{
    return arg0 + arg1;
}
```

## C++

### 0 内联函数

只有当函数只有10行甚至更少时才将其定义为内联函数。

### 1 函数参数

- 变量名一律小写，下划线分词。
- 函数参数的顺序为：输入参数在先，后跟输出参数。
- 当函数参数比较多时，应考虑用结构代替。
- 如果不能避免函数参数比较多，应在排版上考虑每个参数占用一行，参数名竖向对齐。

### 2 命名规则

#### 2.0 目录名

全部小写，使用下划线_进行分词，如`dir_name`

#### 2.1 文件名

全部小写，如`filename.cpp`

#### 2.2 类型命名

首字母大写，使用驼峰命名法，不含下划线：

```C++
// 类、结构体和枚举
class UrlTable {
    ;
}

struct UrlTableProperties {
    ;
}

enum UrlTableErrors {
    ;
}
```

#### 2.3 变量命名

> 避免名字中出现数字编号：如`value1, value2`等，除非逻辑上的确需要编号。

- 2.3.0 普通变量与结构体变量  
    全部小写字母，下划线分词，如

    ```C++
    std::string table_name;

    struct UrlTableProperties {
        string name;
        int num_entries;
        static Pool<UrlTableProperties>* pool;
    };
    ```

- 2.3.1 类数据成员  
    变量名后加一个下划线_

    ```C++
    class TableInfo {
    private:
        string table_name_;
        string tablename_;
        static Pool<TableInfo>* pool_;
    };
    ```

- 2.3.2 指针变量  
    用p打头，如：
    ```C++
    unsigned char* p_gpu_memory;
    ```

#### 2.4 成员函数命名

遵循驼峰命名法，首字母小写，后面大写分词，如：

```C++
int testFunc(int* num_ptr)
{
    ;
}
```

#### 2.5 私有成员函数

遵循驼峰命名法，函数名前加下划线_，如

```C++
int _privateFunc()
{
    ;
}
```

#### 2.6 宏、枚举值

宏和枚举值由全大写字母组成，单词间通过下划线来分割，如：

```C++
#define ERROR_UNKNOWN 1
enum EnumType {
    OP_STOP = 0,
    OP_START
};
```

### 3 头文件包含

1. 用`ifndef def endif`避免头文件重复包含

2. 若头文件中使用了其他定义，应将定义所在头文件包含进来；如果只用声明，则使用前向声明的方法，尽量不要出现交叉引用头文件。包含的话就包干净的纯外部的头，否则可能会导致包含顺序不确定，最终出现莫名其妙的编译错误。

3. 在`stdafx.h`中放置项目中使用较多的系统和第三方的依赖头，**经常改动的头文件不要放在里面**

4. 包含头文件时应加上文件相对路径，如`#include "base/logging.h"`，而不是`#include "logging.h"`

5. 对于`xxx.cpp`，头文件包含顺序应为：

    ```text
    xxx.h
    OS SDK.h
    C标准库.h
    C++标准库.h
    其他第三方库.h
    本项目内.h
    ```

## Python

### 0 缩进

不要使用反斜杠链接行，Python会将圆括号，中括号和花括号中的行隐式的连接起来，可以利用这个特点。  
如果需要，可以在表达式外围增加一对额外的圆括号，如：

```Python
foo_bar(self, width, height, color='black',
        design=None, x='foo',
        emphasis=None, highlight=0)
     if (width == 0 and height == 0 and
         color == 'red' and emphasis == 'strong'):
            pass
```

如果一个文本字符串在一行放不下，可以使用圆括号来实现隐式行连接：

```Python
x = ('This will build a very long long '
     'long long long long long long string')
```

### 1 空行

- 在类和函数的定义间加空行
- 在import不同种类的模块间加空行
- 在函数中的逻辑段落间加空行，即把相关的代码紧凑写在一起，作为一个逻辑段落，段落间以空行分隔。

### 2 空格

#### 2.0 括号内

括号内不要有空格，如：

```Python
def spam(ham[1], {eggs: 2}, [])     # OK
def spam( ham[ 1 ], { eggs: 2 }, [ ] )     # Bad
```

#### 2.1 切片或索引

索引或切片的左括号前不应加空格，如：

```Python
dict['key'] = list[index]   # OK
dict ['key'] = list [index] # Bad
```

#### 2.2 默认参数列表

当’=’用于指示关键字参数或默认参数值时，不要在其两侧使用空格，如：

```Python
Yes: def complex(real, imag=0.0): return magic(r=real, i=imag)
No:  def complex(real, imag = 0.0): return magic(r = real, i = imag)
```

### 3 导入



与通配符导入不同，常规导入不受前导单个下划线命名约定的影响：

应该避免通配符导入（from tt_module import *)，每个导入应该独占一行，按照从最通用到最不通用的顺序分组:

1. 标准库导入
2. 第三方库导入
3. 应用程序指定导入。
>>> import my_module
>>> my_module.external_func()
23
>>> my_module._internal_func()
42

### 4 命名规则

#### 4.0 包命名

小写字母，单词之间用_分割，如`package_name`

#### 4.1 模块命名

小写字母，单词之间用_分割，如：`ad_stats.py`

#### 4.2 类命名

首字母大写，驼峰命名法，不使用下划线连接单词，使用大小写分词，对于基类，可以加一个`Base`或者`Abstract`前缀，如：

```Python
class TestClass(object):
    pass
class BaseCookie(object):
    pass
class AbstractGroup(object):
    pass
```

#### 4.3 变量命名

- 4.3.0 全局变量
    大写字母，单词间使用_分割，如：
    ```Python
    NUMBER = 0
    COLOR_SPACE = False
    ```

- 4.3.1 类的公有变量，保护变量
    全部小写字母，下划线分词，如：
    ```Python
    class TestClass(object):
        public_variable = True
    ```
单个下划线是一个Python命名约定，表示这个名称是供内部使用的。 它通常不由Python解释器强制执行，仅仅作为一种对程序员的提示。
- 4.3.2 类的保护变量
    单下划线开头，全部小写字母，下划线分词，如：
    ```Python
    class TestClass(object):
        _protected_variable = False
    ```
总之，单个末尾下划线（后缀）是一个约定，用来避免与Python关键字产生命名冲突。 PEP 8解释了这个约定。
- 4.3.3 类的私有变量
    以双下划线__开头，如：
    ```Python
    class TestClass(object):
        __private_variable = True
    ```
双下划线前缀会导致Python解释器重写属性名称，以避免子类中的命名冲突。
- 4.3.4 普通变量
    全部小写，下划线分词，如：
    ```Python
    variable = 0
    this_is_a_variable = True
    ```

### 4.4 函数命名

- 4.4.0 普通函数及类的公有函数，保护函数
    驼峰命名法，如：
    ```Python
    def getMask():
        pass
    ```

使用_one_underline来表示该方法或属性是私有的，不属于API；
当创建一个用于python调用或一些特殊情况时，使用__two_underline__；
使用__just_to_underlines，来避免子类的重写！

- 4.4.2 类的私有函数（外部无法访问）
    以下划线_开头，驼峰命名法，如：
    ```Python
    class Test(object):
        def _privateFunc():
            pass
    ```


按照习惯，有时候单个独立下划线是用作一个名字，来表示某个变量是临时的或无关紧要的。

例如，在下面的循环中，我们不需要访问正在运行的索引，我们可以使用“_”来表示它只是一个临时值：

>>> for _ in range(32):
...    print('Hello, World.')


这样就很方便了，比如你可以在一个解释器会话中访问先前计算的结果，或者，你是在动态构建多个对象并与它们交互，无需事先给这些对象分配名字：

>>> 20 + 3
23
>>> _
23
>>> print(_)
23

>>> list()
[]
>>> _.append(1)
>>> _.append(2)
>>> _.append(3)
>>> _
[1, 2, 3]