## Analysis of Trojan.Win32.CoinStealer.i

### Finding the Wallet Thief

To start off, I looked at TibanneBackOffice.exe in binwalk and found an encrypted secion at offset 0x208400. Loading in PEiD under Windows shows that the executable is not packed or obfuscated, but the .project section starts at offset 0x20800. This looks like a promising place to start digging.

Opening TibanneBackOffice.exe in Binwalk shows an encrypted section at offset 0x208400 (the entire .project section). OllyDbg shows that this section is only referenced once in the program, and examining the memory after it is referenced gives us the full source code for the malicious part of this file. The wallet stealer is written in LiveCode, an interpreted language. This also explains why they have a Mac variant bundled in, as LiveCode is cross platform, meaning minimal work on the authors part. It's worth noting that a Linux version could be added easily as well.

I've checked in the dumped code as walletThief.rev
