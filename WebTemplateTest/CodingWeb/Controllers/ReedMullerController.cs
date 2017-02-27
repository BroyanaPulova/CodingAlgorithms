using CodingWeb.Common;
using CodingWeb.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace CodingWeb.Controllers
{
    public class ReedMullerController : BaseCodingControler
    {
        // GET: ReedMuller
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
        
        public string Encode(ReedMullerModel model)
        {
            int input = Convert.ToInt32(model.Input, 2);
            int n = (int)Math.Pow(2, model.M);
            string result = CodeWrapper.CodingHelper.ReedMullerCoding(model.R, model.M, input, model.Input.Length);

            return new string(result.Reverse().Take(n).Reverse().ToArray());
        }
        
        public string Decode(ReedMullerModel model)
        {
            int input = Convert.ToInt32(model.Input, 2);
            return CodeWrapper.CodingHelper.ReedMullerDecode(model.R, model.M, input,model.Input.Length);
        }
    }
}