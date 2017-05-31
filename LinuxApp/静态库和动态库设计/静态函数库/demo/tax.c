/*******************************************************************************
  文 件 名: tax.c
  创建时间: 2017-05-31
  创 建 者: 张晓
  程序说明: 个人所得税计算函数库
*******************************************************************************/

int tax(int salary, int insurance)
{
    int tax_salary = salary - insurance; /* 应交税部分 */
    int tax_temp = tax_salary - 3500;

    if (tax_temp <= 1500)
    {
        return (tax_temp*0.03);
    }
    else if (tax_temp <= 4500)
    {
        return (tax_temp*0.1-105);
    }
    else if (tax_temp <= 9000)
    {
        return (tax_temp*0.2-555);
    }
    else if (tax_temp <= 35000)
    {
        return (tax_temp*0.25-1005);
    }
    else if (tax_temp <= 55000)
    {
        return (tax_temp*0.3-2755);
    }
    else if (tax_temp <= 85000)
    {
        return (tax_temp*0.35-5505);
    }
    else 
    {
        return (tax_temp*0.45-13505);
    }
}











