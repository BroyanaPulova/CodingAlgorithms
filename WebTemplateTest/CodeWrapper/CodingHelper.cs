using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CodeWrapper
{
    public class CodingHelper
    {
        public static string HuffmanEncode(string text)
        {
            return Marshal.PtrToStringAnsi(CodingAlgorithmsMethods.HuffmanEncode(text));
        }

        public static string HuffmanDecode(string text, string plainText)
        {
            return Marshal.PtrToStringAnsi(CodingAlgorithmsMethods.HuffmanDecode(text, plainText));
        }

        public static string HuffmanShowTable(string text)
        {
            return Marshal.PtrToStringAnsi(CodingAlgorithmsMethods.HuffmanShowTable(text));
        }

        public static string ShannonFanoEncode(string text)
        {
            return Marshal.PtrToStringAnsi(CodingAlgorithmsMethods.ShannonFanoEncode(text));
        }

        public static string ShannonFanoDecode(string text, string plainText)
        {
            return Marshal.PtrToStringAnsi(CodingAlgorithmsMethods.ShannonFanoDecode(text, plainText));
        }

        public static string ShannonFanoShowTable(string text)
        {
            return Marshal.PtrToStringAnsi(CodingAlgorithmsMethods.HuffmanShowTable(text));
        }

        public static string SpectreLinearCode(int m, int n, int[] matrix)
        {
            return Marshal.PtrToStringAnsi(CodingAlgorithmsMethods.LinearCode(m, n, matrix));
        }

        public static string SystemFormCheckMatrix(int m, int n, int[] matrix)
        {
            return Marshal.PtrToStringAnsi(CodingAlgorithmsMethods.SystemFormCheckMatrix(m, n, matrix));
        }

        public static string SyndromeDecode(int n, int k, int d, int[] h, string y)
        {
            int input = Convert.ToInt32(y, 2);
            return Marshal.PtrToStringAnsi(CodingAlgorithmsMethods.SyndromeDecode(n, k, d, input, h));
        }

        public static string HammingDecode(int r, int y)
        {
            return Marshal.PtrToStringAnsi(CodingAlgorithmsMethods.HammingDecode(r,y));
        }

        public static string MeggetDecode(int n, int data, int y)
        {
            return Marshal.PtrToStringAnsi(CodingAlgorithmsMethods.MeggetDecode(n, data, y));
        }

        public static string ReedMullerCoding(int r, int m, int y, int yLength)
        {
            return Marshal.PtrToStringAnsi(CodingAlgorithmsMethods.ReedMullerCoding(r, m, y, yLength));
        }

        public static string ReedMullerDecode(int r, int m, int y, int yLength)
        {
            return Marshal.PtrToStringAnsi(CodingAlgorithmsMethods.ReedMullerDecode(r, m, y, yLength));
        }
    }
}