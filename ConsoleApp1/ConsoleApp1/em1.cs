
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp1
{
    class em1
    {
        public event playgamehandle play;
        public int m_salary;
        public int Salary { get => m_salary; set => m_salary = value; }
        public em1()
        {
            Console.WriteLine("创建了一个员工对象");
            m_salary = 3000;
            Console.WriteLine("{0}", Salary);

        }
        public void playgame()
        {
            Console.WriteLine("game is good!");
            EventArgs e = new EventArgs();
            onplaygame(e);
            Console.WriteLine("{0}", Salary);
        }
        public virtual void onplaygame(EventArgs e)
        {
            if (play != null)
            {
                play(this, e);
            }
            else
                Console.WriteLine("没定义");
        }
    }
}