# Texas Hold'em Coin Lobby｜德州金幣大廳與積分大廳原始碼

[簡體中文](README.md) | [English](README.en.md) | [繁體中文](README.zh-TW.md)

<p align="center">
  <img src="https://img.shields.io/badge/Client-Unity%202022-000000?style=flat-square&logo=unity&logoColor=white" alt="Unity 2022 客戶端">
  <img src="https://img.shields.io/badge/Server-C%2B%2B17-00599C?style=flat-square&logo=c%2B%2B&logoColor=white" alt="C++17 遊戲服務端">
  <img src="https://img.shields.io/badge/Database-MySQL%208.0-4479A1?style=flat-square&logo=mysql&logoColor=white" alt="MySQL 8.0 資料庫">
  <img src="https://img.shields.io/badge/Platform-iOS%20%7C%20Android-blueviolet?style=flat-square" alt="iOS 與 Android 客戶端">
</p>

**Texas Hold'em Coin Lobby** 是一套德州撲克金幣大廳與積分大廳原始碼，包含 Unity 客戶端、C++ 遊戲服務端、6 種撲克玩法，以及商城、社交與營運活動等功能模組。

## 目錄

- [專案簡介](#專案簡介)
- [核心玩法](#核心玩法)
- [系統功能](#系統功能)
- [營運活動](#營運活動)
- [技術架構](#技術架構)
- [專案結構](#專案結構)
- [快速開始](#快速開始)
- [產品截圖](#產品截圖)
- [常見問題](#常見問題)
- [相關文件](#相關文件)
- [授權條款](#授權條款)
- [聯絡我們](#聯絡我們)

## 專案簡介

Texas Hold'em Coin Lobby（德州金幣大廳 / 德州積分大廳）是一套棋牌遊戲平台原始碼。目前倉庫主要包含：

- 6 種核心撲克玩法
- 商城、個人中心、寶箱、排行榜、好友、郵件與設定等系統
- 任務、登入獎勵、邀請好友、獎池與轉盤等營運活動
- Unity 客戶端與 C++ 遊戲服務端原始碼
- 簡體中文、英文與繁體中文 README
- 面向 iOS 與 Android 的客戶端介面

實際功能與平台支援範圍，請以倉庫目前的原始碼、設定與文件為準。

## 核心玩法

| 玩法 | 英文名稱 | 說明 |
|---|---|---|
| 經典德州撲克 | No-Limit Texas Hold'em | 標準 52 張牌玩法 |
| AOF 全押或棄牌 | All-in or Fold | 每手牌選擇全押或棄牌 |
| 6+ 短牌德州 | Short Deck / 6+ Hold'em | 移除 2-5，遊戲節奏更快 |
| 單桌錦標賽 | SNG / Sit & Go | 滿桌後開始的單桌錦標賽 |
| 多桌錦標賽 | MTT / Multi-Table Tournament | 多桌淘汰晉級玩法 |
| 俱樂部模式 | Club Mode | 私人牌桌、好友局與俱樂部玩法 |

## 系統功能

- **商城系統**：金幣、鑽石、道具、VIP 禮包與限時折扣
- **個人中心**：頭像、暱稱、戰績、資產、等級與成就
- **寶箱系統**：不同等級寶箱與定時獎勵
- **排行榜**：日榜、週榜、月榜與多種統計維度
- **保險箱**：遊戲資產存取功能
- **好友系統**：新增好友、私聊、戰績查看與對戰邀請
- **郵件系統**：公告、活動獎勵、補償與客服回覆
- **Facebook 登入**：帳號登入、好友邀請與內容分享
- **設定中心**：音效、音樂、語言、通知與帳號設定

## 營運活動

| 活動 | 功能說明 | 主要用途 |
|---|---|---|
| 任務系統 | 每日、每週與成長任務 | 活躍與留存 |
| 每日登入 | 連續登入獎勵 | 日活與留存 |
| 活動中心 | 限時活動與節慶專題 | 活動營運 |
| 邀請好友 | 邀請碼與雙方獎勵 | 使用者邀請 |
| JackPot 獎池 | 全域累積獎池與隨機獎勵 | 遊戲活動 |
| 刮刮樂 | 虛擬刮刮卡與即時獎勵 | 趣味活動 |
| 轉盤活動 | 免費或付費抽獎 | 活躍營運 |
| 激勵廣告 | 觀看廣告取得金幣 | 廣告獎勵 |

## 技術架構

| 層級 | 技術或路徑 | 說明 |
|---|---|---|
| 客戶端 | Unity 2022、C# | 客戶端程式碼與 Unity 專案檔案 |
| 遊戲服務端 | C++ | 服務端原始碼位於 `server/src/` |
| 服務通訊 | TARS 介面檔案 | `server/src/` 包含 `.tars` 介面定義 |
| 資料存取 | C++ DBOperator | 資料庫操作程式碼位於服務端原始碼中 |
| 建置腳本 | Shell、Makefile | `server/src/` 包含建置腳本與 Makefile |
| 客戶端設定 | `Packages/`、`ProjectSettings/` | Unity 套件與專案設定 |

## 專案結構

```text
texas-holdem-coin-lobby/
├── Client/             # 客戶端程式碼與資源
├── Doc/                # 專案文件
├── Packages/           # Unity 套件設定
├── ProjectSettings/    # Unity 專案設定
├── docs/               # README 圖片與其他文件資源
├── server/
│   └── src/            # C++ 服務端原始碼、設定與建置腳本
├── CHANGELOG.md        # 更新記錄
├── CONTRIBUTING.md     # 貢獻指南
├── SECURITY.md         # 安全政策
└── README.md
```

## 快速開始

### 取得原始碼

```bash
git clone https://github.com/alibabamayun888/texas-holdem-coin-lobby.git
cd texas-holdem-coin-lobby
```

### 客戶端

客戶端相關程式碼位於 [`Client/`](Client/)，Unity 套件與專案設定分別位於 [`Packages/`](Packages/) 和 [`ProjectSettings/`](ProjectSettings/)。開發前請依照 `ProjectSettings` 中的版本資訊使用相符的 Unity 版本。

### 服務端

C++ 服務端位於 [`server/src/`](server/src/)。該目錄包含 README、Makefile、設定與多個建置腳本，請依照 [`server/src/README.md`](server/src/README.md) 及目前腳本進行建置。

> 倉庫根目錄目前沒有 Docker Compose、Kubernetes 或 Java/Vue 營運後台目錄，因此本文不提供這些元件的部署指令。

## 產品截圖

<table>
  <tr><td align="center"><strong>營運活動</strong></td><td align="center"><strong>金幣大廳</strong></td></tr>
  <tr>
    <td><img src="docs/Assets/Screenshots/001action.png" alt="德州積分金幣大廳營運活動介面" width="380"></td>
    <td><img src="docs/Assets/Screenshots/002dating.png" alt="Texas Hold'em Coin Lobby 金幣大廳介面" width="380"></td>
  </tr>
  <tr><td align="center"><strong>活動中心</strong></td><td align="center"><strong>經典德州</strong></td></tr>
  <tr>
    <td><img src="docs/Assets/Screenshots/003heguang.png" alt="德州積分大廳活動中心介面" width="380"></td>
    <td><img src="docs/Assets/Screenshots/004jingdian.jpg" alt="經典 Texas Hold'em 遊戲介面" width="380"></td>
  </tr>
  <tr><td align="center"><strong>MTT 錦標賽</strong></td><td align="center"><strong>牌桌</strong></td></tr>
  <tr>
    <td><img src="docs/Assets/Screenshots/005mtt.jpg" alt="德州撲克 MTT 多桌錦標賽介面" width="380"></td>
    <td><img src="docs/Assets/Screenshots/006paizuo.png" alt="德州撲克金幣牌桌介面" width="380"></td>
  </tr>
  <tr><td align="center"><strong>商城</strong></td><td align="center"><strong>SNG 錦標賽</strong></td></tr>
  <tr>
    <td><img src="docs/Assets/Screenshots/007shop.png" alt="Texas Hold'em Coin Lobby 商城介面" width="380"></td>
    <td><img src="docs/Assets/Screenshots/008sng.jpg" alt="德州撲克 SNG 單桌錦標賽介面" width="380"></td>
  </tr>
</table>

## 常見問題

### 這個專案可以商用嗎？

原始碼僅供學習、研究與展示使用。商業使用需要另行取得授權，並遵守專案授權條款與所在地法律規範。

### 支援哪些客戶端平台？

原 README 標示支援 iOS 12+ 與 Android 5+。實際建置範圍取決於 Unity 版本、專案設定與第三方相依套件。

### 如何進行二次開發？

客戶端程式碼與資源位於 `Client/`，Unity 設定位於 `Packages/` 和 `ProjectSettings/`；服務端程式碼位於 `server/src/`。建議先閱讀各目錄中的 README、設定檔與建置腳本。

### 使用哪個資料庫版本？

原 README 標示使用 MySQL 8.0，服務端資料存取程式碼可在 `server/src/DBOperator.cpp` 及相關標頭檔中查看。

### 客戶端是否支援內容更新？

原 README 描述採用 AssetBundle 與 Addressables。實際實作與可更新範圍請以目前客戶端原始碼及 Unity 設定為準。

## 相關文件

- [更新記錄](CHANGELOG.md)
- [貢獻指南](CONTRIBUTING.md)
- [安全政策](SECURITY.md)
- [支援說明](SUPPORT.md)
- [負責任使用規範](RESPONSIBLE-USE.md)
- [服務端說明](server/src/README.md)

## 授權條款

本專案採用自訂授權條款：

- **學習用途**：允許下載、學習與研究
- **禁止事項**：未經授權的轉售、散布或 SaaS 化營運
- **商業用途**：需要另行取得商業授權

This software is provided for learning, research, and demonstration purposes only. Commercial use requires a separate license agreement.

## 聯絡我們

| 管道 | 聯絡方式 |
|---|---|
| Email | `ttpoker40@gmail.com` |
| Telegram | [@alibabama401](https://t.me/alibabama401) |
| GitHub Issues | [提交問題](https://github.com/alibabamayun888/texas-holdem-coin-lobby/issues) |

<p align="center">
  <strong>如果這個專案對你有幫助，請給它一個 Star。</strong><br>
  <em>If this project helps you, please give it a star and share it with your friends.</em><br><br>
  <a href="https://github.com/alibabamayun888/texas-holdem-coin-lobby/stargazers"><img src="https://img.shields.io/github/stars/alibabamayun888/texas-holdem-coin-lobby?style=social" alt="Give a Star"></a>
</p>
