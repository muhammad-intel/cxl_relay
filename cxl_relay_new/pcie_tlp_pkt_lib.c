/****************
 *PCIe TLP Packet lib
 *
 *
 *****************/
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <fcntl.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>


#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <mqueue.h>
#include "pcie_tlp_pkt_lib.h"
#include "cxl_tlp_fifo.h"
#include "dml_memaccess.h"



int init_server_fifo(void);
int init_client_fifo(void);
char cxl_relay_log_path[4096];
FILE *tlp_text_file = NULL;
int init_log(void)
{
   char *p = getenv("CXL_RELAY_LOG_PATH");
   if(p==NULL)
   {
      printf("init_log: CXL_RELAY_LOG_PATH  not set\n");
	  strcpy(cxl_relay_log_path,"./");
      return -1;
   }
   strcpy(cxl_relay_log_path,p);
   strcat(cxl_relay_log_path,"/");	
   
   return 0	;
}
////////////////////////	
int init_cxl_relay_client_lib(void)
{
   printf("init_cxl_relay_client_lib:  enter\n");
   char *p = getenv("CXL_RELAY_LOG_PATH");
   if(p==NULL)
   {
      printf("init_cxl_relay_client_lib: CXL_RELAY_LOG_PATH  not set\n");
	  strcpy(cxl_relay_log_path,"./");
      return -1;
   }
   strcpy(cxl_relay_log_path,p);
   strcat(cxl_relay_log_path,"/");
   init_client_fifo();	
   return 0;
}
////////////////////////	
////////////////////////	
int init_cxl_relay_server_lib(void)
{
   printf("init_cxl_relay_server_lib:  enter\n");
   char *p = getenv("CXL_RELAY_LOG_PATH");
   if(p==NULL)
   {
      printf("init_cxl_relay_server_lib: CXL_RELAY_LOG_PATH  not set\n");
	  strcpy(cxl_relay_log_path,"./");
      return -1;
   }
   strcpy(cxl_relay_log_path,p);
   strcat(cxl_relay_log_path,"/");
   init_server_fifo();

   return 0;
}
////////////////////////
int init_cxl_relay_lib(void)
{
   printf("init_pcie_relay_lib:  enter\n");
   init_server_fifo();
   init_client_fifo();	
   return 0;
}


int simics_print_fifo_pkt_data_and_log(simics_transaction_t *simics_data,FILE *fp,int verbose,int request_reply_flag)
{
    int i;
    struct tm *tm;
	static char timebuf[64];
	time_t stamp_t = time(NULL);
    if ((tm = localtime (&stamp_t)) == NULL) {
        printf ("Error extracting time stuff\n");
        return -1;
    }
    sprintf (timebuf,"%04d-%02d-%02d %02d:%02d:%02d", 
        1900 + tm->tm_year, 
        tm->tm_mon+1, 
        tm->tm_mday,
        tm->tm_hour, 
        tm->tm_min, 
        tm->tm_sec);
   if(verbose)
   {
	   printf("%s: [%s] packet_number=%10d packet_type=%2d sim_type=%2d physical_address=%016llX r0w1=%1d data_size=%4d ",
	          (request_reply_flag==1) ? "simics_dpi_request" : "simics_dpi_reply",
			  timebuf,
			  simics_data->packet_number,
			  simics_data->packet_type,
			  simics_data->sim_type,
			  simics_data->physical_address,
			  simics_data->r0w1,
			  simics_data->data_size);
	   printf(" data: ");
	   for(i=0;i<simics_data->data_size;i++)
		  printf("%02X ",	simics_data->data[i]);
	   printf("\n");
   }   
	
   if(fp != NULL)
   {
      fprintf(fp,"%s: [%s] packet_number=%10d packet_type=%2d sim_type=%2d physical_address=%016llX r0w1=%1d data_size=%4d",
	          (request_reply_flag==1) ? "simics_dpi_request" : "simics_dpi_reply",
			  timebuf,
              simics_data->packet_number,
              simics_data->packet_type,
              simics_data->sim_type,
              simics_data->physical_address,
              simics_data->r0w1,
              simics_data->data_size);
      fprintf(fp," data: ");
      for(i=0;i<simics_data->data_size;i++)
         fprintf(fp,"%02X ", simics_data->data[i]);
      fprintf(fp,"\n");			
      fflush(fp);
   }	

   return 0;
}
