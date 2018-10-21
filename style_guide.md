# joker's style guide

> date:2018-10-21  
当代码是某个算法的实现时，命名规范应优先符合算法公式中的定义，以便理解。  
代码释出版本号，三位数字：`1.2.2`，其中大版本号看产品经理，中位软件更新升级添加功能，末位bug修复。

## C++

### 0 内联函数

只有当函数只有10行甚至更少时才将其定义为内联函数。

### 1 函数参数

- 变量名一律小写，下划线分词。
- 函数参数的顺序为：输入参数在先，后跟输出参数。
- 当函数参数比较多时，应考虑用结构代替。
- 如果不能避免函数参数比较多，应在排版上考虑每个参数占用一行，参数名竖向对齐。

### 2 命名规则

#### 2.0 文件名

全部小写，使用下划线_进行分词，如`file_name.cpp`

#### 2.1 类型命名

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

#### 2.2 变量命名

> 避免名字中出现数字编号：如`value1, value2`等，除非逻辑上的确需要编号。

- 2.2.0 普通变量与结构体变量  
    全部小写字母，下划线分词，如

    ```C++
    std::string table_name;

    struct UrlTableProperties {
    string name;
    int num_entries;
    static Pool<UrlTableProperties>* pool;
    };
    ```

- 2.2.1 类数据成员
    变量名后加一个下划线_

    ```C++
    class TableInfo {
    private:
    string table_name_;
    string tablename_;
    static Pool<TableInfo>* pool_;
    };
    ```

- 2.2.2 指针变量
    用p打头，如：
    ```C++
    unsigned char* p_gpu_memory;
    ```

#### 2.3 函数命名

遵循驼峰命名法，首字母小写，后面大写分词，如

```C++
int testFunc(int* num_ptr)
{
    ;
}
```

#### 2.4 宏、枚举值

宏和枚举值由全大写字母组成，单词间通过下划线来分割，如：

```C++
#define ERROR_UNKNOWN 1
enum EnumType {
    OP_STOP = 0,
    OP_START
};
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

每个导入应该独占一行，按照从最通用到最不通用的顺序分组:

1. 标准库导入
2. 第三方库导入
3. 应用程序指定导入。

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

- 4.3.1 类的公有变量
    全部小写字母，下划线分词，如：
    ```Python
    class TestClass(object):
        public_variable = True
    ```

- 4.3.2 类的保护变量
    单下划线开头，全部小写字母，下划线分词，如：
    ```Python
    class TestClass(object):
        _protected_variable = False
    ```

- 4.3.3 类的私有变量
    以双下划线__开头，如：
    ```Python
    class TestClass(object):
        __private_variable = True
    ```

- 4.3.4 普通变量
    全部小写，下划线分词，如：
    ```Python
    variable = 0
    this_is_a_variable = True
    ```

### 4.4 函数命名

- 4.4.0 普通函数及类的公有函数
    全部小写，下划线分词，如：
    ```Python
    def get_mask():
        pass
    ```

- 4.4.1 类的保护函数
    以单下划线_开头，全部小写字母，如：
    ```Python
    class Test(object):
        def _protected_func():
            pass
    ```

- 4.4.2 类的私有函数（外部无法访问）
    以双下划线__开头，全部小写，如：
    ```Python
    class Test(object):
        def __private_func():
            pass
    ```

## C

大致与C++规范相同，只不过函数的命名有点类似与Python，  
全部小写字母，下划线分词，如：

```C
int handle_event(int arg0, int arg1)
{
    return arg0 + arg1;
}
```

