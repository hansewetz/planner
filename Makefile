SUBDIRS = src 

include $(PROJECT_ROOT)/env/makerules/subdirs.rules

artefacts: src

help:
	@echo "usage: make [all|TARGET=clean]"
	@echo "       all: build all artefacts"
	@echo "       TARGET=clean: remove all artefacts"
