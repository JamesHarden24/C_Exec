/*******************************************************************************
  input输入子系统
    为了对多种不同类别的输入设备(如键盘、鼠标、跟踪球、操作杆、触摸屏、加速计和
  手写板)进行统一处理，内核在字符设备驱动上抽象出的一层，也就是输入子系统层。
    输入子系统由两类驱动程序组成: 事件驱动程序和设备驱动程序。
    事件驱动程序负责处理和应用程序的接口，它向应用程序提供简单的、统一的事件接口；
  设备驱动程序负责和底层输入设备的通信。
  注意:
      事件驱动程序是标准的，对所有输入类都是可用的，所以，我们不需要实现事件驱动，
  因为内核里边已经支持所有的事件驱动；我们需要实现的是输入设备驱动程序。

  (1)input_dev代表底层设备，比如"USB keyboard"或者"Power Button"(PC的电源按键)，
     所有的设备的input_dev对象保存在一个全局的input_dev队列里。
  (2)input_handler代表某类输入设备的处理方法，比如说evdev就是专门处理输入设备产
     生的Event(事件)。所有的input_handler存放在input_hanlder队列里。
  (3)一个input_dev可以有多个input_handler。比如"USB Mouse"设备可以由"evdev"和
     "mousedev"来分别处理它产生的输入。
  (4)input handle用来关联某个input dev和某个input handler。每个input handle都会
     生成一个文件节点。
*******************************************************************************/

/*
** input_dev代表底层设备，所有的设备的input_dev对象保存在一个全局的input_dev队列里。
*/
struct input_dev {
	const char *name;
	const char *phys;
	const char *uniq;
	struct input_id id;
	unsigned long evbit[BITS_TO_LONGS(EV_CNT)];
	unsigned long keybit[BITS_TO_LONGS(KEY_CNT)];
	unsigned long relbit[BITS_TO_LONGS(REL_CNT)];
	unsigned long absbit[BITS_TO_LONGS(ABS_CNT)];
	unsigned long mscbit[BITS_TO_LONGS(MSC_CNT)];
	unsigned long ledbit[BITS_TO_LONGS(LED_CNT)];
	unsigned long sndbit[BITS_TO_LONGS(SND_CNT)];
	unsigned long ffbit[BITS_TO_LONGS(FF_CNT)];
	unsigned long swbit[BITS_TO_LONGS(SW_CNT)];
	unsigned int keycodemax;
	unsigned int keycodesize;
	void *keycode;
	int (*setkeycode)(struct input_dev *dev,
			  unsigned int scancode, unsigned int keycode);
	int (*getkeycode)(struct input_dev *dev,
			  unsigned int scancode, unsigned int *keycode);
	struct ff_device *ff;
	unsigned int repeat_key;
	struct timer_list timer;
	int sync;
	int abs[ABS_CNT];
	int rep[REP_MAX + 1];
	unsigned long key[BITS_TO_LONGS(KEY_CNT)];
	unsigned long led[BITS_TO_LONGS(LED_CNT)];
	unsigned long snd[BITS_TO_LONGS(SND_CNT)];
	unsigned long sw[BITS_TO_LONGS(SW_CNT)];
	int absmax[ABS_CNT];
	int absmin[ABS_CNT];
	int absfuzz[ABS_CNT];
	int absflat[ABS_CNT];
	int absres[ABS_CNT];
	int (*open)(struct input_dev *dev);
	void (*close)(struct input_dev *dev);
	int (*flush)(struct input_dev *dev, struct file *file);
	int (*event)(struct input_dev *dev, unsigned int type, unsigned int code, int value);
	struct input_handle *grab;
	spinlock_t event_lock;
	struct mutex mutex;
	unsigned int users;
	bool going_away;
	struct device dev;
	struct list_head	h_list;
	struct list_head	node;
};

/*
** input_handler 事件驱动
*/
struct input_handler {
	void *private;  /* 私有变量 */
	void (*event)(struct input_handle *handle, unsigned int type, unsigned int code, int value);
	bool (*filter)(struct input_handle *handle, unsigned int type, unsigned int code, int value);
	bool (*match)(struct input_handler *handler, struct input_dev *dev);
	int (*connect)(struct input_handler *handler, struct input_dev *dev, const struct input_device_id *id);
	void (*disconnect)(struct input_handle *handle);
	void (*start)(struct input_handle *handle);
	const struct file_operations *fops;
	int minor;
	const char *name;
	const struct input_device_id *id_table;
	struct list_head h_list;
	struct list_head node;
};


/*
** input_handle 输入事件
*/
struct input_handle {
	void *private;
	int open;
	const char *name;
	struct input_dev *dev;
	struct input_handler *handler;
	struct list_head d_node;
	struct list_head h_node;
};

