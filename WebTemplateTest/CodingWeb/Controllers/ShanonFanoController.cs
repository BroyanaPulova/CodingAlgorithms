using CodeWrapper;
using CodingWeb.Common;
using CodingWeb.Models;
using CodingWeb.Service;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;
using System.Web.Mvc;

namespace CodingWeb.Controllers
{
    public class ShanonFanoController : BaseCodingControler
    {
        // GET: ShanonFano
        public override ActionResult ShortDetails()
        {
            return View();
        }

        public override ActionResult Example()
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
                
                var result = CodingHelper.ShannonFanoEncode(value);
                str.Append(result);
                str.Append(Environment.NewLine);
                str.Append(CodingHelper.ShannonFanoShowTable(value));
                str.AppendFormat("${0}", key);
            }
            catch (Exception exc)
            {

            }

            return str.ToString();
        }

        [HttpPost]
        public string Decode(TableModel model)
        {
            string data = CodingSQLHelper.GetValue(model.Key);

            return CodingHelper.ShannonFanoDecode(model.Text, data);
        }
    }
}