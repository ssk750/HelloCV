**git版本控制的意义；**

1. **<font style="color:rgb(15, 17, 21);">版本回溯</font>**<font style="color:rgb(15, 17, 21);">：可以随时回到项目的任何一个历史状态。</font>
2. **<font style="color:rgb(15, 17, 21);">变更追踪</font>**<font style="color:rgb(15, 17, 21);">：清晰记录每一次修改的内容、原因和责任人。</font>
3. **<font style="color:rgb(15, 17, 21);">协作开发</font>**<font style="color:rgb(15, 17, 21);">：允许多人同时在同一个项目上工作，并能高效地合并代码。</font>
4. **<font style="color:rgb(15, 17, 21);">分支管理</font>**<font style="color:rgb(15, 17, 21);">：可以创建独立的开发线，用于开发新功能或修复Bug，而不会影响主线</font>

**三⼤区域：⼯作区、暂存区、仓库；**

| **<font style="color:rgb(15, 17, 21);">工作区</font>** | <font style="color:rgb(15, 17, 21);">Working Directory</font> | <font style="color:rgb(15, 17, 21);">你在电脑里能看到和直接编辑的文件目录。</font> | `<font style="color:rgb(15, 17, 21);">git add</font>` |
| --- | --- | --- | --- |
| **<font style="color:rgb(15, 17, 21);">暂存区</font>** | <font style="color:rgb(15, 17, 21);">Staging Area / Index</font> | <font style="color:rgb(15, 17, 21);">一个中间区域，临时存放你</font>**<font style="color:rgb(15, 17, 21);">准备</font>**<font style="color:rgb(15, 17, 21);">提交的更改。</font> | `<font style="color:rgb(15, 17, 21);">git commit</font>` |
| **<font style="color:rgb(15, 17, 21);">仓库</font>** | <font style="color:rgb(15, 17, 21);">Repository (.git directory)</font> | <font style="color:rgb(15, 17, 21);">存储所有提交历史记录的地方，位于项目的</font><font style="color:rgb(15, 17, 21);"> </font>`<font style="color:rgb(15, 17, 21);">.git</font>`<br/><font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">隐藏文件夹。</font> | |


**<font style="color:rgb(15, 17, 21);">工作流程</font>**<font style="color:rgb(15, 17, 21);">：</font>`<font style="color:rgb(15, 17, 21);">工作区</font>`<font style="color:rgb(15, 17, 21);"> --</font>`<font style="color:rgb(15, 17, 21);">git add</font>`<font style="color:rgb(15, 17, 21);">--> </font>`<font style="color:rgb(15, 17, 21);">暂存区</font>`<font style="color:rgb(15, 17, 21);"> --</font>`<font style="color:rgb(15, 17, 21);">git commit</font>`<font style="color:rgb(15, 17, 21);">--> </font>`<font style="color:rgb(15, 17, 21);">仓库</font>`

**克隆与同步： git clone , git pull , git push**

将远程仓库克隆到本地（首次获取项目）

git clone [https://github.com/username/repo.git](https://github.com/username/repo.git)

将远程仓库的最新变更拉取到本地并合并（常用）

git pull origin main

将本地提交推送到远程仓库

git push origin main

**⽇常操作： git add , git commit , git status**

查看工作区和暂存区的状态（最常用命令）

git status

将文件的修改添加到暂存区

git add <file_name>      # 添加特定文件

git add .                # 添加所有变更

将暂存区的内容提交到仓库，并附上说明

git commit -m "你的提交信息，说明这次修改的内容"

**历史查看                                                                                  **

查看提交历史

git log

git log --oneline        # 简洁模式

git log --graph          # 图形化显示分支

查看工作区与暂存区的差异

git diff

查看暂存区与最新提交的差异

git diff --staged             **               **

**分⽀管理：**

**创建/切换/合并： git branch , git checkout , git merge**

查看所有分支（当前分支前带 * 号）git branch

创建新分支git branch <new_branch_name>

切换到指定分支git checkout <branch_name>或者git switch <branch_name>

创建并立即切换到新分支git checkout -b <new_branch_name>或git switch -c <new_branch_name>

将指定分支合并到当前分支git merge <branch_name>

**解决合并冲突；**

<font style="color:rgb(15, 17, 21);">当两个分支对同一文件的同一部分进行了不同的修改，Git 无法自动合并时，就会产生冲突</font>

<font style="color:rgb(15, 17, 21);"><<<<<<< HEAD</font>

<font style="color:rgb(15, 17, 21);">这是当前分支的修改</font>

<font style="color:rgb(15, 17, 21);">=======</font>

<font style="color:rgb(15, 17, 21);">这是要合并过来的分支的修改</font>

<font style="color:rgb(15, 17, 21);">>>>>>>> feature-branch</font>

<font style="color:rgb(15, 17, 21);">解决步骤</font>

1. <font style="color:rgb(15, 17, 21);">用编辑器打开冲突文件。</font>
2. <font style="color:rgb(15, 17, 21);">手动选择要保留的代码（或进行整合），</font>**<font style="color:rgb(15, 17, 21);">删除</font>**<font style="color:rgb(15, 17, 21);"> </font>`<font style="color:rgb(15, 17, 21);"><<<<<<<</font>`<font style="color:rgb(15, 17, 21);">,</font><font style="color:rgb(15, 17, 21);"> </font>`<font style="color:rgb(15, 17, 21);">=======</font>`<font style="color:rgb(15, 17, 21);">,</font><font style="color:rgb(15, 17, 21);"> </font>`<font style="color:rgb(15, 17, 21);">>>>>>>></font>`<font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">这些标记。</font>
3. <font style="color:rgb(15, 17, 21);">使用</font><font style="color:rgb(15, 17, 21);"> </font>`<font style="color:rgb(15, 17, 21);">git add <file_name></font>`<font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">将解决后的文件标记为已解决。</font>
4. <font style="color:rgb(15, 17, 21);">使用 </font>`<font style="color:rgb(15, 17, 21);">git commit</font>`<font style="color:rgb(15, 17, 21);"> 完成合并提交。</font>

**理解 git fetch 与 git pull 的区别；**

git fetch<font style="color:rgb(15, 17, 21);">只下载远程仓库的最新数据到本地，但不合并到你的工作文件。让你可以先查看一下别人的修改。</font>

 git pull `<font style="color:rgb(15, 17, 21);">git fetch</font>`<font style="color:rgb(15, 17, 21);"> + </font>`<font style="color:rgb(15, 17, 21);">git merge</font>`<font style="color:rgb(15, 17, 21);">。下载远程数据并立即合并到当前分支。</font>

**掌握远程仓库管理： git remote**

查看远程仓库地址的别名（通常 origin 是默认的远程仓库名）git remote -v

添加一个新的远程仓库地址git remote add <remote_name> <url>

修改远程仓库地址git remote set-url origin <new_url>

**撤销操作：**

**git reset **

软重置：只移动HEAD指针，不修改工作区和暂存区（撤销commit，更改回到暂存区）

git reset --soft HEAD~1

混合重置（默认）：移动HEAD指针，重置暂存区，但不修改工作区（撤销commit和add，更改回到工作区）

git reset --mixed HEAD~1

硬重置：彻底丢弃提交、暂存区和工作区的所有修改（谨慎使用）

git reset --hard HEAD~1

或重置到特定提交

git reset --hard <commit_id>

**git rever**t

创建一个新的提交，用于撤销指定的提交

git revert <commit_id>

 **git stash**

贮藏当前修改git stash

查看贮藏列表git stash list

恢复最近一次的贮藏并删除贮藏记录git stash pop

恢复最近一次的贮藏但不删除记录git stash apply

删除贮藏记录git stash drop

**了解 Rebasing ⼯作流；**

<font style="color:rgb(15, 17, 21);">Rebasing 变基：另一种整合分支的方法，它会将当前分支的提交“重新播放”在目标分支的最新提交之上，从而产生一条更线性的历史</font>

<font style="color:rgb(15, 17, 21);"># 将当前分支变基到 main 分支</font>

<font style="color:rgb(15, 17, 21);">git switch feature-branch</font>

<font style="color:rgb(15, 17, 21);">git rebase main</font>

**Pull Request (PR) 提交流程；**

1. **<font style="color:rgb(15, 17, 21);">Fork & Clone</font>**<font style="color:rgb(15, 17, 21);">： Fork 上游仓库，并克隆到本地。</font>
2. **<font style="color:rgb(15, 17, 21);">分支开发</font>**<font style="color:rgb(15, 17, 21);">： 在本地创建功能分支进行开发。</font>
3. **<font style="color:rgb(15, 17, 21);">推送</font>**<font style="color:rgb(15, 17, 21);">： 将功能分支推送到你自己的远程仓库。</font>
4. **<font style="color:rgb(15, 17, 21);">创建 PR</font>**<font style="color:rgb(15, 17, 21);">： 在 GitHub 上向你 Fork 的上游仓库发起 Pull Request。</font>
5. **<font style="color:rgb(15, 17, 21);">代码审查</font>**<font style="color:rgb(15, 17, 21);">： 团队成员审查你的代码。</font>
6. **<font style="color:rgb(15, 17, 21);">合并</font>**<font style="color:rgb(15, 17, 21);">： 审查通过后，由负责人将你的分支合并到主分支。</font>

**恢复误删的提交（如通过 reflog ）**

1. 查看操作历史，找到被删除提交的 commit id

git reflog

2. 重置回那个提交

git reset --hard <lost_commit_id>

