# Texas Hold'em Coin Lobby｜德州金币大厅与积分大厅源码

[简体中文](README.md) | [English](README.en.md) | [繁體中文](README.zh-TW.md)

<p align="center">
  <img src="https://img.shields.io/badge/Client-Unity%202022-000000?style=flat-square&logo=unity&logoColor=white" alt="Unity 2022 客户端">
  <img src="https://img.shields.io/badge/Server-C%2B%2B17-00599C?style=flat-square&logo=c%2B%2B&logoColor=white" alt="C++17 游戏服务端">
  <img src="https://img.shields.io/badge/Database-MySQL%208.0-4479A1?style=flat-square&logo=mysql&logoColor=white" alt="MySQL 8.0 数据库">
  <img src="https://img.shields.io/badge/Platform-iOS%20%7C%20Android-blueviolet?style=flat-square" alt="iOS 与 Android 客户端">
</p>

**Texas Hold'em Coin Lobby** 是一套德州扑克金币大厅与积分大厅源码，包含 Unity 客户端、C++ 游戏服务端、6 种扑克玩法，以及商城、社交和运营活动等功能模块。

## 目录

- [项目简介](#项目简介)
- [核心玩法](#核心玩法)
- [系统功能](#系统功能)
- [运营活动](#运营活动)
- [技术架构](#技术架构)
- [项目结构](#项目结构)
- [快速开始](#快速开始)
- [产品截图](#产品截图)
- [常见问题](#常见问题)
- [相关文档](#相关文档)
- [许可证](#许可证)
- [联系我们](#联系我们)

## 项目简介

Texas Hold'em Coin Lobby（德州金币大厅 / 德州积分大厅）是一套棋牌游戏平台源码。当前 README 展示的主要内容包括：

- 6 种核心扑克玩法
- 商城、个人中心、宝箱、排行榜、好友和邮件等系统
- 任务、登录奖励、邀请好友、奖池和转盘等运营活动
- Unity 客户端与 C++ 游戏服务端源码
- 中文、英文和繁体中文 README
- iOS 与 Android 客户端界面

具体功能和支持范围以仓库当前源码、配置和文档为准。

## 核心玩法

| 玩法 | 英文名称 | 说明 |
|---|---|---|
| 经典德州扑克 | No-Limit Texas Hold'em | 标准 52 张牌玩法 |
| AOF 全押或弃牌 | All-in or Fold | 每手牌选择全押或弃牌 |
| 6+ 短牌德州 | Short Deck / 6+ Hold'em | 去除 2-5，游戏节奏更快 |
| 单桌锦标赛 | SNG / Sit & Go | 满人开赛的单桌锦标赛 |
| 多桌锦标赛 | MTT / Multi-Table Tournament | 多桌淘汰晋级玩法 |
| 俱乐部模式 | Club Mode | 私人牌桌、朋友局和俱乐部玩法 |

## 系统功能

- **商城系统**：金币、钻石、道具、VIP 礼包和限时折扣
- **个人中心**：头像、昵称、战绩、资产、等级和成就
- **宝箱系统**：不同等级宝箱及定时奖励
- **排行榜**：日榜、周榜、月榜及不同统计维度
- **保险箱**：游戏资产存取功能
- **好友系统**：添加好友、私聊、战绩查看和对战邀请
- **邮件系统**：公告、活动奖励、补偿和客服回复
- **Facebook 登录**：账号登录、好友邀请和内容分享
- **设置中心**：音效、音乐、语言、通知和账号设置

## 运营活动

| 活动 | 功能描述 | 主要用途 |
|---|---|---|
| 任务系统 | 每日、每周和成长任务 | 活跃与留存 |
| 每日登录 | 连续登录奖励 | 日活与留存 |
| 活动中心 | 限时活动和节日专题 | 活跃与运营 |
| 邀请好友 | 邀请码及双方奖励 | 用户邀请 |
| JackPot 奖池 | 全局累积奖池和随机奖励 | 游戏活动 |
| 刮刮乐彩票 | 虚拟刮刮卡和即时奖励 | 趣味活动 |
| 转盘活动 | 免费或付费抽奖 | 活跃运营 |
| 激励广告 | 观看广告获得金币 | 广告激励 |

## 技术架构

| 层级 | 技术或目录 | 说明 |
|---|---|---|
| 客户端 | Unity 2022、C# | 客户端代码与 Unity 工程文件 |
| 游戏服务端 | C++ | 服务端源码位于 `server/src/` |
| 服务通信 | TARS 接口文件 | `server/src/` 中包含 `.tars` 接口定义 |
| 数据访问 | C++ DBOperator | 数据库操作代码位于服务端源码中 |
| 构建脚本 | Shell、Makefile | `server/src/` 包含构建脚本和 Makefile |
| 客户端配置 | `Packages/`、`ProjectSettings/` | Unity 包和项目设置 |

## 项目结构

```text
texas-holdem-coin-lobby/
├── Client/             # 客户端代码与资源
├── Doc/                # 项目文档
├── Packages/           # Unity 包配置
├── ProjectSettings/    # Unity 项目设置
├── docs/               # README 图片与其他文档资源
├── server/
│   └── src/            # C++ 服务端源码、配置与构建脚本
├── CHANGELOG.md        # 更新日志
├── CONTRIBUTING.md     # 贡献指南
├── SECURITY.md         # 安全策略
└── README.md
```

## 快速开始

### 获取源码

```bash
git clone https://github.com/alibabamayun888/texas-holdem-coin-lobby.git
cd texas-holdem-coin-lobby
```

### 客户端

客户端相关代码位于 [`Client/`](Client/)，Unity 包和项目配置分别位于 [`Packages/`](Packages/) 与 [`ProjectSettings/`](ProjectSettings/)。开发前请根据 `ProjectSettings` 中的版本信息使用匹配的 Unity 版本。

### 服务端

C++ 服务端位于 [`server/src/`](server/src/)。该目录包含 `README.md`、Makefile 和多个构建脚本，编译及配置方式请以 [`server/src/README.md`](server/src/README.md) 和当前脚本为准。

> 仓库根目录当前未提供 Docker Compose、Kubernetes 或 Java/Vue 运营后台目录，因此本文不提供相关部署命令。

## 产品截图

<table>
  <tr>
    <td align="center"><strong>运营活动</strong></td>
    <td align="center"><strong>金币大厅</strong></td>
  </tr>
  <tr>
    <td><img src="docs/Assets/Screenshots/001action.png" alt="德州积分金币大厅运营活动界面" width="380"></td>
    <td><img src="docs/Assets/Screenshots/002dating.png" alt="Texas Hold'em Coin Lobby 金币大厅界面" width="380"></td>
  </tr>
  <tr>
    <td align="center"><strong>活动中心</strong></td>
    <td align="center"><strong>经典德州</strong></td>
  </tr>
  <tr>
    <td><img src="docs/Assets/Screenshots/003heguang.png" alt="德州积分大厅活动中心界面" width="380"></td>
    <td><img src="docs/Assets/Screenshots/004jingdian.jpg" alt="经典 Texas Hold'em 游戏界面" width="380"></td>
  </tr>
  <tr>
    <td align="center"><strong>MTT 锦标赛</strong></td>
    <td align="center"><strong>牌桌</strong></td>
  </tr>
  <tr>
    <td><img src="docs/Assets/Screenshots/005mtt.jpg" alt="德州扑克 MTT 多桌锦标赛界面" width="380"></td>
    <td><img src="docs/Assets/Screenshots/006paizuo.png" alt="德州扑克金币牌桌界面" width="380"></td>
  </tr>
  <tr>
    <td align="center"><strong>商城</strong></td>
    <td align="center"><strong>SNG 锦标赛</strong></td>
  </tr>
  <tr>
    <td><img src="docs/Assets/Screenshots/007shop.png" alt="Texas Hold'em Coin Lobby 商城界面" width="380"></td>
    <td><img src="docs/Assets/Screenshots/008sng.jpg" alt="德州扑克 SNG 单桌锦标赛界面" width="380"></td>
  </tr>
</table>

## 常见问题

### 这个项目可以商用吗？

源码仅供学习、研究和演示使用。商业使用需要单独获得授权，并遵守项目许可证及所在地法律法规。

### 支持哪些客户端平台？

当前 README 标明支持 iOS 12+ 和 Android 5+。实际构建支持范围取决于 Unity 版本、项目配置和第三方依赖。

### 如何进行二次开发？

客户端代码和资源位于 `Client/`，Unity 配置位于 `Packages/` 和 `ProjectSettings/`；服务端代码位于 `server/src/`。建议先阅读目录中的 README、配置文件和构建脚本。

### 数据库使用什么版本？

当前 README 标明使用 MySQL 8.0，服务端的数据访问代码可在 `server/src/DBOperator.cpp` 和相关头文件中查看。

### 是否支持热更新？

原 README 描述客户端采用 AssetBundle 与 Addressables。具体实现和可更新范围请以当前客户端源码及 Unity 配置为准。

## 相关文档

- [更新日志](CHANGELOG.md)
- [贡献指南](CONTRIBUTING.md)
- [安全策略](SECURITY.md)
- [支持说明](SUPPORT.md)
- [负责任使用规范](RESPONSIBLE-USE.md)
- [服务端说明](server/src/README.md)

## 许可证

本项目采用自定义许可证：

- **学习用途**：允许下载、学习和研究
- **禁止事项**：未经授权的转售、分发或 SaaS 化运营
- **商业用途**：需要单独取得商业授权

This software is provided for learning, research, and demonstration purposes only. Commercial use requires a separate license agreement.

## 联系我们

| 渠道 | 联系方式 |
|---|---|
| Email | `ttpoker40@gmail.com` |
| Telegram | [@alibabama401](https://t.me/alibabama401) |
| GitHub Issues | [提交问题](https://github.com/alibabamayun888/texas-holdem-coin-lobby/issues) |

<p align="center">
  <strong>如果这个项目对你有帮助，请给它一个 Star。</strong><br>
  <em>If this project helps you, please give it a star and share it with your friends.</em><br><br>
  <a href="https://github.com/alibabamayun888/texas-holdem-coin-lobby/stargazers"><img src="https://img.shields.io/github/stars/alibabamayun888/texas-holdem-coin-lobby?style=social" alt="Give a Star"></a>
</p>
