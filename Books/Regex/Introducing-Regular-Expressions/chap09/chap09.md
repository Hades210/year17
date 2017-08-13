## chap 09 用HTML标记文档

### 匹配标签
```
<[_a-zA-Z][^>]*>
```
第一个字符是左尖括号(<)</br>
在XML中元素可以以下划线字符(_)开头，而在HTML中是以ASCII范围中的大写或小写字母开头</br>
在起始字符之后，标签名称可以是零个或多个除右尖括号(>)之外的任意字符</br>
该表达式以右尖括号结尾</br>

`grep -Eo '<[_a-zA-Z][^>]*>' lorem.dita` </br>

要同时匹配起始标签和结束标签，只需添加一个斜线并在之后加一个问号即可。问号使斜线成为可选匹配部分</br>
`</?[_a-zA-Z][^>]*>` </br>
`grep -Eo '<[_a-zA-Z][^>]*>' lorem.dita | sort | uniq | sed 's/^<//;s/ id=\".*\"//;s/>$//'`

[Learning Perl](http://learn.perl.org/)</br>
`perldoc -v $. ` perl内置变量($.)的文档</br>

[AsciiDoc](http://www/methods.co.nz/asciidoc/)是一种文本格式，可用Python预处理程序将其转换为HTML,PDF,ePUB,DocBook以及技术文档。语法与Wiki或Markdown相似，而且比手工编写HTML或XML标签要快得多。</br>
