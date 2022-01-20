#ifeq (0,${MAKELEVEL})
cur-dir   := $(shell pwd)
whoami    := $(shell whoami)
host-type := $(shell arch)
MAKE := ${MAKE} cur-dir=$(cur-dir) host-type=${host-type} whoami=${whoami}
#endif
all:
	@echo $(MAKELEVEL)
	@echo $(MAKE)      
