## Analysis and Modification of Win32.CoinStealer

### Introduction

Trojan.Win32.CoinStealer.i and Trojan.OSX.Coinstealer.a are Bitcoin wallet stealing trojans that appear to be a desktop interface to MtGox, the world's former largest Bitcoin exchange. They originated in a [torrent](https://thepiratebay.se/torrent/9732163/2014_Mt._Gox_Leak) containing stolen data from the site. It wasn't long until forum posts appeared by curious downloaders who discovered the wallet stealing capability of the executables. 

This isn't the first Bitcoin wallet stealing malware, but it represents a threat that should be taken seriously if Bitcoin (or any cryptocurrency) is to be successful. The goal of this project is to analyze Trojan.Win32.CoinStealer.i and add a worm component that exploits MS03-026 Microsoft RPC DCOM Interface Overflow. A wallet stealing worm presents a serious danger in a (potential) world where everyone's grandmother is using cryptocurrency. Having poor security practices would then lead to financial ruin, instead of just a simple OS reinstall. 

### Blaster Worm

Since this project is limited by the end of the semester, I'm going to be modifying an existing worm rather than writing my own. The Blaster Worm is fairly simple sample to work with due to its small size. The purpose of Blaster was to create a distributed denial of service attack against windowsupdate.com, however the targeted site was redirected to windowsupdate.microsoft.com minimizing the damage. I intend to replace this functionality with that of Trojan.Win32.CoinStealer.i (and Trojan.OSX.Coinstealer.a if time permits) to demonstrate the concept of a wallet stealing worm.
