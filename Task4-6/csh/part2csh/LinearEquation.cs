using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace part2csh
{
    public class LinearEquation
    {
        public double[] indexes;
        int n;
        public LinearEquation()
        {
            n = 0;
            indexes = new double[0];
        }
        public LinearEquation(string s, int n)
        {
            this.n = n;
            string[] s1 = s.Split(' ');
            indexes = new double[n];
            for (int i = 0; i < n; i++)
            {

                indexes[i] = double.Parse(s1[i]);
            }
        }
        public LinearEquation(int n)
        {
            this.n = n;
            indexes = new double[n];
            for (int i = 0; i < n; i++)
            {
                indexes[i] = 0;
            }
        }
        public LinearEquation(double[] array, int n)
        {
            this.n = n;
            indexes = new double[n];
            for (int i = 0; i < n; i++)
            {
                indexes[i] = array[i];
            }
        }
        public void SetIndexes(int x)
        {
            for (int i = 0; i < n; i++)
            {
                indexes[i] = x;
            }
        }
        public void SetIndexesRandom()
        {
            Random rand = new Random();
            for (int i = 0; i < n; i++)
            {
                indexes[i] = rand.Next(1, 100);
            }
        }
        public void ToMass(double[] d)
        {
            if (this)
            {
                for (int i = 0; i < n; i++)
                {
                    d[i] = indexes[i];
                }
            }
            else
                throw new ArgumentException();
        }
        public static LinearEquation operator +(LinearEquation a, LinearEquation b)
        {
            if (a.n == b.n)
            {
                LinearEquation l = new LinearEquation(a.n);
                for (int i = 0; i < a.n; i++)
                {
                    l.indexes[i] = a.indexes[i] + b.indexes[i];
                }
                return l;
            }
            else
                throw new ArgumentException();
        }
        public static LinearEquation operator -(LinearEquation a, LinearEquation b)
        {
            if (a.n == b.n)
            {
                LinearEquation l = new LinearEquation(a.n);
                for (int i = 0; i < a.n; i++)
                {
                    l.indexes[i] = a.indexes[i] - b.indexes[i];
                }
                return l;
            }
            else
                throw new ArgumentException();
        }
        public static LinearEquation operator *(LinearEquation a, double r)
        {
            for (int i = 0; i < a.n; i++)
            {
                a.indexes[i] *= r;
            }
            return a;
        }
        public static LinearEquation operator *(double r, LinearEquation a)
        {
            for (int i = 0; i < a.n; i++)
            {
                a.indexes[i] *= r;
            }
            return a;
        }
        public static LinearEquation operator -(LinearEquation a)
        {
            for (int i = 0; i < a.n; i++)
            {
                a.indexes[i] *= -1;
            }
            return a;
        }
        public static bool operator ==(LinearEquation a, LinearEquation b)
        {
            bool bl = true;
            if (a.n == b.n)
            {
                for (int i = 0; i < a.n; i++)
                {
                    if (a.indexes[i] != b.indexes[i])
                        bl = false;
                }
                return bl;
            }
            else
            {
                throw new ArgumentException();
            }
        }
        public static bool operator !=(LinearEquation a, LinearEquation b)
        {
            bool bl = true;
            if (a.n == b.n)
            {
                for (int i = 0; i < a.n; i++)
                {
                    if (a.indexes[i] != b.indexes[i])
                        bl = false;
                }
                return !bl;
            }
            else
            {
                throw new ArgumentException();
            }
        }
        public static bool operator false(LinearEquation a)
        {
            bool b = false;
            for (int i = 0; i < a.n - 1; i++)
            {
                if (a.indexes[i] == 0 && !b)
                    b = false;
                else
                    b = true;
            }
            if (!b && a.indexes[a.n - 1] != 0)
                b = false;
            else
                b = true;
            return !b;
        }
        public static bool operator true(LinearEquation a)
        {
            bool b = false;
            for (int i = 0; i < a.n - 1; i++)
            {
                if (a.indexes[i] == 0 && !b)
                    b = false;
                else
                    b = true;
            }
            if (!b && a.indexes[a.n - 1] != 0)
                b = false;
            else
                b = true;
            return b;
        }
        public override string ToString()
        {
            string s="";
            for (int i = 0; i < n - 1; i++)
            {
                s += (indexes[i]).ToString() + 'x' + i.ToString();
                if (i < n - 2)
                    s += '+';
            }
            s += '=' + indexes[n - 1];

            return s;
        }
    }
}
