using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bai33
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Nhap so phan tu cua mang:");
            int so_pt = Int32.Parse(Console.ReadLine());
            int[] a = new int[so_pt];
            a = nhap_mang(so_pt);
            Console.WriteLine("Nhap pt can tim");
            int x = Int32.Parse(Console.ReadLine());
            int kq = tim(a, x);
            if (kq == -1)
                Console.WriteLine("Phan tu {0} khong co trong mang", x);
            else
                Console.WriteLine("Phan tu {0} co trong mang ",x);
            Console.ReadLine();
        }
        public static int[] nhap_mang(int so_pt)
        {
            int[] a = new int[so_pt];
            for (int i=0; i<so_pt; i++)
            {
                Console.WriteLine("Nhap pt thu {0}", i);
                a[i] = Int32.Parse(Console.ReadLine());
            } return a;
        }
        public static int tim(int [] a, int n)
        {
            int kq = -1;
            for (int i = 0; i < a.Length; i++)
                if (a[i] == n)
                    kq = i;
            return kq;
        }
    }

}
