using CodeWrapper;
using CodingWeb.Common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace CodingWeb.Controllers
{
    public class HemmingController : BaseCodingControler
    {
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
        
        public string Decode(int r, string y)
        {
            int input = Convert.ToInt32(y, 2);
            return CodingHelper.HammingDecode(r, input);
        }
    }
}