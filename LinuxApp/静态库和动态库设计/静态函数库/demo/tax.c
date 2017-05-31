/*******************************************************************************
  �� �� ��: tax.c
  ����ʱ��: 2017-05-31
  �� �� ��: ����
  ����˵��: ��������˰���㺯����
*******************************************************************************/

int tax(int salary, int insurance)
{
    int tax_salary = salary - insurance; /* Ӧ��˰���� */
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











