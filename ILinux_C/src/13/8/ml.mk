names := a b c d
files := $(foreach n,$(names),$(n).o)
all:
	@echo $(files)
