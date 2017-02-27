using CodeWrapper;
using CodingWeb.Common;
using CodingWeb.Models;
using CodingWeb.Service;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Web;
using System.Web.Mvc;

namespace CodingWeb.Controllers
{
    public class HufmanController : BaseCodingControler
    {
        public override ActionResult Example()
        {
            return View();
        }

        public override ActionResult ShortDetails()
        {
            return View();
        }

        public override ActionResult Theory()
        {
            return View();
        }
        
        [HttpPost]
        public string Encode(string value)
        {
            StringBuilder str = new StringBuilder();
            try
            {
                int key = CodingSQLHelper.SetKey(value);

                var result = CodingHelper.HuffmanEncode(value);
                str.Append(result);
                str.Append(Environment.NewLine);
                str.Append(CodingHelper.HuffmanShowTable(value));
                str.AppendFormat("${0}", key);
            }
            catch(Exception exc)
            {

            }

            return str.ToString();
        }

        [HttpPost]
        public string Decode(TableModel model)
        {
            string data = CodingSQLHelper.GetValue(model.Key);
            
            return CodingHelper.HuffmanDecode(model.Text, data);
        }
    }
}