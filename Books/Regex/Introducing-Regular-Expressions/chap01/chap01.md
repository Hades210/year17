# chap01 -- what's it?

字符串模式</br>

\d</br>
匹配0-9范围内的任意数字的字符组简写式</br>

[Regexpal](http://www.regexpal.com)在线学习</br>

字符串字面值用来匹配目标字符串，所谓字符串字面值，就是字面上看起来是什么就是什么。</br>

以匹配北美电话号码为例</br>
电话号码: 707-827-7019</br>

字符串字面值: 707-827-7019</br>

用字符组来匹配数字</br>
[0-9]</br>
正则表达式将方括号视为特殊的元字符(metacharacter)，因此方括号不参与匹配。元字符是在正则表达式中有特殊含义的字符，也是保留字符。[0-9]这种形式的正则表达式称作字符组(character class),也叫字符集(character set).</br>
[012789] 

字符组：[0-9][0-9][0-9]-[0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]</br>

使用字符组简写式</br>
\d</br>
字符组简写式(character shorthand),也叫转义字符(character escape).</br>
\D 它匹配任何一个非数字字符。</br>

字符组简写式: \d\d\d\D\d\d\d\D\d\d\d\d</br>

匹配任意字符</br>
可以用.来匹配讨厌的连字符</br>
点号一般不匹配行起始符</br>

\d\d\d.\d\d\d.\d\d\d\d</br>

捕获分组和后向引用</br>

捕获分组(capturing group)来匹配电话号码中的某一部分。然后使用后向引用(backreference)对分组中的内容进行引用。要创建捕获分组，先将一个\d放在一对圆括号中，这样就将它放入了一个分组中，后面可以用\1来对捕获的内容进行后向引用。</br>
(\d)\d\1</br>
(\d)匹配第一个数字，并将其捕获</br>
\d 匹配第二个数字，但不捕获</br>
\1 对捕获的数字进行反向引用</br>

捕获分组与后向引用 (\d)0\1\D\d\d\1\D\1\d\d\d</br>

使用量词</br>

\d{3}-?\d{3}-?\d{4}</br>
花括号中的数字表示待查找的数字出现的次数。包含数字的花括号是一种量词(quantifier).花括号本身用作元字符。</br>
问号是另一种量词，上面表达式中的连字符是可选的。</br>
? 表示0次或1次</br>
+ 表示1次或多次</br>
* 表示0次或多次</br>

(\d{3,4}[.-]?)+</br>
(\d{3}[.-]?){2}\d{4}</br>

括选文字符</br>
^(\(\d{3}\)|^\d{3}[.-]?)?\d{3}[.-]?\d{4}$</br>
出现在正则表达式起始位置或者竖线(|)之后的脱字符^,表示电话号码会出现在一行的起始位置。</br>
美元符$匹配行结束位置</br>

Notepad++ 采用了PCRE(Perl Compatible Regular Expression, Perl兼容正则表达式)库</br>

















