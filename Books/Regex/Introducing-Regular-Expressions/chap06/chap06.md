## chap06 匹配Unicode和其他字符
有很多方式可以指定Unicode字符(也称为代码点)</br>
`\u00e9`该正则表达式\u之后紧跟十六进制值00e9(这里不区分大小写00E9也可以).00e9对应十进制233,在ASCII范围(0-127)之外</br>
JavaScript支持`\xe9`的方式，匹配为同一个字符</br>
`\u2014` 长破折号</br>
`\u2013` 短破折号</br>

### 使用vim
`/\%u6c60` 在\%之后，你可以使用x或X来匹配0-255(0-FF)范围内的值，使用u匹配256-65535(100-FFFF)范围内的四位十六进制数，还可以用U来匹配65536-2147483647(10000-7FFFFFFF)范围内的八位十六进制数</br>

### 用八进制数匹配字符
在正则表达式处理器中，就是要在反斜线(\)后加三位数字</br>
`\351` 等同于`\u00e9`</br>

### 匹配Unicode字符属性
在某些实现中(比如perl)中，还可以匹配Unicode的字符属性。这些属性包括字符是否是字母，数字或标点符号</br>
ack 用perl编写的命令行工具，跟grep功能相似</br>

`ack '\pL' schiller.txt` 查看那些属性为字母(L)的字符</br>
`ack '\p{Ll}' schiller.txt` 查看小写字母</br>
`ack '\p{Lu}' schiller.txt` 查看大写字母</br>

要指定不符合某个属性的字符，则使用大写P</br>
`ack '\PL' schiller.txt` 查看非字符字母</br>
`ack '\P{Ll} schiller.txt'` 查看非小写字母</br>
`ack '\P{Lu} schiller.txt'` 查看非大写字母</br>

更多字符属性，请参考[pcresyntax3](http://www.pcre.org/pcre.txt)</br>

### 匹配控制字符
在正则表达式中，可以像这样来指定一个控制字符`\cx` 其中x就是你想匹配的控制字符</br>
`perl -ne 'print if /\c@/' ascii.txt` 查找空字符</br>
`perl -ne 'print if /\0/' ascii.txt` 查找空字符</br>
`perl -ne 'print if /\cG/' ascii.txt` 查找报警字符</br>
`perl -ne 'print if /\a/' ascii.txt` 查找报警字符</br>
`perl -ne 'print if /\c[/' ascii.txt` 查找转义字符</br>
`perl -ne 'print if /\e/' ascii.txt` 查找转义字符</br>
`perl -ne 'print if /\cH/' ascii.txt` 查找退格符</br>
`perl -ne 'print if /[\b]/' ascii.txt` 查找退格符</br>

下表展示匹配Unicode及其字符</br>
\uxxxx      (unicode四位)</br>
\xxx        (unicode两位)</br>
\x{xxxx}    (unicode四位)</br>
\x{xx}      (unicode两位)</br>
\ooo        八进制(基数为8)</br>
\cx         控制字符</br>
\0          空字符</br>
\a          报警符</br>
\e          转义符</br>
[\b]        退格符</br>
