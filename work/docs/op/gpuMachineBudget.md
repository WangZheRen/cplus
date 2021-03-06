## 参考指标

|项目名称 | 实体关系抽取 | 文本标签挖掘 | 词条评论分类 | 备注 | 
|---|---|---|---|---|
|采用方式 | 传统机器学习（目前在做人物关系挖掘，后续还会增加词条属性挖掘） | 传统机器学习（目前主要基于nlpc算子在做） | 传统机器学习（目前主要基于关键词和词嵌入模型在做） | <font color=red>未来想通过引入深度网络来支持百科内容建设及数说的运营 </font>| 
|模型总量m:13 |~~规则提取4，语义提取4~~ 8个（深度网络的话不存在规则提取和语义提取一说，直接是端对端的模型）  |1  |4  |  | 
|平均每模型数据集大小s |人物关系标注数据：2万条+ |(单垂类)标注数据：1w条+  |标注数据：10万条+  |  | 
|每个模型训练完成平均训练的次数d：25 |25	|25  |25  | 迭代次数 |
|每次训练过程epoch数量e： 100|100|100 |100 |所有样本训练的次数  |
|上述数据集的单卡qps处理能力p|20| 100| 2|  |
|多机多卡训练时效率折算值|0.75| 0.75| 0.75|  |
	
## 常见问题

1、下半年的规划？
除了现有项目，部分采用神经网络进行尝试之外，新的项目，如编审流程（需求调研阶段）、数说新垂类（城市、景点、交通、楼盘）拓展，也计划采用深度神经网络进行尝试。

2、新闻标签挖掘，为什么不采用nlpc服务？
目前我们使用的就是nlpc的服务，主要的问题在于，nlpc是通用化服务，对于一些精细化的方向上，召回和精准度都偏低（如景点、楼盘）。后面规划在nlpc的基础上，进行深度挖掘。




## 会议纪要（2018-07-11 13：00~14：00）
**目的：**
- review规划说明
- 计算公式说明

**硬件状况：**
	 - V100卡
	 - 单台gpu机器售价： 60~70万
	 - 网络：100G（故需要特殊机房）
	 - 一个机架只能存放一台gpu服务器
	 - 机型： A22-GN4-5

**公司使用现状：**整体利用率偏低

**后期规划：** 统一由“阡陌”平台管理

**使用率要求：**集群使用率要在40%以上， 开发机要求在20%以上。

**参数说明：**
- m：模型总量算法。如果一个模型每个月更新一次，那么一年的值为12，即m=12.
- s：如语言类，按照词或句子的数目统计。
- d：通常值为10~30次。
- e： d * e为数据过gpu的次数。

> 若预算不足，可以采用弹性添加方式，不用重新走预算流程。

## 相关文档

- [GPU需求计算说明-在线预测/离线训练](http://wiki.baidu.com/pages/viewpage.action?pageId=504613530)
- [申请入口](http://rms.baidu.com/?r=indexNew/index#355)
- [深度学习中的Epoch，Batchsize，Iterations，都是什么鬼？](https://www.jianshu.com/p/e5076a56946c)
