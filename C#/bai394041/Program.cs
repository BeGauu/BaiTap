using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace bai_39_40_41
{
    class Program
    {
        static void Main(string [] args)
        {
            LopSn sn = new LopSn();

            sn.nhap_mang();
            sn.ktsoam();
            sn.tong_so_am();
            sn.tong_so_chan();
        }
    }
    
}
