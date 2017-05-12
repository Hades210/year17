## Robotics: Fundamentals Week 1

### What is MATLAB
[Matlab Academy](https://matlabacademy.mathworks.com)</br>

MATLAB Onramp</br>

### Course Overview
`MATLAB Commands`</br>
`Importing and Visualizing Data`</br>
`Projects`</br>

#### Commands
##### Entering Commands
默认变量ans</br>
m = 3 * 5 变量起名</br>
m = m + 1  赋值操作</br>
y = m / 2 workspace会显示变量名及信息</br>
k - 8 - 2; semicolon会执行命令，但不展现在command window处</br>
在command window中使用up调出历史命令，可在历史命令基础上修改</br>
输入变量名回车，返回该变量的值 </br>
##### Sorting Data in Variables
变量命名规则,字母开头，包含数字 字母 _ </br>
clear会清空所有变量</br>
clc只清空command window</br>
##### Using Built-in Functions and Constants
内置常量，比如pi</br>
内置函数，比如sin()</br>
z = sqrt(-9)  i是常量</br>

#### Vectors and Matrices

Manually Entering Arrays</br>
x = 2 </br>
x = [3 5] 1X2 </br>
x = [3,5] 1X2 </br>
x = [3;5] 2X1 </br>

x = [5 6 7 ; 8 9 10] 2X3 Matrix</br>

x = [sqrt(10) pi^2] </br>

x = 1 : 3 / x = [1 2 3] </br>
x = first : space : last </br>
space 不写时，默认为1</br>

x = linspace(first,last,number_of_elements)</br>
:和linspace都是生成行向量</br>
x = x' 转置</br>

x = (5 : 2 : 9)' </br>
x = linspace(5,9,3)' </br>

Array Creation Functions</br>
x = rand (5) 5by5 matrix </br>
x = rand (5, 1) 5by1 matrix </br>
x = zeros(6,3) 6by3 全零矩阵</br>

### Saving and Loading Variables
save foo x 将变量x保存到foo.mat文件中</br>
load foo 从foo.mat文件中加载</br>

### Indexing into Arrays

x = A(6,3) 取矩阵A的第6行，第3列的数字</br>
x = A(end,3) 最后一行，第3列</br>
x = A(end - 2, end - 3)</br>

### Extracting Multiple Elements

x = data(2,:) 第二行的所有数据</br>
x = data(:,2) 第二列的所有数据</br>

x = data(1:3,:) 1到3行，任意列</br>
x = data(:,end-1:end) 最后两列，任意行</br>

x = v(3) v是向量（列/行）第3个元素</br>
x = v(3:5) </br>

v(2) = 5 </br>

### Perform Array Operations on Vectors
y = x + 1 每一个元素都加1</br>

z = z1 + z2 z1和z2同型时，可相加</br>

za = z/2 </br>

zm = max(za)</br>
xSqrt = sqrt(x)</br>
vr = round(va) 四舍五入</br>

\* 矩阵乘法</br>
.* 点乘(对应元素相称，两个向量要相同)</br>

### Obtaining Multiple Outputs from Function Calls

dsize = size(data) 返回行数 列数</br>
[dr,dc] = size(data) 返回行数 列数</br>
[vMax,ivMax] = max(v) 返回最大值及其索引</br>

doc fcnName 打开函数帮助手册</br>

### Plotng vectors
同样大小的向量，使用plot(x,y)绘制图形</br>
plot(x,y,'r--o')设置线的属性</br>
hold on 不抹去之前的图层</br>
hold off 回复默认</br>
close all 关闭所有图</br>
plot(v1) 作用于向量，横轴索引，数轴为值</br>
plot(v1,'LineWidth',5)  设置线的属性</br>
plot(sample,v1,'ro','LineWidth',5) </br>
title('TITLE') 字符串使用单引号</br>
ylabel('产量')</br>
xlabel('时间')</br>
legend('产能')图例</br>

### Logical Operations and Variables
> < == ~= 返回值 1 (true) 0 (false)</br>
pi > 3 </br>
test = pi > 3 </br>
[5 10 15] > 12 返回值 [0 0 1]</br>
[5 10 15] > [6 9 20] 返回值 [0 1 0] </br>

### Combining Logical Conditions
 & (与) or(或)</br>

 ### Logical Indexing
 You can use a logical array as an array index, in which case MATLAB extracts the array elements where the index is true. The following example will extract all elements in v1 that are greater than six.</br>
 ```
 >> v = v1 (v1 > 6)
 v =
    6.6678
    9.0698
```
Try creating a variable `s` that contais the elements in `sample` corresponding to where `v1` is less than `4`</br>
`s = sample(v1 < 4)`
x(x == 999) = 0</br>
x(x > 5) = 10</br>

### Decision Branching
Each if statement must contain one if keyword and one end keyword, and code between the if and end keywords is executed only when the condition is met</br>
```
x = rand;
if x > 0.5
    y = 3; %Executed only if x > 0.5
end
```

```
x = rand;
if x > 0.5
    y = 3;
else
    y = 4;
end
```

### For Loops
```
for i = 1 : 3
    disp(i)
end
```

```
x = (11:15).^2;
for idx = 1 : 5
    disp(x(idx))
end
```
结果为121 144 169 196 255 </br>

### final project 
loglog 函数也是绘图的，两个坐标都是对数</br>




