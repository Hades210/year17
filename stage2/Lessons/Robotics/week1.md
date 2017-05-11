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
Ĭ�ϱ���ans</br>
m = 3 * 5 ��������</br>
m = m + 1  ��ֵ����</br>
y = m / 2 workspace����ʾ����������Ϣ</br>
k - 8 - 2; semicolon��ִ���������չ����command window��</br>
��command window��ʹ��up������ʷ���������ʷ����������޸�</br>
����������س������ظñ�����ֵ </br>
##### Sorting Data in Variables
������������,��ĸ��ͷ���������� ��ĸ _ </br>
clear��������б���</br>
clcֻ���command window</br>
##### Using Built-in Functions and Constants
���ó���������pi</br>
���ú���������sin()</br>
z = sqrt(-9)  i�ǳ���</br>

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
space ��дʱ��Ĭ��Ϊ1</br>

x = linspace(first,last,number_of_elements)</br>
:��linspace��������������</br>
x = x' ת��</br>

x = (5 : 2 : 9)' </br>
x = linspace(5,9,3)' </br>

Array Creation Functions</br>
x = rand (5) 5by5 matrix </br>
x = rand (5, 1) 5by1 matrix </br>
x = zeros(6,3) 6by3 ȫ�����</br>

### Saving and Loading Variables
save foo x ������x���浽foo.mat�ļ���</br>
load foo ��foo.mat�ļ��м���</br>

### Indexing into Arrays

x = A(6,3) ȡ����A�ĵ�6�У���3�е�����</br>
x = A(end,3) ���һ�У���3��</br>
x = A(end - 2, end - 3)</br>

### Extracting Multiple Elements

x = data(2,:) �ڶ��е���������</br>
x = data(:,2) �ڶ��е���������</br>

x = data(1:3,:) 1��3�У�������</br>
x = data(:,end-1:end) ������У�������</br>

x = v(3) v����������/�У���3��Ԫ��</br>
x = v(3:5) </br>

v(2) = 5 </br>

### Perform Array Operations on Vectors
y = x + 1 ÿһ��Ԫ�ض���1</br>

z = z1 + z2 z1��z2ͬ��ʱ�������</br>

za = z/2 </br>

zm = max(za)</br>
xSqrt = sqrt(x)</br>
vr = round(va) ��������</br>

\* ����˷�</br>
.* ���(��ӦԪ����ƣ���������Ҫ��ͬ)</br>

### Obtaining Multiple Outputs from Function Calls

dsize = size(data) �������� ����</br>
[dr,dc] = size(data) �������� ����</br>
[vMax,ivMax] = max(v) �������ֵ��������</br>

doc fcnName �򿪺��������ֲ�</br>

### Plotng vectors
ͬ����С��������ʹ��plot(x,y)����ͼ��</br>
plot(x,y,'r--o')�����ߵ�����</br>
hold on ��Ĩȥ֮ǰ��ͼ��</br>
hold off �ظ�Ĭ��</br>
close all �ر�����ͼ</br>
plot(v1) ��������������������������Ϊֵ</br>
plot(v1,'LineWidth',5)  �����ߵ�����</br>
plot(sample,v1,'ro','LineWidth',5) </br>
title('TITLE') �ַ���ʹ�õ�����</br>
ylabel('����')</br>
legend('����')ͼ��</br>






