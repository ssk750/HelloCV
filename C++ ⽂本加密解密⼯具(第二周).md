<font style="color:rgb(38,38,38);">设计思路&实现步骤</font>

<font style="color:rgb(38,38,38);">1.</font><font style="color:rgb(38,38,38);">编写 CMakeLists.txt ⽂件，为vs code配置CMake。</font>

<font style="color:rgb(38,38,38);">2.编写代码</font>

<font style="color:rgb(38,38,38);">遇到的问题与解决⽅法 &关键截图或代码⽚段</font>

**1.配置CMake**

一开始没有配置cmake,只着手于launch.json和task.json。报错



![](https://cdn.nlark.com/yuque/0/2025/png/61266488/1760935395799-ce7d1590-69c9-4cdd-b8e3-8db2993e8737.png)

![](https://cdn.nlark.com/yuque/0/2025/png/61266488/1760935440778-2e6e2af8-0a31-45ac-bb73-cd8cb8c450ee.png)

解决方法：

1.<font style="color:#FFFFFF;background-color:#000000;">"args": [</font>

<font style="color:#FFFFFF;background-color:#000000;">    "-fdiagnostics-color=always",</font>

<font style="color:#FFFFFF;background-color:#000000;">    "-g",</font>

<font style="color:#FFFFFF;background-color:#000000;">    "crypto/main.cpp",</font>

<font style="color:#FFFFFF;background-color:#000000;">    "include/menu.cpp",</font>

<font style="color:#FFFFFF;background-color:#000000;">    "-Iinclude",</font>

<font style="color:#FFFFFF;background-color:#000000;">    "-o",</font>

<font style="color:#FFFFFF;background-color:#000000;">    "crypto/main"],</font>

2.把 cwd 从 ${fileDirname} 改为 ${workspaceFolder}

2.添加"preLaunchTask": "C/C++: g++ 生成活动文件"

3.在 setupCommands 数组的结束花括号 ] 后面加上逗号，然后再写 miDebuggerPath

4."miDebuggerPath": "/usr/bin/gdb"

<font style="color:#FFFFFF;background-color:#000000;"></font>**<font style="color:#000000;background-color:#FFFFFF;">2.配置c++IntelliSense</font>**

<font style="color:#000000;background-color:#FFFFFF;">包含路径</font>

<font style="color:#000000;background-color:#FFFFFF;">${workspaceFolder}/**</font>

<font style="color:#000000;background-color:#FFFFFF;">/home/ssk/decode/include/**</font>

<font style="color:#000000;background-color:#FFFFFF;">/usr/include</font>

<font style="color:#000000;background-color:#FFFFFF;">/usr/local/include</font>

编译器路径

/usr/bin/g++

**3.配置CMake**

安装CMake Tool扩展

配置见[https://www.yuque.com/sunshukai-fe8wb/vcwfhz/qvumeuq0edl5v8hy?singleDoc#](https://www.yuque.com/sunshukai-fe8wb/vcwfhz/qvumeuq0edl5v8hy?singleDoc#) 

配置CMake时要保证代码完整。

核心代码

cd build

make

./CryptoTool

**4.代码**

流的语法

![](https://cdn.nlark.com/yuque/0/2025/jpeg/61266488/1760938617295-37c7c506-22c3-45f7-a80d-ee0470cfcba9.jpeg)

![](https://cdn.nlark.com/yuque/0/2025/jpeg/61266488/1760938652193-3e14378c-28a9-4fb4-9b01-8b3360a6c8fc.jpeg)



![](https://cdn.nlark.com/yuque/0/2025/jpeg/61266488/1760938672871-ed6e7505-df24-4a73-9abe-3471054944c3.jpeg)



![](https://cdn.nlark.com/yuque/0/2025/jpeg/61266488/1760938687342-e4e79887-92b4-4aaa-90b1-621bd8fddcc6.jpeg)

创建文件指令:echo "Hello, World!" > input.txt

**出现的问题**

忘记在函数名前写Crypto::   FileHandler::  Menu::

---

头文件不需用using namespace  std.用std::

---

用cin>>终端会不停输出请输入:输入文本: 输入密钥:加密后的文本:。World!留在了缓冲区

解决方案:用cin.ignore() getline(cin,a)

---

使用windows的system ("pause")

解决方案:使用跨平台的，

<font style="color:#FFFFFF;background-color:#000000;">cout << "按回车键继续...";</font>

<font style="color:#FFFFFF;background-color:#000000;">cin.ignore(); </font>

<font style="color:#FFFFFF;background-color:#000000;">cin.get();  </font>

---

crosses initialization of ‘FileHandler file_2’ 

解决方案:为case增加{}，在switch之前声明变量input 

---

char encrypted_char = a[i] + b; 

char decrypted_char = a[i] -b; 加密标点符号，Hello, World! +3 → Khoor/#Zruog$

解决方案:

<font style="color:#FFFFFF;background-color:#000000;">if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {</font>

<font style="color:#FFFFFF;background-color:#000000;">            if (ch >= 'a' && ch <= 'z') {</font>

<font style="color:#FFFFFF;background-color:#000000;">                encrypted_char = 'a' + (ch - 'a' + b) % 26;</font>

<font style="color:#FFFFFF;background-color:#000000;">            } </font>

<font style="color:#FFFFFF;background-color:#000000;">            else {</font>

<font style="color:#FFFFFF;background-color:#000000;">                encrypted_char = 'A' + (ch - 'A' + b) % 26;</font>

<font style="color:#FFFFFF;background-color:#000000;">            }</font>

<font style="color:#FFFFFF;background-color:#000000;">        }</font>

<font style="color:#FFFFFF;background-color:#000000;">        else {</font>

<font style="color:#FFFFFF;background-color:#000000;">            encrypted_char = ch;</font>

<font style="color:#FFFFFF;background-color:#000000;">        }</font>

---

回车后只有ssk@ssk-virtual-machine:~/CryptoTool/build$

解决方案：case和1之间要有空格

---



