SHELL=tcsh

ifndef VCS_HOME
 $(error "Please run 'source source.me' first")
endif

SHARED_LIB_SRC=pcie_tlp_pkt_lib.c cxl_tlp_fifo.c  named_pipe.c dpi_sv.c 
SHARED_LIB_FLAGS=-shared -o libcxltlprelay.so
CLIENT_SRC= cxl_tlp_relay_client.c cxlcommlib.c
SERVER_SRC= cxl_tlp_relay_server.c cxlcommlib.c
SIMIC_DML_INTERFACE_SRC=dml_cxl_relay_interface.c dml_debug.c
SHARED_LIB_NAME=libcxltlprelay.so
TEST_HOST_SRC=testhost.c cxlcommlib.c
SIMIC_MEMOP_SRC=testhost_simics.c cxlcommlib.c
LINK_LIB=-lcxltlprelay -lpthread -lrt
COM_LIB=cxlcommlib.o
INCLUDE	= cxlcommlib.h cxl_tlp_fifo.h pcie_tlp_pkt_lib.h 
INCLUDE_PATH= -I. -I${VCS_HOME}/include
LIB_PATH=-L.
C_FLAGS=-fpermissive -Wenum-compare -fPIC 
CXL_RELAY_SO=libcxltlprelay
SV_OBJ_DIR=.
SV_SRC_FILE=${PWD}/dpi_sv.sv

CC=g++

targets: so client server testhost compile 

.PHONY: all clean so client server testhost cxlrelay compile simulate memop
all:$(INCLUDE)
	echo "Building CXL Client, Server, testhost, cxlrelay  executables..."
	$(CC) $(SHARED_LIB_SRC)  $(SIMIC_DML_INTERFACE_SRC)  $(INCLUDE_PATH)  $(SHARED_LIB_FLAGS)
	$(CC) $(CLIENT_SRC) $(INCLUDE_PATH) $(LIB_PATH) $(LINK_LIB)	-o cxlrelayclient
	$(CC) $(SERVER_SRC) $(INCLUDE_PATH) $(LIB_PATH)	$(LINK_LIB) -o cxlrelayserver
	$(CC) $(TEST_HOST_SRC) $(INCLUDE_PATH) $(LIB_PATH) $(LINK_LIB)	-o testhost
	$(CC) cxlrelay.c -o cxlrelay	
	echo "Build end ALL !!."

so:$(INCLUDE)
	echo "Building CXL TLP relay shared library..."
	$(CC) $(SHARED_LIB_SRC) $(SIMIC_DML_INTERFACE_SRC) $(INCLUDE_PATH) $(C_FLAGS) $(SHARED_LIB_FLAGS)
	echo "Build end - so"
client:$(INCLUDE)
	$(CC) $(CLIENT_SRC)  $(INCLUDE_PATH) $(LIB_PATH) $(LINK_LIB)	-o cxlrelayclient
	echo "Build end - client"
server:$(INCLUDE)
	$(CC) $(SERVER_SRC) $(C_FLAGS) $(INCLUDE_PATH) $(LIB_PATH) $(LINK_LIB)	-o cxlrelayserver
	echo "Build end - server"
testhost:$(INCLUDE)
	$(CC) $(TEST_HOST_SRC) $(INCLUDE_PATH) $(LIB_PATH) $(LINK_LIB)	-o testhost
	echo "Build end - testhost"
simics:$(INCLUDE)
	$(CC) $(SIMIC_MEMOP_SRC) $(INCLUDE_PATH) $(LIB_PATH) $(LINK_LIB)	-o testhostsimics
	echo "Build end - simics"	
cxlrelay:
	$(CC) cxlrelay.c -o cxlrelay
	echo "Build end - cxlrelay"	
compile:
	mkdir -p $(SV_OBJ_DIR)
	source source.me && vcs -full64 -debug_acc+all -kdb -lca -sverilog +libext+.v+.sv -y ${PWD} +incdir+${PWD} $(SV_SRC_FILE) -l compile.log  -o $(SV_OBJ_DIR)/simv 
simulate:$(SV_OBJ_DIR)/simv
	cd ${SV_OBJ_DIR} && simv +vcs+lic+wait +fsdb+all=on -ucli -i ./batch.tcl -l sim.log -sv_lib $(CXL_RELAY_SO)
clean:
	echo "Cleaning.."
	rm -rf *.o *.so csrc simv.daidir *.log *.txt novas.fsdb
