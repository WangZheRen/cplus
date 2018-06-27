
## 规则提取 ##
特征提取：
1. 远祖：于栗磾，太尉
1. 换行提取
1. 卡片提取

相关数据
1. 测试数据: data/relation/T_train
1. 家庭成员映射关系: data/relation/D_map_family

相关脚本
1. 根据T_train生成 id和url的映射文件。文件位置 data/relation/id_url

```commandline
./work_relation -g id2url
```

2. 关系提取
```commandline
./work_relation
```

