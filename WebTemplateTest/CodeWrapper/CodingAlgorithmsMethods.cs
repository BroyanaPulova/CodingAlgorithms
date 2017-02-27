using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CodeWrapper
{
    public class CodingAlgorithmsMethods
    {
        [DllImport(@"C:\Users\Boryana\Desktop\Дипломна\WebTemplateTest\WebTemplateTest\Debug\NativeLib.dll")]
        public static extern System.IntPtr HuffmanEncode(string text);

        [DllImport(@"C:\Users\Boryana\Desktop\Дипломна\WebTemplateTest\WebTemplateTest\Debug\NativeLib.dll")]
        public static extern System.IntPtr HuffmanDecode(string text, string plainText);

        [DllImport(@"C:\Users\Boryana\Desktop\Дипломна\WebTemplateTest\WebTemplateTest\Debug\NativeLib.dll")]
        public static extern System.IntPtr HuffmanShowTable(string text);

        [DllImport(@"C:\Users\Boryana\Desktop\Дипломна\WebTemplateTest\WebTemplateTest\Debug\NativeLib.dll")]
        public static extern System.IntPtr ShannonFanoEncode(string text);

        [DllImport(@"C:\Users\Boryana\Desktop\Дипломна\WebTemplateTest\WebTemplateTest\Debug\NativeLib.dll")]
        public static extern System.IntPtr ShannonFanoDecode(string text, string plainText);

        [DllImport(@"C:\Users\Boryana\Desktop\Дипломна\WebTemplateTest\WebTemplateTest\Debug\NativeLib.dll")]
        public static extern System.IntPtr ShannonFanoShowTable(string text);

        [DllImport(@"C:\Users\Boryana\Desktop\Дипломна\WebTemplateTest\WebTemplateTest\Debug\BinaryCodes.dll",
            CallingConvention = CallingConvention.Cdecl)]
        public static extern System.IntPtr LinearCode(int m, int n, int[] matrix);

        [DllImport(@"C:\Users\Boryana\Desktop\Дипломна\WebTemplateTest\WebTemplateTest\Debug\BinaryCodes.dll",
         CallingConvention = CallingConvention.Cdecl)]
        public static extern System.IntPtr SystemFormCheckMatrix(int m, int n, int[] matrix);

        [DllImport(@"C:\Users\Boryana\Desktop\Дипломна\WebTemplateTest\WebTemplateTest\Debug\BinaryCodes.dll",
        CallingConvention = CallingConvention.Cdecl)]
        public static extern System.IntPtr SyndromeDecode(int n, int k, int d, int y, int[] h);

        [DllImport(@"C:\Users\Boryana\Desktop\Дипломна\WebTemplateTest\WebTemplateTest\Debug\BinaryCodes.dll",
        CallingConvention = CallingConvention.Cdecl)]
        public static extern System.IntPtr HammingDecode(int r, int y);

        [DllImport(@"C:\Users\Boryana\Desktop\Дипломна\WebTemplateTest\WebTemplateTest\Debug\BinaryCodes.dll",
        CallingConvention = CallingConvention.Cdecl)]
        public static extern System.IntPtr MeggetDecode(int n, int data, int y);

        [DllImport(@"C:\Users\Boryana\Desktop\Дипломна\WebTemplateTest\WebTemplateTest\Debug\BinaryCodes.dll",
        CallingConvention = CallingConvention.Cdecl)]
        public static extern System.IntPtr ReedMullerDecode(int r, int m, int y, int yLength);

        [DllImport(@"C:\Users\Boryana\Desktop\Дипломна\WebTemplateTest\WebTemplateTest\Debug\BinaryCodes.dll",
        CallingConvention = CallingConvention.Cdecl)]
        public static extern System.IntPtr ReedMullerCoding(int r, int m, int y, int yLength);
    }
}
