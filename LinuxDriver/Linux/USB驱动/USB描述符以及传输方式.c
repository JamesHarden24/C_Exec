/*************************************************************************************
lsusb -v ���Բ�ϵͳ��USB�豸�������Ϣ

�豸ͨ������һ�����߶�����á�
���þ�������һ�����߶���ӿڡ�
�ӿ�ͨ������һ�����߶�����á�
�ӿ�û�л��߾���һ�����϶˵㡣

�˵�:
(1)USBͨ�ŵ��������ʽ
(2)�˵�ֻ����һ�����������ݣ�����IN������OUT(�˵�0����)
(3)�˵������USB�豸��

USB�Ĵ��䷽ʽ:
(1)���ƴ���---����/�������á�
(2)�жϴ���---��:USB��ꡣ
(3)��������---���ڴ����������ݴ��䣬û�й̶��Ĵ������ʣ�����:USB��ӡ����ɨ���ǡ�������
              �洢�豸��U�̵ȡ�
(4)�ȴ�����---���Դ�������������ݣ�����û�������Ƿ񵽴�ı�֤������ʵʱ�Ե�Ҫ��ܸ�
              ����: ��Ƶ����Ƶ���豸(USB����ͷ��USB��Ͳ)��

URB(USB�������):
�������������͸�USB�豸��

*************************************************************************************/
/*
** usb�豸����
*/
struct usb_device_descriptor {
    __u8  bLength;
    __u8  bDescriptorType;

    __le16 bcdUSB;
    __u8  bDeviceClass;
    __u8  bDeviceSubClass;
    __u8  bDeviceProtocol;
    __u8  bMaxPacketSize0;
    __le16 idVendor;
    __le16 idProduct;
    __le16 bcdDevice;
    __u8  iManufacturer;
    __u8  iProduct;
    __u8  iSerialNumber;
    __u8  bNumConfigurations;
} __attribute__ ((packed));

/*
** USB��������
*/
struct usb_config_descriptor {
    __u8  bLength;
    __u8  bDescriptorType;

    __le16 wTotalLength;
    __u8  bNumInterfaces; /* ÿ���ӿڱ�ʾһ������ */
    __u8  bConfigurationValue;
    __u8  iConfiguration;
    __u8  bmAttributes;
    __u8  bMaxPower;
} __attribute__ ((packed));

/*
** USB�ӿ�������
*/
struct usb_interface_descriptor {
    __u8  bLength;
    __u8  bDescriptorType;

    __u8  bInterfaceNumber;
    __u8  bAlternateSetting;
    __u8  bNumEndpoints;
    __u8  bInterfaceClass;
    __u8  bInterfaceSubClass;
    __u8  bInterfaceProtocol;
    __u8  iInterface;
} __attribute__ ((packed));

/*
** USB�˵�������
*/
struct usb_endpoint_descriptor {
    __u8  bLength;          /* ���������ֽڳ��� */
    __u8  bDescriptorType;  /* ���������ͣ����ڶ˵����USB_DT_ENDPOINT */

    __u8  bEndpointAddress; /* 0~3bit��ʾ�ľ��Ƕ˵��ַ��bit8��ʾ�������뻹����� */
    __u8  bmAttributes;     /* ��ʾ���ԡ���bit0��bit1��ͬ����
                               00:��ʾ���� 01:��ʾ��ʱ 10:��ʾ���� 11:��ʾ�ж�*/
    __le16 wMaxPacketSize;  /* �˵�һ�ο��Դ��������ֽ��� */
    __u8  bInterval;        /* ϣ��������ѯ�Լ���ʱ���� */

    /* NOTE:  these two are _only_ in audio endpoints. */
    /* use USB_DT_ENDPOINT*_SIZE in bLength, not sizeof. */
    __u8  bRefresh;
    __u8  bSynchAddress;
} __attribute__ ((packed));


/*
** USB�����
*/
struct urb {
    /* private: usb core and host controller only fields in the urb */
    struct kref kref;		/* reference count of the URB */
    void *hcpriv;			/* private data for host controller */
    atomic_t use_count;		/* concurrent submissions counter */
    atomic_t reject;		/* submissions will fail */
    int unlinked;			/* unlink error code */

    /* public: documented fields in the urb that can be used by drivers */
    struct list_head urb_list;	/* list head for use by the urb's
    			 * current owner */
    struct list_head anchor_list;	/* the URB may be anchored */
    struct usb_anchor *anchor;
    struct usb_device *dev;		/* (in) pointer to associated device */
    struct usb_host_endpoint *ep;	/* (internal) pointer to endpoint */
    unsigned int pipe;		/* (in) pipe information */
    unsigned int stream_id;		/* (in) stream ID */
    int status;			/* (return) non-ISO status */
    unsigned int transfer_flags;	/* (in) URB_SHORT_NOT_OK | ...*/
    void *transfer_buffer;		/* (in) associated data buffer */
    dma_addr_t transfer_dma;	/* (in) dma addr for transfer_buffer */
    struct scatterlist *sg;		/* (in) scatter gather buffer list */
    int num_sgs;			/* (in) number of entries in the sg list */
    u32 transfer_buffer_length;	/* (in) data buffer length */
    u32 actual_length;		/* (return) actual transfer length */
    unsigned char *setup_packet;	/* (in) setup packet (control only) */
    dma_addr_t setup_dma;		/* (in) dma addr for setup_packet */
    int start_frame;		/* (modify) start frame (ISO) */
    int number_of_packets;		/* (in) number of ISO packets */
    int interval;			/* (modify) transfer interval
    			 * (INT/ISO) */
    int error_count;		/* (return) number of ISO errors */
    void *context;			/* (in) context for completion */
    usb_complete_t complete;	/* (in) completion routine */
    struct usb_iso_packet_descriptor iso_frame_desc[0];
					/* (in) ISO ONLY */
};