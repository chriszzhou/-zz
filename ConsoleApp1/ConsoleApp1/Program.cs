using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public delegate void playgamehandle(object sender,EventArgs e);
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("场景开始");
            //manager m1=new manager();
            //em_ori e1=new em_ori(m1);
            //e1.playgame();
            em1 e1 = new em1();
            ma1 m1 = new ma1();
            e1.play += new playgamehandle(m1.deductsalary);
            e1.playgame();
            System.Threading.Thread.Sleep(2000);
            Console.ReadLine();
        }
    }
}
