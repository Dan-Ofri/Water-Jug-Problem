@echo off
REM ============================================================================
REM Water Jug Problem - Build Script
REM ============================================================================
REM This script builds the Water-Jug-Problem project using MSBuild
REM It supports both Debug and Release configurations
REM ============================================================================

setlocal enabledelayedexpansion

echo.
echo ====================================
echo  Water Jug Problem - Build Script
echo ====================================
echo.

REM Check for Visual Studio 2022
set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist "%VSWHERE%" (
    echo [ERROR] Visual Studio 2022 not found!
    echo Please install Visual Studio 2022 with C++ Desktop Development workload
    pause
    exit /b 1
)

REM Find MSBuild
for /f "usebackq tokens=*" %%i in (`"%VSWHERE%" -latest -requires Microsoft.Component.MSBuild -find MSBuild\**\Bin\MSBuild.exe`) do (
    set MSBUILD=%%i
)

if not defined MSBUILD (
    echo [ERROR] MSBuild not found!
    echo Please install Visual Studio 2022 Build Tools
    pause
    exit /b 1
)

echo [INFO] Found MSBuild: !MSBUILD!
echo.

REM Get build configuration from parameter or default to Release
set "CONFIG=%~1"
if "%CONFIG%"=="" set "CONFIG=Release"

echo [INFO] Build Configuration: %CONFIG%
echo [INFO] Platform: x64
echo.

REM Clean previous build (optional)
if /i "%2"=="clean" (
    echo [INFO] Cleaning previous build...
    "%MSBUILD%" "Water-Jug-Problem.sln" /t:Clean /p:Configuration=%CONFIG% /p:Platform=x64 /v:minimal
    echo.
)

REM Build the solution
echo [INFO] Building Water-Jug-Problem.sln...
echo.
"%MSBUILD%" "Water-Jug-Problem.sln" /p:Configuration=%CONFIG% /p:Platform=x64 /v:minimal

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ====================================
    echo   BUILD SUCCESSFUL!
    echo ====================================
    echo.
    echo Executable: .\x64\%CONFIG%\Water-Jug-Problem.exe
    echo.
    
    REM Check if input.txt exists
    if exist "Water-Jug-Problem\input.txt" (
        echo [INFO] input.txt found - Ready to run!
        echo [TIP] Run: x64\%CONFIG%\Water-Jug-Problem.exe
    ) else (
        echo [WARN] input.txt not found
        echo [TIP] Create input.txt in Water-Jug-Problem\ folder
        echo        Format:
        echo        ^<capacityA^> ^<capacityB^> ^<target^>
        echo        ^<algorithm^>
    )
    echo.
) else (
    echo.
    echo ====================================
    echo   BUILD FAILED!
    echo ====================================
    echo.
    echo Check the errors above for details
    echo.
)

pause
