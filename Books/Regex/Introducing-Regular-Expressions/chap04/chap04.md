## chap04 选择、分组和后向引用
分组对文本加括号以帮助执行某种操作</br>

### 选择操作
选择操作可在多个可选模式中匹配一个</br>
`(the|The|THE)`</br>
可以使用一个选项来使分组更简短。借助选项，可以指定查找模式的方式。例如，选项`(?i)`让你的模式不再区分大小写。因此原来的带选择操作的模式可以简写成`(?i)the`</br>

正则表达式中的选项</br>
选项      描述          支持平台</br>
(?d)    Unix中的行        Java </br>
(?i)    不区分大小写      PCRE、Perl、Java</br>
(?J)    允许重复的名字     PCRE </br>
(?m)    多行              PCRE、Perl、Java</br>
(?s)    单行(dotall)      PCRE、Perl、Java</br>
(?u)    Unicode           Java</br>
(?U)    默认最短匹配      PCRE</br>
(?x)    忽略空格和注释     PCRE、Perl、Java</br>
(?-...) 复原或关闭选项     PCRE</br>

`grep -Ec "(the|The|THE)" rime.txt`</br>

-E选项表示使用扩展的正则表达式(ERE),而不是基本正则表达式(BRE)。本例中省去了将括号和竖线符转义的步骤，如果使用BRE则必须进行转义</br>
-c选项返回匹配的行数（不是匹配的单词）</br>
括号将对the、The以及THE的选择操作归为一个分组</br>
竖线符将备选项分开，对备选项求值的顺序是从左向右</br>

下面的方法会将单词的每一次出现都作为一行内容返回，这样就可以得到实际的出现次数</br>
`grep -Eo "(the|The|THE)" rime.txt | wc -l`</br>
-o选项表示只显示一行中与制定模式匹配的部分</br>

使用Perl的写法如下</br>
`perl -ne 'print if /(the|The|THE)/' rime.txt`</br>
`perl -ne 'print if /(?i)the/' rime.txt`</br>
`perl -ne 'print if /the/i' rime.txt`</br>

Perl中的修饰符</br>
修饰符                             描述          </br>
a               匹配\d、\s、\w以及处于ASCII范围内的POSIX字符</br>
c               匹配失败后，则停留在当前位置</br>
d               使用默认的本地平台的规则</br>
g               全局匹配</br>
i               匹配时不区分大小写</br>
l               使用当前位置的规则</br>
m               多行字符串</br>
p               保留匹配的字符串</br>
s               将字符串看作一行内容</br>
u               匹配时使用Unicode规则</br>
x               忽略空格及注释</br>

### 子模式</br>
子模式(subpattern)，就是指分组中的一个或多个分组。子模式就是模式中的模式。多数情况下，子模式中的条件能得到匹配的前提是前面的模式得到匹配，但也有例外。子模式的写法可以有很多种，这里主要关注括号中的子模式</br>

从某种意义上说，(the|The|THE)有三个子模式：the是第一个子模式,The是第二个，而THE是第三个。但是这种情况下，匹配第二个子模式不依赖于是否匹配第一个。（最左边的模式会首先匹配）</br>
而在以下的模式中，子模式依赖于前面的模式</br>
`(t|T)h(e|eir)`</br>

括号对于子模式不是必须的，下面是一个使用字符组的子模式实例:</br>
`\b[tT]h[ceinry]*\b`</br>
\b匹配单词起始边界</br>
[tT]是字符组，它匹配小写字母t或者大写字母T.可以将其看做是第一个子模式</br>
然后匹配（或尝试匹配）小写字母h</br>
第二个也就是最后一个子模式也表示为字符组[ceinry],其后用量词*表示零个或多个</br>

### 捕获分组和后向引用

当一个模式的全部或者部分内容由一对括号分组时，它就对内容进行捕获并临时存储于内存中。可以通过后向引用重用捕获的内容，形式为:</br>
`\1`或`$1`. 这里`\1`或`$1`引用的是第一个捕获的分组，而`\2`或`$2`引用第二个捕获的分组，以此类推</br>
sed只接受`\1`这种形式，而perl则两种都接受</br>

比如，使用Replace功能</br>
`(It is) (an ancyent Marinere)`</br>
`$2 $1` </br>

使用sed的方式</br>
`sed -En 's/(It is) (an ancyent Marinere)/\2 \1/p' rime.txt`</br>
-E选项仍然是调用ERE(扩展的正则表达式),因此，括号可以直接当成字面值来使用</br>
-n选项覆盖打印每一行的默认设置</br>
替换命令搜索与文本"It is an ancyent Marinere,"匹配的内容，再将其捕获放哪购入两个分组中</br>
替换命令还将捕获的文本重排为先后向引用\2的内容再是\1的内容，再将匹配的文本替换为重排后的内容并输出</br>
替换命令结尾处的p表示要打印该行</br>

使用perl的方式</br>
`perl -ne 'print if s/(It is) (an ancyent Marinere)/\2 \1' rime.txt`</br>
`perl -ne 'print if s/(It is) (an ancyent Marinere)/$2 $1' rime.txt`</br>

在转换的过程中，处理大小写的问题.</br>
`perl -ne 'print if s/(It is) (an ancyent Marinere)/\u$2 \l$1/' rime.txt` </br>
\l 语法并不匹配任何字符，而是会将紧邻其后的字母变为小写</br>
\u 语法将紧邻其后的字母变为大写</br>
\U指令将紧接气候的文本字符串全部变为大写</br>
\L指令将紧接其后的文本字符串全部变为小写</br>


### 命名分组
命名分组(named group) 就是有名字的分组，这样就可以通过名字而不是数字来引用分组。</br>
`perl -ne 'print if s/(?<one>It is) (?<two> an ancyent Marinere)/\u$+{two} \l$+{one}/' rime.txt`</br>
在括号中添加?<one>和?<two>将分组分别命名为one和two</br>
$+{one}引用名为one的分组,而$+{two}则引用命为two的分组</br>
如果在一个模式中有分组被命名，那么你还可以重用该命名分组</br>

### 非捕获分组
还有一种分组是非捕获分组(Non-Capturing Group).非捕获分组不会将其内容存储在内存中。在你并不想引用分组的时候，可以使用它。由于不存储内容，非捕获分组就会带来较高的性能。</br>
`(the|The|THE)`</br>
`(?:the|The|THE)` 非捕获分组</br>
`(?i)(?:the)`   不区分大小写的非捕获分组</br>
`(?:(?i)the)`不区分大小写的非捕获分组</br>
`(?i:the)`不区分大小写的非捕获分组</br>

### 原子分组
另一种非捕获分组是原子分组(atomic group). 如果你使用正则表达式引擎进行回溯操作，这种分组就可以将回溯操作关闭，但它只针对原子分组内的部分，而不针对整个正则表达式。其语法如下：</br>
`(?>the)`</br>
原子分组主要与性能相关</br>