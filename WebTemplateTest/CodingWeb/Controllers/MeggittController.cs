using CodingWeb.Common;
using CodingWeb.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace CodingWeb.Controllers
{
    public class MeggittController : BaseCodingControler
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
        
        public string Decode(MeggitModel model)
        {
            int input = Convert.ToInt32(model.YInput, 2);
            return CodeWrapper.CodingHelper.MeggetDecode(model.N, model.Data, input);
        }
    }
}