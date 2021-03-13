sources := foo.c bar.c baz.s ugh.h
all:
	@echo $(filter %.c %.s,$(sources))

#以上代码用于显示，以下代码用于编译
#foo: $(sources)
#	cc $(filter %.c %.s,$(sources)) -o foo
