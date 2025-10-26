<font style="color:rgb(38,38,38);">设计思路&实现步骤 </font>

<font style="color:rgb(38,38,38);">1.搭建环境配备文件   2.写程序</font>

<font style="color:rgb(38,38,38);">遇到的问题与解决⽅法 &关键截图或代码⽚段</font>

<font style="color:rgb(38,38,38);"></font>

_<font style="color:rgb(38,38,38);">Q传入MP4视频</font>_

<font style="color:rgb(38,38,38);">S关闭Ubuntu打开虚拟机设置 选择共享文件夹，路径指示到MP4</font>

<font style="color:#FFFFFF;background-color:#000000;">vmware-toolbox-cmd -v                    # 查看VMware Tools版本</font>

<font style="color:#FFFFFF;background-color:#000000;">sudo mkdir -p /mnt/hgfs                  # 创建挂载目录</font>

<font style="color:#FFFFFF;background-color:#000000;">sudo vmhgfs-fuse .host:/ /mnt/hgfs -o allow_other -o uid=1000  # 挂载共享文件夹</font>

<font style="color:#FFFFFF;background-color:#000000;">mount | grep -i vmhgfs                   # 检查挂载状态</font>

<font style="color:#FFFFFF;background-color:#000000;">ls -l /mnt/hgfs/                         # 列出共享文件夹内容</font>

<font style="color:#FFFFFF;background-color:#000000;">cd /mnt/hgfs/Share  		 # 进入共享文件夹</font>

<font style="color:#FFFFFF;background-color:#000000;">ls                               		# 查看里面的文件</font>

<font style="color:#FFFFFF;background-color:#000000;">cp  xx ~/Documents/		# 将文件xx复制到Ubuntu的文档目录</font>

---

Q<font style="color:rgb(34, 34, 38);">配置opencv环境</font>

<font style="color:rgb(34, 34, 38);">S</font>[https://blog.csdn.net/roadtohacker/article/details/121201073?utm_source=miniapp_weixin](https://blog.csdn.net/roadtohacker/article/details/121201073?utm_source=miniapp_weixin)不普适:

<font style="color:rgb(15, 17, 21);background-color:#FFFFFF;">库文件路径             find /usr -name "libopencv_*.so" 2>/dev/null</font>

<font style="color:rgb(15, 17, 21);">OpenCV头文件位置pkg-config --cflags opencv4</font><font style="color:rgb(15, 17, 21);background-color:#FFFFFF;"> -I/usr/include/opencv4</font>

<font style="color:rgb(15, 17, 21);background-color:#FFFFFF;">把前三行改成</font>

<font style="color:rgb(15, 17, 21);background-color:#FFFFFF;">"-I", "/usr/include",                    </font>

<font style="color:rgb(15, 17, 21);background-color:#FFFFFF;">"-I", "/usr/include/opencv4",           </font>

<font style="color:rgb(15, 17, 21);background-color:#FFFFFF;">"-L", "/usr/lib/x86_64-linux-gnu"</font>

添加 "cppStandard": "c++17",

includePath中添加

"/usr/include/opencv4",        

 "/usr/include/x86_64-linux-gnu/opencv4"

<font style="color:rgb(15, 17, 21);background-color:#FFFFFF;"> </font>

---

_<font style="color:#FFFFFF;background-color:#000000;">Q:CMake Error at CMakeLists.txt:9 (target_compile_definitions):Cannot specify compile definitions for target "TrafficLight" which is notbuilt by this project.</font>_

<font style="color:rgb(38,38,38);">S把  target_compile_definitions 放在add_executable  之后</font>

---

_Q__<font style="color:#FFFFFF;background-color:#000000;">CMake Error at CMakeLists.txt:9 (add_executable):Cannot find source file: test.cpp</font>_

<font style="color:#000000;background-color:#FFFFFF;">S指定 traffic 目录下的 test.cpp: add_executable(${PROJECT_NAME} </font>**<font style="color:#000000;background-color:#FFFFFF;">traffic/</font>**<font style="color:#000000;background-color:#FFFFFF;">test.cpp)</font>

<font style="color:#000000;background-color:#FFFFFF;">    </font>**<font style="color:#000000;background-color:#FFFFFF;">         </font>****<font style="color:#000000;background-color:#FBDE28;"> ↑   test.cpp在项目中不用加/,在项目的一个文件夹里就加/</font>**

---

_<font style="color:#000000;background-color:#FFFFFF;">QTrafficLight.mp4文件路径不对</font>_

<font style="color:#000000;background-color:#FFFFFF;">S"/home/ssk/TrafficLight/TrafficLight.mp4"或"../TrafficLight.mp4"</font>

---

_Q窗口过大_

S  <font style="color:#FFFFFF;background-color:#000000;">namedWindow("交通灯视频", WINDOW_FREERATIO);</font>

<font style="color:#FFFFFF;background-color:#FFFFFF;">    </font><font style="color:#FFFFFF;background-color:#000000;">resizeWindow("交通灯视频", 800, 600);</font>

---



