using CodingWeb.Common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace CodingWeb.Models
{
    public class MatrixCodeModel
    {
        /// <summary>
        /// Rows
        /// </summary>
        public int M { get; set; }
        
        /// <summary>
        /// Columns
        /// </summary>
        public int N { get; set; }
        public string[][] Matrix { get; set; }

        public int[] ConvertToDecMatrix()
        {
            return MatrixMath.ConvertBinaryMatrixToDec(Matrix);
        }
    }
}