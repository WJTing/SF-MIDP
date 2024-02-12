# -*- coding: utf-8 -*-
"""
Created on Tue Jan 16 19:39:07 2024

@author: 10021
"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif']='SimHei'
plt.rcParams['axes.unicode_minus']=False
from pylab import mpl

data=pd.DataFrame(columns=('The length of genomes', 'OptimalSolution', 'BasicInsert',
       'time2(ms)', 'GreedyScaffoldFilling', 'time3(ms)',
       'LocalSearchScaffoldFilling', 'time4(ms)',
       'SLocalSearchScaffoldFilling(s = 2)', 'time5(ms)',
       'Approximation factor'))

data100=pd.read_csv('record/record0119100.csv')
data100.drop(columns=['SLocalSearchScaffoldFilling(s = 3)','time6(ms)'], inplace=True)
data100.dropna(inplace=True)
data100['Approximation factor'] = data100.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 2)'],axis=1)
mean=data100.mean()
data.loc[0]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['Approximation factor']]

data200=pd.read_csv('record/record0119200.csv')
data200.drop(columns=['SLocalSearchScaffoldFilling(s = 3)','time6(ms)'], inplace=True)
data200.dropna(inplace=True)
data200['Approximation factor'] = data200.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 2)'],axis=1)
mean=data200.mean()
data.loc[1]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['Approximation factor']]

data300=pd.read_csv('record/record0119300.csv')
data300.drop(columns=['SLocalSearchScaffoldFilling(s = 3)','time6(ms)'], inplace=True)
data300.dropna(inplace=True)
data300['Approximation factor'] = data300.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 2)'],axis=1)
mean=data300.mean()
data.loc[2]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['Approximation factor']]

data400=pd.read_csv('record/record0120400.csv')
data400.drop(columns=['SLocalSearchScaffoldFilling(s = 3)','time6(ms)'], inplace=True)
data400.dropna(inplace=True)
data400['Approximation factor'] = data400.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 2)'],axis=1)
mean=data400.mean()
data.loc[3]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['Approximation factor']]

data500=pd.read_csv('record/record0119500.csv')
data500.drop(columns=['SLocalSearchScaffoldFilling(s = 3)','time6(ms)'], inplace=True)
data500.dropna(inplace=True)
data500['Approximation factor'] = data500.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 2)'],axis=1)
mean=data500.mean()
data.loc[4]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['Approximation factor']]

data600=pd.read_csv('record/record0121600.csv')
data600.drop(columns=['SLocalSearchScaffoldFilling(s = 3)','time6(ms)'], inplace=True)
data600.dropna(inplace=True)
data600['Approximation factor'] = data600.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 2)'],axis=1)
mean=data600.mean()
data.loc[5]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['Approximation factor']]

data700=pd.read_csv('record/record0122700.csv')
data700.drop(columns=['SLocalSearchScaffoldFilling(s = 3)','time6(ms)'], inplace=True)
data700.dropna(inplace=True)
data700['Approximation factor'] = data700.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 2)'],axis=1)
mean=data700.mean()
data.loc[6]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['Approximation factor']]

data800=pd.read_csv('record/record0123800.csv')
data800.drop(columns=['SLocalSearchScaffoldFilling(s = 3)','time6(ms)'], inplace=True)
data800.dropna(inplace=True)
data800['Approximation factor'] = data800.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 2)'],axis=1)
mean=data800.mean()
data.loc[7]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['Approximation factor']]

data900=pd.read_csv('record/record0202900.csv')
data900.drop(columns=['SLocalSearchScaffoldFilling(s = 3)','time6(ms)'], inplace=True)
data900.dropna(inplace=True)
data900['Approximation factor'] = data900.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 2)'],axis=1)
mean=data900.mean()
data.loc[8]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['Approximation factor']]

data1000=pd.read_csv('record/record01311000.csv')
data1000.drop(columns=['SLocalSearchScaffoldFilling(s = 3)','time6(ms)'], inplace=True)
data1000.dropna(inplace=True)
data1000['Approximation factor'] = data1000.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 2)'],axis=1)
mean=data1000.mean()
data.loc[9]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['Approximation factor']]

data['The length of genomes'] =  data['The length of genomes'].astype(int)

plt.figure()
mpl.rcParams['font.sans-serif'] = ['SimHei']
x = np.arange(0,10,1)
bar_width = 0.15  
tick_label=data['The length of genomes']
plt.bar(x, data['OptimalSolution'], bar_width, align='center', label='OptimalSolution')
plt.bar(x+bar_width, data['SLocalSearchScaffoldFilling(s = 2)'], bar_width, align='center', label='SLocalSearchScaffoldFilling(s = 2)')
plt.bar(x+2*bar_width, data['LocalSearchScaffoldFilling'], bar_width, align='center', label='LocalSearchScaffoldFilling')
plt.bar(x+3*bar_width, data['GreedyScaffoldFilling'], bar_width, align='center', label='GreedyScaffoldFilling')
plt.bar(x+4*bar_width, data['BasicInsert'], bar_width, align='center', label='BasicInsert')
plt.xlabel('基因组框架的长度')
plt.ylabel('增加的保留有序对数量')
plt.title('不同长度数据算法效果比较')
plt.xticks(x+2*bar_width, tick_label)
plt.legend()
plt.show()

plt.figure()
plt.subplot(221)
plt.plot(data['The length of genomes'],data['time5(ms)'],linestyle='--',marker='d',color='red',label='SLocalSearchScaffoldFilling(s = 2)')
plt.plot(data['The length of genomes'],data['time4(ms)'],linestyle='--',marker='o',color='blue',label='LocalSearchScaffoldFilling')
plt.legend()
plt.xticks(range(100,1001,100))
plt.xlabel('基因组框架的长度')
plt.ylabel('程序消耗的时间(ms)')

plt.subplot(222)
plt.plot(data['The length of genomes'],data['time4(ms)'],linestyle='--',marker='o',color='blue',label='LocalSearchScaffoldFilling')
plt.plot(data['The length of genomes'],data['time3(ms)'],linestyle='--',marker='^',color='purple',label='GreedyScaffoldFilling')
plt.legend()
plt.xticks(range(100,1001,100))
plt.xlabel('基因组框架的长度')
plt.ylabel('程序消耗的时间(ms)')

plt.subplot(223)
plt.plot(data['The length of genomes'],data['time3(ms)'],linestyle='--',marker='^',color='purple',label='GreedyScaffoldFilling')
plt.plot(data['The length of genomes'],data['time2(ms)'],linestyle='--',marker='x',color='green',label='BasicInsert')
plt.legend()
plt.xticks(range(100,1001,100))
plt.xlabel('基因组框架的长度')
plt.ylabel('程序消耗的时间(ms)')
plt.show()

plt.figure()
plt.scatter(data['The length of genomes'], data['Approximation factor'],marker='^',label='Approximation factor(s=2)')
plt.xticks(range(100,1001,100))
plt.ylim(1,1.5)
y_mean = np.mean(data['Approximation factor'])
plt.axhline(y=y_mean, linestyle='-',color='red',label='Average Approximation factor')
plt.xlabel('基因组框架的长度')
plt.ylabel('近似性能比')
plt.title('近似性能比')
plt.legend()
plt.show()


data1=pd.DataFrame(columns=('The length of genomes', 'OptimalSolution', 'BasicInsert', 'time2(ms)',
       'GreedyScaffoldFilling', 'time3(ms)', 'LocalSearchScaffoldFilling',
       'time4(ms)', 'SLocalSearchScaffoldFilling(s = 2)', 'time5(ms)',
       'SLocalSearchScaffoldFilling(s = 3)', 'time6(ms)',
       'Approximation factor'))

data1100=pd.read_csv('record1/record0207100.csv')
data1100['Approximation factor'] = data1100.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 3)'],axis=1)
mean=data1100.mean()
data1.loc[0]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['SLocalSearchScaffoldFilling(s = 3)'],mean['time6(ms)'],mean['Approximation factor']]

data1110=pd.read_csv('record1/record0207110.csv')
data1110.dropna(inplace=True)
data1110['Approximation factor'] = data1110.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 3)'],axis=1)
mean=data1110.mean()
data1.loc[1]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['SLocalSearchScaffoldFilling(s = 3)'],mean['time6(ms)'],mean['Approximation factor']]

data1120=pd.read_csv('record1/record0207120.csv')
data1120.dropna(inplace=True)
data1120['Approximation factor'] = data1120.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 3)'],axis=1)
mean=data1120.mean()
data1.loc[2]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['SLocalSearchScaffoldFilling(s = 3)'],mean['time6(ms)'],mean['Approximation factor']]

data1130=pd.read_csv('record1/record0207130.csv')
data1130.dropna(inplace=True)
data1130['Approximation factor'] = data1130.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 3)'],axis=1)
mean=data1130.mean()
data1.loc[3]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['SLocalSearchScaffoldFilling(s = 3)'],mean['time6(ms)'],mean['Approximation factor']]

data1140=pd.read_csv('record1/record0207140.csv')
data1140.dropna(inplace=True)
data1140['Approximation factor'] = data1140.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 3)'],axis=1)
mean=data1140.mean()
data1.loc[4]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['SLocalSearchScaffoldFilling(s = 3)'],mean['time6(ms)'],mean['Approximation factor']]

data1150=pd.read_csv('record1/record0207150.csv')
data1150.dropna(inplace=True)
data1150['Approximation factor'] = data1150.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 3)'],axis=1)
mean=data1150.mean()
data1.loc[5]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['SLocalSearchScaffoldFilling(s = 3)'],mean['time6(ms)'],mean['Approximation factor']]

data1160=pd.read_csv('record1/record0207160.csv')
data1160.dropna(inplace=True)
data1160['Approximation factor'] = data1160.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 3)'],axis=1)
mean=data1160.mean()
data1.loc[6]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['SLocalSearchScaffoldFilling(s = 3)'],mean['time6(ms)'],mean['Approximation factor']]

data1170=pd.read_csv('record1/record0207170.csv')
data1170.dropna(inplace=True)
data1170['Approximation factor'] = data1170.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 3)'],axis=1)
mean=data1170.mean()
data1.loc[7]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['SLocalSearchScaffoldFilling(s = 3)'],mean['time6(ms)'],mean['Approximation factor']]

data1180=pd.read_csv('record1/record0207180.csv')
data1180.dropna(inplace=True)
data1180['Approximation factor'] = data1180.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 3)'],axis=1)
mean=data1180.mean()
data1.loc[8]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['SLocalSearchScaffoldFilling(s = 3)'],mean['time6(ms)'],mean['Approximation factor']]

data1190=pd.read_csv('record1/record0207190.csv')
data1190.dropna(inplace=True)
data1190['Approximation factor'] = data1190.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 3)'],axis=1)
mean=data1190.mean()
data1.loc[9]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['SLocalSearchScaffoldFilling(s = 3)'],mean['time6(ms)'],mean['Approximation factor']]

data1200=pd.read_csv('record1/record0207200.csv')
data1200.dropna(inplace=True)
data1200['Approximation factor'] = data1200.apply(lambda x:x['OptimalSolution']/x['SLocalSearchScaffoldFilling(s = 3)'],axis=1)
mean=data1200.mean()
data1.loc[10]=[mean['The length of genomes'],mean['OptimalSolution'],mean['BasicInsert'],mean['time2(ms)'],mean['GreedyScaffoldFilling'],mean['time3(ms)'],mean['LocalSearchScaffoldFilling'],mean['time4(ms)'],mean['SLocalSearchScaffoldFilling(s = 2)'],mean['time5(ms)'],mean['SLocalSearchScaffoldFilling(s = 3)'],mean['time6(ms)'],mean['Approximation factor']]

data1['The length of genomes'] =  data1['The length of genomes'].astype(int)

plt.figure()
x = np.arange(0,11,1)
bar_width = 0.15  
tick_label=data1['The length of genomes']
plt.bar(x, data1['OptimalSolution'], bar_width, align='center', label='OptimalSolution')
plt.bar(x+bar_width, data1['SLocalSearchScaffoldFilling(s = 3)'], bar_width, align='center', label='SLocalSearchScaffoldFilling(s = 3)')
plt.bar(x+2*bar_width, data1['SLocalSearchScaffoldFilling(s = 2)'], bar_width, align='center', label='SLocalSearchScaffoldFilling(s = 2)')
plt.bar(x+3*bar_width, data1['LocalSearchScaffoldFilling'], bar_width, align='center', label='LocalSearchScaffoldFilling')
plt.bar(x+4*bar_width, data1['GreedyScaffoldFilling'], bar_width, align='center', label='GreedyScaffoldFilling')
plt.bar(x+5*bar_width, data1['BasicInsert'], bar_width, align='center', label='BasicInsert')
plt.xlabel('基因组框架的长度')
plt.ylabel('增加的保留有序对数量')
plt.title('不同长度数据算法效果比较')
plt.xticks(x+2.5*bar_width, tick_label)
plt.legend()
plt.show()

plt.figure()
plt.subplot(221)
plt.plot(data1['The length of genomes'],data1['time6(ms)'],linestyle='--',marker='v',color='orange',label='SLocalSearchScaffoldFilling(s = 3)')
plt.plot(data1['The length of genomes'],data1['time5(ms)'],linestyle='--',marker='d',color='red',label='SLocalSearchScaffoldFilling(s = 2)')
plt.legend()
plt.xticks(range(100,201,10))
plt.xlabel('基因组框架的长度')
plt.ylabel('程序消耗的时间(ms)')

plt.subplot(222)
plt.plot(data1['The length of genomes'],data1['time5(ms)'],linestyle='--',marker='d',color='red',label='SLocalSearchScaffoldFilling(s = 2)')
plt.plot(data1['The length of genomes'],data1['time4(ms)'],linestyle='--',marker='o',color='blue',label='LocalSearchScaffoldFilling')
plt.legend()
plt.xticks(range(100,201,10))
plt.xlabel('基因组框架的长度')
plt.ylabel('程序消耗的时间(ms)')

plt.subplot(223)
plt.plot(data1['The length of genomes'],data1['time4(ms)'],linestyle='--',marker='o',color='blue',label='LocalSearchScaffoldFilling')
plt.plot(data1['The length of genomes'],data1['time3(ms)'],linestyle='--',marker='^',color='purple',label='GreedyScaffoldFilling')
plt.legend()
plt.xticks(range(100,201,10))
plt.xlabel('基因组框架的长度')
plt.ylabel('程序消耗的时间(ms)')

plt.subplot(224)
plt.plot(data1['The length of genomes'],data1['time3(ms)'],linestyle='--',marker='^',color='purple',label='GreedyScaffoldFilling')
plt.plot(data1['The length of genomes'],data1['time2(ms)'],linestyle='--',marker='x',color='green',label='BasicInsert')
plt.legend()
plt.xticks(range(100,201,10))
plt.xlabel('基因组框架的长度')
plt.ylabel('程序消耗的时间(ms)')
plt.show()

plt.figure()
plt.scatter(data1['The length of genomes'],data1['Approximation factor'],marker='v',label='Approximation factor(s=3)')
plt.xticks(range(100,201,10))
plt.ylim(1,1.5)
y_mean1 = np.mean(data1['Approximation factor'])
plt.axhline(y=y_mean1, linestyle='-',color='orange',label='Average Approximation factor')
plt.xlabel('基因组框架的长度')
plt.ylabel('近似性能比')
plt.title('近似性能比')
plt.legend()
plt.show()