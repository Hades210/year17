## chap03 边界

断言标记边界，但是并不耗用字符。字符并不会返回到结果中。断言也被称做零宽度断言(zero-width assertion)。零宽度断言不匹配字符，而是匹配字符串中的位置。其中一些，比如^和$，也叫做锚位符(anchor)</br>

### 行的起始与结束
要匹配行或者字符串的起始要使用^</br>
根据上下文，^会匹配行或者字符串的起始位置，有时还会匹配整个文档的起始位置。而上下文则依赖应用程序和在应用程序中所使用的选项。</br>

要匹配行或字符串的结束位置要使用$</br>

`^How.*Country\.$` 匹配以单词How开头的整行</br>
想匹配作为字面值的.号，就必须将点号转义或者将其放入字符组中</br>

### 单词边界与非单词边界
`\bTHE\b`</br>
还可以匹配非单词边界。非单词边界匹配除单词边界之外的位置，比如单词或者字符串中的字母或数字。要匹配一个非单词边界，试一下`\Be\B`

在有些应用中，指定单词边界使用`\<`来指定单词的开头，使用`\>`来指定单词的结尾</br>
在`vi/vim`中，`/\>`查找单词的结尾 `/\<`查找单词的开头</br>
`ZZ`可以退出vim</br>

grep同样支持这一语法</br>
`grep -Eoc '\<(THE|The|the)\>' rime.txt`</br>
-E 选项表示要使用扩展的正则表达式(ERE),而不是grep默认使用的基本正则表达式(BRE), -o 选项代表结果只显示一行中与模式相匹配的那部分。-c 选项的意思是只返回结果的数量.单引号中的模式会对THE,The,the进行整词匹配。着就是\<和\>帮你寻找的。</br>

### 其他锚位符
\A匹配主题词的起始</br>
\Z匹配主题词的结尾</br>
可以在Perl和PCRE中使用</br>

`pcregrep -c '\A\s*(THE|The|the)' rime.txt`</br>
`pcregrep -n '(MARINERE|Marinere)(.)?\Z' rime.txt`</br>

###使用元字符的字面值
用\Q和\E之间的字符集匹配字符串字面值</br>
可以在元字符之前加一个\使其匹配字面值</br>

### 添加标签
使用sed添加标签</br>
sed中的插入命令(i)允许你在文件或字符串中的某个位置之前插入文本。而与i命令相反的是a，它在某个位置之后添加文本。</br>

```
sed '1 i\
<!DOCTYPE html>\
<html lang=\"en"\>\
<head>\
<title>Rime</title>\
</head>\
<body>

s/^/<h1>/
s/$/<\/h1>/
q' rime.txt
```
行尾的反斜杠(\)允许你在该流中插入新行而不会提前执行命令。引号前的反斜杠将引号转义为字面值</br>

将上述命令保存到top.sed文件中，则可以用如下命令</br>
`sed -f top.sed rime.txt`
或进行文件重定向</br>
`sed -f top.sed rime.txt > temp`

使用perl添加标签</br>

```
perl -ne 'print "<!DOCTYPE html>\
                 <html lang=\"en\">\
                 <head><title>Rime</title></head>\
                 <body>\
                 " if $. == 1;
                 s/^/<h1>/;s/$/<\/h1>/m;print;exit;' rime.txt
```
