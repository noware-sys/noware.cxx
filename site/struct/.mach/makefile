#.PHONY : clean
.PHONY : all, clean

# QUEX_PATH = /opt/quex
QUEX_PATH = /usr/include/quex
LIB = noware
LIB_PATH = /root/Documents/C++/NoWare
COMPILER = g++
CCOMPILER = gcc
# IN = main.c++ $(LIB_PATH)/$(LIB)/mathematics.c++ $(LIB_PATH)/$(LIB)/tools.c++ $(LIB_PATH)/$(LIB)/network/endpoint.c++ $(LIB_PATH)/$(LIB)/network/ip.c++ $(LIB_PATH)/$(LIB)/network/ip/tcp.c++ $(LIB_PATH)/$(LIB)/network/ip/udp.c++ $(LIB_PATH)/$(LIB)/network/ip/mpi.c++ $(LIB_PATH)/$(LIB)/network/mpi.c++ $(LIB_PATH)/$(LIB)/network/connection.c++ $(LIB_PATH)/$(LIB)/containers/variable.c++ $(LIB_PATH)/$(LIB)/language/interpreter.c++ $(LIB_PATH)/$(LIB)/machine/device.c++ $(LIB_PATH)/$(LIB)/machine/devices/memory.c++ $(LIB_PATH)/$(LIB)/machine/devices/processor.c++ $(LIB_PATH)/$(LIB)/machine/network/communication/message.c++ $(LIB_PATH)/$(LIB)/cluster/machine.c++
# IN = mathematics.obj tools.obj network-endpoint.obj network/ip.obj network-ip-tcp.obj network-ip-udp.obj network-ip-mpi.obj network-mpi.obj network-connection.obj containers-variable.obj language-interpreter.obj machine-device.obj machine-devices-memory.obj machine-devices-processor.obj machine-network-communication-message.obj cluster-machine.obj
IN = computer.obj
# For "entity" only:
#IN = main.c++ $(LIB_PATH)/$(LIB)/containers/variable.c++ $(LIB_PATH)/$(LIB)/tools.c++
#IN = tools.obj containers-variable.obj cluster.obj
OUT = main.do
OUT_32 = main-32.do
IN_QUEX = quex-example.cpp
OUT_QUEX = quex-example.do
#	COMPILER = g++ -o main.exe

ifdef ASSERTS_ENABLED_F
	CCFLAG_ASSERTS = # By default, asserts are enabled.
else 
	CCFLAG_ASSERTS = -DQUEX_OPTION_ASSERTS_DISABLED
endif

#ADD_FLAGS := #
#COMPILER_FLAGS = -ggdb -pedantic -Wconversion -Wall -W -std=c++11 -std=gnu++11 -m64 -o main.do
#COMPILER_FLAGS = -g -ggdb -pedantic -fpermissive -W -Wall -Wmain -Wcomment -Wconversion -Wunused-parameter -Wparentheses -std=c++14 -I . -I $(QUEX_PATH) -I /usr/include/boost -I $(LIB_PATH) $(CCFLAG_ASSERTS) -l sqlite3 -l boost_system -l boost_serialization -l boost_thread -l cln -fopenmp
CCOMPILER_FLAGS = -l pthread -l dl
#CCOMPILER_FLAGS = -I . -I $(LIB_PATH) $(CCFLAG_ASSERTS)
#CCOMPILER_FLAGS = -I . -I $(LIB_PATH) $(CCFLAG_ASSERTS) -l pthread -l dl
#COMPILER_FLAGS = -static -ggdb -pedantic -Wconversion -Wall -W -std=c++11 -std=gnu++11 -m64 -o main.do
COMPILER_FLAGS = -g -ggdb -pedantic -fpermissive -W -Wall -Wmain -Wcomment -Wconversion -Wunused-parameter -Wparentheses -std=c++14 -I . -I $(QUEX_PATH) -I $(LIB_PATH) $(CCFLAG_ASSERTS) -L . -l boost_system -l boost_serialization -l boost_thread -l cln -fopenmp -l pthread -l dl
#COMPILER_FLAGS = -g -ggdb -pedantic -fpermissive -static -W -Wall -Wmain -Wcomment -Wconversion -Wunused-parameter -Wparentheses -std=c++14 -I . -I $(QUEX_PATH) -I /usr/include/boost -I $(LIB_PATH) $(CCFLAG_ASSERTS) -L . -l boost_system -l boost_serialization -l boost_thread -l cln -fopenmp $(CCOMPILER_FLAGS)
#COMPILER_FLAGS = -g -ggdb -pedantic -fpermissive -static -W -Wall -Wmain -Wcomment -Wconversion -Wunused-parameter -Wparentheses -std=c++14 -I . -I $(QUEX_PATH) -I /usr/include/boost -I $(LIB_PATH) $(CCFLAG_ASSERTS) -l boost_system -l boost_serialization -l boost_thread -l cln -fopenmp -l pthread -l dl
#COMPILER_FLAGS = -g -static -ggdb -pedantic -fpermissive -W -Wall -Wmain -Wcomment -Wconversion -Wunused-parameter -Wparentheses -std=c++14 -I . -I $(QUEX_PATH) -I /usr/include/boost -I $(LIB_PATH) $(CCFLAG_ASSERTS) -l sqlite3 -l boost_system -l boost_serialization -l boost_thread -l cln -fopenmp
#CC = $(COMPILER) \
	# -I ./ -I $(QUEX_PATH)  \
	 -I ./ -I /usr/include/quex  \
	 $(COMPILER_FLAGS) \
	$(CCFLAG_ASSERTS)
	# -DQUEX_OPTION_ASSERTS_DISABLED \
	# -DQUEX_OPTION_ASSERTS_WARNING_MESSAGE_DISABLED \
	# -DQUEX_OPTION_DEBUG_SHOW \

#ifndef QUEX_PATH
#	$(error The environment variable QUEX_PATH is not defined!)
#endif

#include $(QUEX_PATH)/quex/code_base/core.mkd
include /usr/include/quex/quex/code_base/core.mkd

#all:
all : $(OUT)
$(OUT) : #sqlite.obj #$(IN)
#lexical_analyzer: lexer/lexical_analyzer.qx $(QUEX_CORE)
	if test ! -f $(OUT);\
	then\
		##$(CC) $(IN); \
		##$(COMPILER) $(COMPILER_FLAGS) -o $(OUT) $(IN); \
		$(COMPILER) $(COMPILER_FLAGS) -o main.obj -c main.c++; \
		#$(COMPILER) $(COMPILER_FLAGS) -o mathematics.obj -c $(LIB_PATH)/$(LIB)/mathematics.c++; \
		#$(COMPILER) $(COMPILER_FLAGS) -o tools.obj -c $(LIB_PATH)/$(LIB)/tools.c++; \
		#$(COMPILER) $(COMPILER_FLAGS) -o network-endpoint.obj -c $(LIB_PATH)/$(LIB)/network/endpoint.c++; \
		#$(COMPILER) $(COMPILER_FLAGS) -o network-ip.obj -c $(LIB_PATH)/$(LIB)/network/ip.c++; \
		#$(COMPILER) $(COMPILER_FLAGS) -o network-ip-tcp.obj -c $(LIB_PATH)/$(LIB)/network/ip/tcp.c++; \
		#$(COMPILER) $(COMPILER_FLAGS) -o network-ip-udp.obj -c $(LIB_PATH)/$(LIB)/network/ip/udp.c++; \
		#$(COMPILER) $(COMPILER_FLAGS) -o network-ip-mpi.obj -c $(LIB_PATH)/$(LIB)/network/ip/mpi.c++; \
		#$(COMPILER) $(COMPILER_FLAGS) -o network-mpi.obj -c $(LIB_PATH)/$(LIB)/network/mpi.c++; \
		#$(COMPILER) $(COMPILER_FLAGS) -o network-_mpi.obj -c $(LIB_PATH)/$(LIB)/network/_mpi.c++; \
		#$(COMPILER) $(COMPILER_FLAGS) -o containers-variable.obj -c $(LIB_PATH)/$(LIB)/containers/variable.c++ ; \
		#$(COMPILER) $(COMPILER_FLAGS) -o containers-memory.obj -c $(LIB_PATH)/$(LIB)/containers/memory.c++ ; \
		##$(COMPILER) $(COMPILER_FLAGS) -o sqlite-3.obj -c $(LIB_PATH)/sqlite/3.c ; \
		#$(COMPILER) $(COMPILER_FLAGS) -o containers-databases-sqlite.c++.obj -c $(LIB_PATH)/$(LIB)/containers/databases/sqlite.c++ ; \
		#$(COMPILER) $(COMPILER_FLAGS) -o language-interpreter.obj -c $(LIB_PATH)/$(LIB)/language/interpreter.c++; \
		#$(COMPILER) $(COMPILER_FLAGS) -o communication-message.obj -c $(LIB_PATH)/$(LIB)/communication/message.c++; \
		#$(COMPILER) $(COMPILER_FLAGS) -o communication-transmission.obj -c $(LIB_PATH)/$(LIB)/communication/transmission.c++; \
		#$(COMPILER) $(COMPILER_FLAGS) -o communication-messaging.obj -c $(LIB_PATH)/$(LIB)/communication/messaging.c++; \
		#$(COMPILER) $(COMPILER_FLAGS) -o machine-resource.obj -c $(LIB_PATH)/$(LIB)/machine/resource.c++; \
		#$(COMPILER) $(COMPILER_FLAGS) -o machine-resources-memory.obj -c $(LIB_PATH)/$(LIB)/machine/resources/memory.c++; \
		#$(COMPILER) $(COMPILER_FLAGS) -o machine-resources-processor.obj -c $(LIB_PATH)/$(LIB)/machine/resources/processor.c++; \
		##$(COMPILER) $(COMPILER_FLAGS) -o machine-network-communication-message.obj -c $(LIB_PATH)/$(LIB)/machine/network/communication/message.c++; \
		#$(COMPILER) $(COMPILER_FLAGS) -o cluster-machine.obj -c $(LIB_PATH)/$(LIB)/cluster/machine.c++; \
		##$(COMPILER) $(COMPILER_FLAGS) -o cluster.obj -c $(LIB_PATH)/$(LIB)/cluster.c++; \
		$(COMPILER) $(COMPILER_FLAGS) -o computer.obj -c $(LIB_PATH)/$(LIB)/computer.c++;\
		\
		$(COMPILER) $(COMPILER_FLAGS) -o $(OUT) main.obj $(IN); \
	fi
	
	if test -f $(OUT) && test ! -x $(OUT); \
	#if test ! -x $(OUT); \
	then \
		chmod +x $(OUT); \
	fi
quex_example:
	if test ! -f ./lexer/lexical_analyzer.cpp; \
	then \
		cd ./lexer; \
		#export QUEX_PATH=$(QUEX_PATH); \
		python2 $(QUEX_PATH)/quex.py --engine lexical_analyzer -i lexical_analyzer.qx; \
	fi
	
	if test ! -f $(OUT_QUEX); \
	then \
		#$(COMPILER) $(COMPILER_FLAGS) -o $(OUT_QUEX) $(IN_QUEX); \
		$(COMPILER) -g -ggdb -pedantic -fpermissive -Wconversion -Wall -W -Wmain -Wcomment -std=c++11 -I . -I $(QUEX_PATH) -o $(OUT_QUEX) $(IN_QUEX); \
	fi
	
	if test -f $(OUT_QUEX) && test ! -x $(OUT_QUEX); \
	#if test ! -x $(OUT_QUEX); \
	then \
		chmod +x $(OUT_QUEX); \
	fi
32:
	if test ! -f ./lexer/lexical_analyzer.cpp; \
	then \
		cd ./lexer; \
		#export QUEX_PATH=$(QUEX_PATH); \
		python2 $(QUEX_PATH)/quex.py --engine lexical_analyzer -i lexical_analyzer.qx; \
	fi
	
	if test ! -f $(OUT_32); \
	then \
		#$(CC) $(IN); \
		$(COMPILER) $(COMPILER_FLAGS) -m32 -o $(OUT_32) $(IN); \
	fi
	
	if test -f $(OUT_32) && test ! -x $(OUT_32); \
	#if test ! -x $(OUT_32); \
	then \
		chmod +x $(OUT_32); \
	fi
sqlite.obj :
	#$(CCOMPILER) $(CCOMPILER_FLAGS) -o sqlite.obj -c $(LIB_PATH)/sqlite/3.c\
	$(CCOMPILER) -o containers-databases-sqlite.c.obj -c $(LIB_PATH)/$(LIB)/containers/databases/sqlite.c
sqlite.a : sqlite.obj
	# Create the static library for sqlite.\
	ar rcs libsqlite.a containers-databases-sqlite.c.obj
sqlite.so : sqlite.obj
	$(CCOMPILER) -shared -Wl,-soname,sqlite.so.1 -o sqlite.so.1.0.1 -c $(LIB_PATH)/$(LIB)/containers/databases/sqlite.c
clean:
	#rm --force *.do *.run *.exe *.bin lexical_analyzer* *.bak *.E lexer
	#rm --force *.do lexical_analyzer* *.bak *.E lexer
	#rm --force *.do lexer/lexical_analyzer lexer/lexical_analyzer.cpp lexer/lexical_analyzer-configuration lexer/lexical_analyzer-token lexer/lexical_analyzer-token_ids *.bak *.E
	rm --force *.do *.obj
