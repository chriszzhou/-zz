
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp1
{
    class manager
    {
        public manager()
        {
            Console.WriteLine("创建部门经理对象");
        } 
        public void deductsalary(em_ori employee)
        {
            Console.WriteLine("你玩游戏，我扣你工资");
            employee.Salary -= 100;
        }
    }
}