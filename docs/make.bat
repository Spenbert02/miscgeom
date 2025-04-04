@ECHO OFF

pushd %~dp0

REM Command file for Sphinx documentation

if "%SPHINXBUILD%" == "" (
	set SPHINXBUILD=sphinx-build
)
set SOURCEDIR=source
set BUILDDIR=build

%SPHINXBUILD% >NUL 2>NUL
if errorlevel 9009 (
	echo.
	echo.The 'sphinx-build' command was not found. Make sure you have Sphinx
	echo.installed, then set the SPHINXBUILD environment variable to point
	echo.to the full path of the 'sphinx-build' executable. Alternatively you
	echo.may add the Sphinx directory to PATH.
	echo.
	echo.If you don't have Sphinx installed, grab it from
	echo.https://www.sphinx-doc.org/
	exit /b 1
)

if "%1" == "" goto help
if "%1" == "help" goto help
if "%1" == "clean" goto clean
if "%1" == "html" goto html
if "%1" == "show" goto show

:help
	echo.
	echo Please use "make.bat <target>" where ^<target^> is one of
	echo.
	echo html		to make standalone HTML files
	echo show		to show the HTML output in a web browser
	goto end

:html
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS% %O%
	goto end

:show
	python -m webbrowser -t "%~dp0\build\html\index.html"
	goto end

:end
popd
