using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace part2csh
{
    class Program
    {
        static void Main(string[] args)
        {
            LinearEquation l1 = new LinearEquation("1,2 2,1 3 4", 4);
            Console.WriteLine("{0}", l1.indexes[0]);
        }
    }
}
