using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace bai394041
{ 
    class LopSN
    {   
        private int[] a;
        private int so_pt;

        public LopSN (int so_pt)
        {
            this.so_pt = so_pt;
            this.a = new int[so_pt];
        }
        public void nhap_mang()
        {
            

            for (int i = 0; i < so_pt; i++)
            {
                Console.WriteLine("Nhap phan tu thu {0}", i);
                a[i] = Int32.Parse(Console.ReadLine());
            }
        }

        public void ktsoam()
        {
            for (int i = 0; i < so_pt; i++)
                if (a[i] < 0)
                    Console.WriteLine("{0} là số am", a[i]);
                else
                    Console.WriteLine("{0} khong là số am", a[i]);
        }

        public int tong_so_am()
        {
            int kq = 0;
            for (int i = 0; i < so_pt; i++)
                if (a[i] < 0)
                    kq += a[i];
            Console.WriteLine("Tong so am: {0}", kq);
            return kq;
        }

        public int tong_so_chan()
        {
            int kq = 0;
            for (int i = 0; i < so_pt; i++)
                if ( a[i] % 2 == 0)
                    kq += a[i];
            Console.WriteLine("Tong so chan: {0}", kq);
            return kq;
        }
    }
}
