using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace part1csh
{
    class Program
    {
        static void Main(string[] args)
        {
            double[] array = new double[] { 1, 2, 3, 4 };
            var indexer1 = new Indexer(ref array, 1, 2);
            var indexer2 = new Indexer(ref array, 0, 2);
            indexer1[0] = 100500;
            Console.WriteLine(indexer2[1]);
        }
    }
}
