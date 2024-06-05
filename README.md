# samp-rce-fix
This repository provides a fix for the RCE vulnerability found in previous versions of the SA-MP R5 client. This allows users who need to continue using the R1 version to do so securely, without the risk of infection.

## Build
```
git clone https://github.com/alexchwoj/samp-rce-fix.git
cd samp-rce-fix
cmake -B build -A Win32
```

After creating CMake cache
```
cmake --build build
```

## Contribution
If you find any issues or have improvements, feel free to submit a pull request or open an issue. If you come up with better ways to detect the vulnerability or any other enhancements, all pull requests are welcome!