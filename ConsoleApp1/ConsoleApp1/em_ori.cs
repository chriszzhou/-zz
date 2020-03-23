
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp1
{
    class em_ori
    {
        private int m_salary;
        public  manager manager;
        public int Salary { get => m_salary; set => m_salary = value; }
        public em_ori(manager manager)
        {
            Console.WriteLine("创建了一个员工对象");
            m_salary = 3000;
            this.manager = manager;
            Console.WriteLine("{0}", Salary);

        }
        public void playgame()
        {
            Console.WriteLine("game is good!");
            manager.deductsalary(this);
            Console.WriteLine("{0}", Salary);
        }
    }
}