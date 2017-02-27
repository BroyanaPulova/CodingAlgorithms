using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace CodingWeb.Models
{
    public class SyndromDecode : MatrixCodeModel
    { 
        public int MinimalLength { get; set; }
        public string YInput { get; set; }
    }
}