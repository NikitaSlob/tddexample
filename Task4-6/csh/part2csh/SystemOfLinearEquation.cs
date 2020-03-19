using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace part2csh
{
    public class SystemOfLinearEquation
    {
        LinearEquation[] SLAU;
        int n;
        public SystemOfLinearEquation(int n)
        {
            this.n = n;
            SLAU = new LinearEquation[n];
        }
        public LinearEquation this[int i]
        {

            get
            {
                if (i < n && i >= 0) return SLAU[i];
                else
                    throw new IndexOutOfRangeException();
            }
            set
            {
                if (i < n && i >= 0) SLAU[i] = value;
                else
                    throw new IndexOutOfRangeException();
            }
        }
        public double[] gauss()
        {
            double[,] a = new double[n,n];
            double[,] b = new double[n,n+1];
            double[] y = new double[n];
            for (int i = 0; i < n; i++)
            {
                double[] c = new double[n + 1];
                SLAU[i].ToMass(c);
                for (int j = 0; j < n + 1; j++)
                    b[i, j] = c[j];
            }
            for (int i = 0; i < n; i++)
            {
                y[i] = b[i,n];
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    a[i,j] = b[i,j];
            }
            double[] x;
            double max;
            int k, index;
            const double eps = 0.00001;  // точность
            x = new double[n];
            k = 0;
            while (k < n)
            {
                // Поиск строки с максимальным a[i][k]
                max = Math.Abs(a[k,k]);
                index = k;
                for (int i = k + 1; i < n; i++)
                {
                    if (Math.Abs(a[i,k]) > max)
                    {
                        max = Math.Abs(a[i,k]);
                        index = i;
                    }
                }
                // Перестановка строк
                if (max < eps)
                {
                    // нет ненулевых диагональных элементов
                    throw new ArgumentException();
                }
                for (int j = 0; j < n; j++)
                {
                    double temp1 = a[k,j];
                    a[k,j] = a[index,j];
                    a[index,j] = temp1;
                }
                double temp = y[k];
                y[k] = y[index];
                y[index] = temp;
                // Нормализация уравнений
                for (int i = k; i < n; i++)
                {
                    double temp2 = a[i,k];
                    if (Math.Abs(temp2) < eps) continue; // для нулевого коэффициента пропустить
                    for (int j = 0; j < n; j++)
                        a[i,j] = a[i,j] / temp2;
                    y[i] = y[i] / temp2;
                    if (i == k) continue; // уравнение не вычитать само из себя
                    for (int j = 0; j < n; j++)
                        a[i,j] = a[i,j] - a[k,j];
                    y[i] = y[i] - y[k];
                }
                k++;
            }
            // обратная подстановка
            for (k = n - 1; k >= 0; k--)
            {
                x[k] = y[k];
                for (int i = 0; i < k; i++)
                    y[i] = y[i] - a[i,k] * x[k];
            }
            return x;
        }
        ~SystemOfLinearEquation() { }
    }
}
