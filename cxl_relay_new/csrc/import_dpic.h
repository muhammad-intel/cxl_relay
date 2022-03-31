typedef struct _vcs_dpi_simics_transaction_t	simics_transaction_t;

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



 extern int open_server_fifo();

 extern void print_simics_pkt_data(const /* INPUT */simics_transaction_t *pkt);

 extern int simics_dpi_request(/* OUTPUT */simics_transaction_t *from_simics);

 extern int simics_dpi_response(const /* INPUT */simics_transaction_t *to_simics);
