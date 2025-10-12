**<font style="color:rgb(38,38,38);">软件安装</font>**

更新软件包列表sudo apt update

安装软件sudo apt install package_name

卸载软件sudo apt remove package_name

搜索软件apt search keyword

列出已安装软件apt list --installed

安装 snap 包sudo snap install package_name

查看已安装的 snapsnap list

卸载 snap 包sudo snap remove package_name

**<font style="color:rgb(38,38,38);">⽂件管理</font>**

<font style="color:rgb(38,38,38);">ubuntu会把硬件装在一个文件中管理</font>

<font style="color:rgb(38,38,38);">列出文件</font>

<font style="color:rgb(38,38,38);">ls</font>

<font style="color:rgb(38,38,38);">ls -l    # 详细信息</font>

<font style="color:rgb(38,38,38);">ls -a    # 包括隐藏文件</font>

<font style="color:rgb(38,38,38);">ls -la   # 详细信息+隐藏文件</font>

<font style="color:rgb(38,38,38);">创建文件</font>

<font style="color:rgb(38,38,38);">touch filename.txt</font>

<font style="color:rgb(38,38,38);">复制文件</font>

<font style="color:rgb(38,38,38);">cp source.txt destination.txt</font>

<font style="color:rgb(38,38,38);">cp -r dir1 dir2  # 递归复制目录</font>

<font style="color:rgb(38,38,38);">移动/重命名文件</font>

<font style="color:rgb(38,38,38);">mv oldname.txt newname.txt</font>

<font style="color:rgb(38,38,38);">mv file.txt /path/to/destination/</font>

<font style="color:rgb(38,38,38);">删除文件</font>

<font style="color:rgb(38,38,38);">rm filename.txt</font>

<font style="color:rgb(38,38,38);">rm -r directory_name  # 递归删除目录</font>

<font style="color:rgb(38,38,38);">rm -rf directory_name # 强制递归删除</font>

<font style="color:rgb(38,38,38);">创建目录</font>

<font style="color:rgb(38,38,38);">mkdir new_directory</font>

<font style="color:rgb(38,38,38);">mkdir -p path/to/nested/directory  # 创建多级目录</font>

**<font style="color:rgb(38,38,38);">权限管理</font>**<font style="color:rgb(38,38,38);"> </font>

<font style="color:rgb(38,38,38);">drwxr-xr-x</font>

<font style="color:rgb(38,38,38);">││┌┌┌┌┌┌┌┌</font>

<font style="color:rgb(38,38,38);">│└┬┬┬┬┬┬┬┬ 文件类型 (d=目录, -=普通文件, l=链接)</font>

<font style="color:rgb(38,38,38);"> │└┬┬┬┬┬┬┬ 所有者权限 (rwx)</font>

<font style="color:rgb(38,38,38);">  │└┬┬┬┬┬┬ 所属组权限 (r-x)</font>

<font style="color:rgb(38,38,38);">   │└┬┬┬┬┬ 其他用户权限 (r-x)</font>

<font style="color:rgb(38,38,38);">查看权限</font>

<font style="color:rgb(38,38,38);">ls -l</font>

<font style="color:rgb(38,38,38);">更改权限 (数字方式)</font>

<font style="color:rgb(38,38,38);">chmod 755 filename    # rwxr-xr-x</font>

<font style="color:rgb(38,38,38);">chmod 644 filename    # rw-r--r--</font>

<font style="color:rgb(38,38,38);">更改权限 (符号方式)</font>

<font style="color:rgb(38,38,38);">chmod u+x filename    # 给所有者添加执行权限</font>

<font style="color:rgb(38,38,38);">chmod g-w filename    # 移除组的写权限</font>

<font style="color:rgb(38,38,38);">chmod o=r filename    # 设置其他用户只读</font>

<font style="color:rgb(38,38,38);"> 更改所有者</font>

<font style="color:rgb(38,38,38);">chown user:group filename</font>

<font style="color:rgb(38,38,38);">chown user filename</font>

<font style="color:rgb(38,38,38);">chown :group filename</font>

**<font style="color:rgb(38,38,38);">进程控制</font>**

<font style="color:rgb(38,38,38);">查看进程</font>

<font style="color:rgb(38,38,38);">ps aux                 # 查看所有进程</font>

<font style="color:rgb(38,38,38);">ps -ef | grep process_name</font>

<font style="color:rgb(38,38,38);">实时监控进程</font>

<font style="color:rgb(38,38,38);">top</font>

<font style="color:rgb(38,38,38);">htop                   # 需要安装，更友好的top</font>

<font style="color:rgb(38,38,38);">杀死进程</font>

<font style="color:rgb(38,38,38);">kill PID               # 温和终止</font>

<font style="color:rgb(38,38,38);">kill -9 PID            # 强制终止</font>

<font style="color:rgb(38,38,38);">pkill process_name     # 按名称终止</font>

<font style="color:rgb(38,38,38);">服务管理 (systemd)</font>

<font style="color:rgb(38,38,38);">sudo systemctl start service_name</font>

<font style="color:rgb(38,38,38);">sudo systemctl stop service_name</font>

<font style="color:rgb(38,38,38);">sudo systemctl restart service_name</font>

<font style="color:rgb(38,38,38);">sudo systemctl status service_name</font>

<font style="color:rgb(38,38,38);">sudo systemctl enable service_name   # 开机自启</font>

<font style="color:rgb(38,38,38);">sudo systemctl disable service_name  # 禁用开机自启</font>

**<font style="color:rgb(38,38,38);">根⽬录 作⽤</font>**

<font style="color:rgb(38,38,38);">/          根目录</font>

<font style="color:rgb(38,38,38);">/home      用户主目录</font>

<font style="color:rgb(38,38,38);">/etc       系统配置文件</font>

<font style="color:rgb(38,38,38);">/var       可变数据（日志、数据库等）</font>

<font style="color:rgb(38,38,38);">/tmp       临时文件</font>

<font style="color:rgb(38,38,38);">/usr       用户程序和数据</font>

<font style="color:rgb(38,38,38);">/bin       基本命令二进制文件</font>

<font style="color:rgb(38,38,38);">/boot      启动相关文件</font>

<font style="color:rgb(38,38,38);">/dev       设备文件</font>

<font style="color:rgb(38,38,38);">/opt       可选的应用软件包</font>

**<font style="color:rgb(38,38,38);">绝对路径 vs 相对路径</font>**

**<font style="color:rgb(38,38,38);"># 绝对路径 (从根目录开始)</font>**

<font style="color:rgb(38,38,38);">cd /home/user/documents</font>

<font style="color:rgb(38,38,38);"></font>

<font style="color:rgb(38,38,38);"># 相对路径 (从当前目录开始)</font>

<font style="color:rgb(38,38,38);">cd documents</font>

<font style="color:rgb(38,38,38);">cd ./documents</font>

<font style="color:rgb(38,38,38);">cd ../parent_directory</font>

**<font style="color:rgb(38,38,38);">基础服务管理（ systemd ）与⽹络配置</font>**

<font style="color:rgb(38,38,38);">查看IP地址</font>

<font style="color:rgb(38,38,38);">ip addr show</font>

<font style="color:rgb(38,38,38);">ifconfig</font>

<font style="color:rgb(38,38,38);">测试网络连接</font>

<font style="color:rgb(38,38,38);">ping google.com</font>

<font style="color:rgb(38,38,38);">查看路由表</font>

<font style="color:rgb(38,38,38);">ip route show</font>

<font style="color:rgb(38,38,38);">网络服务管理</font>

<font style="color:rgb(38,38,38);">sudo systemctl restart networking</font>

<font style="color:rgb(38,38,38);">sudo systemctl status network-manager</font>

**<font style="color:rgb(38,38,38);">Vim 编辑器⼊⻔： </font>**

**<font style="color:rgb(38,38,38);">模式切换（普通模式、插⼊模式、命令模式）； </font>**

<font style="color:rgb(38,38,38);">普通模式 → 插入模式: i, I, a, A, o, O</font>

<font style="color:rgb(38,38,38);">插入模式 → 普通模式: Esc</font>

<font style="color:rgb(38,38,38);">普通模式 → 命令模式: :</font>

**<font style="color:rgb(38,38,38);">基本操作：</font>**

<font style="color:rgb(38,38,38);">打开文件</font>

<font style="color:rgb(38,38,38);">vim filename.txt</font>

<font style="color:rgb(38,38,38);">常用命令</font>

<font style="color:rgb(38,38,38);">i          # 进入插入模式</font>

<font style="color:rgb(38,38,38);">Esc        # 返回普通模式</font>

<font style="color:rgb(38,38,38);">:w         # 保存</font>

<font style="color:rgb(38,38,38);">:q         # 退出</font>

<font style="color:rgb(38,38,38);">:wq        # 保存并退出</font>

<font style="color:rgb(38,38,38);">:q!        # 强制退出不保存</font>

<font style="color:rgb(38,38,38);">x          # 删除当前字符</font>

<font style="color:rgb(38,38,38);">dd         # 删除整行</font>

<font style="color:rgb(38,38,38);">u          # 撤销</font>

<font style="color:rgb(38,38,38);">Ctrl+r     # 重做</font>

<font style="color:rgb(38,38,38);">/pattern   # 搜索</font>

**<font style="color:rgb(38,38,38);">常⽤命令⾏⼯具</font>**

<font style="color:rgb(15, 17, 21);">grep - 文本搜索</font>

<font style="color:rgb(15, 17, 21);">grep "pattern" filename</font>

<font style="color:rgb(15, 17, 21);">grep -r "pattern" directory/  # 递归搜索</font>

<font style="color:rgb(15, 17, 21);">grep -i "pattern" filename    # 忽略大小写</font>

<font style="color:rgb(15, 17, 21);">grep -v "pattern" filename    # 反向匹配</font>

**<font style="color:rgb(15, 17, 21);">awk - 文本处理</font>**

<font style="color:rgb(15, 17, 21);">打印第一列</font>

<font style="color:rgb(15, 17, 21);">awk '{print $1}' filename</font>

<font style="color:rgb(15, 17, 21);"> 打印包含特定模式的行</font>

<font style="color:rgb(15, 17, 21);">awk '/pattern/ {print $0}' filename</font>

<font style="color:rgb(15, 17, 21);">使用分隔符</font>

<font style="color:rgb(15, 17, 21);">awk -F: '{print $1}' /etc/passwd</font>

**<font style="color:rgb(15, 17, 21);">sed - 流编辑器</font>**

<font style="color:rgb(15, 17, 21);">替换文本</font>

<font style="color:rgb(15, 17, 21);">sed 's/old/new/g' filename</font>

<font style="color:rgb(15, 17, 21);">删除行</font>

<font style="color:rgb(15, 17, 21);">sed '5d' filename              # 删除第5行</font>

<font style="color:rgb(15, 17, 21);">sed '/pattern/d' filename      # 删除匹配模式的行</font>

<font style="color:rgb(15, 17, 21);">原地修改文件</font>

<font style="color:rgb(15, 17, 21);">sed -i 's/old/new/g' filename</font>

**<font style="color:rgb(15, 17, 21);">tmux - 终端复用器</font>**

<font style="color:rgb(15, 17, 21);">tmux new -s session_name    # 创建新会话</font>

<font style="color:rgb(15, 17, 21);">tmux attach -t session_name # 连接到会话</font>

<font style="color:rgb(15, 17, 21);">Ctrl+b d                    # 分离会话</font>

<font style="color:rgb(15, 17, 21);">Ctrl+b c                    # 创建新窗口</font>

<font style="color:rgb(15, 17, 21);">Ctrl+b n                    # 下一个窗口</font>

<font style="color:rgb(15, 17, 21);">Ctrl+b p                    # 上一个窗口</font>

