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
legend('产能')图例</br>






