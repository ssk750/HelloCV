## 一、Docker 与虚拟机的区别
这是一个根本性的区别，理解它就能明白 Docker 为什么这么轻量和快速。

| **特性** | **虚拟机 (VM)** | **Docker 容器** |
| --- | --- | --- |
| **抽象层级** | 硬件级虚拟化 | 操作系统级虚拟化 |
| **隔离单位** | 完整的虚拟机（包括虚拟硬件、内核、系统） | 应用进程（共享主机内核 |
| **Guest OS** | 每个 VM 都需要独立的完整操作系统 | 所有容器共享主机操作系统内核（无需完整OS） |
| **性能** | 较重，性能有损耗 | 轻量，接近原生性能 |
| **启动速度** | 慢（分钟级） | 极快（秒级甚至毫秒级） |
| **磁盘占用** | 大（通常 GB 级别） | 小（通常 MB 级别） |
| **隔离性** | 强（完全隔离，更安全 | 较弱（进程级隔离，内核共享） |




## 二、核心概念
**镜像** (Image)

定义：一个只读的模板，用于创建容器。它包含了运行应用所需的一切：代码、运行时、库、环境变量和配置文件。

**容器 **(Container)

定义：镜像的一个运行实例。你可以创建、启动、停止、移动或删除容器。

**仓库** (Registry) / Docker Hub

定义：一个集中存储和分发镜像的地方。

Docker Hub：是 Docker 官方提供的公共仓库，就像 GitHub 对于代码一样，里面有海量的官方和个人制作的镜像。

**分层镜像结构**

概念：Docker 镜像由一系列只读层叠加而成。每一层代表 Dockerfile 中的一条指令。

好处：

共享层：多个镜像可以共享相同的底层（如 ubuntu 基础层），节省磁盘空间和下载时间。

高效构建：构建镜像时，只有被修改的层需要重新构建，缓存机制使得构建速度极快。

## 三、常用命令
| <font style="color:rgb(15, 17, 21);">命令</font> | <font style="color:rgb(15, 17, 21);">作用</font> | <font style="color:rgb(15, 17, 21);">常用参数示例</font> |
| --- | --- | --- |
| `<font style="color:rgb(15, 17, 21);background-color:#FFFFFF;">docker pull <镜像名></font>` | <font style="color:rgb(15, 17, 21);">从仓库拉取镜像</font> | `<font style="color:rgb(15, 17, 21);">docker pull nginx:latest</font>` |
| `<font style="color:rgb(15, 17, 21);background-color:#FFFFFF;">docker images</font>` | <font style="color:rgb(15, 17, 21);">列出本地所有镜像</font> | |
| `<font style="color:rgb(15, 17, 21);">docker run <镜像名></font>` | **<font style="color:rgb(15, 17, 21);">创建并启动</font>**<font style="color:rgb(15, 17, 21);">一个新容器</font> | `<font style="color:rgb(15, 17, 21);">-d</font>`<br/><font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">后台运行，</font>`<font style="color:rgb(15, 17, 21);">-p 80:80</font>`<br/><font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">端口映射，</font>`<font style="color:rgb(15, 17, 21);">--name mynginx</font>`<br/><font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">给容器命名</font> |
| `<font style="color:rgb(15, 17, 21);">docker ps</font>` | <font style="color:rgb(15, 17, 21);">列出正在运行的容器</font> | `<font style="color:rgb(15, 17, 21);">-a</font>`<br/><font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">列出所有容器（包括已停止的）</font> |
| `<font style="color:rgb(15, 17, 21);">docker stop <容器ID/名></font>` | <font style="color:rgb(15, 17, 21);">停止一个运行中的容器</font> | `<font style="color:rgb(15, 17, 21);">docker stop mynginx</font>` |
| `<font style="color:rgb(15, 17, 21);">docker rm <容器ID/名></font>` | **<font style="color:rgb(15, 17, 21);">删除</font>**<font style="color:rgb(15, 17, 21);">一个已停止的容器</font> | `<font style="color:rgb(15, 17, 21);">-f</font>`<br/><font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">强制删除（包括运行中的）</font> |
| `<font style="color:rgb(15, 17, 21);">docker rmi <镜像ID></font>` | **<font style="color:rgb(15, 17, 21);">删除</font>**<font style="color:rgb(15, 17, 21);">一个本地镜像</font> | |
| `<font style="color:rgb(15, 17, 21);">docker exec <容器ID/名></font>` | <font style="color:rgb(15, 17, 21);">在正在运行的容器中执行命令</font> | `<font style="color:rgb(15, 17, 21);">-it /bin/bash</font>`<br/><font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">进入容器交互式终端</font> |
| `<font style="color:rgb(15, 17, 21);">docker logs <容器ID/名></font>` | <font style="color:rgb(15, 17, 21);">查看容器的日志输出</font> | `<font style="color:rgb(15, 17, 21);">-f</font>`<br/><font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">持续跟踪日志</font> |


命令示例组合：

1. 拉取一个 Nginx 镜像

docker pull nginx

2. 以后台模式运行，并做端口映射，命名为 my-web

docker run -d -p 8080:80 --name my-web nginx

3. 查看正在运行的容器

docker ps

4. 查看容器日志

docker logs my-web

5. 进入容器内部（像连接到一个迷你Linux）

docker exec -it my-web /bin/bash

6. 停止并删除容器

docker stop my-web

docker rm my-web

7. 删除 nginx 镜像

docker rmi nginx

## 四、Dockerfile
Dockerfile 是一个文本文件，里面包含了一条条的指令(Instruction)，用来说明如何构建一个 Docker 镜像。

**基本结构与指令**：

| <font style="color:rgb(15, 17, 21);">指令</font> | <font style="color:rgb(15, 17, 21);">作用</font> |
| --- | --- |
| `<font style="color:rgb(15, 17, 21);">FROM <基础镜像></font>` | **<font style="color:rgb(15, 17, 21);">指定基础镜像</font>**<font style="color:rgb(15, 17, 21);">。必须是第一条指令。例如</font><font style="color:rgb(15, 17, 21);"> </font>`<font style="color:rgb(15, 17, 21);">FROM ubuntu:20.04</font>` |
| `<font style="color:rgb(15, 17, 21);">RUN <命令></font>` | **<font style="color:rgb(15, 17, 21);">执行命令</font>**<font style="color:rgb(15, 17, 21);">并创建新的镜像层。常用于安装软件包。例如</font><font style="color:rgb(15, 17, 21);"> </font>`<font style="color:rgb(15, 17, 21);">RUN apt-get update && apt-get install -y python3</font>` |
| `<font style="color:rgb(15, 17, 21);">COPY <源路径> <目标路径></font>` | **<font style="color:rgb(15, 17, 21);">从宿主机复制文件或目录</font>**<font style="color:rgb(15, 17, 21);">到容器内。</font> |
| `<font style="color:rgb(15, 17, 21);">WORKDIR <工作目录路径></font>` | **<font style="color:rgb(15, 17, 21);">设置工作目录</font>**<font style="color:rgb(15, 17, 21);">。相当于</font><font style="color:rgb(15, 17, 21);"> </font>`<font style="color:rgb(15, 17, 21);">cd</font>`<br/><font style="color:rgb(15, 17, 21);">，如果目录不存在则会创建。</font> |
| `<font style="color:rgb(15, 17, 21);">CMD ["可执行文件", "参数1", "参数2"]</font>` | **<font style="color:rgb(15, 17, 21);">指定容器启动时默认运行的命令</font>**<font style="color:rgb(15, 17, 21);">。一个 Dockerfile 只能有一条</font><font style="color:rgb(15, 17, 21);"> </font>`<font style="color:rgb(15, 17, 21);">CMD</font>`<br/><font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">指令。</font> |


一个简单的 Dockerfile **示例**：

#使用 Python 3.9 作为基础镜像

FROM python:3.9-slim

#设置工作目录为 /app

WORKDIR /app

#将当前目录下的所有文件复制到容器的 /app 目录下

COPY . /app

#安装依赖

RUN pip install -r requirements.txt

#告诉 Docker 容器在运行时监听 80 端口

EXPOSE 80

#定义环境变量

ENV NAME World

#容器启动时运行 app.py

CMD ["python", "app.py"]

**构建镜像**：

#在 Dockerfile 所在目录执行，-t 用于给镜像命名

docker build -t my-python-app .

## 五、端口映射
问题：容器有自己的内部网络，默认与宿主机是隔离的。外部无法直接访问容器内运行的服务（如 Nginx 的 80 端口）。

解决方案：使用 -p 参数进行端口映射。

语法：-p <宿主机端口>:<容器内部端口>

示例：

#将容器的 80 端口映射到宿主机的 8080 端口

docker run -d -p 8080:80 nginx

执行后，在宿主机上通过浏览器访问 [http://localhost:8080](http://localhost:8080) 就能看到容器内 Nginx 的服务。

## 六、Docker Hub 的使用
**搜索**镜像：

在 Docker Hub 网站 (hub.docker.com) 上搜索。

或使用命令行：docker search <关键词>

**拉取**镜像：

#拉取官方镜像（如 Redis）

docker pull redis

#拉取特定版本

docker pull redis:6.2-alpine

#拉取个人发布的镜像

docker pull username/repository-name

**推送**镜像（需要注册 Docker Hub 账号）：

1. 给本地镜像打标签

docker tag my-app myusername/my-app:latest

2. 登录 Docker Hub

docker login

3. 推送镜像

docker push myusername/my-app:latest



