# Texas Hold'em Coin Lobby Source Code

[简体中文](README.md) | [English](README.en.md) | [繁體中文](README.zh-TW.md)

<p align="center">
  <img src="https://img.shields.io/badge/Client-Unity%202022-000000?style=flat-square&logo=unity&logoColor=white" alt="Unity 2022 client">
  <img src="https://img.shields.io/badge/Server-C%2B%2B17-00599C?style=flat-square&logo=c%2B%2B&logoColor=white" alt="C++17 game server">
  <img src="https://img.shields.io/badge/Database-MySQL%208.0-4479A1?style=flat-square&logo=mysql&logoColor=white" alt="MySQL 8.0 database">
  <img src="https://img.shields.io/badge/Platform-iOS%20%7C%20Android-blueviolet?style=flat-square" alt="iOS and Android clients">
</p>

**Texas Hold'em Coin Lobby** is a poker coin and points lobby source-code project. It includes a Unity client, a C++ game server, six poker modes, social features, a shop, and live-operations modules.

## Contents

- [Overview](#overview)
- [Game Modes](#game-modes)
- [Platform Features](#platform-features)
- [Live Operations](#live-operations)
- [Technical Structure](#technical-structure)
- [Repository Layout](#repository-layout)
- [Getting Started](#getting-started)
- [Screenshots](#screenshots)
- [FAQ](#faq)
- [Documentation](#documentation)
- [License](#license)
- [Contact](#contact)

## Overview

Texas Hold'em Coin Lobby is a source-code project for Texas Hold'em coin and points lobby products. The current repository includes:

- Six poker game modes
- Shop, profile, chest, leaderboard, friends, mail, and settings modules
- Tasks, login rewards, invitations, jackpot, wheel, and rewarded-ad activities
- A Unity client and C++ game-server source code
- Simplified Chinese, English, and Traditional Chinese README files
- Client screenshots for iOS and Android-oriented interfaces

The exact feature set and platform support depend on the current source code, configuration, and documentation in this repository.

## Game Modes

| Mode | Alternative Name | Description |
|---|---|---|
| Classic Texas Hold'em | No-Limit Texas Hold'em | Standard 52-card Texas Hold'em |
| AOF | All-in or Fold | Each hand is played by going all-in or folding |
| 6+ Short Deck | Short Deck Hold'em | Faster Hold'em variant without cards 2 through 5 |
| Single-Table Tournament | SNG / Sit & Go | A tournament that starts when the table is full |
| Multi-Table Tournament | MTT | Multi-table elimination tournament |
| Club Mode | Private and Friends Tables | Club, private-room, and friends-game scenarios |

## Platform Features

- **Shop:** coins, diamonds, items, VIP packages, and limited-time offers
- **Profile:** avatar, nickname, records, assets, level, and achievements
- **Chests:** multiple chest levels and timed rewards
- **Leaderboards:** daily, weekly, monthly, and category rankings
- **Safe Box:** in-game asset storage
- **Friends:** friend requests, private chat, records, and game invitations
- **Mail:** announcements, rewards, compensation, and support replies
- **Facebook Login:** sign-in, friend invitations, and sharing
- **Settings:** sound, music, language, notifications, and account options

## Live Operations

| Activity | Description | Purpose |
|---|---|---|
| Tasks | Daily, weekly, and progression tasks | Engagement and retention |
| Daily Login | Consecutive login rewards | Daily activity and retention |
| Activity Center | Limited-time and seasonal activities | Live operations |
| Invite Friends | Invitation codes and two-sided rewards | User invitations |
| Jackpot | Accumulated prize pool and random rewards | Game events |
| Scratch Card | Virtual scratch cards and instant rewards | Casual activity |
| Prize Wheel | Free or paid spins | Engagement |
| Rewarded Ads | Coins awarded for watching ads | Ad-supported rewards |

## Technical Structure

| Layer | Technology or Path | Description |
|---|---|---|
| Client | Unity 2022, C# | Client code and Unity project files |
| Game Server | C++ | Server source code under `server/src/` |
| Service Interface | TARS definitions | `.tars` interface definitions under `server/src/` |
| Data Access | C++ DBOperator | Database access implementation in the server source |
| Build | Shell scripts, Makefile | Build scripts and Makefile under `server/src/` |
| Unity Configuration | `Packages/`, `ProjectSettings/` | Unity packages and project settings |

## Repository Layout

```text
texas-holdem-coin-lobby/
├── Client/             # Client code and assets
├── Doc/                # Project documentation
├── Packages/           # Unity package configuration
├── ProjectSettings/    # Unity project settings
├── docs/               # README images and documentation assets
├── server/
│   └── src/            # C++ server source, configuration, and build scripts
├── CHANGELOG.md        # Changelog
├── CONTRIBUTING.md     # Contribution guide
├── SECURITY.md         # Security policy
└── README.md
```

## Getting Started

### Clone the Repository

```bash
git clone https://github.com/alibabamayun888/texas-holdem-coin-lobby.git
cd texas-holdem-coin-lobby
```

### Client

Client-related code is under [`Client/`](Client/). Unity package and project settings are stored in [`Packages/`](Packages/) and [`ProjectSettings/`](ProjectSettings/). Use a Unity version compatible with the checked-in project settings.

### Server

The C++ server is under [`server/src/`](server/src/). That directory contains its own README, Makefile, configuration, and build scripts. Follow [`server/src/README.md`](server/src/README.md) and the current scripts rather than assuming a root-level build command.

> The repository root currently does not include Docker Compose, Kubernetes, or a Java/Vue admin application, so this README does not provide deployment commands for those components.

## Screenshots

<table>
  <tr><td align="center"><strong>Live Activity</strong></td><td align="center"><strong>Coin Lobby</strong></td></tr>
  <tr>
    <td><img src="docs/Assets/Screenshots/001action.png" alt="Texas Hold'em coin lobby live activity screen" width="380"></td>
    <td><img src="docs/Assets/Screenshots/002dating.png" alt="Texas Hold'em Coin Lobby home screen" width="380"></td>
  </tr>
  <tr><td align="center"><strong>Activity Center</strong></td><td align="center"><strong>Classic Hold'em</strong></td></tr>
  <tr>
    <td><img src="docs/Assets/Screenshots/003heguang.png" alt="Poker points lobby activity center" width="380"></td>
    <td><img src="docs/Assets/Screenshots/004jingdian.jpg" alt="Classic Texas Hold'em game screen" width="380"></td>
  </tr>
  <tr><td align="center"><strong>MTT</strong></td><td align="center"><strong>Poker Table</strong></td></tr>
  <tr>
    <td><img src="docs/Assets/Screenshots/005mtt.jpg" alt="Texas Hold'em MTT tournament screen" width="380"></td>
    <td><img src="docs/Assets/Screenshots/006paizuo.png" alt="Texas Hold'em coin poker table" width="380"></td>
  </tr>
  <tr><td align="center"><strong>Shop</strong></td><td align="center"><strong>SNG</strong></td></tr>
  <tr>
    <td><img src="docs/Assets/Screenshots/007shop.png" alt="Texas Hold'em Coin Lobby shop" width="380"></td>
    <td><img src="docs/Assets/Screenshots/008sng.jpg" alt="Texas Hold'em SNG tournament screen" width="380"></td>
  </tr>
</table>

## FAQ

### Can this project be used commercially?

The source code is provided for learning, research, and demonstration. Commercial use requires separate authorization and compliance with the project license and applicable laws.

### Which client platforms are supported?

The existing README states support for iOS 12+ and Android 5+. Actual build support depends on the Unity version, project configuration, and third-party dependencies.

### Where should secondary development begin?

Client code and assets are under `Client/`; Unity configuration is under `Packages/` and `ProjectSettings/`; server code is under `server/src/`. Review the README, configuration, and build scripts in those directories first.

### Which database version is used?

The existing README identifies MySQL 8.0. Server-side data-access code is available in `server/src/DBOperator.cpp` and its related header files.

### Does the client support content updates?

The existing README describes an AssetBundle and Addressables-based approach. Refer to the current client source and Unity configuration for the implemented update scope.

## Documentation

- [Changelog](CHANGELOG.md)
- [Contribution Guide](CONTRIBUTING.md)
- [Security Policy](SECURITY.md)
- [Support](SUPPORT.md)
- [Responsible Use](RESPONSIBLE-USE.md)
- [Server README](server/src/README.md)

## License

This project uses a custom license:

- **Learning:** downloading, studying, and researching the source is permitted
- **Restricted:** unauthorized resale, redistribution, or SaaS operation is prohibited
- **Commercial use:** separate commercial authorization is required

This software is provided for learning, research, and demonstration purposes only. Commercial use requires a separate license agreement.

## Contact

| Channel | Contact |
|---|---|
| Email | `ttpoker40@gmail.com` |
| Telegram | [@alibabama401](https://t.me/alibabama401) |
| GitHub Issues | [Open an issue](https://github.com/alibabamayun888/texas-holdem-coin-lobby/issues) |

<p align="center">
  <strong>If this project helps you, please give it a Star.</strong><br><br>
  <a href="https://github.com/alibabamayun888/texas-holdem-coin-lobby/stargazers"><img src="https://img.shields.io/github/stars/alibabamayun888/texas-holdem-coin-lobby?style=social" alt="Give a Star"></a>
</p>
