using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace CodingWeb.Common
{
    public class MatrixMath
    {
        public static int[] ConvertBinaryMatrixToDec(string[][] matrix)
        {
            int[] decMatrix = new int[matrix.GetLength(0)];

            for (int i = 0; i < matrix.Length; i++)
            {
                string[] tempArray = matrix[i];
               
                string r = string.Empty;
                for (int j = 0; j < matrix[i].Length; j++)
                {
                    r += matrix[i][j];
                }
                decMatrix[i] = Convert.ToInt32(r, 2);
            }

            return decMatrix;
        }
    }
}