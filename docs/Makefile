# Minimal makefile for Sphinx documentation
#

# You can set these variables from the command line, and also
# from the environment for the first two.
SPHINXOPTS    ?=
SPHINXBUILD   ?= sphinx-build
FILES         ?=

.PHONY: help clean html

# Put it first so that "make" without argument is like "make help".
help:
	@echo "Use 'make <target>' where <target> is one of"
	@echo "  html      to make standalone HTML files"
	@echo "  clean     to clean up the build directory"
	@echo "  show      to show the HTML output in a web browser"

clean:
	rm -rf $(BUILDDIR)/*
	rm -rf $(SOURCEDIR)/api/*

html:
	python preprocess.py
	$(SPHINXBUILD) -b html $(SPHINXOPTS) build/html $(FILES)

show:
	@python -c "import webbrowser; webbrowser.open('file://$(PWD)/build/html/index.html')"
