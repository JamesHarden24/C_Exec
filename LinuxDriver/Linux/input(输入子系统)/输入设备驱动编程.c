/*******************************************************************************
    ��Linux�У�input�豸��input_dev�ṹ����������input.h�С��豸������ֻ��Ҫ����
���²���ע��Ϳ�����:
    (1)����һ��struct input dev;
    (2)��ʼ��input dev����ṹ��;
    (3)ע�����input�豸
       input_register_device(dev);
    (4)��input�豸�����������ʱ(����������/̧�𡢴�����������/̧��/�ƶ�����걻
       �ƶ�/����/̧��ʱ��)���ύ���������¼��Լ���Ӧ�ļ�ֵ/�����״̬��
       
    �¼�����(/input.h)
    #define EV_SYN			0x00   ͬ���¼�
    #define EV_KEY			0x01   �����¼�
    #define EV_REL			0x02   ��������¼�
    #define EV_ABS			0x03   ���������¼�
    #define EV_MSC			0x04
    #define EV_SW			0x05
    #define EV_LED			0x11   LED
    #define EV_SND			0x12   ����
    #define EV_REP			0x14
    #define EV_FF			0x15
    #define EV_PWR			0x16
    #define EV_FF_STATUS		0x17
    #define EV_MAX			0x1f
    #define EV_CNT			(EV_MAX+1)

       
*******************************************************************************/
