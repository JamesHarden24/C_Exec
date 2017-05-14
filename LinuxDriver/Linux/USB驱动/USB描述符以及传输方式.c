/*************************************************************************************
lsusb -v 可以查系统中USB设备的相关信息

设备通常具有一个或者多个配置。
配置经常具有一个或者多个接口。
接口通常具有一个或者多个设置。
接口没有或者具有一个以上端点。

端点:
(1)USB通信的最基本形式
(2)端点只能往一个方向传输数据，或者IN，或者OUT(端点0除外)
(3)端点存在与USB设备端

USB的传输方式:
(1)控制传输---或者/配置设置。
(2)中断传输---如:USB鼠标。
(3)批量传输---用于大容量的数据传输，没有固定的传输速率，例如:USB打印机、扫描仪、大容量
              存储设备，U盘等。
(4)等待传输---可以传输大批量的数据，但是没有数据是否到达的保证，它对实时性的要求很高
              例如: 音频、视频等设备(USB摄像头，USB话筒)。

URB(USB的请求块):
主机控制器发送给USB设备的

*************************************************************************************/
/*
** usb设备描述
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
** USB配置描述
*/
struct usb_config_descriptor {
    __u8  bLength;
    __u8  bDescriptorType;

    __le16 wTotalLength;
    __u8  bNumInterfaces; /* 每个接口表示一个功能 */
    __u8  bConfigurationValue;
    __u8  iConfiguration;
    __u8  bmAttributes;
    __u8  bMaxPower;
} __attribute__ ((packed));

/*
** USB接口描述符
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
** USB端点描述符
*/
struct usb_endpoint_descriptor {
    __u8  bLength;          /* 描述符的字节长度 */
    __u8  bDescriptorType;  /* 描述符类型，对于端点就是USB_DT_ENDPOINT */

    __u8  bEndpointAddress; /* 0~3bit表示的就是端点地址，bit8表示方向，输入还是输出 */
    __u8  bmAttributes;     /* 表示属性。又bit0和bit1共同控制
                               00:表示控制 01:表示等时 10:表示批量 11:表示中断*/
    __le16 wMaxPacketSize;  /* 端点一次可以处理的最大字节数 */
    __u8  bInterval;        /* 希望主机轮询自己的时间间隔 */

    /* NOTE:  these two are _only_ in audio endpoints. */
    /* use USB_DT_ENDPOINT*_SIZE in bLength, not sizeof. */
    __u8  bRefresh;
    __u8  bSynchAddress;
} __attribute__ ((packed));


/*
** USB请求块
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