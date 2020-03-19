using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace part1csh
{
    public class Indexer
    {           
        private double[] array;
        public int begin;
        public int Length;
        Indexer() { }
        public Indexer(ref double[] array, int begin, int length)
        {
            if (begin < 0 || length <= 0 || array.Length < begin + length)
                throw new ArgumentException();
            this.array = array;
            this.begin = begin;
            this.Length = length;
        }
        public double this[int i]
        {

            get
            {
                if (begin + i < array.Length && i >= 0) return array[i + begin];
                else
                    throw new IndexOutOfRangeException();
            }
            set
            {
                if (begin + i < Length && i >= 0) array[i + begin] = value;
                else
                    throw new IndexOutOfRangeException();
            }
        }
        ~Indexer() { }
    }
    
}
