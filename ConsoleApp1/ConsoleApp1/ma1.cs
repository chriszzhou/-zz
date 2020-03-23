
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp1
{
    class ma1
    {
        public ma1()
        {
            Console.WriteLine("创建部门经理对象");
        }
        public void deductsalary(Object sender,EventArgs e)
        {
            Console.WriteLine("你玩游戏，我扣你工资");
            ((em1)sender).m_salary -= 100;
        }
    }
}