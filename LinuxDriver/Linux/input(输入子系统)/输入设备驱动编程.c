/*******************************************************************************
    在Linux中，input设备用input_dev结构体描述，在input.h中。设备的驱动只需要按照
如下步骤注册就可以了:
    (1)分配一个struct input dev;
    (2)初始化input dev这个结构体;
    (3)注册这个input设备
       input_register_device(dev);
    (4)在input设备发生输入操作时(按键被按下/抬起、触摸屏被触摸/抬起/移动、鼠标被
       移动/单击/抬起时等)，提交所发生的事件以及相应的键值/坐标等状态。
       
    事件类型(/input.h)
    #define EV_SYN			0x00   同步事件
    #define EV_KEY			0x01   按键事件
    #define EV_REL			0x02   相对坐标事件
    #define EV_ABS			0x03   绝对坐标事件
    #define EV_MSC			0x04
    #define EV_SW			0x05
    #define EV_LED			0x11   LED
    #define EV_SND			0x12   声音
    #define EV_REP			0x14
    #define EV_FF			0x15
    #define EV_PWR			0x16
    #define EV_FF_STATUS		0x17
    #define EV_MAX			0x1f
    #define EV_CNT			(EV_MAX+1)

       
*******************************************************************************/
