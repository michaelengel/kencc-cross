#                                              -*-makefile-*-

DIRS=\
	lib9\
	libbio\
	liblex\
	libmach\
	libregexp\
	libmath\
    \
	mk\
	lex\
	yacc\
    \
	cc\
	tc\
	tl\
	qa\
	qc\
	ql\
	7a\
	7c\
	7l\
	6a\
	6c\
	6l\
	ka\
	kc\
	kl\
	2a\
	2c\
	2l\
	1a\
	1c\
	1l\
	va\
	vc\
	vl\
	0a\
	0c\
	0l\
	8a\
	8c\
	8l\
	za\
	zc\
	zl\
	5a\
	5c\
	5l\
    \
	ar\
	acid\
    pcc\
    \
    rc\
    utilities

# mkconfig is included at this point to allow it to override
# the preceding declarations if need be

<mkconfig

all:V:		all-$HOSTMODEL
clean:V:	clean-$HOSTMODEL
install:V:	install-$HOSTMODEL
installall:V:	installall-$HOSTMODEL
nuke:V:		nuke-$HOSTMODEL

cleandist:V: clean
	rm -f $ROOT/$OBJDIR/lib/lib*.a

nukedist:V: nuke
	rm -f $ROOT/$OBJDIR/bin/*.exe
	rm -f $ROOT/$OBJDIR/lib/lib*.a

&-Posix:QV:
	for j in $DIRS
	do
		echo "(cd $j; mk $MKFLAGS $stem)"
		(cd $j; mk $MKFLAGS $stem) || exit 1
	done

&-Plan9:QV:
	for (j in $DIRS)
	{
		echo '@{builtin cd' $j '; mk $MKFLAGS $stem}'
		@{builtin cd $j; mk $MKFLAGS $stem }
	}

# Convenience targets

Plan9-% plan9-%:V:
	mk 'SYSHOST=Plan9' 'OBJTYPE=386' $stem

Linux-% linux-%:V:
	mk 'SYSHOST=Linux' 'OBJTYPE=386' $stem
