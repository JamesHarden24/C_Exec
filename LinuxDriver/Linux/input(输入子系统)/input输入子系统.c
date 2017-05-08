/*******************************************************************************
  input������ϵͳ
    Ϊ�˶Զ��ֲ�ͬ���������豸(����̡���ꡢ�����򡢲����ˡ������������ټƺ�
  ��д��)����ͳһ�����ں����ַ��豸�����ϳ������һ�㣬Ҳ����������ϵͳ�㡣
    ������ϵͳ�����������������: �¼�����������豸��������
    �¼��������������Ӧ�ó���Ľӿڣ�����Ӧ�ó����ṩ�򵥵ġ�ͳһ���¼��ӿڣ�
  �豸����������͵ײ������豸��ͨ�š�
  ע��:
      �¼����������Ǳ�׼�ģ������������඼�ǿ��õģ����ԣ����ǲ���Ҫʵ���¼�������
  ��Ϊ�ں�����Ѿ�֧�����е��¼�������������Ҫʵ�ֵ��������豸��������

  (1)input_dev����ײ��豸������"USB keyboard"����"Power Button"(PC�ĵ�Դ����)��
     ���е��豸��input_dev���󱣴���һ��ȫ�ֵ�input_dev�����
  (2)input_handler����ĳ�������豸�Ĵ�����������˵evdev����ר�Ŵ��������豸��
     ����Event(�¼�)�����е�input_handler�����input_hanlder�����
  (3)һ��input_dev�����ж��input_handler������"USB Mouse"�豸������"evdev"��
     "mousedev"���ֱ��������������롣
  (4)input handle��������ĳ��input dev��ĳ��input handler��ÿ��input handle����
     ����һ���ļ��ڵ㡣
*******************************************************************************/

/*
** input_dev����ײ��豸�����е��豸��input_dev���󱣴���һ��ȫ�ֵ�input_dev�����
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
** input_handler �¼�����
*/
struct input_handler {
	void *private;  /* ˽�б��� */
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
** input_handle �����¼�
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

