## chap08 环视

环视是一种非捕获分组，它根据某个模式之前或之后的内容匹配其他模式，环视也称为零宽度断言</br>

环视包括</br>
正前瞻</br>
反前瞻</br>
正后顾</br>
反后顾</br>

grep没有环视的概念，使用perl和ack进行展示.</br>

### 正前瞻

`(?i)ancytent (?=marinere)` 忽略大小写，每一行中寻找后跟marinere的单词ancyent</br>

`perl -ne 'print if /(?i)ancyent (?=marinere)/' rime.txt` 使用perl来做正前瞻</br>
`perl -ne 'print if /(?i)ancyent (?=m)/' rime.txt` ancyent后面的单词以m|M开头</br>
`ack '(?i)ancyent (?=ma)' rime.txt` 使用ack命令</br>
`ack -i 'ancyent (?=ma)' rime.txt` 使用ack命令,命令行选项-i不区分大小写</br>
`ack -Hi 'ancyent (?=ma) rime.txt'` 使用-H选项，在输出中添加行号以方便计数</br>
`ack -i --output '$.:$_' 'ancyent (?=ma)' rime.txt` 输出也带有行号，但是关闭了标亮功能</br>

### 反前瞻
反前瞻是对正前瞻的取反操作。这意味着要匹配某个模式时，需要在它后面找不到含有给定前瞻模式的内容。反前瞻的形式如下:</br>
`(?i)ancyent (?!marinere)`</br>
正前瞻的等号(=)变为反前瞻的感叹号(!)</br>
`perl -ne 'print if /(?i)ancyent (?!marinere)/' rime.txt`</br> 使用perl
`ack -i 'ancyent (?!marinere)' rime.txt` </br> 使用ack</br>

### 正后顾
正后顾会查看左边的内容，这与正前瞻的方向相反</br>
`(?i)(?<=ancyent) marinere`</br>
小于号(<)提醒你后顾是哪个方向，被标亮的是marinere而不是ancyent</br>
`perl -ne 'print if /(?i) (?<=ancyent) marinere/' rime.txt` 使用Perl</br>
`ack -i '(?<=ancyent) marinere' rime.txt` 使用ack</br>

### 反后顾
反后顾会查看某个模式在从左到右的文本流的最后没有出现。同样，它有一个小于号(<),提醒后顾的是哪个方向</br>

`(?i)(?<!ancyent) marinere`</br>
`perl -ne 'print if /(?i)(?<!ancyent) marinere/' rime.txt`使用perl</br>
`ack -iH '(?i)(?<!ancyent) marinere' rime.txt`  使用ack</br>
