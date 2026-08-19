# Source code for Introduction to 3D Game Programming Using DirectX 11

## Introduction

Unofficial source code repo for Frank D. Luna's book [Introduction to 3D Game Programming using DirectX 11](http://www.d3dcoder.net/d3d11.htm). The source code is reproduced here for reference and remains the copyright of Frank D. Luna. This repo is for the original source code, I'm separately working on [updating the source code](https://github.com/yottaawesome/intro-to-dx11-revisited/tree/main) to remove the dated dependencies and to use modern C++.

## Changes

The codebase is being updated over time to migrate it over to use DirectX Math instead of the legacy XNA Math. Solutions are also being updated to retarget them to VS2022 and the latest toolset. References to dxerr and other depracated libraries will be gradually removed.

## Revisited source code

I have a separate repo where [I'm modernising the codebase](https://github.com/yottaawesome/intro-to-dx11-revisited) to eliminate the deprecated DX11 framework, updating the toolset to the latest MSVC, migrating to modules for better readability, and applying various other improvements. The revisited codebase is easier to compile due to the elimination of outdated components.

## Additional resources

* [DirectXMath Portal](https://docs.microsoft.com/en-us/windows/win32/dxmath/directxmath-portal)
* [Where is the DirectX SDK?](https://docs.microsoft.com/en-us/windows/win32/directx-sdk--august-2009-)
