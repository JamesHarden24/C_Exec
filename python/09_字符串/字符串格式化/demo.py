Python 3.6.1 (v3.6.1:69c0db5, Mar 21 2017, 18:41:36) [MSC v.1900 64 bit (AMD64)] on win32
Type "copyright", "credits" or "license()" for more information.
>>> "{0}  love {1}.{2}".format("I", "FishC", "com")
'I  love FishC.com'
>>> "{a}  love {b}.{c}".format(a = "I", b = "FishC", c = "com")
'I  love FishC.com'
>>> "{0}  love {b}.{c}".format("I", b = "FishC", c = "com")
'I  love FishC.com'
>>> "{{0}}".format("²»´òÓ¡")
'{0}'
>>> '{0:.1f}{1}'.format(27.658, )
Traceback (most recent call last):
  File "<pyshell#4>", line 1, in <module>
    '{0:.1f}{1}'.format(27.658, )
IndexError: tuple index out of range

>>> '{0:.1f}{1}'.format(27.658, 'GB')
'27.7GB'
>>> '%c' % 97
'a'
>>> '%c %c %c ' % (97, 98, 99)
'a b c '
>>> '%s' % 'I am Rookie'
'I am Rookie'
>>> '%d + %d = %d' % (4, 5, 4+5)
'4 + 5 = 9'
>>> '%#X' % 108
'0X6C'
>>> '%#x' % 108
'0x6c'
>>> '%010d' % 5
'0000000005'
>>> '%010d' % 5
KeyboardInterrupt
>>> '%-010d' % 5
'5         '
>>> 