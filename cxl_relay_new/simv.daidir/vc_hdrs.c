#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <dlfcn.h>
#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif

/* VCS error reporting routine */
extern void vcsMsgReport1(const char *, const char *, int, void *, void*, const char *);

#ifndef _VC_TYPES_
#define _VC_TYPES_
/* common definitions shared with DirectC.h */

typedef unsigned int U;
typedef unsigned char UB;
typedef unsigned char scalar;
typedef struct { U c; U d;} vec32;

#define scalar_0 0
#define scalar_1 1
#define scalar_z 2
#define scalar_x 3

extern long long int ConvUP2LLI(U* a);
extern void ConvLLI2UP(long long int a1, U* a2);
extern long long int GetLLIresult();
extern void StoreLLIresult(const unsigned int* data);
typedef struct VeriC_Descriptor *vc_handle;

#ifndef SV_3_COMPATIBILITY
#define SV_STRING const char*
#else
#define SV_STRING char*
#endif

#endif /* _VC_TYPES_ */

#ifndef _VC_STRUCT_TYPE_simics_transaction_t_
#define _VC_STRUCT_TYPE_simics_transaction_t_
typedef struct _vcs_dpi_simics_transaction_t	simics_transaction_t;
#endif

#ifndef _VC_STRUCT_TYPE_simics_transaction_t_
#define _VC_STRUCT_TYPE_simics_transaction_t_
struct	_vcs_dpi_simics_transaction_t	{
	unsigned int	packet_number;
	unsigned int	packet_type;
	unsigned int	sim_type;
	unsigned long long	base_address;
	unsigned long long	physical_address;
	unsigned int	r0w1;
	unsigned int	data_size;
	unsigned char	data[256];
};

#endif


#ifndef __VCS_IMPORT_DPI_STUB_open_server_fifo
#define __VCS_IMPORT_DPI_STUB_open_server_fifo
__attribute__((weak)) int open_server_fifo()
{
    static int _vcs_dpi_stub_initialized_ = 0;
    static int (*_vcs_dpi_fp_)() = NULL;
    if (!_vcs_dpi_stub_initialized_) {
        _vcs_dpi_fp_ = (int (*)()) dlsym(RTLD_NEXT, "open_server_fifo");
        _vcs_dpi_stub_initialized_ = 1;
    }
    if (_vcs_dpi_fp_) {
        return _vcs_dpi_fp_();
    } else {
        const char *fileName;
        int lineNumber;
        svGetCallerInfo(&fileName, &lineNumber);
        vcsMsgReport1("DPI-DIFNF", fileName, lineNumber, 0, 0, "open_server_fifo");
        return 0;
    }
}
#endif /* __VCS_IMPORT_DPI_STUB_open_server_fifo */

#ifndef __VCS_IMPORT_DPI_STUB_print_simics_pkt_data
#define __VCS_IMPORT_DPI_STUB_print_simics_pkt_data
__attribute__((weak)) void print_simics_pkt_data(const /* INPUT */simics_transaction_t *A_1)
{
    static int _vcs_dpi_stub_initialized_ = 0;
    static void (*_vcs_dpi_fp_)(const /* INPUT */simics_transaction_t *A_1) = NULL;
    if (!_vcs_dpi_stub_initialized_) {
        _vcs_dpi_fp_ = (void (*)(const simics_transaction_t* A_1)) dlsym(RTLD_NEXT, "print_simics_pkt_data");
        _vcs_dpi_stub_initialized_ = 1;
    }
    if (_vcs_dpi_fp_) {
        _vcs_dpi_fp_(A_1);
    } else {
        const char *fileName;
        int lineNumber;
        svGetCallerInfo(&fileName, &lineNumber);
        vcsMsgReport1("DPI-DIFNF", fileName, lineNumber, 0, 0, "print_simics_pkt_data");
    }
}
#endif /* __VCS_IMPORT_DPI_STUB_print_simics_pkt_data */

#ifndef __VCS_IMPORT_DPI_STUB_simics_dpi_request
#define __VCS_IMPORT_DPI_STUB_simics_dpi_request
__attribute__((weak)) int simics_dpi_request(/* OUTPUT */simics_transaction_t *A_1)
{
    static int _vcs_dpi_stub_initialized_ = 0;
    static int (*_vcs_dpi_fp_)(/* OUTPUT */simics_transaction_t *A_1) = NULL;
    if (!_vcs_dpi_stub_initialized_) {
        _vcs_dpi_fp_ = (int (*)(simics_transaction_t* A_1)) dlsym(RTLD_NEXT, "simics_dpi_request");
        _vcs_dpi_stub_initialized_ = 1;
    }
    if (_vcs_dpi_fp_) {
        return _vcs_dpi_fp_(A_1);
    } else {
        const char *fileName;
        int lineNumber;
        svGetCallerInfo(&fileName, &lineNumber);
        vcsMsgReport1("DPI-DIFNF", fileName, lineNumber, 0, 0, "simics_dpi_request");
        return 0;
    }
}
#endif /* __VCS_IMPORT_DPI_STUB_simics_dpi_request */

#ifndef __VCS_IMPORT_DPI_STUB_simics_dpi_response
#define __VCS_IMPORT_DPI_STUB_simics_dpi_response
__attribute__((weak)) int simics_dpi_response(const /* INPUT */simics_transaction_t *A_1)
{
    static int _vcs_dpi_stub_initialized_ = 0;
    static int (*_vcs_dpi_fp_)(const /* INPUT */simics_transaction_t *A_1) = NULL;
    if (!_vcs_dpi_stub_initialized_) {
        _vcs_dpi_fp_ = (int (*)(const simics_transaction_t* A_1)) dlsym(RTLD_NEXT, "simics_dpi_response");
        _vcs_dpi_stub_initialized_ = 1;
    }
    if (_vcs_dpi_fp_) {
        return _vcs_dpi_fp_(A_1);
    } else {
        const char *fileName;
        int lineNumber;
        svGetCallerInfo(&fileName, &lineNumber);
        vcsMsgReport1("DPI-DIFNF", fileName, lineNumber, 0, 0, "simics_dpi_response");
        return 0;
    }
}
#endif /* __VCS_IMPORT_DPI_STUB_simics_dpi_response */


#ifdef __cplusplus
}
#endif

