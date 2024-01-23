# BigIntFromPJH

## 1.01版本日志

更新了 $bigint$ 和 $modint$。

## 一、 $bigint$ 支持通过 $string$ 形式赋值，初始值为 $0$

支持大小比较运算，四则运算及取模（注：仅支持整除操作）；

支持通过 cin，cout 输入输出；

支持通过 neg() 函数获取 $bigint$ 内数值的正负性；

支持通过 size() 函数获取 $bigint$ 内数值的位数；

支持通过 empty() 函数获取 $bigint$ 内数值是否为空（理论上 empty() 始终为假，因为0也有一位数）；

支持通过 value() 函数获取一个 $vector<short>$ 类，用于表示 $bigint$ 内部数值；

支持通过 push_front(),push_back() 函数向最低位、最高位插入一个数位；

支持通过 memorize() 函数以一个新的字符串重新对 $bigint$ 赋值。

## 二、 $modint$ 底层以 $bigint$ 形式实现，在未指定模数时等效于 $bigint$

指定模数后会在运算时自动对模数取模，并在输出时于结尾带上括号，其中含有模数，

可以通过 setmod() 函数设定模数，模数类型为 $bigint$。

## 三、底层由自主实现的 $vector$ 替换掉了 STL 库的 $vector$

注：未实现迭代器，因为不想。

## 四、规范了 README.md 格式
