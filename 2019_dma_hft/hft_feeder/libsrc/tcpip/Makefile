#
# Generated By "genmake"
# Date : 1996.12.03
# PentaSoft Co.,Ltd.
#

SUBDIRS1 = idgram/libsrc istream/libsrc multi/libsrc udgram/libsrc ustream/libsrc 
MAKE    = make
SUBDIRS = $(SUBDIRS1)

all:
	@for i in $(SUBDIRS); do (cd ./$$i && echo $$i: && $(MAKE) $@) done || exit 1
install:
	@for i in $(SUBDIRS); do (cd ./$$i && echo $$i: && $(MAKE) $@) done || exit 1

clean:
	@for i in $(SUBDIRS); do (cd ./$$i && echo $$i: && $(MAKE) $@) done || exit 1

compress :
	@for i in $(SUBDIRS); do (cd ./$$i && echo $$i: && $(MAKE) $@) done || exit 1
	@rm -f ./lib/*.a
	@tar -cvf ../back.tar ./
