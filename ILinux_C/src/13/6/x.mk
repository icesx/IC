    comma:= ,
    empty:=
    space:= $(empty) $(empty)
    foo:= a b c
bar:= $(subst $(space),$(comma),$(foo))
all:
	@echo $(bar)
