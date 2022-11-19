# tetris

#### 介绍

1. 代码编辑器： 　==visual studio==
2. 使用的c++ 图形库：　==easyx==
3. 在 `main.cpp` 文件 直接运行该文件即可

C 语言 + easyx  实现俄罗斯方块

#### 软件架构
俄罗斯方块游戏逻辑  俄罗斯方块是在一块特定的长方形区域进行游戏运行，还有一个显示下一个方块的区域，得到的分数可以用一个变量贮存，然后在窗口打印出来，那么此时要完成这些基本游戏逻辑我们需要选择一个好的图形工具，可以画方块，可以画游戏区域和下一个方块提示，我们这里选择由C++开发的easyx图形开发库来实现，整个游戏开发最难的部分在于 如何在地图动态标记方块，和触边判断，

1. 第一步难度：两个星 1.用函数绘出所需窗口，设置好每一步的像素（还有一个方法是可以通过电脑的画图绘图出来，然后在游戏直接加载，注意加载像素和窗口像素要一样，这样可以美观的显示游戏区域了像这样：两张图对比）…）这个是最关键的一步，因为这里不配置好，后面要改的话已全部都要改，所以这里花时间是没问题的  

2. 第二步难度：三颗星 实现游戏逻辑（按照难度从小到大排序） 1.方块实现下落功能，2.触边判断（包括触底，触左，触右，实现了最重要触底，触右触左判断就可以举一反三了），3.随机生成方块，以及显示下一个出现的方块，4.方块用怎样的数据结构来存储 5.消行实现 

3. 第三步难度：两颗星 1.实现消行音效，2.游戏开始音效，3.游戏暂停同时停止音效（这里有个难点就是重新播放不会从 原本暂停地方重新播放，如果要实现我的想法是弄一个计时器）4.保存游戏分数最高记录

代码优化建议

1. 进行函数封装，可以分为几个头文件，例如实现页面窗口绘图的函数声明的，放在UI.h头文件中（user interface） 实现游戏逻辑函数声明的放在APP.h头文件中，再分别在UI.cpp，APP.cpp中进行函数实现，在主函数main.cpp中引入UI.h和APP.h文件 再运行主函数

2. .h头文件中（use interface） 实现游戏逻辑函数**声明**的放在APP.h头文件中，再分别在UI.cpp，APP.cpp中进行函数实现，在主函数main.cpp中引入UI.h和APP.h文件 再运行主函数


#### 使用说明
 在下载 前需要 再到easyx官网下载 easyx 库 直接搜即可 ，下载好 程序，再选择vscode的那个选项 安装即可、下载好了压缩包，解压后 ，在 `main.cpp` 文件 直接运行该文件即可正常游戏。中途有任何问题欢迎在项目中题issue哦！🙋‍♂️ 适合给自己女朋友一个惊喜嘿嘿，表面看完成C 语言课程设计作业，实际逗女朋友开心为主😉  总共五个文件 三个cpp ，两个头文件  在vscode创建c++/c项目放入代码即可 